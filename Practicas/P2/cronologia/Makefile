SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Compilación *********** 

$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(LIB)/libcronologia.a
	$(CXX) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o -I$(INC) -L$(LIB) -lcronologia

$(LIB)/libcronologia.a : $(OBJ)/cronologia.o $(OBJ)/eventohistorico.o
	ar rvs $(LIB)/libcronologia.a $(OBJ)/cronologia.o $(OBJ)/eventohistorico.o

$(OBJ)/eventohistorico.o : $(SRC)/eventohistorico.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/eventohistorico.o $(SRC)/eventohistorico.cpp

$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp $(OBJ)/eventohistorico.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp $(OBJ)/eventohistorico.o

$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp $(OBJ)/cronologia.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp $(OBJ)/cronologia.o $(OBJ)/eventohistorico.o


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
