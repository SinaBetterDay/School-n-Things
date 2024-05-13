.586
.MODEL FLAT

INCLUDE io.h           

.STACK 4096

.DATA
number DWORD ?
array DWORD 10 DUP(?)    ; Array of 10 numbers
count DWORD ?            ; Variable to store the count of occurrences

promptNumber BYTE "Enter a number: ", 0
promptArray BYTE "Enter 10 numbers separated by spaces: ", 0
outputBuffer BYTE 11 DUP (?), 0
resultLbl BYTE "Number of occurrences: ", 0

.CODE
_MainProc PROC
        ; Input number
        input promptNumber, outputBuffer, 11
        atod outputBuffer
        mov number, eax

        ; Input array
        mov ecx, LENGTHOF array
        mov esi, OFFSET array
    input_loop:
        input promptArray, outputBuffer, 11
        atod outputBuffer
        mov [esi], eax
        add esi, 4
        loop input_loop

        ; Count occurrences
        mov ecx, LENGTHOF array
        mov eax, 0           ; Reset count
        mov edi, 0           ; Index of current element in array
    count_loop:
        mov edx, [array + edi * 4]
        cmp edx, number
        je @found
        inc edi
        loop count_loop
        jmp @done

    @found:
        inc eax            ; Increment count
        inc edi            ; Move to next element
        loop count_loop    ; Continue looping

    @done:
        mov count, eax

        ; Output result
        dtoa outputBuffer, count
        output resultLbl, outputBuffer

        mov eax, 0  
        ret
_MainProc ENDP
END
