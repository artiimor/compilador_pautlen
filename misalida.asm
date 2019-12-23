;escribir_subseccion_data
segment .data
	zero_error db 'Error, has dividido por 0',0
	out_of_range_error db 'Error, al acceder al vector',0
;escribir_cabecera_bss
segment .bss
	__esp resd 1
;D:	main
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
;D:	,
;declarar_variable
	_x resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;D:	y
;D:	;
;declarar_variable
	_y resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;R18:	<identificadores> ::= <identificador> 
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
;R2:	<declaraciones> ::= <declaracion>
segment .text
	global main
	extern malloc, free
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
;R21:	<funciones> ::= 
main: 
	mov dword [__esp], esp


;D:	x
	push dword _x
	call scan_int
	add esp, 4


;R54:	<lectura> ::= scanf <identificador> 
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	y
;D:	=
;D:	x
;D:	+
	push dword _x
;R80:	<exp> ::= <identificador>
;D:	1
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 1
;R81:	<exp> ::= <constante> 
;D:	;
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	add eax, edx
	push dword eax


;R72:	<exp> ::= <exp> + <exp>
	pop dword eax
	mov dword [_y], eax
;R43:	<asigancion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	printf
;D:	y
;D:	;
	push dword _y
;R80:	<exp> ::= <identificador>
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;R31:	<sentencias> ::= <sentencia> <sentencias> 
;R31:	<sentencias> ::= <sentencia> <sentencias> 
fin:
	mov esp, [__esp]
	ret


div_zero_fin:
	push dword zero_error
	call print_string
	add esp, 4
	call print_endofline
	 mov eax, 1
	mov ebx, 0
	int 80h


out_of_range_vector_fin:
	push dword out_of_range_error
	call print_string
	add esp, 4
	call print_endofline
	 mov eax, 1
	mov ebx, 0
	int 80h


;R1:	<programa> ::=	main { <declaraciones> <funciones> <sentencias> }
