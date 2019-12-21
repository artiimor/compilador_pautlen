%{
	#include <stdlib.h>
	#include <stdio.h>
	extern int line;
	extern int col;
	extern FILE* fout;

	int pos_parametro_actual = 0; // Indica en que parametro estamos
	int num_parametros_actual = 0; // Contador del numero de parametros
	int num_variables_locales_actual = 0; // contador de varibles locales
	int pos_variable_local_actual = 0; // Indica en que variable local estamos
	int hayReturn = 0; // Indica si la funcion tiene return para cde
	int tipoReturn;
	int cuantos = 0;//esta variable es un contador para generar saltos unicos
	int num_parametros_llamada_actual = 0;


%}

%union
{
    tipo_atributos atributos
}

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
%token TOK_IDENTIFICADOR



/* CONSTANTES */
%token <atributos> TOK_CONSTANTE_ENTERA
%token TOK_CONSTANTE_ENTERA
%token TOK_FALSE
%token TOK_TRUE


/* ERRORES */
%token TOK_ERROR


%type <atributos> tipo
%type <atributos> comparacion
%type <atributos> constante
%type <atributos> clase_escalar
%type <atributos> clase_vector
%type <atributos> condicional
%type <atributos> if_exp_sentencias
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


%start programa
%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right MENOSU '!'

%%

programa: TOK_MAIN '{' declaraciones funciones sentencias '}' 
				{
				fprintf(fout, ";R1:\t<programa> ::=	main { <declaraciones> <funciones> <sentencias> }\n");
				}
		| TOK_MAIN '{' funciones sentencias '}' 
				{
				fprintf(fout, ";R1:\tprograma: main { <funciones> <sentencias> }\n");
				};


declaraciones: declaracion 
				{
					fprintf(fout, ";R2:\t<declaraciones> ::= <declaracion>\n");
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
					tipo_actual = INT;
					fprintf(fout, ";R10:\t<tipo> ::= int\n"); tipo_actual = INT;
				}
        | TOK_BOOLEAN 
				{
					tipo_actual = BOOLEAN;
					fprintf(fout, ";R11:\t<tipo> ::= boolean\n"); tipo_actual = BOOLEAN;
				};


/*
	REGLA 15
*/

clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']' 
				{
					
					if  (($4.valor_entero < 1 )
					{
						yyerror("El vector tiene un tamano menor que 1.\n");
						return -1;
					}
					else if($4.valor_entero > MAX_TAMANIO_VECTOR 1))
					{
						yyerror("El vector tiene un tamano mayor que el permitido.\n");
						return -1;
					}

					tamanio_vector_actual = $4.valor_entero;

					fprintf(fout, ";R15:\t<clase_vector>: array <tipo> [ <constante_entera> ]");
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
					if ($$.tipo != $3.tipo)
					{
						yyerror("ERROR, el tipo de la funcion no coincide\n");
						return -1;
					}
				  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.nombre
					if (buscar_simbolo(TGLOBAL, $3.nombre) != NULL)
					{
						yyerror("La funcion %s ha sido declarada dos veces.\n",$1.nombre);
						return -1;
					}
				  //CIERRE DE AMBITO, ETC
				  simbolo->num_parametros = num_parametros;
				};

fn_declaration : fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion 
				{
				  //COMPROBACIONES SEMANTICAS
				  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.nombre
					if (buscar_simbolo(TGLOBAL, $1.nombre) != NULL)
					{
						yyerror("La funcion %s ha sido declarada dos veces.\n",$1.nombre);
						return -1;
					}
				  simbolo->num_parametros = num_parametros;
				  strcpy($$.nombre, $1.nombre);
				  $$.tipo = $1.tipo;
				  //GENERACION DE CODIGO
				  declararFuncion(out, $1.nombre, num_variables_locales_actual);
				} 

fn_name : TOK_FUNCTION tipo TOK_IDENTIFICADOR 
				{
  				//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $3.nombre
					if (buscar_simbolo(TGLOBAL, $3.nombre) != NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",$3.nombre);
						return -1;
					}
  				simbolo.identificador = $3.nombre;
  				simbolo.cat_simbolo = FUNCION;
  				simbolo.tipo = tipo_actual;
  				$$.tipo = tipo_actual;
  				strcpy($$.nombre, $3.nombre);

  				//ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.nombre
					// TODO supongo adicionales como 0
					insertar_simbolo(TGLOBAL, $3.nombre, FUNCION, tipo_actual, clase_actual, 0, 0);

  				//RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
					num_variables_locales_actual = 0;
					pos_variable_local_actual = 1;
					num_parametros_actual = 0;
					pos_parametro_actual = 0;
				}

