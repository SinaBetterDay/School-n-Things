.586
.MODEL FLAT
INCLUDE io.h
.STACK 4096
.DATA
array DWORD 10, 25, 56, 80, 3
arraySize = ($ - array) / 4

outputLbl BYTE "Array in reverse: ", 0
result BYTE 11 DUP (?), 0

.CODE

reverse PROC
    mov esi, OFFSET array + (arraySize - 1) * 4
    mov ecx, arraySize

reverseLoop:
    mov eax, [esi]
    dtoa result, eax
    output outputLbl, result
    sub esi, 4
    loop reverseLoop

    ret
reverse ENDP

_MainProc PROC
    call reverse
    ret
_MainProc ENDP

END
