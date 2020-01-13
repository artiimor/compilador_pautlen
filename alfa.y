%{
	#include <stdlib.h>
	#include <stdio.h>

	#include "alfa.h"
	#include "tablahash.h"
	#include "generacion.h"
	#include "tablasimbolos.h"

	#include "y.tab.h"
	
	extern int line;
	extern int col;
	extern FILE* fout;

	int pos_parametro_actual = 0; /* Indica en que parametro estamos */
	int num_parametros_actual = 0; /* Contador del numero de parametros */
	int num_variables_locales_actual = 0; /* contador de varibles locales */
	int pos_variable_local_actual = 0; /* Indica en que variable local estamos */
	int hayReturn = 0; /* Indica si la funcion tiene return para cde */
	int tiporeturn;
	int cuantos = 0;/* esta variable es un contador para generar saltos unicos */
 	int num_parametros_llamada_actual = 0;
	int clase_actual;
	int tipo_actual;
	int tamanio_vector_actual;
	int etiqueta = 0;
	char* pos_vector_actual;


%}

%union
	{
	tipo_atributos atributos;
	}
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEANO
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN

/* IDENTIFICADOR */
%token <atributos> TOK_IDENTIFICADOR 

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



/* CONSTANTES */
%token <atributos> TOK_CONSTANTE_ENTERA
%token TOK_FALSE
%token TOK_TRUE


/* ERRORES */
%token TOK_ERROR

/* OTROS */
%token fn_complete_name
%token tipo_retorno


%type <atributos> tipo
%type <atributos> comparacion
%type <atributos> constante
%type <atributos> clase_escalar
%type <atributos> clase_vector
%type <atributos> condicional
%type <atributos> if_else_exp
%type <atributos> if_exp
%type <atributos> exp
%type <atributos> asignacion
%type <atributos> elemento_vector
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> parametros_funcion
%type <atributos> funcion
%type <atributos> resto_parametros_funcion
%type <atributos> lista_expresiones
%type <atributos> resto_lista_expresiones
%type <atributos> fn_name
%type <atributos> idpf
%type <atributos> fn_complete_name
%type <atributos> tipo_retorno
%type <atributos> sentencia_simple
%type <atributos> retorno_funcion
%type <atributos> fn_declaration
%type <atributos> bucle
%type <atributos> while
%type <atributos> while_exp

/* PRUEBA MAL */



%start programa
%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right MENOSU '!'

%%

programa: inicio TOK_MAIN '{' declaraciones funciones escritura_main sentencias '}' escribir_fin
				{
					
					fprintf(fout, ";R1:\t<programa> ::=	main { <declaraciones> <funciones> <sentencias> }\n");
				}
		| inicio TOK_MAIN '{' funciones escritura_main sentencias '}' 
				{
					
				fprintf(fout, ";R1:\tprograma: main { <funciones> <sentencias> }\n");
				};


inicio:	{	crearAmbitoGlobal();
					escribir_subseccion_data(fout);
					escribir_cabecera_bss(fout); 
					pos_parametro_actual = 0;
					num_parametros_actual = 0;
					num_variables_locales_actual = 0;
					pos_variable_local_actual = 0;
					num_parametros_llamada_actual = 0;};
					

escritura_main: {	escribir_inicio_main(fout);  };

escribir_fin: {	escribir_fin(fout);  };


