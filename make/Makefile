INC= include
SRC= src
OBJ= obj
LIB= lib
BIN= bin

AR= ar
CXX= g++
CXXFLAGS= -Wall -g -I$(INC)
LDFLAGS= -L$(LIB)
LDLIBS= -lformas

all : $(BIN)/central $(BIN)/area $(BIN)/longitud $(BIN)/delimitar

$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/central $(OBJ)/central.o $(LDFLAGS) $(LDLIBS)
$(BIN)/area : $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/area $(OBJ)/area.o $(LDFLAGS) $(LDLIBS)
$(BIN)/longitud : $(OBJ)/longitud.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/longitud $(OBJ)/longitud.o $(LDFLAGS) $(LDLIBS)
$(BIN)/delimitar : $(OBJ)/delimitar.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/delimitar $(OBJ)/delimitar.o $(LDFLAGS) $(LDLIBS)
$(OBJ)/punto.o : $(INC)/punto.h $(SRC)/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp
$(OBJ)/circulo.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp
$(OBJ)/central.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/central.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/central.o $(SRC)/central.cpp
$(OBJ)/area.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/central.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/area.o $(SRC)/area.cpp
$(OBJ)/longitud.o : $(INC)/punto.h $(SRC)/longitud.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/longitud.o $(SRC)/longitud.cpp
$(OBJ)/delimitar.o : $(INC)/punto.h $(SRC)/delimitar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/delimitar.o $(SRC)/delimitar.cpp
$(LIB)/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o
	$(AR) rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

# *********LIMPIEZA************
clean:
	echo "Limpiando . . . "
	rm $(OBJ)/*.o $(LIB)/lib*.a
mrproper: clean
	rm $(BIN)/central $(BIN)/area $(BIN)/longitud $(BIN)/delimitar
