Program = compito.o tipo.o liste.o
CXXFLAGS = -Wall

Compito: $(Program)
	g++ -Wall -o compito $(Program)

-include dependencies

.PHONY : clean clean-all

depend: 
	g++ -MM *.cc > dependencies

clean:
	rm -f *.o

clea-all :
	rm -f compito *.o