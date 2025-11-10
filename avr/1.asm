.include "m48def.inc"

; Настройка портов
SBI DDRB, 1
SBI DDRB, 2
SBI DDRB, 3

; Главный цикл
Main:
; Led1
SBI PORTB, 1
CBI PORTB, 2
CBI PORTB, 3
RCALL Delay_3s74
CBI PORTB, 1

; Led2
SBI PORTB, 2
CBI PORTB, 1
CBI PORTB, 3
RCALL Delay_3s74
CBI PORTB, 2

; Led3
SBI PORTB, 3
CBI PORTB, 1
CBI PORTB, 2
RCALL Delay_3s74
CBI PORTB, 3

RJMP Main

; Подпрограмма точной задержки 3.74с
Delay_3s74:
    LDI R20, 174       ; внешний цикл
L1: LDI R19, 227       ; средний цикл
L2: LDI R18, 252       ; внутренний цикл
L3:
    NOP
    NOP
    NOP                ; 3 nop для  подстройки
    DEC R18
    BRNE L3
    DEC R19
    BRNE L2
    DEC R20
    BRNE L1

    ; 5 nop для выравнивания до 59 840 000 тактов
    NOP
    NOP
    NOP
    NOP
    NOP

RET
