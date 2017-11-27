#include <iosfwd> 
#include <cstring> 
#include <fstream>
#include "matriz_operaciones.h"

using namespace std;

void EliminarBlancos(istream& is){
	while(isspace(is.peek()))
    		is.ignore();
}

bool Leer(istream& is, MatrizBit& m){
  	int filas;
  	int columnas;
  	bool exito;

 	EliminarBlancos(is);
	if (is.peek() == 'X' || is.peek() == '.'){
 		const int MAX_POS = 1024;
    		char valores[MAX_POS];
   		char aux[MAX_POS];

    		is.getline(valores, MAX_POS);
    		columnas = strlen(valores);
    		filas = 1;
    		EliminarBlancos(is);

    		while (is.getline(aux, MAX_POS)){
	      		if (strlen(aux) != columnas)
        			return false;
			strcat(valores, aux);
      			filas++;
      			EliminarBlancos(is);
    		}

		exito =  is.eof() && Inicializar(m, filas, columnas);
		if (exito)
	      		for (int i = 0; i < filas; i++)
        			for (int j = 0; j < columnas; j++){
          				char c = valores[columnas*i + j];
					if (c == 'X' || c == '.')
        	    				Set(m, i, j, c == 'X');
          				else
            					return false;
   				}
  	}
	
	else{
    		is >> filas >> columnas;
    		exito = is && Inicializar(m, filas, columnas);

    		if (exito){
			for (int i = 0; i < filas && exito; i++)
        			for (int j = 0; j < columnas; j++){
          				char aux;
          				is >> aux;
					if (aux == '1' || aux == '0')
            					Set(m, i, j, aux == '1');
          				else
            					return false;
        			}
        
      			exito = is;
    		}
  	}

  	return exito;
}

bool Escribir(ostream& os, const MatrizBit& m){
  	const int FILAS = Filas(m);
  	const int COLUMNAS = Columnas(m);
	os << FILAS << " " << COLUMNAS << "\n";
	for (int i = 0; i < FILAS; i++){
		for (int j = 0; j < COLUMNAS; j++)
      			os << (Get(m, i, j) ? '1' : '0') << ' ';
    		os << "\n";
  	}
  	os << "\n";
	return os;
}

bool Leer(const char nombre[], MatrizBit& m){
	ifstream f(nombre);
	return Leer(f, m);
}

bool Escribir(const char nombre[], const MatrizBit& m){
  	ofstream f(nombre);
  	return Escribir(f, m);
}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
  	for (int i = 0; i < Filas(m1); i++)
    		for (int j = 0; j < Columnas(m1); j++)
      			Set(res, i, j, Get(m1, i, j) && Get(m2, i, j));
}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
  	for (int i = 0; i < Filas(m1); i++)
    		for (int j = 0; j < Columnas(m1); j++)
      			Set(res, i, j, Get(m1, i, j) || Get(m2, i, j));
}

void Not(MatrizBit& res, const MatrizBit& m){
	for (int i = 0; i < Filas(m); i++)
    		for (int j = 0; j < Columnas(m); j++)
      			Set(res, i, j, !Get(m, i, j));
}

void Traspuesta(MatrizBit& res, const MatrizBit& m){
  	for (int i = 0; i < Filas(m); i++)
    		for (int j = 0; j < Columnas(m); j++)
      			Set(res, j, i, Get(m, i, j));
}
