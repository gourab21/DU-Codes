.MODEL SMALL
.DATA
AA DW 1234H
BB DW 0BCDEH
.CODE
.STARTUP
MOV BX,WORD PTR AA
MOV CX,WORD PTR BB
ADD BX,CX
MOV AX,BX
.EXIT
END
