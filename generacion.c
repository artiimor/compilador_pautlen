#include <stdio.h>
#include "generacion.h"

extern FILE* fout;

/**************************************************************************/
/**********************NOTAS SOBRE LA IMPLEMENTACION:**********************/
/**************************************************************************/
/*1.- A la hora de escribir siempre se comienza a escribir en una nueva
      linea y se termina por \n*/
/*2.- A la hora de escribir, cada linea la escribiremos en un fprintf
      distinto para facilitar entender este codigo*/
/*3.- Cuando terminemos una función, siempre se pondrán dos saltos de linea
      para facilitar la lectura del programa*/
/*4.- Cuando se haya escrito el main, todas las funciones comenzarán con
      \t para facilitar la lectura del código*/
/*5.- Para las operaciones aritméticas el segundo operando se guardará en
      edx y el primero en eax (se extraen de la pila al reves)*/
/*6.- En la operacion de division sera ebx en lugar de edx para poder
      guardar el resto sin problema*/
/*7.- Las comparaciones sacan de la pila las dos partes a comparar y 
      devuelven usando la pila si la comparacion ha ido bien o no*/
/*8.- Los if else utilizan los valores de las comparaciones devueltos
      en la pila. Por lo que se hace pop y el if se ejecuta si hay un
      1. Si hay un 0 se ejecuta el else*/

/**************************************************************************/
/**************************COMIENZO DEL PROGRAMA:**************************/
/**************************************************************************/

void escribir_cabecera_bss(FILE *fpasm)
{
    if (fpasm == NULL)
        return;
    
    fprintf(fpasm, ";escribir_cabecera_bss\n");
    fprintf(fpasm, "segment .bss\n\t__esp resd 1\n");
}

void escribir_subseccion_data(FILE *fpasm)
{
    if (fpasm == NULL)
        return;
    fprintf(fpasm, ";escribir_subseccion_data\n");
    fprintf(fpasm, "segment .data\n");
    fprintf(fpasm, "\tzero_error db 'Error, has dividido por 0',0\n");
    fprintf(fpasm, "\tout_of_range_error db 'Error, al acceder al vector',0\n");
}

void declarar_variable(FILE *fpasm, char *nombre, int tipo, int tamano)
{
    /*Control de errores*/
    if (fpasm == NULL || nombre == NULL || tipo < ENTERO || tipo > BOOLEANO)
        return;

    /*TODO lo mismo el tipo importa*/
    fprintf(fpasm, ";declarar_variable\n");
    

    fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);

    /*Aqui no terminamos con dos saltos de linea por si se declaran varias variables seguidas*/
}

void escribir_segmento_codigo(FILE *fpasm)
{
    fprintf(fpasm, "segment .text\n");
    fprintf(fpasm, "\tglobal main\n");
    /*TODO comprobar que no hay mas funciones*/
	fprintf(fpasm, "\textern malloc, free\n");
	fprintf(fpasm, "\textern scan_int, print_int, scan_boolean, print_boolean\n");
	fprintf(fpasm, "\textern print_endofline, print_blank, print_string\n");
}

void escribir_inicio_main(FILE *fpasm)
{
    fprintf(fpasm, "main: \n");
    fprintf(fpasm, "\tmov dword [__esp], esp\n");
    fprintf(fpasm, "\n\n");
}

void escribir_fin(FILE *fpasm)
{
    fprintf(fpasm, "fin:\n");
    fprintf(fpasm, "\tmov dword esp, [__esp]\n");
    fprintf(fpasm, "\tret\n");
    fprintf(fpasm, "\n\n");

    /*Tambien hay que poner los finales donde ocurre algun error*/
    /*caso division por cero:*/
    fprintf(fpasm, "div_zero_fin:\n");
    fprintf(fpasm, "\tpush dword zero_error\n");
    fprintf(fpasm, "\tcall print_string\n");
    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tcall print_endofline\n");
    /*Por algun motivo ret me da segmentation fault*/
    fprintf(fpasm, "\t mov eax, 1\n");
    fprintf(fpasm, "\tmov ebx, 0\n");
    fprintf(fpasm, "\tint 80h\n");
    fprintf(fpasm, "\n\n");

    /*caso acceso fuera de un vector*/
    fprintf(fpasm, "out_of_range_vector_fin:\n");
    fprintf(fpasm, "\tpush dword out_of_range_error\n");
    fprintf(fpasm, "\tcall print_string\n");
    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tcall print_endofline\n");
    /*Por algun motivo ret me da segmentation fault*/
    fprintf(fpasm, "\t mov eax, 1\n");
    fprintf(fpasm, "\tmov ebx, 0\n");
    fprintf(fpasm, "\tint 80h\n");
    fprintf(fpasm, "\n\n");
}

