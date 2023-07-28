Program = coda.o grafi.o compito.o
CXXFLAGS = -Wall

Compito: $(Program)
	g++ -Wall -o Esame318215 $(Program)

-include dependencies.txt

.PHONY: clean clean-all

depend:
	g++ -MM *.cc > dependencies.txt

clean:
	rm -f *.o

clean-all:
	rm -f Esame318215 *.o