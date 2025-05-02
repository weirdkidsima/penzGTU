%include "io.inc"

section .data
    ; Эмуляция массива по адресу 0202h
    align 16
    array_start equ 0202h  ; Символическое обозначение адреса
    array db 1, 1, 1, 1, 0  ; Первые 5 элементов (4-й индекс = 0)
    times 37 db 1           ; Остальные 37 элементов (не нули)

section .text
global CMAIN
CMAIN:
    mov ebp, esp        ; Для корректной отладки

    ; Инициализация указателя
    mov esi, array      ; ESI указывает на начало массива

    ; Настройка цикла поиска
    mov ecx, 42         ; Всего 42 элемента
    xor ebx, ebx        ; Индекс начинается с 0

.search_loop:
    ; Проверка текущего элемента
    cmp byte [esi + ebx], 0
    je .found_zero      ; Если ноль - выход

    ; Переход к следующему
    inc ebx
    loop .search_loop

    ; Если нулей нет (в нашем случае сюда не попадем)
    mov ebx, -1
    jmp .end

.found_zero:
    ; EBX содержит индекс 4

.end:
    ; Для демонстрации выведем результат
    PRINT_DEC 4, ebx    ; Выведет "4"

    ; Завершение
    xor eax, eax
    ret