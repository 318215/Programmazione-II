Program = main.o liste.o tipo.o
CXXFLAGS = -Wall

Modulo_Inverted_Index : $(Program)
	g++ -Wall -o Modulo_Inverted_Index $(Program)

-include dependencies

.PHONY : clean clean-all

depend : 
	g++ -MM *.cc > dependencies

clean :
	rm -f *.o

clean-all :
	rm -f Modulo_Inverted_Index *.o