void escribir_operando(FILE *fpasm, char *nombre, int es_variable)
{
    /*Simplemente hacer un push. Comprobamos si es variable o no*/
    if (es_variable)
    {
        fprintf(fpasm, "\tpush dword _%s\n", nombre);
    }
    else
    {
        fprintf(fpasm, "\tpush dword %s\n", nombre);
    }

    /*No pongo doble salto de linea porque se puede hacer varias veces*/
}

void asignar(FILE *fpasm, char *nombre, int es_variable)
{
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable)
    {
        fprintf(fpasm, "\tmox eax, dword [eax]\n");
    }

    fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre);
}

void sumar(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    /*Operamos y guardamos el resultado en la pila*/
    fprintf(fpasm, "\tadd eax, edx\n"); /*eax = eax + edx*/
    fprintf(fpasm, "\tpush dword eax\n");
    fprintf(fpasm, "\n\n");
}
void restar(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    /*Operamos y guardamos el resultado en la pila*/
    fprintf(fpasm, "\tsub eax, edx\n"); /*eax = eax - edx*/
    fprintf(fpasm, "\tpush dword eax\n");
    fprintf(fpasm, "\n\n");
}
void multiplicar(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    /*Operamos y guardamos el resultado en la pila*/
    fprintf(fpasm, "\timul edx\n"); /*eax = eax * edx*/
    fprintf(fpasm, "\tpush dword eax\n");
    fprintf(fpasm, "\n\n");
}
void dividir(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov ebx, dword [ebx]\n");
    }
    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    /*comprobacion del divisor*/
    fprintf(fpasm, "\tcmp ebx, 0\n");    /*if (divisor == 0)*/
    fprintf(fpasm, "\tje div_zero_fin\n"); /*error division por cero*/

    /*else*/
    /*Operamos y guardamos el resultado en la pila*/
    fprintf(fpasm, "\tcdq\n"); /*convert double to quad*/
    fprintf(fpasm, "\tidiv ebx\n"); /*eax = eax/ebx y edx el resto*/
    fprintf(fpasm, "\tpush dword eax\n");
    fprintf(fpasm, "\n\n");
}
void o(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    /*Operamos y guardamos el resultado en la pila*/
    fprintf(fpasm, "\tor eax, edx\n"); /*eax = eax |tsub edx*/
    fprintf(fpasm, "\tpush dword eax\n");
    fprintf(fpasm, "\n\n");
}
void y(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable_2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable_1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    /*Operamos y guardamos el resultado en la pila*/
    fprintf(fpasm, "\tand eax, edx\n"); /*eax = eax & edx*/
    fprintf(fpasm, "\tpush dword eax\n");
    fprintf(fpasm, "\n\n");
}
void cambiar_signo(FILE *fpasm, int es_variable)
{
    /*Sacamos el operandos de la pila*/
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    /*Operamos y guardamos el resultado en la pila*/
    fprintf(fpasm, "\tneg eax\n"); /*eax = -eax*/
    fprintf(fpasm, "\tpush dword eax\n");
    fprintf(fpasm, "\n\n");
}
void no(FILE *fpasm, int es_variable, int cuantos_no)
{
    /*Sacamos el operando de la pila*/
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }
    /*Comparacion*/
    fprintf(fpasm, "\tcmp eax, 0\n");
    /*Salto si es cero*/
    /*TODO lo mismo hay que poner near idk*/
    fprintf(fpasm, "\tje _booleano_falso_%d\n", cuantos_no);
    /*El booleano era 1 y metemos un 0*/
    fprintf(fpasm, "\tpush 0\n");
    /*y nos vamos*/
    fprintf(fpasm, "\tjmp _fin_booleano_%d\n", cuantos_no);
    /*Cuando si es igual*/
    fprintf(fpasm, "_booleano_falso_%d:\n", cuantos_no);
    /*El booleano era 0 y metemos un 1*/
    fprintf(fpasm, "\tpush 1\n");
    fprintf(fpasm, "_fin_booleano_%d:\n", cuantos_no);

    fprintf(fpasm, "\n\n");
}

void igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }
    /*Comparacion*/
    fprintf(fpasm, "\tcmp eax, edx\n");
    /*Salto si se cumple la condicion*/
    /*TODO lo mismo hay que poner near idk*/
    fprintf(fpasm, "\tje _igual_%d\n", etiqueta);
    /*Caso cuando no se cumple la condicion*/
    fprintf(fpasm, "\tpush 0\n");
    /*y nos vamos*/
    fprintf(fpasm, "\tjmp _fin_igual_%d\n", etiqueta);
    /*Cuando si es igual*/
    fprintf(fpasm, "_igual_%d:\n", etiqueta);
    fprintf(fpasm, "\tpush 1\n");
    fprintf(fpasm, "_fin_igual_%d:\n", etiqueta);

    fprintf(fpasm, "\n\n");
}
void distinto(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }
    /*Comparacion*/
    fprintf(fpasm, "\tcmp eax, edx\n");
    /*Salto si se cumple la condicion*/
    /*TODO lo mismo hay que poner near idk*/
    fprintf(fpasm, "\tjne _no_igual_%d\n", etiqueta);
    /*Caso cuando no se cumple la condicion*/
    fprintf(fpasm, "\tpush 0\n");
    /*y nos vamos*/
    fprintf(fpasm, "\tjmp _fin_no_igual_%d\n", etiqueta);
    /*Cuando si es igual*/
    fprintf(fpasm, "_no_igual_%d:\n", etiqueta);
    fprintf(fpasm, "\tpush 1\n");
    fprintf(fpasm, "_fin_no_igual_%d:\n", etiqueta);

    fprintf(fpasm, "\n\n");
}
void menor_igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }
    /*Comparacion*/
    fprintf(fpasm, "\tcmp eax, edx\n");
    /*Salto si se cumple la condicion*/
    /*TODO lo mismo hay que poner near idk*/
    fprintf(fpasm, "\tjle _menor_igual_%d\n", etiqueta);
    /*Caso cuando no se cumple la condicion*/
    fprintf(fpasm, "\tpush 0\n");
    /*y nos vamos*/
    fprintf(fpasm, "\tjmp _fin_menor_igual_%d\n", etiqueta);
    /*Cuando si es igual*/
    fprintf(fpasm, "_menor_igual_%d:\n", etiqueta);
    fprintf(fpasm, "\tpush 1\n");
    fprintf(fpasm, "_fin_menor_igual_%d:\n", etiqueta);

    fprintf(fpasm, "\n\n");
}
void mayor_igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }
    /*Comparacion*/
    fprintf(fpasm, "\tcmp eax, edx\n");
    /*Salto si se cumple la condicion*/
    /*TODO lo mismo hay que poner near idk*/
    fprintf(fpasm, "\tjge _mayor_igual_%d\n", etiqueta);
    /*Caso cuando no se cumple la condicion*/
    fprintf(fpasm, "\tpush 0\n");
    /*y nos vamos*/
    fprintf(fpasm, "\tjmp _fin_mayor_igual_%d\n", etiqueta);
    /*Cuando si es igual*/
    fprintf(fpasm, "_mayor_igual_%d:\n", etiqueta);
    fprintf(fpasm, "\tpush 1\n");
    fprintf(fpasm, "_fin_mayor_igual_%d:\n", etiqueta);

    fprintf(fpasm, "\n\n");
}
void menor(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }
    /*Comparacion*/
    fprintf(fpasm, "\tcmp eax, edx\n");
    /*Salto si se cumple la condicion*/
    /*TODO lo mismo hay que poner near idk*/
    fprintf(fpasm, "\tjl _menor_%d\n", etiqueta);
    /*Caso cuando no se cumple la condicion*/
    fprintf(fpasm, "\tpush 0\n");
    /*y nos vamos*/
    fprintf(fpasm, "\tjmp _fin_menor_%d\n", etiqueta);
    /*Cuando si es igual*/
    fprintf(fpasm, "_menor_%d:\n", etiqueta);
    fprintf(fpasm, "\tpush 1\n");
    fprintf(fpasm, "_fin_menor_%d:\n", etiqueta);

    fprintf(fpasm, "\n\n");
}
void mayor(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    /*Sacamos los dos operandos de la pila*/
    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    /*comprobamos el tipo de operandos*/
    if (es_variable2)
    {
        fprintf(fpasm, "\tmov edx, dword [edx]\n");
    }
    if (es_variable1)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }
    /*Comparacion*/
    fprintf(fpasm, "\tcmp eax, edx\n");
    /*Salto si se cumple la condicion*/
    /*TODO lo mismo hay que poner near idk*/
    fprintf(fpasm, "\tjg _mayor_%d\n", etiqueta);
    /*Caso cuando no se cumple la condicion*/
    fprintf(fpasm, "\tpush 0\n");
    /*y nos vamos*/
    fprintf(fpasm, "\tjmp _fin_mayor_%d\n", etiqueta);
    /*Cuando si es igual*/
    fprintf(fpasm, "_mayor_%d:\n", etiqueta);
    fprintf(fpasm, "\tpush 1\n");
    fprintf(fpasm, "_fin_mayor_%d:\n", etiqueta);

    fprintf(fpasm, "\n\n");
}
void leer(FILE *fpasm, char *nombre, int tipo)
{
    fprintf(fpasm, "\tpush _%s\n", nombre);

    if (tipo == BOOLEANO)
    {
        fprintf(fpasm, "\tcall scan_boolean\n");
    }
    else
    {
        fprintf(fpasm, "\tcall scan_int\n");
    }

    /*la pila debe estar bien*/
    fprintf(fpasm, "\tadd esp, 4\n");

    fprintf(fpasm, "\n\n");
}
void escribir(FILE *fpasm, int es_variable, int tipo)
{
    if (es_variable) /*we need in the stack the true value of the variable*/
    {
        fprintf(fpasm, "\tpop eax\n");
        fprintf(fpasm, "\tpush dword [eax]\n");
    }

    if (tipo == BOOLEANO)
    {
        fprintf(fpasm, "\tcall print_boolean\n");
    }

    else
    {
        fprintf(fpasm, "\tcall print_int\n");
    }

    /*la pila debe estar bien*/
    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tcall print_endofline\n");

    fprintf(fpasm, "\n\n");
}
void ifthenelse_inicio(FILE *fpasm, int exp_es_variable, int etiqueta)
{
    fprintf(fpasm, "\tpop eax\n");

    if (exp_es_variable)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    fprintf(fpasm, "\tcmp eax, 0\n");
    fprintf(fpasm, "\tje _if_fin_%d\n", etiqueta);
}
void ifthen_inicio(FILE *fpasm, int exp_es_variable, int etiqueta)
{
    fprintf(fpasm, "\tpop eax\n");

    if (exp_es_variable)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    fprintf(fpasm, "\tcmp eax, 0\n");
    fprintf(fpasm, "\tje _if_fin_%d\n", etiqueta);
}
/*
- Generación de código para el inicio de una estructura if-then
- Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
- exp_es_variable
- Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
- Es 0 en caso contrario (constante u otro tipo de expresión)
*/
void ifthen_fin(FILE *fpasm, int etiqueta)
{
    fprintf(fpasm, "_if_fin_%d:\n", etiqueta);
}
/*
- Generación de código para el fin de una estructura if-then
- Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
- Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/
void ifthenelse_fin_then(FILE *fpasm, int etiqueta)
{
    fprintf(fpasm, "\tjmp _else_%d\n", etiqueta);
    fprintf(fpasm, "_if_fin_%d:\n", etiqueta);
}
/*
- Generación de código para el fin de la rama then de una estructura if-then-else
- Sólo necesita usar la etiqueta adecuada, aunque es el final de una rama, luego debe venir
otra (la rama else) antes de que se termine la estructura y se tenga que ajustar las etiquetas
por lo que sólo se necesita que se utilice la etiqueta que corresponde al momento actual.
*/
void ifthenelse_fin(FILE *fpasm, int etiqueta)
{
    fprintf(fpasm, "_else_%d:\n", etiqueta);
}
/*
- Generación de código para el fin de una estructura if-then-else
- Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
- Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

void while_inicio(FILE *fpasm, int etiqueta)
{
    fprintf(fpasm, "_while_inicio_%d:\n", etiqueta);
}

void while_exp_pila(FILE *fpasm, int exp_es_variable, int etiqueta)
{
    fprintf(fpasm, "\tpop eax\n");

    if (exp_es_variable)
    {
        fprintf(fpasm, "\tmov eax, dword [eax]\n");
    }

    fprintf(fpasm, "\tcmp eax, 0\n");
    fprintf(fpasm, "\tje _while_fin_%d\n", etiqueta);
}
void while_fin(FILE *fpasm, int etiqueta)
{

    fprintf(fpasm, "\tjmp _while_inicio_%d\n", etiqueta);
    fprintf(fpasm, "_while_fin_%d:\n", etiqueta);
}
void escribir_elemento_vector(FILE *fpasm, char *nombre_vector,
                              int tam_max, int exp_es_direccion)
{

    fprintf(fpasm, "\tpop dword eax\n");

    if (exp_es_direccion)
    {
        fprintf(fpasm, "\tmov dword eax , [eax]\n");
    }

    /*comprobamos que no accedemos a una posicion menor que cero*/
    fprintf(fpasm, "\tcmp eax,0\n");
    fprintf(fpasm, "\tjl out_of_range_vector_fin\n");

    /*comprobamos que no nos pasamos por arriba*/
    fprintf(fpasm, "\tcmp eax, %d\n", tam_max - 1);
    fprintf(fpasm, "\tjg out_of_range_vector_fin\n");

    /*Cuando no hay errores de acceso se procede*/
    fprintf(fpasm, "\tmov dword edx, _%s\n", nombre_vector);
    /*leemos lo que hay en el vector*/
    fprintf(fpasm, "\tlea eax, [edx + eax*4]\n");
    /*lo pusheamos*/
    fprintf(fpasm, "\tpush dword eax\n");

    fprintf(fpasm, "\n\n");
}

