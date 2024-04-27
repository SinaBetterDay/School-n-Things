.586
.MODEL FLAT
INCLUDE io.h
.STACK 4096
.DATA
number1 DWORD ?
number2 DWORD ?
operator BYTE ?
prompt1 BYTE "Enter number 1: ", 0
prompt2 BYTE "Enter number 2: ", 0
promptOperator BYTE "Enter operator (+, -, *, /) or 'e' to exit: ", 0
string BYTE 40 DUP (?)
outputLbl BYTE "The result is: ", 0
result BYTE 11 DUP (?), 0
.CODE

Addition PROC
    mov eax, number1
    add eax, number2
    ret
Addition ENDP

Subtraction PROC
    mov eax, number1
    sub eax, number2
    ret
Subtraction ENDP

Multiplication PROC
    mov eax, number1
    imul eax, number2
    ret
Multiplication ENDP

Division PROC
    mov eax, number1
    cdq
    idiv number2
    ret
Division ENDP

_MainProc PROC
    jmp Start

OperationLoop:
    input promptOperator, operator, 2

    cmp operator, 'e'
    je Exit

    input prompt1, string, 40
    atod string
    mov number1, eax

    input prompt2, string, 40
    atod string
    mov number2, eax

    cmp operator, '+'
    je AddOperation
    cmp operator, '-'
    je SubtractOperation
    cmp operator, '*'
    je MultiplyOperation
    cmp operator, '/'
    je DivideOperation

    jmp OperationLoop

AddOperation:
    call Addition
    jmp OutputResult

SubtractOperation:
    call Subtraction
    jmp OutputResult

MultiplyOperation:
    call Multiplication
    jmp OutputResult

DivideOperation:
    call Division
    jmp OutputResult

OutputResult:
    dtoa result, eax
    output outputLbl, result
    jmp OperationLoop

Start:
    jmp OperationLoop

Exit:
    mov eax, 0
    ret
_MainProc ENDP

END
