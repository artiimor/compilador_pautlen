%{
	#include <stdlib.h>
	#include <stdio.h>
	extern int line;
	extern int col;
	extern FILE* fout;

%}

%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN

%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR

/* IDENTIFICADOR */
%token TOK_IDENTIFICADOR


/* CONSTANTES */
%token TOK_CONSTANTE_ENTERA
%token TOK_FALSE
%token TOK_TRUE


/* ERRORES */
%token TOK_ERROR

%start programa
%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right MENOSU '!'

%%

programa: 	TOK_MAIN '{' declaraciones funciones sentencias '}' {fprintf(fout, ";R:\tprograma: 	TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
			| TOK_MAIN '{' funciones sentencias '}' {fprintf(fout, ";R:\tprograma: 	TOK_MAIN '{' funciones sentencias '}'\n");};

declaraciones: declaracion {fprintf(fout, ";R:\tdeclaraciones:	declaracion\n");}
				| declaracion declaraciones	{fprintf(fout, ";R:\tdeclaraciones: declaracion declaraciones\n");};

declaracion: clase identificadores ';' {fprintf(fout, ";R:\tdeclaracion: clase identificadores ';'\n");};

clase: clase_escalar {fprintf(fout, ";R:\tclase: clase_escalar\n");}
		| clase_vector {fprintf(fout, ";R:\tclase: clase_vector\n");}

clase_escalar: tipo {fprintf(fout, ";R:\tclase_escalar: tipo\n");};

tipo: TOK_INT {fprintf(fout, ";R:\ttipo: TOK_INT\n");}
        | TOK_BOOLEAN {fprintf(fout, ";R:\ttipo: TOK_BOOLEAN\n");};

clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']' {fprintf(fout, ";R:\tclase_vector: TOK_ARRAY TIPO '[' TOK_CONSTANTE_ENTERA ']'");};

identificadores: TOK_IDENTIFICADOR {fprintf(fout, ";R:\tidentificadores: 	TOK_IDENTIFICADOR \n");}
					| TOK_IDENTIFICADOR ',' identificadores	{fprintf(fout, ";R:\tidentificadores:	TOK_IDENTIFICADOR ',' identificadores\n");};

funciones: /*vacio*/ {fprintf(fout, ";R:\tfunciones: \n");}
            | funcion funciones {fprintf(fout, ";R:\tfunciones: funcion funciones\n");};

funcion: TOK_FUNCTION tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
				{fprintf(fout, ";R:\tfuncion: 	TOK_FUNCTION tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");};

tipo_retorno:	tipo {fprintf(fout, ";R:\ttipo_retorno:	tipo\n");};

parametros_funcion:	parametro_funcion resto_parametros_funcion {fprintf(fout, ";R:\tparametros_funcion:	parametro_funcion resto_parametros_funcion\n");}
                       | /*vacio*/ {fprintf(fout, ";R:\tparametros_funcion: \n");};

resto_parametros_funcion:	';' parametro_funcion resto_parametros_funcion {fprintf(fout, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion \n");}
							| /*vacio*/ {fprintf(fout, ";R:\tresto_parametros_funcion: \n");};

parametro_funcion:	tipo TOK_IDENTIFICADOR {fprintf(fout, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");};

declaraciones_funcion:	 declaraciones {fprintf(fout, ";R:\tdeclaraciones_funcion: declaraciones\n");}
						| /*vacio*/ {fprintf(fout, ";R:\tdeclaraciones_funcion:\n");};

sentencias:	sentencia {fprintf(fout, ";R:\tsentencias:	sentencia \n");}
            | sentencia sentencias {fprintf(fout, ";R:\tsentencias:	sentencia sentencias \n");};

sentencia:	sentencia_simple ';' {fprintf(fout, ";R:\tsentencia: sentencia_simple ';' \n");}
			| bloque {fprintf(fout, ";R:\tsentencia: bloque\n");};

sentencia_simple: asignacion {fprintf(fout, ";R:\tsentencia_simple: asignacion\n");}
					| lectura {fprintf(fout, ";R:\tsentencia_simple: lectura\n");}
					| escritura {fprintf(fout, ";R:\tsentencia_simple: escritura\n");}
					| retorno_funcion {fprintf(fout, ";R:\tsentencia_simple: retorno_funcion\n");}
					|  TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(fout, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')' \n");};

bloque:	condicional {fprintf(fout, ";R:\tbloque: condicional\n");}
            | bucle {fprintf(fout, ";R:\tbloque: bucle\n");};

asignacion:	TOK_IDENTIFICADOR '=' exp {fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");}
            | elemento_vector '=' exp {fprintf(fout, ";R:\tasignacion: elemento_vector '=' exp\n");};

elemento_vector: TOK_IDENTIFICADOR '[' exp ']' {fprintf(fout, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");};

condicional: TOK_IF '(' exp ')' '{' sentencias '}' {fprintf(fout, ";R:\tcondicional:	TOK_IF '(' exp ')' '{' sentencias '}' \n");}
                | TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'
                    {fprintf(fout, ";R:\tcondicional:	TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");};

bucle: TOK_WHILE '(' exp ')' '{' sentencias '}' {fprintf(fout, ";R:\tbucle: 	TOK_WHILE '(' exp ')' '{' sentencias '}'\n");};

lectura: TOK_SCANF TOK_IDENTIFICADOR {fprintf(fout, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR \n");};

escritura:	TOK_PRINTF exp {fprintf(fout, ";R:\tescritura: TOK_PRINTF exp\n");};


retorno_funcion: TOK_RETURN exp	{fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN exp\n");};

exp: exp '+' exp {fprintf(fout, ";R:\texp:	exp '+' exp\n");}
		| exp '-' exp {fprintf(fout, ";R:\texp:	exp '-' exp\n");}
		| exp '/' exp {fprintf(fout, ";R:\texp:	exp '/' exp\n");}
		| exp '*' exp {fprintf(fout, ";R:\texp:	exp '*' exp\n");}
		| '-' exp %prec MENOSU {fprintf(fout, ";R:\texp:	'-' exp\n");}
		| exp TOK_AND exp {fprintf(fout, ";R:\texp:	exp TOK_AND exp\n");}
		| exp TOK_OR exp {fprintf(fout, ";R:\texp:	exp TOK_OR exp\n");}
		| '!' exp {fprintf(fout, ";R:\texp:	'!' exp\n");}
		| TOK_IDENTIFICADOR {fprintf(fout, ";R:\texp:	TOK_IDENTIFICADOR\n");}
		| constante {fprintf(fout, ";R:\texp:	constante \n");}
		| '(' exp ')' {fprintf(fout, ";R:\texp:	'(' exp ')'\n");}
		| '(' comparacion ')' {fprintf(fout, ";R:\texp:	'(' comparacion ')'\n");}
		| elemento_vector {fprintf(fout, ";R:\texp:	elemento_vector\n");}
		| TOK_IDENTIFICADOR '(' lista_expresiones ')' {fprintf(fout, ";R:\texp:	TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");};

lista_expresiones: exp resto_lista_expresiones {fprintf(fout, ";R:\tlista_expresiones: exp resto_lista_expresiones \n");}
					| /*vacio*/ {fprintf(fout, ";R:\tlista_expresiones:	\n");};

resto_lista_expresiones: ',' exp resto_lista_expresiones {fprintf(fout, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones \n");}
							| /*vacio*/ {fprintf(fout, ";R:\tresto_lista_expresiones: \n");};

comparacion: exp TOK_IGUAL exp {fprintf(fout, ";R:\tcomparacion: exp TOK_IGUAL exp \n");}
				| exp TOK_DISTINTO exp {fprintf(fout, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");}
				| exp TOK_MAYORIGUAL exp {fprintf(fout, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");}
				| exp TOK_MENORIGUAL exp {fprintf(fout, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");}
				| exp '>' exp {fprintf(fout, ";R:\tcomparacion:	exp '>' exp\n");}
				| exp '<' exp {fprintf(fout, ";R:\tcomparacion:	exp '<' exp\n");};

constante: constante_logica {fprintf(fout, ";R:\tconstante: constante_logica \n");}
			| TOK_CONSTANTE_ENTERA {fprintf(fout, ";R:\tconstante: TOK_CONSTANTE_ENTERA \n");};

constante_logica: TOK_TRUE {fprintf(fout, ";R:\tconstante_logica: TOK_TRUE \n");}
                    | TOK_FALSE {fprintf(fout, ";R:\tconstante_logica: TOK_FALSE \n");};

%%

void yyerror(char* s) {
	fprintf(stdout,"ERROR SINTACTICO:%d:%d\n", line, col);
}
