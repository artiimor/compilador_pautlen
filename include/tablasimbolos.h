#ifndef TABLASIMBOLOS
#define TABLASIMBOLOS

/************* DECLARACIONES DE TIPOS **************/
/* Retorno de funcion error/ok */
typedef enum { ERR = 0, OK = 1 } STATUS;

/*Categoría de un símbolo: variable, parametro de funcion o funcion*/
typedef enum { VARIABLE, PARAMETRO, FUNCION } CATEGORIA;

/* Tipo de un dato: solo se trabajara con enteros y booleanos */
typedef enum { ENTERO, BOOLEANO } TIPO;

/* Clase de un simbolo: pueden ser variables atomicas (escalares) o listas/arrays
 (vectores) */
typedef enum { ESCALAR, VECTOR } CLASE;

/* Informacion de un simbolo */
typedef struct info_simbolo{
    char *lexema;           /* identificador */
    CATEGORIA categoria;    /* categoria */
    TIPO tipo;              /* tipo */
    CLASE clase;            /* clase */
    /* valor si escalar, longitud si vector, numero de parametros si funcion */
    int adicional1;
    /* posicion en llamada a funcion si parametro, posicion de declaracion si
        variable local de funcion, numero de variables locales si funcion */
    int adicional2;
} INFO_SIMBOLO;

/* Nodo de la tabla hash */
typedef struct nodo_hash {
    /* Informacion del simbolo */
    INFO_SIMBOLO *info;
    /* puntero al siguiente nodo (encadenamiento si colision en misma celda) */
    struct nodo_hash *siguiente;
} NODO_HASH;

/* Tabla hash */
typedef struct tabla_hash {
    int tam;            /* tamanio de la tabla hash */
    NODO_HASH **tabla;  /* tabla en si (array de tam punteros a nodo) */
} TABLA_HASH;
/*********** FUNCIONES *************/
INFO_SIMBOLO *crear_info_simbolo(const char *lexema, CATEGORIA categ, TIPO tipo,
CLASE clase, int adic1, int adic2);

void liberar_info_simbolo(INFO_SIMBOLO *is);

NODO_HASH *crear_nodo(INFO_SIMBOLO *is);

void liberar_nodo(NODO_HASH *nh);

TABLA_HASH *crear_tabla(int tam);

void liberar_tabla(TABLA_HASH *th);

unsigned long hash(const char *str);

INFO_SIMBOLO *buscar_simbolo(const TABLA_HASH *th, const char *lexema);

STATUS insertar_simbolo(TABLA_HASH *th, const char *lexema, CATEGORIA categ,
     TIPO tipo, CLASE clase, int adic1, int adic2);

void borrar_simbolo(TABLA_HASH *th, const char *lexema);

#endif
