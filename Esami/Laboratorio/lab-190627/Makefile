Program = compito.o liste.o grafo.o tipo.o
CXXFLAGS = -Wall

PuntoInteresse: $(Program)
	g++ -Wall -o PuntoInteresse $(Program)

-include dependencies.txt

-PHONY: clean clean-all

depend:
	g++ -MM *.cc > dependencies.txt

clean : 
	rm -f *.o

clean-all :
	rm -f PuntoInteresse *.cc