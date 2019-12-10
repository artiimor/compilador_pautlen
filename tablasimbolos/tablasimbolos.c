#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablasimbolos.h"

/************* CONSTANTES **************/

/* posicion inicial de parametros de funcion (empiezan a contar en 0) */
#define POS_INI_PARAMS 0
/* posicion de inicio de variables locales de funcion (empieza a contar en 0) */
#define POS_INI_VARS_LOCALES 1

#define HASH_INI 5381
#define HASH_FACTOR 33

/***********************************/
/********** FUNCIONES *************/
/**********************************/
INFO_SIMBOLO* crear_info_simbolo(const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2){
    INFO_SIMBOLO *simb;

    simb = (INFO_SIMBOLO*)calloc(1, sizeof(INFO_SIMBOLO));
    if(simb == NULL){
        printf("Error al crear simbolo.\n");
        return NULL;
    }

    strcpy(simb->lexema, lexema);
    simb->categoria = categ;
    simb->tipo = tipo;
    simb->clase = clase;
    simb->adicional1 = adic1;
    simb->adicional2 = adic2;

    return simb;
}

/*******************************************/
void liberar_info_simbolo(INFO_SIMBOLO *is){
    free(is);

    return;
}

/*******************************************/
NODO_HASH* crear_nodo(INFO_SIMBOLO *is){
    NODO_HASH *nodo;

    nodo = (NODO_HASH*)calloc(1, sizeof(NODO_HASH));
    if(nodo == NULL){
        printf("Error al crear nuevo nodo.\n");
        return NULL;
    }

    nodo->info = is;
    nodo->siguiente = NULL;

    return nodo;
}

/*******************************************/
void liberar_nodo(NODO_HASH *nh){
    liberar_info_simbolo(nh->info);
    free(nh);

    return ;
}

/*******************************************/
TABLA_HASH *crear_tabla(int tam){
    TABLA_HASH *tabla;

    tabla = (TABLA_HASH*)calloc(1, sizeof(TABLA_HASH));
    if(tabla == NULL){
        printf("Error al crear la nueva tabla.\n");
        return NULL;
    }

    tabla->tam = tam;
    tabla->tabla = (NODO_HASH**)calloc(tam, sizeof(NODO_HASH*));

    return tabla;
}

/*******************************************/
void liberar_tabla(TABLA_HASH *th){
    free(th->tabla);
    free(th);

    return ;
}

/*******************************************/
unsigned long hash(const char *str){
    unsigned long hash;
    char *temp;

    if(str == NULL){
        printf("Error al calcular el hash.\n");
        return ERR;
    }

    strcpy(temp, str);
    hash = HASH_INI + HASH_FACTOR * temp[0];
    return hash;
}

/*******************************************/
INFO_SIMBOLO *buscar_simbolo(const TABLA_HASH *th, const char *lexema){
    int pos;
    NODO_HASH *temp;

    pos = hash(lexema) % th->tam;
    temp = th->tabla[pos];

    while(strcmp(temp->info->lexema, lexema)){
        temp = temp->siguiente;
    }

    return temp->info;
}

/*******************************************/
STATUS insertar_simbolo(TABLA_HASH *th, const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2){
    int pos;
    INFO_SIMBOLO *newInfo;
    NODO_HASH *newNodo;
    NODO_HASH *temp;

    if(th == NULL){
        printf("Error al insertar el simbolo.\n");
        return ERR;
    }

    newInfo = crear_info_simbolo(lexema,categ, tipo,clase, adic1, adic2);
    if(newInfo == NULL) return ERR;

    newNodo = crear_nodo(newInfo);
    if(newNodo == NULL) return ERR;

    pos = hash(lexema) % th->tam;

    if(th->tabla[pos] == NULL){
        th->tabla[pos] = newNodo;
    }else {
        temp = th->tabla[pos];
        while(temp->siguiente != NULL){
            temp = temp->siguiente;
        }
        temp->siguiente = newNodo;
    }
    return OK;
}

/*******************************************/
void borrar_simbolo(TABLA_HASH *th, const char *lexema){
    int pos, location, i;
    NODO_HASH *objetivo;
    NODO_HASH *temp;

    if(th == NULL || lexema == NULL){
        printf("Error al borrar simbolo\n");
        return ;
    }

    pos = hash(lexema) % th->tam;
    objetivo = th->tabla[pos];
    temp = th->tabla[pos];

    location = 0;
    while(strcmp(lexema, objetivo->info->lexema)){
        objetivo = objetivo->siguiente;
        location++;
    }
    for(i=0; i<location; i++){
        temp = temp->siguiente;
    }

    temp->siguiente = objetivo->siguiente;
    free(objetivo);

    return ;
}
