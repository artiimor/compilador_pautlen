#ifndef _ALFA_H
#define _ALFA_H


typedef struct{
	// Guarda el lexema de los identificadores
	char *lexema;
	// guarda el tipo de una expresion (entero o logico)
	int tipo;
	// guarda el valor de una constante entera
	int valor_entero;
	// Indica si un simbolo es una direccion de memoria o un valor cte
	int es_direccion;
	// Para los condicionales y sentencias iterativas
	int etiqueta;
} tipo_atributos;

#endif

