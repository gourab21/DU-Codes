#include <iostream>
#include <string>
using namespace std;

void display(int as[],int size,int base=0)
{
	for (int i=0;i<size;i++)
	{
		cout<<as[i+base];
	}
	cout<<endl;
}

int X(int x,int y)
{
	if (x==y)
		return 0;
	else
		return 1;
}

int crc(int a[],int b[],int temp[],int la,int lb)
{
	int count=0,start=0;
	for (int i=0;i<lb;i++)
		{
			temp[i]=X(a[i],b[i]);
			count++;
		}
		
	while (true)
	{
		while(temp[start]==0)
		{
			start++;
			temp[lb-1+start]=a[count];
			count++;
			if (count==la)
			{
				return start;
			}
		}
		for (int i=0;i<lb;i++)
		{
			temp[i+start]=X(temp[i+start],b[i]);
		}
	}
}

int main()
{
	int a[100],b[100], la=0,lb=0,i=0;
	char c[100],d[100];
	
	cout<<"Enter The Message : ";
	 gets(c);
	for(int i=0;c[i];i++)
	{
		if (c[i]=='1')
			a[i]=1;
		else if(c[i]=='0')
			a[i]=0;
		else
			{cout<<"Enter Correct Message!!!!!!!!!!!!"; exit(0);			}
		la=i+1;
	}
	///display(a,la);
	cout<<"Enter The Generator : ";
	gets(d);
	for(int i=0;d[i];i++)
	{
		if (d[i]=='1')
			b[i]=1;
		else if(d[i]=='0')
			b[i]=0;
		else
			{cout<<"Enter Correct Message!!!!!!!!!!!!"; exit(0);			}
		lb=i+1;
	}
	///display(b,lb);
	int temp[la];
	///display(a,la);
	
	/////////////////////
	//cout<<la<<lb;
	int start=crc(a,b,temp,la,lb);
	///cout<<start;
	cout<<"Since Remainder is - ";
	display(temp,lb,start);
	cout<<"";
	for (int i=0;i<lb-1;i++)
	{
		if (temp[start+i]!=0)
		{
			cout<<"There is Error!!!!!!!";
			break;
		}
		else
		{
			cout<<"No Error is Present...";
			break;
		}
			
	}
	
}

