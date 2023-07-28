Program = compito.o carta.o bst.o
CXXFLAGS = -Wall

Compito: $(Program)
	g++ -Wall -o Compito $(Program)

-include dependencies.txt

.PHONY: clean clean-all

depend:
	g++ -MM *.cc > dependencies.txt

clean :
	rm -f *.o

clean-all:
	rm -f Compito *.o