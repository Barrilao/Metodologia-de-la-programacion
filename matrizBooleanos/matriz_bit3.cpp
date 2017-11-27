#include<iostream>

using namespace std;

bool Inicializar(MatrizBit& m, int fils, int cols){
	if((fils*cols)>100)
		return false;
	else{
		m.capacidad=(fils<<16)|cols;
		for(int i=0;i<fils*cols;i++){
			m.matriz[i]='0';
		}
	}
	return true;
}

int Filas(const MatrizBit& m){
	return m.capacidad >> 16;
}

int Columnas(const MatrizBit& m){
	return m.capacidad & 0xFFFF;
}

bool Get(const MatrizBit& m, int f, int c){
	return m.matriz[Columnas(m)*f+c]=='1';
}

void Set(MatrizBit& m, int f, int c, bool v){
	if(v==true)
		m.matriz[Columnas(m)*f+c]='1';
	else
		m.matriz[Columnas(m)*f+c]='0';
}
