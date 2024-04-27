.586
.MODEL FLAT
INCLUDE io.h          

.STACK 4096

.DATA
startingWeight  DWORD   ?
expectedWeight  DWORD   ?
caloriesPerDay  DWORD   500
poundsPerMonth  DWORD   4
monthcount      DWORD   0

prompt          BYTE    "Enter your starting weight: ", 0
resultLbl       BYTE    "Expected weight after ", 0
monthsLbl       BYTE    10 DUP (?)
monthsUnit      BYTE    " months: "
monthsVal       BYTE    2 DUP (?)
weightLbl       BYTE    " pounds", 0

.CODE
_MainProc PROC

    input   prompt, monthsVal, 10
    atod    monthsVal
    mov     startingWeight, eax
    mov     edx, 1
    mov     ecx, 6


    L1:
        mov     eax, startingWeight
        sub     eax, poundsPerMonth
        mov     expectedWeight, eax
        add     monthcount, edx

        dtoa    monthsLbl, monthcount
        dtoa    monthsVal, expectedWeight

        output  resultLbl, monthsLbl, monthsUnit, monthsVal, weightLbl

        mov     ebx, expectedWeight
        mov     startingWeight, ebx

        loop    L1

    mov     eax, 0
    ret
_MainProc ENDP
END
