; Example assembly language program to calculate car's gas mileage
; Author: Your Name
; Date:   2/2024

.586
.MODEL FLAT

INCLUDE io.h            ; header file for input/output

.STACK 4096

.DATA
gallonsHold DWORD ?
milesDriven DWORD ?
mileageResult DWORD ?

promptGallonsHold BYTE "Enter number of gallons of gas the car can hold: ", 0
promptMilesDriven BYTE "Enter number of miles the car can be driven on a full tank: ", 0
resultLbl BYTE "The car's gas mileage is: ", 0
outputBuffer BYTE 11 DUP (?), 0

.CODE
_MainProc PROC
        ; Input information
        input promptGallonsHold, outputBuffer, 11
        atod outputBuffer
        mov gallonsHold, eax

        input promptMilesDriven, outputBuffer, 11
        atod outputBuffer
        mov milesDriven, eax

        ; Calculate gas mileage
        mov eax, milesDriven
        xor edx, edx  ; Clear edx to avoid integer overflow
        div gallonsHold
        mov mileageResult, eax

        ; Output result
        dtoa outputBuffer, mileageResult
        output resultLbl, outputBuffer

        mov eax, 0  ; exit with return code 0
        ret
_MainProc ENDP
END                             ; end of source code