declaraciones: declaracion 
				{
					
					fprintf(fout, ";R2:\t<declaraciones> ::= <declaracion>\n");
					escribir_segmento_codigo(fout);
				}
		| declaracion declaraciones	
				{
					fprintf(fout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
				};

declaracion: clase identificadores ';' 
				{
					fprintf(fout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
				};

/*
	REGLAS 5 y 7
*/

clase: clase_escalar 
				{
					clase_actual = ESCALAR;
					
					fprintf(fout, ";R5:\t<clase> ::= <clase_escalar>\n"); clase_actual = ESCALAR;
				}
		| clase_vector 
				{
					clase_actual = VECTOR;
					fprintf(fout, ";R7:\t<clase> ::= <clase_vector>\n"); clase_actual = VECTOR;
				};

clase_escalar: tipo 
				{
					fprintf(fout, ";R9:\t<clase_escalar> ::= <tipo>\n");
				};

/*
	REGLAS 10 y 11
*/
tipo: TOK_INT 
				{
					tipo_actual = ENTERO;
					fprintf(fout, ";R10:\t<tipo> ::= int\n");
				}
        | TOK_BOOLEANO 
				{
					tipo_actual = BOOLEANO;
					fprintf(fout, ";R11:\t<tipo> ::= BOOLEANO\n"); tipo_actual = BOOLEANO;
				};


/*
	REGLA 15
*/

clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']' 
				{
					
					if  ($4.valor_entero < 1 )
					{
						yyerror("El vector tiene un tamano menor que 1.\n");
						return -1;
					}
					else if($4.valor_entero > MAX_TAMANIO_VECTOR)
					{
						yyerror("El vector tiene un tamano mayor que el permitido.\n");
						return -1;
					}

					tamanio_vector_actual = $4.valor_entero;

					fprintf(fout, ";R15:\t<clase_vector>: array <tipo> [ <constante_entera> ]");
				};



elemento_vector: TOK_IDENTIFICADOR '[' exp ']' 
{
						INFO_SIMBOLO *simbolo = buscarSimbolo($1.lexema);
					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada. $1.lexema\n");
						return -1;
					}

					// Comprobamos que no es funcion
					if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] Asignacion a funcion.\n");
						return -1;
					}

					//si el ambito es local y no es una variable global dentro de un ambito local
					if(es_local($1.lexema) == 1  && !(simbolo->adicional2 == -1 && simbolo->adicional1 == -1))
					{
			 			errorSemantico("No estan permitidas las variables locales de tipo no escalar.");
						return -1;
					}
					// Comprobamos que no es escalar
					if (simbolo->clase == ESCALAR)
					{
						errorSemantico ("[ERROR] Asignacion a un elemento que no es vector.\n");
						return -1;
					}

					// SINTESIS
					$$.valor_entero = atoi($3.lexema);
					$$.tipo = simbolo->tipo;
					$$.es_direccion = TRUE;

					escribir_elemento_vector(fout, $1.lexema, simbolo->adicional1, $3.es_direccion);

					fprintf(fout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");

};

