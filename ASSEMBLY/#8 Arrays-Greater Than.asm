.586
.MODEL FLAT
INCLUDE io.h
.STACK 4096
.DATA
array DWORD 100 DUP (?)
prompt1 BYTE "Enter the length of the array: ", 0
prompt2 BYTE "Enter the value of n: ", 0
prompt3 BYTE "Enter the numbers in the array: ", 0
resultPrompt BYTE "Numbers greater than n in the array: ", 0
string BYTE 40 DUP (?)
count DWORD ?
n DWORD ?
result BYTE 11 DUP (?), 0

.CODE
_MainProc PROC
input prompt1, string, 40
atod string
mov count, eax

input prompt2, string, 40
atod string
mov n, eax

mov esi, 0
input_loop:
    cmp esi, count
    jge end_input_loop

    input prompt3, string, 40
    atod string
    mov [array + esi * 4], eax
    inc esi
    jmp input_loop

end_input_loop:

mov ecx, count
mov esi, 0
loop_start:
    cmp esi, ecx
    jge loop_end

    mov eax, [array + esi * 4]
    cmp eax, n
    jle skip_print

    dtoa result, eax
    output resultPrompt, result

    skip_print:
    inc esi
    jmp loop_start

loop_end:
    mov eax, 0
    ret
_MainProc ENDP
END
