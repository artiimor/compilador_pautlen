segment .bss
_x resd 1
_y resd 1
segment .text

global main
extern scan_int ;etc
; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
main:

push dword _x
call scan_int
add esp, 4
push dword _x
push dword 1

pop dword edx
pop dword eax
mov dword eax, [eax]
add eax,edx
push dword eax


pop dword eax
mov dword [_y], eax



push dword _y
pop dword eax
mov dword eax, [eax]
push dword eax
call print_int
add esp, 4
call print_endofline
ret