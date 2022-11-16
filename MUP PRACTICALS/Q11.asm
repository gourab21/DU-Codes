; doing bcd addition with 1234H and 0022H

.MODEL SMALL
.486
.DATA
    data1   DW    1234H
    data2   DW    0022H
    result  DD    ?
.CODE
.STARTUP
    MOV     BX,  data1
    MOV     DX,  data2
    
    ADD     DL,   BL
    MOV     AL,   DL
    DAA
    MOV     CL,   AL

    ADC     DH,   BH
    MOV     AL,   DH
    DAA
    MOV     CH,   AL

    MOV     result, CX
.EXIT
END