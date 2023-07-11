Program = main.o albero.o albero-tipo.o
CXXFLAGS = -Wall

ModuloAlbero : $(Program)
	g++ -Wall -o Modulo_BST $(Program)

-include dependencies

.PHONY : clean clean-all

depend : 
	g++ -MM *.cc > dependencies

clean :
	rm -f *.o

clean-all :
	rm -f ModuloAlbero *.o