void declararFuncion(FILE *fd_asm, char *nombre_funcion, int num_var_loc)
{
    /*ponemos el number*/
    fprintf(fd_asm, "_%s:\n", nombre_funcion);
    /*reservamos en la pila espacio para todas las variables*/
    fprintf(fd_asm, "\tpush ebp\n");
    fprintf(fd_asm, "\tmov ebp, esp\n");
    fprintf(fd_asm, "\tsub esp, %d\n", 4 * num_var_loc);
}

void retornarFuncion(FILE *fd_asm, int es_variable)
{

    /*Lo que se retorna va a eax*/
    fprintf(fd_asm, "\tpop dword eax\n");

    if (es_variable)
    {
        fprintf(fd_asm, "\tmov eax, [eax]\n");
    }

    fprintf(fd_asm, "\tmov dword esp, ebp\n");
    fprintf(fd_asm, "\tpop dword ebp\n");
    fprintf(fd_asm, "\tret\n");

    fprintf(fd_asm, "\n\n");
}
void escribirParametro(FILE *fpasm, int pos_parametro, int num_total_parametros)
{
    int direccion;

    /*calculamos la direccion*/
    direccion = 4 + 4 * (num_total_parametros - pos_parametro); /*sumo 4 porque el parametro no va a ser cero*/
    fprintf(fpasm, "\tlea eax, [ebp+%d]\n", direccion);
    fprintf(fpasm, "\tpush dword eax\n");
}
void escribirVariableLocal(FILE *fpasm, int posicion_variable_local)
{
    int direccion;

    direccion = 4 * posicion_variable_local;

    fprintf(fpasm, "\tlea eax, [ebp-%d]\n", direccion);
    fprintf(fpasm, "\tpush dword eax\n");
}

