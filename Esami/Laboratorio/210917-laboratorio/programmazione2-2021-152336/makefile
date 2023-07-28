OBJ = compito.o liste.o tipo.o
CXXFLAGS=-Wall
appuntamenti: $(OBJ)
	g++ -o appuntamenti $(OBJ)
    
-include dependencies
.PHONY: depend all clean cleanall
depend:
	g++ -MM *.cc > dependencies
    
all: depend appuntamenti
clean:  
	rm -f *.o
cleanall:
	rm -f appuntamenti *.