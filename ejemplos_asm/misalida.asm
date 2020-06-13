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
;D:	,
;declarar_variable
	_y resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;D:	z
;D:	;
;declarar_variable
	_z resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;R18:	<identificadores> ::= <identificador> 
;R19:	<identificadores> ::= <identificador> , <identificadores>
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
;D:	scanf
;D:	y
	push dword _y
	call scan_int
	add esp, 4


;R54:	<lectura> ::= scanf <identificador> 
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	scanf
;D:	z
	push dword _z
	call scan_int
	add esp, 4


;R54:	<lectura> ::= scanf <identificador> 
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	if
;D:	(
;D:	(
;D:	x
;D:	==
	push dword _x
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	je near _igual_0
	push dword 0
	jmp near _fin_igual_0
_igual_0:
	push dword 1
_fin_igual_0:


;R93:	<comparacion> ::= <exp> == <exp> 
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	==
	push dword _y
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	je near _igual_1
	push dword 0
	jmp near _fin_igual_1
_igual_1:
	push dword 1
_fin_igual_1:


;R93:	<comparacion> ::= <exp> == <exp> 
;R83:	<exp> ::= ( <comparacion> )
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax


;R77:	<exp> ::= <exp> && <exp>
;D:	&&
;D:	(
;D:	z
;D:	==
	push dword _z
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	je near _igual_2
	push dword 0
	jmp near _fin_igual_2
_igual_2:
	push dword 1
_fin_igual_2:


;R93:	<comparacion> ::= <exp> == <exp> 
;R83:	<exp> ::= ( <comparacion> )
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax


;R77:	<exp> ::= <exp> && <exp>
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_3
;D:	{
;D:	printf
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	else
	jmp _else_3
_if_fin_3:
;D:	{
;D:	if
;D:	(
;D:	(
;D:	x
;D:	>
	push dword _x
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg near _mayor_3
	push dword 0
	jmp near _fin_mayor_3
_mayor_3:
	push dword 1
_fin_mayor_3:


;R98:	<comparacion> ::= exp > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>
	push dword _y
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg near _mayor_4
	push dword 0
	jmp near _fin_mayor_4
_mayor_4:
	push dword 1
_fin_mayor_4:


;R98:	<comparacion> ::= exp > <exp>
;R83:	<exp> ::= ( <comparacion> )
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax


;R77:	<exp> ::= <exp> && <exp>
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_5
;D:	{
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
	push dword _z
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg near _mayor_5
	push dword 0
	jmp near _fin_mayor_5
_mayor_5:
	push dword 1
_fin_mayor_5:


;R98:	<comparacion> ::= exp > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_6
;D:	{
;D:	printf
;D:	1
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 1
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	else
	jmp _else_6
_if_fin_6:
;D:	{
;D:	printf
;D:	5
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 5
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
_else_6:
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	if
_if_fin_5:
;R50:	<condicional> ::=	if ( <exp> ) { <sentencias> } 
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
	push dword _x
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jl _menor_6
	push 0
	jmp _fin_menor_6
_menor_6:
	push 1
_fin_menor_6:


;R97:	<comparacion> ::= exp < <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>
	push dword _y
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg near _mayor_7
	push dword 0
	jmp near _fin_mayor_7
_mayor_7:
	push dword 1
_fin_mayor_7:


;R98:	<comparacion> ::= exp > <exp>
;R83:	<exp> ::= ( <comparacion> )
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax


;R77:	<exp> ::= <exp> && <exp>
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_8
;D:	{
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
	push dword _z
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg near _mayor_8
	push dword 0
	jmp near _fin_mayor_8
_mayor_8:
	push dword 1
_fin_mayor_8:


;R98:	<comparacion> ::= exp > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_9
;D:	{
;D:	printf
;D:	2
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 2
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	else
	jmp _else_9
_if_fin_9:
;D:	{
;D:	printf
;D:	6
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 6
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
_else_9:
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	if
_if_fin_8:
;R50:	<condicional> ::=	if ( <exp> ) { <sentencias> } 
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
	push dword _x
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jl _menor_9
	push 0
	jmp _fin_menor_9
_menor_9:
	push 1
_fin_menor_9:


;R97:	<comparacion> ::= exp < <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<
	push dword _y
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jl _menor_10
	push 0
	jmp _fin_menor_10
_menor_10:
	push 1
_fin_menor_10:


;R97:	<comparacion> ::= exp < <exp>
;R83:	<exp> ::= ( <comparacion> )
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax


;R77:	<exp> ::= <exp> && <exp>
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_11
;D:	{
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
	push dword _z
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg near _mayor_11
	push dword 0
	jmp near _fin_mayor_11
_mayor_11:
	push dword 1
_fin_mayor_11:


;R98:	<comparacion> ::= exp > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_12
;D:	{
;D:	printf
;D:	3
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 3
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	else
	jmp _else_12
_if_fin_12:
;D:	{
;D:	printf
;D:	7
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 7
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
_else_12:
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	if
_if_fin_11:
;R50:	<condicional> ::=	if ( <exp> ) { <sentencias> } 
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	>
	push dword _x
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg near _mayor_12
	push dword 0
	jmp near _fin_mayor_12
_mayor_12:
	push dword 1
_fin_mayor_12:


;R98:	<comparacion> ::= exp > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<
	push dword _y
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jl _menor_13
	push 0
	jmp _fin_menor_13
_menor_13:
	push 1
_fin_menor_13:


;R97:	<comparacion> ::= exp < <exp>
;R83:	<exp> ::= ( <comparacion> )
	pop dword edx
	pop dword eax
	and eax, edx
	push dword eax


;R77:	<exp> ::= <exp> && <exp>
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_14
;D:	{
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
	push dword _z
;R80:	<exp> ::= <identificador>
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	)
	pop dword edx
	pop dword eax
	mov dword eax, [eax]
	cmp eax, edx
	jg near _mayor_14
	push dword 0
	jmp near _fin_mayor_14
_mayor_14:
	push dword 1
_fin_mayor_14:


;R98:	<comparacion> ::= exp > <exp>
;R83:	<exp> ::= ( <comparacion> )
;D:	)
	pop eax
	cmp eax, 0
	je _if_fin_15
;D:	{
;D:	printf
;D:	4
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 4
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	else
	jmp _else_15
_if_fin_15:
;D:	{
;D:	printf
;D:	8
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 8
;R81:	<exp> ::= <constante> 
;D:	;
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
_else_15:
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;D:	}
_if_fin_14:
;R50:	<condicional> ::=	if ( <exp> ) { <sentencias> } 
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;R30:	<sentencias> ::= <sentencia> 
;R31:	<sentencias> ::= <sentencia> <sentencias> 
;R31:	<sentencias> ::= <sentencia> <sentencias> 
;R31:	<sentencias> ::= <sentencia> <sentencias> 
_else_3:
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia> 
;R31:	<sentencias> ::= <sentencia> <sentencias> 
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
