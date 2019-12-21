segment .data
	zero_error db 'Error, has dividido por 0',0
	out_of_range_error db 'Error, al acceder al vector',0


segment .bss
__esp    resd 1
;D:	main
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
;D:	,
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;D:	resultado
;D:	;
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;R18:	<identificadores> ::= <identificador> 
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
;D:	int
;R10:	<tipo> ::= int
;D:	fibonacci
;D:	(
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	res1
;D:	,
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;D:	res2
;D:	;
;R108:	<identificador> ::= TOK_IDENTIFICADOR 
;R18:	<identificadores> ::= <identificador> 
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	if
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
;D:	(
;D:	(
;D:	num1
;D:	==
