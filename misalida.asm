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
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;D:	y
;D:	,
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;D:	resultado
;D:	;
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;R18:	<identificadores> ::= <identificador> 
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
segment .text
	global main
	extern malloc, free
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
;D:	int
;R10:	<tipo> ::= int
;D:	suma
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	;
;D:	int
;R10:	<tipo> ::= int
;D:	num2
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion> 
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	return
;R29:	<declaraciones_funcion> ::=
;D:	num1
;D:	+
;R80:	<exp> ::= <identificador>
;D:	num2
;D:	;
;R80:	<exp> ::= <identificador>
	pop dword edx
	pop dword eax
	add eax, edx
	push dword eax


;R72:	<exp> ::= <exp> + <exp>
;R61:	<retorno_funcion> ::= return<exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	}
;R30:	<sentencias> ::= <sentencia> 
	pop dword eax
	mov dword esp, ebp
	pop dword ebp
	ret


;R22:	<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }
;D:	x
;R21:	<funciones> ::= 
;R20:	<funciones>: <funcion> <funciones>
;D:	=
;D:	1
	push dword 1
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
;R81:	<exp> ::= <constante> 
;D:	;
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	y
;D:	=
;D:	3
	push dword 3
;R104:	<constante_entera> ::= <numero> 
;R100:	<constante> ::= <constante_entera> 
;R81:	<exp> ::= <constante> 
;D:	;
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ; 
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;D:	x
;D:	,
