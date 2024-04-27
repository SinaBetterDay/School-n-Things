.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
calories    DWORD   0
minutes     DWORD   5

resultLbl   BYTE    "Calories burned:", 0
minutesVal  BYTE    10 DUP (?), 0
minutesStr  BYTE    " minutes:"
caloriesVal BYTE    10 DUP (?), 0
caloriesStr BYTE    " calories.", 0

.CODE
_MainProc PROC

    mov ecx, 5 

    L1:
        mov eax, minutes
        imul eax, 4
        add calories, eax

        dtoa minutesVal, minutes
        dtoa caloriesVal, calories
        output resultLbl, minutesVal, minutesStr, caloriesVal, caloriesStr

        add minutes, 5

        loop L1

    mov     eax, 0
    ret
_MainProc ENDP
END
