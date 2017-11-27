#include<iostream>

using namespace std;


struct MatrizBit{
	unsigned int matriz[4];
	unsigned short int capacidad;
};

bool Inicializar(MatrizBit& m, int fils, int cols);

int Filas(const MatrizBit& m);

int Columnas(const MatrizBit& m);

bool Get(const MatrizBit& m, int f, int c);

void Set(MatrizBit& m, int f, int c, bool v);
