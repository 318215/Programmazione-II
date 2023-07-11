Program = main.o fun-app.o liste.o liste-tipo.o
CXXFLAGS=-Wall

Web-list: $(Program)
	g++ -o Web-list $(Program)

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f Web-list *.o
