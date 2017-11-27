#include<iostream>

using namespace std;

bool Inicializar(MatrizBit& m, int fils, int cols){
	m.capacidad=(fils<<8)|cols;
	if((fils*cols)>128)
		return false;
	else{
		for(int i;i<4;i++){
			m.matriz[i]=0;
		}
	}
	return true;
}

int Filas(const MatrizBit& m){
	return m.capacidad >> 8;
}

int Columnas(const MatrizBit& m){
	return m.capacidad & 0xFF;
}

bool Get(const MatrizBit& m, int f, int c){
	const int meme=f*Columnas(m)+c;

	if(((1<<meme%32) & m.matriz[meme/32])!=0)
		return true;
	else
		return false;
}

void Set(MatrizBit& m, int f, int c, bool v){
	const int meme=f*Columnas(m)+c;
	unsigned int aux=1<<meme%32;
	
	if(v==true)
		m.matriz[meme/32] |= aux;
	else
		m.matriz[meme/32] &= ~aux;

}
