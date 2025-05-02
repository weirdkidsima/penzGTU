; Выполнил студент гр. 22ИП2б Ступников Максим
; В - 24
; работа в регистре 32 разряда
%include "io.inc" ; Ввод и вывод
section .text
global main ; начало программы
main:
mov ebp, esp; for correct debugging
mov ax,1020h ; Инициализация EAX значением 1020h (4128 в десятичной системе)
mov ecx,00FFh ; Инициализация ECX значением 00FFh (255 в десятичной системе)
add eax,ecx ; Сложение EAX и ECX. Результат остаётся в EAX
mov[0006h],ecx ; Запись ECX в память по адресу 0006h
ret ; выход
