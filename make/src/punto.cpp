#include "punto.h"
#include <iostream>
#include <cmath> // sqrt, M_PI
using namespace std;

// Funciones para manejar puntos __________________________________

// FIXME: Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Punto LeerPunto()
{
	char c;
	Punto p;
	cin >> c;
	cin >> p.x;
	cin >> c;
	cin >> p.y;
	cin >> c;
	
	return p;
}

// FIXME: Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (Punto p)
{
	cout << "(" << p.x << "," << p.y << ") ";
}

// FIXME: Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto& p, double cx, double cy)
{
	p.x=cx;
	p.y=cy;
}

// FIXME: Devuelve la coordenada X del punto p
double GetX (Punto p)
{
	return p.x;
}

// FIXME: Devuelve la coordenada Y del punto p
double GetY (Punto p)
{
	return p.y;
}

// FIXME: Devuelve la distancia euclídea entre p1 y p2
double Distancia (Punto p1, Punto p2)
{
	return sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
}

// FIXME: Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (Punto p1, Punto p2)
{
	Punto p_res;
	p_res.x=(p1.x+p2.x)/2;
	p_res.y=(p1.y+p2.y)/2;
	
	return p_res;
}

//FIXME: Compara las coordenadas de los puntos y devuelve las menores
Punto Menor (Punto p1, Punto p2)
{
	Punto p_res=p1;
	if(p1.x>p2.x)
		p_res.x=p2.x;
	if(p1.y>p2.y)
		p_res.y=p2.y;

	return p_res;
}
		
//FIXME: Compara las coordenadas de los puntos y devuelve las mayores
Punto Mayor (Punto p1, Punto p2)
{
	Punto p_res=p1;
	if(p1.x<p2.x)
		p_res.x=p2.x;
	if(p1.y<p2.y)
		p_res.y=p2.y;

	return p_res;
}

 
