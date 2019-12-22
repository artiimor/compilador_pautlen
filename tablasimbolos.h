#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#include "tablahash.h"

/**************** CONSTANTES *************************************************/
#define TH_SIZE 128 /*tamano estandat*/

/**************** DECLARACIONES DE TIPOS *************************************/
/* Tabla de simbolos */
typedef struct
{
    TABLA_HASH *contexto_global;
    TABLA_HASH *contexto_local;
} TablaSimbolos;


/**************** FUNCIONES **************************************************/
void crearAmbitoGlobal();
void cerrarAmbitos();
STATUS insertarSimbolo(const char *lexema, INFO_SIMBOLO *info);
INFO_SIMBOLO *buscarSimbolo(const char *lexema);
STATUS crearAmbitoLocal(const char *lexema, INFO_SIMBOLO *info);
STATUS cerrarAmbitoLocal();
int es_local(const char *lexema);

#endif