identificadores: identificador 
				{
					fprintf(fout, ";R18:\t<identificadores> ::= <identificador> \n");
				}
		| identificador ',' identificadores	
				{
					fprintf(fout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
				};

funciones: /*vacio*/ 
				{
					fprintf(fout, ";R21:\t<funciones> ::= \n");
				}
        | funcion funciones 
				{
					fprintf(fout, ";R20:\t<funciones>: <funcion> <funciones>\n");
				};


/*
	COSAS PARA FUNCIONES
*/
/*
	REGLA 22
*/

funcion: fn_declaration sentencias TOK_LLAVEDERECHA 
				{
				  //COMPROBACIONES SEMANTICAS
				  //ERROR SI LA FUNCION NO TIENE SENTENCIA DE RETORNO
					if (hayReturn == 0)
					{
						yyerror("ERROR, la funcion no tiene sentencia de retorno\n");
						return -1;
					}
					if ($$.tipo != $1.tipo)
					{
						yyerror("ERROR, el tipo de la funcion no coincide\n");
						return -1;
					}
				  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema
					if (buscarSimbolo($1.lexema) != NULL)
					{
						yyerror("La funcion %s ha sido declarada dos veces.\n",$1.lexema);
						return -1;
					}
				  //CIERRE DE AMBITO, ETC
				};

fn_declaration : fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion 
				{
				  //COMPROBACIONES SEMANTICAS
				  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema
					if (buscarSimbolo($1.lexema) != NULL)
					{
						errorSemantico("La funcion ha sido declarada dos veces.\n",$1.lexema);
						return -1;
					}
				  // simbolo->num_parametros = num_parametros_actual;
				  strcpy($$.lexema, $1.lexema);
				  $$.tipo = $1.tipo;
				  //GENERACION DE CODIGO
				  
				} 

fn_name : TOK_FUNCTION tipo TOK_IDENTIFICADOR 
				{
  				//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $3.lexema
					if (buscarSimbolo($3.lexema) != NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",$3.lexema);
						return -1;
					}

  				$$.tipo = tipo_actual;
  				strcpy($$.lexema, $3.lexema);

  				//ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.lexema
					// TODO supongo adicionales como 0
					crearAmbitoLocal($3.lexema, crear_info_simbolo($3.lexema, FUNCION, tipo_actual, clase_actual, 0, 0));

  				//RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
					num_variables_locales_actual = 0;
					pos_variable_local_actual = 1;
					num_parametros_actual = 0;
					pos_parametro_actual = 0;

				}

funcion: TOK_FUNCTION tipo TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
				{
					retornarFuncion(fout, tiporeturn); 
					tiporeturn=0; 
					fprintf(fout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
				};

parametros_funcion:	parametro_funcion resto_parametros_funcion 
				{
					fprintf(fout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
				}
        | /*vacio*/ 
				{
					fprintf(fout, ";R24:\t<parametros_funcion> ::= \n");
				};

resto_parametros_funcion:	';' parametro_funcion resto_parametros_funcion 
				{
					fprintf(fout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion> \n");
				}
		| /*vacio*/ 
				{
					fprintf(fout, ";R26:\t<resto_parametros_funcion> ::= \n");
				};


/*
	REGLA 27
*/

idpf : TOK_IDENTIFICADOR 
				{
					errorSemantico($1.lexema);
					// COMPROBACIONES SEMANTICAS PARA $1.lexema
					if (buscarSimbolo($1.lexema) != NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",$1.lexema);
						return -1;
					}
    			// DECLARAR SIMBOLO EN LA TABLA
					// Categoria = FUNCION. El tipo y clase los actuales
					insertarSimbolo(crear_info_simbolo($1.lexema, FUNCION, tipo_actual, clase_actual, num_parametros_actual, num_variables_locales_actual));
					if (buscarSimbolo($1.lexema) == NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",$1.lexema);
						return -1;
					}
				};

parametro_funcion: tipo idpf 
				{
					
					// Incrementamos contadores
					num_parametros_actual++;
					pos_parametro_actual++;

					// Imprimimos la regla
					fprintf(fout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
				};

declaraciones_funcion:	 declaraciones 
				{
					
					fprintf(fout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
				}
		| /*vacio*/ 
				{
					fprintf(fout, ";R29:\t<declaraciones_funcion> ::=\n");
				};

sentencias:	sentencia 
				{
					fprintf(fout, ";R30:\t<sentencias> ::= <sentencia> \n");
				}
        | sentencia sentencias 
				{
					fprintf(fout, ";R31:\t<sentencias> ::= <sentencia> <sentencias> \n");
				};

sentencia:	sentencia_simple ';' 
				{
					fprintf(fout, ";R32:\t<sentencia> ::= <sentencia_simple> ; \n");
				}
		| bloque 
				{
					fprintf(fout, ";R33:\t<sentencia> ::= <bloque>\n");
				};

sentencia_simple: asignacion 
				{
					fprintf(fout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
				}
		| lectura 
				{
					fprintf(fout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
				}
		| escritura 
				{
					fprintf(fout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
				}
		| retorno_funcion 
				{
					fprintf(fout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
				};

bloque:	condicional 
				{
					fprintf(fout, ";R40:\t<bloque> ::= <condicional>\n");
				}
            | bucle 
				{
					fprintf(fout, ";R41:\t<bloque> ::= <bucle>\n");
				};

/*
	REGLAS 43 y 44
*/

asignacion:	TOK_IDENTIFICADOR '=' exp 
				{
					INFO_SIMBOLO *simbolo = buscarSimbolo($1.lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] La variable no ha sido declarada.\n");
						return -1;
					}
					// Comprobamos que no es funcion
					/*if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] Asignacion a funcion.\n");
						return -1;
					}
					// Comprobamos que no es vector
					if (simbolo->clase == VECTOR)
					{
						errorSemantico ("[ERROR] Asignacion a vector.\n");
						return -1;
					} 

					if (simbolo->tipo != $3.tipo){
						errorSemantico("[ERROR]. Los tipos no coinciden");
					} */

					// Si la variable esta en el ambito local
					if (es_local($1.lexema))
					{
					}
					// Si la variable es global
					else
					{
						INFO_SIMBOLO* info = buscarSimbolo($1.lexema);
					if(info == NULL)
					{
						errorSemantico("Acceso a variable no declarada\n");
						return -1;
					} else if(info->categoria == FUNCION)
					{
						errorSemantico("asignacion a funcion\n");
						return -1;
					} else if(info->clase == VECTOR)
					{
						errorSemantico("asignacion a vector\n");
						return -1;
					} else if(info->tipo != $3.tipo)
					{
						errorSemantico("error en los tipos.\n");
						return -1;
					}

					// DECLARAMOS
					asignar(fout, $1.lexema, tipo_actual);

					// Por ultimo, imprimimos
					fprintf(fout, ";R43:\t<asigancion> ::= <identificador> = <exp>\n");
				}
				}
            | elemento_vector '=' exp 
				{
					//COMPROBACIONES SEMANTICAS (VER SI $1.tipo == $3.tipo)
					if ($1.tipo != $3.tipo)
					{
						errorSemantico("ERROR EN LA IGUALDAD DE LOS TIPOS\n");
					}
					INFO_SIMBOLO *simbolo = buscarSimbolo($1.lexema);
  				//$1.valor ES EL INDICE DEL VECTOR EN EL QUE QUEREMOS ASIGNAR exp
					
					char *aux;
					aux = (char*)malloc(1);
					aux[0] = (char)($1.valor_entero + 48);
					escribir_operando(fout, aux, 0);
  				escribir_elemento_vector(fout, $1.lexema, simbolo->adicional1, $3.es_direccion);
  				asignarDestinoEnPila(fout, $3.es_direccion);
					fprintf(fout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");

};
  				
				


/*
	CONDICIONALES
*/
condicional: if_exp ')' '{' sentencias '}' {
    
		// GENERACION
		ifthen_fin(fout, $1.etiqueta); 
		
		fprintf(fout, ";R50:\t<condicional> ::=	if ( <exp> ) { <sentencias> } \n");
		}
| if_else_exp TOK_ELSE '{' sentencias '}' {

		// GENERACION
    	ifthenelse_fin(fout, $1.etiqueta);

		fprintf(fout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
};

if_exp: TOK_IF '(' exp {
  //COMPROBACIONES SEMANTICAS
	if($3.tipo != BOOLEANO){
			errorSemantico("Tipo del condicional no booleano\n");
			return -1;
	}
		
  	//SINTESIS
	$$.etiqueta = cuantos;

	//GENERACION
  ifthen_inicio(fout, $3.es_direccion, cuantos);
};

if_else_exp: if_exp ')' '{'  sentencias '}' {

	// SINTESIS
  	$$.etiqueta = $1.etiqueta;

	// GENERACION
  	ifthenelse_fin_then(fout, $1.etiqueta);
}


/*
	PARA BUCLES
*/

bucle: while_exp sentencias '}' {
	
  while_fin(fout, $1.etiqueta);
	fprintf(fout, ";R52:\tbucle ::= while ( <exp> ) { <sentencias> }\n");
	};

while: TOK_WHILE '(' {
	$$.etiqueta = etiqueta++;
  while_inicio(fout, $$.etiqueta);
};

while_exp: while exp ')' '{' {
	//COMPROBACIONES SEMANTICAS (VER SI EL TIPO DE exp ES BOOLEAN)
	if ($2.tipo != BOOLEANO)
	{
		errorSemantico("BUCLE sin expresion booleana\n");
		return -1;
	}
	$$.etiqueta = $1.etiqueta;
  while_exp_pila(fout, $2.es_direccion, $$.etiqueta);
};


/*
	Regla 54
*/
lectura: TOK_SCANF TOK_IDENTIFICADOR 
				{

					INFO_SIMBOLO *simbolo = buscarSimbolo($2.lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						return -1;
					}

					// Si la categoria es una funcion
					if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] intento de scan a una funcion\n");
						return -1;
					}

					// Si la clase no es escalar
					if (simbolo->clase != ESCALAR)
					{
						errorSemantico("[ERROR] intento de scan a un no escalar.\n");
						return -1;
					}

					if (es_local($2.lexema) == 1)
					{
					}

					// VAMOS A ESCANEAR UNA VARIABLE GLOBAL
					else
					{
						// GENERACION CODIGO
						leer(fout, $2.lexema, tipo_actual);
					}

					$2.es_direccion = FALSE;
					fprintf(fout, ";R54:\t<lectura> ::= scanf <identificador> \n");
				};

escritura:	TOK_PRINTF exp 
				{
					// GENERACION
					escribir(fout, $2.es_direccion, $2.tipo);

					fprintf(fout, ";R56:\t<escritura> ::= printf <exp>\n");
				};


retorno_funcion: TOK_RETURN exp	
				{
					fprintf(fout, ";R61:\t<retorno_funcion> ::= return<exp>\n");
				};

/*
	OPERACIONES
*/
exp: exp '+' exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					sumar(fout, $1.es_direccion, $3.es_direccion);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = ENTERO;

					fprintf(fout, ";R72:\t<exp> ::= <exp> + <exp>\n");
				}
		| exp '-' exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					restar(fout, $1.es_direccion, $3.es_direccion);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = ENTERO;

					fprintf(fout, ";R73:\t<exp> ::=  <exp> - <exp>\n");
				}
		| exp '/' exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					dividir(fout, $1.es_direccion, $3.es_direccion);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = ENTERO;

					fprintf(fout, ";R74:\t<exp> ::=  <exp> / <exp>\n");
				}
		| exp '*' exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					multiplicar(fout, $1.es_direccion, $3.es_direccion);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = ENTERO;

					fprintf(fout, ";R75:\t<exp> ::= <exp> * <exp>\n");
				}
		| '-' exp %prec MENOSU 
				{
					// El tipo tiene que ser entero.
					if($2.tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					cambiar_signo(fout, $2.es_direccion);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = ENTERO;

					fprintf(fout, ";R76:\t<exp> ::= -<exp>\n");
				}
		| exp TOK_AND exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != BOOLEANO || $3.tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					y(fout, $1.es_direccion, $3.es_direccion);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R77:\t<exp> ::= <exp> && <exp>\n");
				}
		| exp TOK_OR exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != BOOLEANO || $3.tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					o(fout, $1.es_direccion, $3.es_direccion);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R78:\t<exp> ::= <exp> || <exp>\n");
				}
		| '!' exp 
				{
					// El tipo tiene que ser entero.
					if($2.tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					no(fout, $2.es_direccion, cuantos);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R79:\t<exp> ::= !<exp>\n");
				}
		| TOK_IDENTIFICADOR 
				{
					
					INFO_SIMBOLO *simbolo = buscarSimbolo($1.lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == 0)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						errorSemantico($1.lexema);
						return -1;
					}
					
					// Si la categoria es una funcion
					if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] intento de scan a una funcion\n");
					}

					$$.tipo = simbolo->tipo;
					$$.es_direccion = TRUE;

					
					// Si la clase es un vector
					if (simbolo->clase == VECTOR)
					{
						errorSemantico("[ERROR] intento de scan a un vector.\n");
						return -1;
					}

					escribir_operando(fout, $1.lexema, !$1.es_direccion);
					fprintf(fout, ";R80:\t<exp> ::= <identificador>\n");
				}
		| constante 
				{
					//SINTESIS
					$$.tipo = $1.tipo;
					$$.es_direccion = $1.es_direccion;
					// GENERACION
					escribir_operando(fout, $1.lexema, $1.es_direccion);

					fprintf(fout, ";R81:\t<exp> ::= <constante> \n");
				}
		| '(' exp ')' 
				{
					// SINTESIS
					$$.tipo = $2.tipo;
					$$.es_direccion = $2.es_direccion;

					fprintf(fout, ";R82:\t<exp> ::= ( <exp> )\n");
				}
		| '(' comparacion ')' 
				{
					// SINTESIS
					$$.tipo = BOOLEANO;
					$$.es_direccion = $2.es_direccion;

					fprintf(fout, ";R83:\t<exp> ::= ( <comparacion> )\n");
				}
		| elemento_vector 
				{
					// SINTESIS 
					$$.tipo = $1.tipo;

					fprintf(fout, ";R85:\t<exp> ::= <elemento_vector>\n");
				}
		| identificador '(' lista_expresiones ')' 
				{
					fprintf(fout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
				};

lista_expresiones: exp resto_lista_expresiones 
				{
					 // SINTESIS
					num_parametros_llamada_actual++;

					fprintf(fout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones> \n");
				}
		| /*vacio*/ 
				{
					fprintf(fout, ";R90:\t<lista_expresiones> ::= \n");
				};

resto_lista_expresiones: ',' exp resto_lista_expresiones 
				{
					// SINTESIS
					num_parametros_llamada_actual++;

					fprintf(fout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones> \n");
				}
		| /*vacio*/ 
				{
					fprintf(fout, ";R92:\t<resto_lista_expresiones> ::=  \n");
				};

/*
	COMPARACIONES
*/
comparacion: exp TOK_IGUAL exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					igual(fout, $1.es_direccion, $3.es_direccion, cuantos++);
					

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R93:\t<comparacion> ::= <exp> == <exp> \n");
				}
		| exp TOK_DISTINTO exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					distinto(fout, $1.es_direccion, $3.es_direccion, cuantos++);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R94:\t<comparacion> ::= <exp> != exp\n");
				}
				| exp TOK_MAYORIGUAL exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					mayor_igual(fout, $1.es_direccion, $3.es_direccion, cuantos++);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R95:\t<comparacion> ::= <exp> >= exp\n");
				}
				| exp TOK_MENORIGUAL exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					menor_igual(fout, $1.es_direccion, $3.es_direccion, cuantos++);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R96:\t<comparacion> ::= <exp> TOK_MENORIGUAL exp\n");
				}
				| exp '>' exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					mayor(fout, $1.es_direccion, $3.es_direccion, cuantos++);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R98:\t<comparacion> ::= exp > <exp>\n");
				}
				| exp '<' exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					menor(fout, $1.es_direccion, $3.es_direccion, cuantos++);

					// SINTESIS
					$$.es_direccion = FALSE;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R97:\t<comparacion> ::= exp < <exp>\n");
				};

