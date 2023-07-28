CXXFLAGS=-Wall

OBJ = compito.o tipo.o liste.o

esame_prog2: $(OBJ)
	g++ -o esame_prog2 $(OBJ)

tipo.o: tipo.h

liste.h: tipo.h

liste.o: liste.h

compito.o: liste.h

.PHONY: clean cleanall debug
clean:
	rm -f *.o
cleanall:
	rm -f esame_prog2 *.o