funcion: TOK_FUNCTION tipo identificador '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
				{
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

parametro_funcion: tipo idpf 
				{
				  //INCREMENTAR CONTADORES, POR EJEMPLO
				  num_parametros++;
				  pos_parametro_actual++;
				};


/*
	REGLA 27
*/

idpf : TOK_IDENTIFICADOR 
				{
					// COMPROBACIONES SEMANTICAS PARA $1.nombre
					if (buscar_simbolo(TGLOBAL, $1.nombre) != NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",$1.nombre);
						return -1;
					}
    			simbolo.identificador = $1.nombre;
    			simbolo.cat_simbolo = PARAMETRO;
    			simbolo.tipo = tipo_actual;
    			simbolo.categoria = ESCALAR;
    			simbolo.posicion = posicion_paremetro;
    			// DECLARAR SIMBOLO EN LA TABLA
					// Categoria = FUNCION. El tipo y clase los actuales
					insertar_simbolo(TGLOBAL, $1.nombre, FUNCION, tipo_actual, clase_actual, num_parametros_actual, pos_parametro_actual);
				};

parametro_funcion:	tipo idpf 
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

asignacion:	identificador '=' exp 
				{
					INFO_SIMBOLO simbolo = buscarSimbolo($1.lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						return -1;
					}
					// Comprobamos que no es funcion
					if (info->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] Asignacion a funcion.\n");
						return -1;
					}
					// Comprobamos que no es vector
					if (info->clase == VECTOR)
					{
						errorSemantico ("[ERROR] Asignacion a vector.\n");
						return -1;
					}

					if (simbolo->tipo != $3.tipo){
						errorSemantico("[ERROR]. Los tipos no coinciden");
					}

					// Si la variable esta en el ambito local
					if (ambito_local($1.lexema))
					{
						printf("PENDIENTE\n");
					}
					// Si la variable es global
					else
					{
						printf("PENDIENTE\n");
					}

					// Por ultimo, imprimimos
					fprintf(fout, ";R43:\t<asigancion> ::= <identificador> = <exp>\n");
				}
            | elemento_vector '=' exp 
				{
					fprintf(fout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
				};

elemento_vector: identificador '[' exp ']' 
				{
					INFO_SIMBOLO simbolo = buscarSimbolo($1.lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						return -1;
					}

					// Comprobamos que no es funcion
					if (info->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] Asignacion a funcion.\n");
						return -1;
					}

					//si el ambito es local y no es una variable global dentro de un ambito local
					if(ambito_local($1.lexema) == 1  && !(info->adicional2 == -1 && info->adicional1 == -1))
					{
			 			errorSemantico("No estan permitidas las variables locales de tipo no escalar.");
						return -1;
					}
					// Comprobamos que no es escalar
					if (info->clase == ESCALAR)
					{
						errorSemantico ("[ERROR] Asignacion a un elemento que no es vector.\n");
						return -1;
					}

					

					printf("PENDIENTE.\n");

					// SINTESIS
					strcpy($$.lexema, $1.lexema);
					$$.tipo = info->tipo;

					fprintf(fout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
				};

condicional: TOK_IF '(' exp ')' '{' sentencias '}' 
				{
					fprintf(fout, ";R50:\t<condicional> ::=	if ( <exp> ) { <sentencias> } \n");
				}
                | TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'
                {
					fprintf(fout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
				};

bucle: TOK_WHILE '(' exp ')' '{' sentencias '}' 
				{
					fprintf(fout, ";R52:\tbucle ::= while ( <exp> ) { <sentencias> }\n");
				};


/*
	Regla 54
*/
lectura: TOK_SCANF identificador 
				{

					INFO_SIMBOLO simbolo = buscarSimbolo($2.lexema);

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

					// Si la clase es un vector
					if (simbolo->clase == VECTOR)
					{
						errorSemantico("[ERROR] intento de scan a un vector.\n");
						return -1;
					}

					if (es_local($2.lexema) == 1)
					{
						printf("PENDIENTE\n");
					}

					else
					{
						printf("PENDIENTE\n");
					}


					fprintf(fout, ";R54:\t<lectura> ::= scanf <identificador> \n");
				};

escritura:	TOK_PRINTF exp 
				{
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
					sumar(output, $1.es_variable, $3.es_variable);

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = 1;

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
					restar(output, $1.es_variable, $3.es_variable);

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = 1;

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
					dividir(output, $1.es_variable, $3.es_variable);

					// SINTESIS
					$$.es_direccion = 0;
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
					multiplicar(output, $1.es_variable, $3.es_variable);

					// SINTESIS
					$$.es_direccion = 0;
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
					cambiar_signo(output, $2.es_variable);

					// SINTESIS
					$$.es_direccion = 0;
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
					y(output, $1.es_direccion, $3.es_direccion);

					// SINTESIS
					$$.es_direccion = 0;
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
					o(output, $1.es_direccion, $3.es_direccion);

					// SINTESIS
					$$.es_direccion = 0;
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
					no(output, $1.es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R79:\t<exp> ::= !<exp>\n");
				}
		| identificador 
				{
					INFO_SIMBOLO simbolo = buscarSimbolo($1.lexema);

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

					// Si la clase es un vector
					if (simbolo->clase == VECTOR)
					{
						errorSemantico("[ERROR] intento de scan a un vector.\n");
						return -1;
					}

					printf("PENDIENTE\n");

					fprintf(fout, ";R80:\t<exp> ::= <identificador>\n");
				}
		| constante 
				{
					//SINTESIS
					$$.tipo = $1.tipo;
					$$.es_direccion = $1.es_direccion;

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
					$$.tipo = $2.tipo;
					$$.es_direccion = $2.es_direccion;

					fprintf(fout, ";R83:\t<exp> ::= ( <comparacion> )\n");
				}
		| elemento_vector 
				{
					// SINTESIS 
					$$.tipo = $1.tipo;
					$$.es_direccion = $1.es_direccion;

					fprintf(fout, ";R85:\t<exp> ::= <elemento_vector>\n");
				}
		| identificador '(' lista_expresiones ')' 
				{
					printf("PENDIENTE\n");
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
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					igual(output, $1.es_direccion, $3.es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R93:\t<comparacion> ::= <exp> == <exp> \n");
				}
		| exp TOK_DISTINTO exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					distinto(output, $1.es_direccion, $3.es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R94:\t<comparacion> ::= <exp> != exp\n");
				}
				| exp TOK_MAYORIGUAL exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					mayor_igual(output, $1.es_direccion, $3.es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R95:\t<comparacion> ::= <exp> >= exp\n");
				}
				| exp TOK_MENORIGUAL exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					menor_igual(output, $1.es_direccion, $3.es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R96:\t<comparacion> ::= <exp> TOK_MENORIGUAL exp\n");
				}
				| exp '>' exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					mayor(output, $1.es_direccion, $3.es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R97:\t<comparacion> ::= exp > <exp>\n");
				}
				| exp '<' exp 
				{
					// El tipo tiene que ser entero.
					if($1.tipo != ENTERO || $3.tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					menor(output, $1.es_direccion, $3.es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					$$.es_direccion = 0;
					$$.tipo = BOOLEANO;

					fprintf(fout, ";R98:\t<comparacion> ::= exp < <exp>\n");
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
					escribir_operando(output, "1", 0);

					fprintf(fout, ";R102:\t<constante_logica> ::= true \n");
				}
        | TOK_FALSE 
				{
					// SINTESIS
					$$.tipo = BOOLEANO;
					$$.es_direccion = FALSE;
					$$.valor_entero = TRUE;

					// GENERACION
					escribir_operando(output, "0", 0);

					fprintf(fout, ";R103:\t<constante_logica> ::= false \n");
				};

constante_entera: numero 
				{
					// SINTESIS
					$$.tipo = ENTERO;
					$$.es_direccion = FALSE;
					$$.valor_entero = $1.valor_entero;

					// GENERACION
					escribir_operando(output, $1.lexema, 0);//en $1.lexema guardo la string del valor_entero 
					
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


void errorSemantico (char *msg)
{
  fprintf(stderr,"****Error semantico en lin %d: %s\n", yylineno, msg);
}