constante: constante_logica 
				{
					// SINTESIS
					$$.tipo = $1.tipo;
					$$.es_direccion = $1.es_direccion;

					fprintf(fout, ";R99:\t<constante> ::= <constante_logica> \n");
				}
		| constante_entera 
				{
					// SINTESIS
					$$.tipo = $1.tipo;
					$$.es_direccion = $1.es_direccion;

					fprintf(fout, ";R100:\t<constante> ::= <constante_entera> \n");
				};

constante_logica: TOK_TRUE 
				{
					// SINTESIS
					$$.tipo = BOOLEANO;
					$$.es_direccion = FALSE;
					$$.valor_entero = TRUE;

					// GENERACION
					escribir_operando(fout, "1", 0);

					fprintf(fout, ";R102:\t<constante_logica> ::= true \n");
				}
        | TOK_FALSE 
				{
					// SINTESIS
					$$.tipo = BOOLEANO;
					$$.es_direccion = FALSE;
					$$.valor_entero = TRUE;

					// GENERACION
					escribir_operando(fout, "0", 0);

					fprintf(fout, ";R103:\t<constante_logica> ::= false \n");
				};

constante_entera: TOK_CONSTANTE_ENTERA 
				{
					
					// SINTESIS
					$$.tipo = ENTERO;
					$$.es_direccion = FALSE;
					$$.valor_entero = $1.valor_entero;

					
					
					fprintf(fout, ";R104:\t<constante_entera> ::= <numero> \n");
				};

