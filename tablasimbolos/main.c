#include <stdio.h>
#include <string.h>
#include "tablasimbolos.h"

#define MAXLINE 50

typedef enum { GLO = 0, LOC = 1 } AMBITO;

int cuenta_palabras(char *line){
    int numpalabras, i;

    for(i=0, numpalabras=1; i<strlen(line); i++){
        if(line[i] == ' ')
            numpalabras++;
    }

    return numpalabras;
}

int main(int argc, char *argv[] ){
    FILE *entrada;
    FILE *salida;
    TABLA_HASH *global, *local;
    STATUS status;
    INFO_SIMBOLO *resultado;
    char line[MAXLINE];
    char nombre[MAXLINE];
    int numpalabras, i, valor;
    AMBITO ambito=0;

    if (argc!= 3){
        printf("Especifica fichero de entrada y de salida\n");
        return 0;
    }

    if ((entrada = fopen(argv[1],"r")) == NULL){
		printf("Error al abrir el fichero de entrada\n");
        return 1;
	}

	if ((salida = fopen(argv[2],"w")) == NULL){
		printf("Error al abrir el fichero de salida\n");
        return 1;
    }

    global = crear_tabla(20);
    local = crear_tabla(20);

    while(fgets(line, MAXLINE, entrada) != NULL){
        numpalabras = cuenta_palabras(line);
        line[(strlen(line)-1)] = '\0';
        sscanf(line, "%s %d", nombre, &valor);

        /* Una sola palabra significa que hay que buscar el simbolo */
        if(numpalabras == 1){
            if(ambito == LOC){
                /* Si no esta en el ambito local mirar tambien en el global*/
                resultado = buscar_simbolo(local, nombre);
                if(resultado == NULL){
                    resultado = buscar_simbolo(global, nombre);
                    if(resultado == NULL){
                        fprintf(salida, "%s -1\n", nombre);
                    }else{
                        fprintf(salida, "%s %d\n", nombre, resultado->adicional1);
                    }
                }else{
                    fprintf(salida, "%s %d\n", nombre, resultado->adicional1);
                }

            }else{
                resultado = buscar_simbolo(global, nombre);
                if(resultado == NULL){
                    fprintf(salida, "%s -1\n", nombre);
                }else{
                    fprintf(salida, "%s %d\n", nombre, resultado->adicional1);
                }
            }

        /* Puede ser un cierre, una funcion o una insercion*/
        }else if (numpalabras == 2){
            /* El valor es negativo, o es un cierre o una funcion */
            if(valor < 0){
                /* Cierre de funciones */
                if(valor == -999){
                    /* vaciar tabla local */
                    liberar_tabla(local);
                    local = crear_tabla(20);
                    fprintf(salida, "cierre\n");

                /* si no es un cierre es una funcion*/
                }else{
                    status = insertar_simbolo(global, nombre, FUNCION, ENTERO, ESCALAR, valor, 0);
                    if(status == OK){
                        fprintf(salida, "%s\n", nombre);
                    }else{
                        fprintf(salida, "-1 %s\n", nombre);
                    }

                    /* Crear tabla local y poner variable ambito a LOC*/
                    ambito = LOC;
                    local = crear_tabla(20);
                    insertar_simbolo(local, nombre, FUNCION, ENTERO, ESCALAR, valor, 0);
                }

            /* si el valor es positivo entonces es una insercion */
            }else{
                if(ambito == LOC){
                    status = insertar_simbolo(local, nombre, VARIABLE, ENTERO, ESCALAR, valor, 0);
                    if(status == OK){
                        fprintf(salida, "%s\n", nombre);
                    }else{
                        fprintf(salida, "-1 %s\n", nombre);
                    }
                }else{
                    status = insertar_simbolo(global, nombre, VARIABLE, ENTERO, ESCALAR, valor, 0);
                    if(status == OK){
                        fprintf(salida, "%s\n", nombre);
                    }else{
                        fprintf(salida, "-1 %s\n", nombre);
                    }
                }
            }

        }else{
            printf("Formato de la linea de entrada incorrecto.\n");
        }
    }
    return 0;
}
