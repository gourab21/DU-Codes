; doing bcd subtraction with 9876H and 8654H

.MODEL SMALL
.DATA
    data1   DW    9876H
    data2   DW    8654H
    result  DW    ?
.CODE
.STARTUP
    MOV     DX,  data1
    MOV     BX,  data2
    
    SUB     DL,   BL
    MOV     AL,   DL
    DAS
    MOV     CL,   AL

    SBB     DH,   BH
    MOV     AL,   DH
    DAS
    MOV     CH,   AL


    MOV     result, CX
.EXIT
END