numero: digito 
				{
					fprintf(fout, ";R105:\t<numero> ::= <digito> \n");
				}
        | numero digito 
				{
					fprintf(fout, ";R106:\t<numero> ::= <numero><digito> \n");
				};

cola_identificador: alfanumerico 
				{
					
					fprintf(fout, ";R110:\t<cola_identificador> ::= <alfanumerico> \n");
				}
        | alfanumerico cola_identificador 
				{
					fprintf(fout, ";R111:\t<cola_identificador> ::= <alfanumerico><cola_identificador> \n");
				};

alfanumerico: letra 
				{
					fprintf(fout, ";R112:\t<alfanumerico> ::= <letra> \n");
				}
    	| digito 
				{
					fprintf(fout, ";R113:\t<alfanumerico> ::= <digito> \n");
				};

letra: TOK_IDENTIFICADOR 
				{
					fprintf(fout, ";R114:\t<letra> ::= a|b|...|z|A|B|...|Z \n");
				};

digito: TOK_CONSTANTE_ENTERA 
				{
					
					fprintf(fout, ";R115:\t<digito> ::= 0|1|2|3|4|5|6|7|8|9 \n");
				};

identificador: TOK_IDENTIFICADOR 
				{

					if (existe_local() == 0)
					{	
						// NO HAY AMBITO LOCAL
						if (clase_actual == ESCALAR){
							pos_variable_local_actual++;
							num_variables_locales_actual++;

							// ANADIMOS A LA TABLA HASH
							insertarSimbolo(crear_info_simbolo($1.lexema, VARIABLE, tipo_actual, clase_actual, 0, 0));

							//GENERAMOS EL CODIGO
							declarar_variable(fout, $1.lexema, $1.tipo, clase_actual);
						}
						else if (clase_actual == VECTOR){
							pos_variable_local_actual++;
							num_variables_locales_actual++;

							// ANADIMOS A LA TABLA HASH
							insertarSimbolo(crear_info_simbolo($1.lexema, VARIABLE, tipo_actual, clase_actual, tamanio_vector_actual, 0));

							//GENERAMOS EL CODIGO
							declarar_variable(fout, $1.lexema, $1.tipo, tamanio_vector_actual);
						}
						else {
							errorSemantico("ERROR. Variable de tipo raro");
							return -1;
						}
					}

					fprintf(fout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR \n");
				}
        | letra cola_identificador 
				{
					fprintf(fout, ";R109:\t<identificador> ::= <letra><cola_identificador> \n");
				};

%%

void yyerror(char* s) {
	fprintf(stdout,"****Error sintactico en [lin %d, col %d]\n", line, col);
}

void errorSemantico (char *s)
{
  fprintf(stderr,"****Error semantico en lin %d: %s\n", line, s);
}
