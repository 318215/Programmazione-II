OBJ = lista.o tipo.o compito.o

CXXFLAGS=-Wall

Agenda: $(OBJ)
	g++ -o Agenda $(OBJ)
    
-include dependencies

.PHONY: depend all clean cleanall

depend:
	g++ -MM *.cc > dependencies
    
all: depend Agenda

clean:
	rm -f *.o
cleanall:
	rm -f Agenda *.o