#include "alfa.h"
#include "y.tab.h"

extern FILE* yyin;
FILE* fout;


int main(int argc, char** argv) {
  if (argc == 2) {
    yyin = fopen(argv[1], "r");
    fout = stdout;
  } else if (argc == 3) {
    yyin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
  } else {
    fprintf(stderr, "formato incorrecto:\n./ejecutable input.txt output.txt\n");
    return 1;
  }
	escribir_subseccion_data(fout);
	escribir_cabecera_bss(fout);
  yyparse();
  fclose(yyin);
  if (fout != stdout)
    fclose(fout);

  return 0;
}