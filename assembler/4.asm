%include "io.inc"

section .data
    result dw 0     ; Переменная для результата (если нужно)

section .text
global CMAIN
CMAIN:
    mov ebp, esp    ; Для корректной отладки

    ; Инициализация
    mov AX, 5       ; AX = 5 (исходное значение)
    mov DX, 3       ; DX = 3

    ; Сохраняем исходный AX, потому что XOR его изменит
    mov CX, AX      ; CX = исходный AX (5)

    ; Вычисляем AX XOR DX
    xor AX, DX      ; AX = 5 XOR 3 = 6

    ; Находим MAX(AX, 8)
    cmp AX, 8
    jg .keep_AX     ; Если AX > 8, оставляем AX
    mov AX, 8       ; Иначе AX = 8

.keep_AX:
    ; Прибавляем исходный AX (который сохранили в CX)
    add AX, CX      ; AX = MAX(AX XOR DX, 8) + исходный_AX

    ; Сохраняем результат (если нужно)
    mov [result], AX

    ; Завершение программы

    ret