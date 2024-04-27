.586
.MODEL FLAT

INCLUDE io.h    

.STACK 4096

.DATA
rentExpense DWORD ?
utilitiesExpense DWORD ?
phonesExpense DWORD ?
cableExpense DWORD ?
totalMonthlyExpense DWORD ?
totalAnnualExpense DWORD ?

promptRent BYTE "Enter monthly rent or mortgage payment: ", 0
promptUtilities BYTE "Enter monthly utilities cost: ", 0
promptPhones BYTE "Enter monthly phone expenses: ", 0
promptCable BYTE "Enter monthly cable expenses: ", 0
resultMonthlyLbl BYTE "Total monthly housing expenses: ", 0
resultAnnualLbl BYTE "Total annual housing expenses: ", 0
outputBuffer BYTE 11 DUP (?), 0

.CODE
_MainProc PROC
        ; Input monthly expenses
        input promptRent, outputBuffer, 11
        atod outputBuffer
        mov rentExpense, eax

        input promptUtilities, outputBuffer, 11
        atod outputBuffer
        mov utilitiesExpense, eax

        input promptPhones, outputBuffer, 11
        atod outputBuffer
        mov phonesExpense, eax

        input promptCable, outputBuffer, 11
        atod outputBuffer
        mov cableExpense, eax

        mov eax, rentExpense
        add eax, utilitiesExpense
        add eax, phonesExpense
        add eax, cableExpense
        mov totalMonthlyExpense, eax

        mov eax, totalMonthlyExpense
        imul eax, 12
        mov totalAnnualExpense, eax

        dtoa outputBuffer, totalMonthlyExpense
        output resultMonthlyLbl, outputBuffer

        dtoa outputBuffer, totalAnnualExpense
        output resultAnnualLbl, outputBuffer

        mov eax, 0 
        ret
_MainProc ENDP
END
