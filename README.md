# compilador pautlen
Prácticas de laboratorio para Proyecto de Autómatas y Lenguajes en la UAM

## Construido con

* [Yacc](https://www.gnu.org/software/bison/) - Para el analizador sintántico y semántico
* [Lexx](https://en.wikipedia.org/wiki/Lex_(software)) - Para el analizador morfológico
* [C](https://en.wikipedia.org/wiki/C_%28programming_language%29) - Para el generador de código y la tabla de símbolos

## Developers

* **Juan Martín** - [JuanMartinP](https://github.com/JuanMartinP/)
* **Arturo Morcillo** - [artiimor](https://github.com/artiimor)

## Resumen
El compilador (o mejor dicho, intérprete) se basa en la especificación del lenguaje alfa. Contiene los siguientes directorios
- **ejemplos_alfa** Ejemplos de la especificación alfa
- **ejemplos_asm** Los anteriores ejemplos compilados de forma correcta
- **generador de código** Crea código en asm
- **tabla_simbolos** Tabla hash y tabla de símbolos

## Ejecutarlo
- **Antes que nada** 
     make clean
     make
- **Ejecutar un ejemplo** 
     ./alfa ejemplos_alfa/<nombre_archivo> misalida.asm
     make asm
- **Compilar todos los ejemplos** 
     make compilar_ejemplos

## NOTAS
- **No funcionan**
    * Las funciones. Por tanto fibonacci.alfa y funciones.alfa no pueden ser compilador






