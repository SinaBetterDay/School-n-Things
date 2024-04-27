.586
.MODEL FLAT

INCLUDE io.h           

.STACK 4096

.DATA
year DWORD ?
daysInFebruary DWORD ?

promptYear BYTE "Enter a year: ", 0
resultLbl BYTE "Number of days in February: ", 0
outputBuffer BYTE 11 DUP (?), 0

.CODE
_MainProc PROC
        input promptYear, outputBuffer, 11
        atod outputBuffer
        mov year, eax

        mov eax, year
        mov edx, 0
        mov ecx, 100
        div ecx

        cmp edx, 0
        jne @notDivisibleBy100

        mov eax, year
        mov edx, 0
        mov ecx, 400
        div ecx

        cmp edx, 0
        je @leapYear
        jmp @notLeapYear

    @notDivisibleBy100:
        mov eax, year
        mov edx, 0
        mov ecx, 4
        div ecx

        cmp edx, 0
        je @leapYear
        jmp @notLeapYear

    @leapYear:
        mov daysInFebruary, 29
        jmp @outputResult

    @notLeapYear:
        mov daysInFebruary, 28

    @outputResult:
        dtoa outputBuffer, daysInFebruary
        output resultLbl, outputBuffer

        mov eax, 0  
        ret
_MainProc ENDP
END
