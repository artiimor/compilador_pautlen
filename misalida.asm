;escribir_subseccion_data
segment .data
	zero_error db 'Error, has dividido por 0',0
	out_of_range_error db 'Error, al acceder al vector',0
;escribir_cabecera_bss
segment .bss
	__esp resd 1
;D:	main
;D:	{
;D:	array
;D:	int
;R10:	<tipo> ::= int
;D:	[
;D:	20
;D:	]
;R15:	<clase_vector>: array <tipo> [ <constante_entera> ];R7:	<clase> ::= <clase_vector>
;D:	vector1
;D:	;
;declarar_variable
	_vector1 resd 20
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;R18:	<identificadores> ::= <identificador> 
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	vector1
;R2:	<declaraciones> ::= <declaracion>
segment .text
	global main
	extern malloc, free
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
;R21:	<funciones> ::= 
main: 
	mov dword [__esp], esp


;D:	[
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	]
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	6
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 6
;R81:	<exp> ::= <constante> 
;D:	;
	push dword 0
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


	pop dword eax
	pop dword ebx
	mov [eax], ebx


;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 1
;R81:	<exp> ::= <constante> 
;D:	]
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	9
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 9
;R81:	<exp> ::= <constante> 
;D:	;
	push dword 1
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


	pop dword eax
	pop dword ebx
	mov [eax], ebx


;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	vector1
;D:	[
;D:	15
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 15
;R81:	<exp> ::= <constante> 
;D:	]
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	69
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 69
;R81:	<exp> ::= <constante> 
;D:	;
	push dword 15
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


	pop dword eax
	pop dword ebx
	mov [eax], ebx


;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	printf
;D:	vector1
;D:	[
;D:	0
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 0
;R81:	<exp> ::= <constante> 
;D:	]
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R85:	<exp> ::= <elemento_vector>
;D:	;
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	printf
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 1
;R81:	<exp> ::= <constante> 
;D:	]
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R85:	<exp> ::= <elemento_vector>
;D:	;
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline


;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	printf
;D:	vector1
;D:	[
;D:	15
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
	push dword 15
;R81:	<exp> ::= <constante> 
;D:	]
	pop dword eax
	cmp eax,0
	jl out_of_range_vector_fin
	cmp eax, 19
	jg out_of_range_vector_fin
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax


;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R85:	<exp> ::= <elemento_vector>
;D:	;
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
