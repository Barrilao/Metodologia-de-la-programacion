#include<iostream>

using namespace std;

bool Inicializar(MatrizBit& m, int fils, int cols){
	m.filas=fils;
	m.columnas=cols;
	if(fils>10||cols>10)
		return false;
	else{
		for(int i=0;i<fils;i++){
			for(int j=0;j<cols;j++){
				m.matriz[i][j]=false;
			}
		}
	}
	return true;
}

int Filas(const MatrizBit& m){
	return m.filas;
}

int Columnas(const MatrizBit& m){
	return m.columnas;
}

bool Get(const MatrizBit& m, int f, int c){
	return m.matriz[f][c];
}

void Set(MatrizBit& m, int f, int c, bool v){
	m.matriz[f][c]=v;
}
