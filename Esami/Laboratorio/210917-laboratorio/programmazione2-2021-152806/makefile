OBJ = compito.o tipo.o liste.o 
CXXFLAGS=-Wall

all: $(OBJ)
	g++ -o a.out $(OBJ)
	./a.out

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f Web-list *.o