
CC = gcc -g

EJ = tsprueba

tsprueba: main.c tablasimbolos.o tablasimbolos.h
	gcc -o tsprueba tablasimbolos.o main.c

.PHONY : clean all
clean :
	@rm -f $(EJ)
	@rm -f *.o
	@rm -f *.h.gch
