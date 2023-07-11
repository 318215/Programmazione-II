Program = main.o grafo.o grafo-tipo.o coda-bfs.o
CXXFLAGS = -Wall

ModuloGrafo : $(Program)
	g++ -Wall -o Modulo_Grafo $(Program)

-include dependencies

.PHONY : clean clean-all

depend : 
	g++ -MM *.cc > dependencies

clean :
	rm -f *.o

clean-all :
	rm -f ModuloAlbero *.o