void asignarDestinoEnPila(FILE *fpasm, int es_variable)
{
    /*Primero la direccion donde hay que asignar (no lo toco)*/
    fprintf(fpasm, "\tpop dword eax\n");

    /*Lo que queremos asignar*/
    fprintf(fpasm, "\tpop dword ebx\n");
    if (es_variable)
    {
        fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tmov [eax], ebx\n");

    /*Esta va despues de las dos anteriores*/
    fprintf(fpasm, "\n\n");
}
void operandoEnPilaAArgumento(FILE *fd_asm, int es_variable)
{
    /*Solo se hace cambio si es variable*/
    if (es_variable)
    {
        fprintf(fd_asm, "\tpop eax\n");
        fprintf(fd_asm, "\tpush dword [eax]\n");
        fprintf(fd_asm, "\n\n");
    }
}
void llamarFuncion(FILE *fd_asm, char *nombre_funcion, int num_argumentos)
{
    fprintf(fd_asm, "\tcall _%s\n", nombre_funcion);

    fprintf(fd_asm, "\tadd esp, %d\n", 4 * num_argumentos);
    /*push de eax porque al final nos lo pueden sobreesribir al retornar*/
    fprintf(fd_asm, "\tpush dword eax\n");

    fprintf(fd_asm, "\n\n");
}
void limpiarPila(FILE *fd_asm, int num_argumentos)
{
    /*añadir a la pila y listo*/
    fprintf(fd_asm, "add esp, %d\n", 4 * num_argumentos);

    fprintf(fd_asm, "\n\n");
}