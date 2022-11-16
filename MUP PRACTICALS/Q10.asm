.model small ; contain two segment data and code
 .stack ; tells the assembler to reserve storage
;instructions for the 80386 processor
 .data ; start of data segment
 ARRAY DB 10 DUP(?); Declaring an array with garbage
 
 MESS0 DB 13,10,"ENTER THE NUMBER: $" ; 10 is the ASCII control code for line feed while 13 is the code

 MESS1 DB 13,10,"ENTER THE NUMBER OF ELEMENTS: $"
 MESS2 DB 13,10,"ENTER THE ELEMENT TO BE SEARCHED: $"
 MESS3 DB 13,10,"VALUE FOUND AT LOCATION- $"
 MESS4 DB 13,10,"VALUE NOT FOUND!!!$"
 ErrMess DB 13,10,"ERROR IN INPUT DIGIT$"
 DAT DB ? ;set byte size variable
 number dw ? ; set double word size variable
 .code ; start of code segment
 .startup ; Generates program start-up code
 MOV DX,OFFSET MESS1
 MOV AH,09
 INT 21H ; Output a string terminated by '$’ stored in DX, as AH =9
 MOV AH,01
 INT 21H ; input from user
 cmp al,39h
 jbe abc ; jump if below or equal to
 MOV DX,OFFSET ErrMess
 MOV AH,09
 INT 21H ; Output a string terminated by '$’ stored in DX, as AH =9
 jmp myexit
 abc:
 and al,0fh
 mov ah,0
 
 mov number,ax
 MOV CX,AX
 MOV DI,0
 MYLOOP:
 MOV DX,OFFSET MESS0
 MOV AH,09
 INT 21H ; Output a string terminated by '$’ stored in DX, as AH =9
 MOV AH,01
 INT 21H ; input from user
 cmp al,39h
 jbe abc2 ; jump if below or equal to
 MOV DX,OFFSET ErrMess
 MOV AH,09
 INT 21H ; Output a string terminated by '$’ stored in DX, as AH =9
 jmp myexit
 abc2:
 and al,0fh
 MOV ARRAY[DI],AL
 INC DI
 LOOP MYLOOP
 MOV DX,OFFSET MESS2
 MOV AH,09
 INT 21H ; Output a string terminated by '$’ stored in DX, as AH =9
 MOV AH,01
 INT 21H ; input from user
 cmp al,39h
 jbe abc3 ; jump if below or equal to
 MOV DX,OFFSET ErrMess
 
 MOV AH,09
 INT 21H ; Output a string terminated by '$’ stored in DX, as AH =9
 jmp myexit
 abc3:
 and al,0fh
 MOV DAT,AL
 mov ax,ds
 mov es,ax
 mov al,dat
 CLD ; auto increment mode
 mov cx,number
 INC CX
 mov DI, offset ARRAY
 repne SCASB ; scan the memory for AL
 CMP CX,0
 JE NTFOUND
 MOV DX,OFFSET MESS3
 MOV AH,09
 INT 21H ; Output a string terminated by '$’ stored in DX, as AH =9
 SUB NUMBER,CX ;FIND ELEMENT LOCATION
 ADD NUMBER,30H
 MOV DX,NUMBER
 INC DX
 MOV AH,02
 INT 21H ; Output a character present in DL , as AH value is 2
 JMP myexit
 NTFOUND:
 
 MOV DX,OFFSET MESS4
 MOV AH,09
 INT 21H ; Output a string terminated by '$’ stored in DX, as AH =9
 myexit:
 MOV AH,4CH
 INT 21H ; causes the current process to terminate
 END