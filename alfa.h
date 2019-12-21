#ifndef ALFA_H
#define ALFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum { FALSE = 0, TRUE = 1 } BOOL;


#define MAX_TAMANIO_VECTOR 64

typedef struct {
	char *lexema;
	int tipo;
	int valor_entero;
	int es_direccion;
	int etiqueta;
}tipo_atributos;

#endif

