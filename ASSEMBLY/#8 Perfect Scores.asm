.586
.MODEL FLAT
INCLUDE io.h
.STACK 4096

.DATA
array WORD 10 DUP (?)
perfectScores DWORD 0
prompt BYTE "Enter a test score (0 to 100): ", 0
perfectPrompt BYTE "Perfect scores entered: ", 0
countString BYTE 11 DUP (?), 0

.CODE
_MainProc PROC
    lea ebx, array
    mov ecx, 10
    mov perfectScores, 0

inputLoop:
    cmp ecx, 0
    je exitLoop
    input prompt, countString, 11
    atod countString
    cmp eax, 100
    je perfectScoreFound

    mov [ebx], ax
    add ebx, 2
    loopCount: dec ecx
    jmp inputLoop

perfectScoreFound:
    inc perfectScores
    loopCountPerfect: dec ecx
    jmp inputLoop

exitLoop:
    dtoa countString, perfectScores
    output perfectPrompt, countString
    mov eax, 0
    ret

_MainProc ENDP
END
