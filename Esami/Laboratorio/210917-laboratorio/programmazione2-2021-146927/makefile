OBJ = compito.o tipo.o liste.o 
CXXFLAGS=-Wall

Web: $(OBJ)
	g++ -o Web $(OBJ)

-include dependencies

.PHONY: clean cleanall run
depend:
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f Web *.o