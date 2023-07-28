TARGET = output
OBJ = compito.o lista.o tipo.o
DEPENDECIES = dep
# FLAG C++ #
############
CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -pedantic

# genero i file oggetto #
#########################
#  .) $@ -> il target della regola
# ..) $^ -> tutti i prerequisiti
$(TARGET): $(OBJ)
	g++ $(CXXFLAGS) -o $@ $^

depend:
# genero un file delle dipendenze #
###################################
#  .) -M -> genero le dipendenze dei file sorgenti passati come argomenti
# ..) -MM -> -M + per omettere file di sistema
	g++ -MM ./*.cc > $(DEPENDECIES)

# se dep non esiste non creo errore #
#####################################
-include $(DEPENDECIES)

# pulisco la directory dai file temporanei #
############################################
.PHONY: clean cleanall
clean:
	rm -rf *.o
cleanall:
	rm -rf $(TARGET) deps
