.586
.MODEL FLAT

INCLUDE io.h          

.STACK 4096

.DATA
studentName BYTE 40 DUP (?)
degreeName BYTE 40 DUP (?)
creditsTaken DWORD ?
creditsRequired DWORD ?
remainingCredits DWORD ?

promptStudentName BYTE "Enter student name: ", 0
promptDegreeName BYTE "Enter degree name: ", 0
promptCreditsTaken BYTE "Enter number of credits taken so far: ", 0
promptCreditsRequired BYTE "Enter total number of credits required: ", 0
resultLbl BYTE "Remaining credits needed to graduate: ", 0
outputBuffer BYTE 11 DUP (?), 0

.CODE
_MainProc PROC
        input promptStudentName, studentName, 40
        input promptDegreeName, degreeName, 40
        input promptCreditsTaken, outputBuffer, 11
        atod outputBuffer
        mov creditsTaken, eax

        input promptCreditsRequired, outputBuffer, 11
        atod outputBuffer
        mov creditsRequired, eax

        mov eax, creditsRequired
        sub eax, creditsTaken
        mov remainingCredits, eax

        dtoa outputBuffer, remainingCredits
        output resultLbl, outputBuffer

        mov eax, 0  ; exit with return code 0
        ret
_MainProc ENDP
END 
