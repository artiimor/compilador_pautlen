all:
	gcc -Wall -o ej1 ej1.c generacion.c
	./ej1 ej.asm
	nasm -felf32 -g ej.asm
	gcc -o ej -m32 ej.o alfalib.o
	./ej

generacion:
	gcc -Wall -c generacion.c -o generacion.o

clean :
	@rm ej1
	@rm ej.asm
	@rm ej.o
	@rm ej