

#include <cstdio>
#include <climits>
#include <iomanip>
#include <iostream>
#define MAX_NODES 50

using namespace std;

class Graph
{
public:
  int edges;
  int vertices;
  int nextHop[MAX_NODES][MAX_NODES];
  int distances[MAX_NODES][MAX_NODES];
  int adjMatrix[MAX_NODES][MAX_NODES];

  void input(int v, int e)
  {
    edges = e;
    vertices = v;

    for (int i = 0; i < v; i++)
      for (int j = 0; j < v; j++)
        adjMatrix[i][j] = 0;

    int src, dest, weight;

    for (int i = 0; i < edges; i++)
    {
      cout << "\nEDGE " << (i + 1)
           << "\n======\n";
      cout << "Enter Source: ";
      cin >> src;
      cout << "Enter Destination: ";
      cin >> dest;
      cout << "Enter Weight: ";
      cin >> weight;
      adjMatrix[src - 1][dest - 1] = weight;
      adjMatrix[dest - 1][src - 1] = weight;
    }
  }

  void display()
  {
    for (int i = 0; i < vertices; i++)
    {
      for (int j = 0; j < vertices; j++)
        cout << setw(5) << adjMatrix[i][j] << " ";
      cout << endl;
    }
  }

  void distanceVector()
  {
   
    for (int i = 0; i < vertices; i++)
      for (int j = 0; j < vertices; j++)
      {
        if (i == j)
          distances[i][j] = 0;
        else if (adjMatrix[i][j] == 0)
          distances[i][j] = INT_MAX / 2;
        else
          distances[i][j] = adjMatrix[i][j];
        nextHop[i][j] = -1;
      }

    cout << "Initial Distance Matrix\n";
    cout << "======================\n";
    for (int i = 0; i < vertices; i++)
    {
      for (int j = 0; j < vertices; j++)
        if (distances[i][j] == INT_MAX / 2)
          cout << setw(5) << right << "INF"
               << " ";
        else
          cout << setw(5) << distances[i][j] << " ";
      cout << endl;
    }

    
    bool flag;
    do
    {
      
      flag = false;
      
      for (int i = 0; i < vertices; i++)
        
        for (int j = 0; j < vertices; j++)
          
          for (int k = 0; k < vertices; k++)
            if (distances[i][j] > (distances[i][k] + distances[k][j]))
            {
              distances[i][j] = distances[j][i] =
                  distances[i][k] + distances[k][j];
              nextHop[i][j] = nextHop[j][i] = k;
              flag = true;
            }
    } while (flag);

    cout << "\nFinal Distance Matrix\n";
    cout << "======================\n";
    for (int i = 0; i < vertices; i++)
    {
      for (int j = 0; j < vertices; j++)
        cout << setw(5) << distances[i][j] << " ";
      cout << endl;
    }

    for (int i = 0; i < vertices; i++)
    {
      cout << "\nRouting Table for Router " << (i + 1) << ":";
      cout << "\nDest Router \t Via \t\t Distance";
      cout << "\n=========== \t ======== \t ========\n";
      for (int j = 0; j < vertices; j++)
      {
        if (i == j)
          continue;
        cout << (j + 1)
             << " \t\t ";
        if (nextHop[i][j] == -1)
          cout << "-";
        else
          cout << (nextHop[i][j] + 1);
        cout << " \t\t "
             << distances[i][j] << endl;
      }
    }
  }
};

int main()
{
  int v, e;
  int link1, link2;
  Graph graph;

  cout << "Enter No. of Nodes: ";
  cin >> v;
  cout << "Enter No. of Edges: ";
  cin >> e;

  graph.input(v, e);

  cout << "\nGRAPH\n=====\n";
  graph.display();
  cout << endl;

  graph.distanceVector();

  cout << "\nSimulating Link Failure\n";
  cout << "=======================\n";
  cout << "Enter Routers to Break Link Between: ";
  cin >> link1 >> link2;
  cout << endl;

  graph.adjMatrix[link1 - 1][link2 - 1] =
      graph.adjMatrix[link2 - 1][link1 - 1] = 0;

  graph.distanceVector();

  return 0;
}
