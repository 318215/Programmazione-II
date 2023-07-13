Program = main.o lista.o lista-tipo.o parola.o
CXXFLAGS = -Wall

ModuloAlbero : $(Program)
	g++ -Wall -o Modulo_Inverted_Index $(Program)

-include dependencies

.PHONY : clean clean-all

depend : 
	g++ -MM *.cc > dependencies

clean :
	rm -f *.o

clean-all :
	rm -f ModuloAlbero *.o