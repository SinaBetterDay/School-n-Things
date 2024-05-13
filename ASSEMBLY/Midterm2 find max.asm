.586
.MODEL FLAT
INCLUDE io.h
.STACK 4096
.DATA
number1 DWORD ?
number2 DWORD ?
prompt1 BYTE "Enter number 1", 0
prompt2 BYTE "Enter number 2", 0
string BYTE 40 DUP (?)
outputLbl BYTE "The maximum is", 0
result BYTE 11 DUP (?), 0
.CODE

maximum MACRO num1, num2
    mov eax, num1
    mov ebx, num2
    cmp eax, ebx
    jge max_done
    mov eax, ebx
max_done:
ENDM

_MainProc PROC
    input prompt1, string, 40
    atod string
    mov number1, eax
    input prompt2, string, 40
    atod string
    mov number2, eax

    maximum number1, number2

    dtoa result, eax
    output outputLbl, result
    ret
_MainProc ENDP
END
