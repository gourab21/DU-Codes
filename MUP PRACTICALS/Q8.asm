.MODEL SMALL
.DATA
A DB 1,2,3,4,5,6,7,8
B DB 8,7,6,5,4,3,2,1
C DB 8 (?)
.CODE
.STARTUP          
MOV SI,OFFSET A
MOV BX,OFFSET B      
MOV DI,OFFSET C
MOV CX,08H
rashu: MOV AL,[SI]
MOV DL,[BX]
SUB AL,DL
MOV [DI],AL
INC SI
INC DI
INC BX
LOOP rashu
.EXIT
END