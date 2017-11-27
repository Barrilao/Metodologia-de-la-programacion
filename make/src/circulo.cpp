#include "circulo.h"
#include <iostream>
#include <cmath> // sqrt, M_PI
using namespace std;

// Funciones para manejar circulos __________________________________

// FIXME: Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
Circulo LeerCirculo()
{
	Circulo c;
	char t;
	cin >> c.radio;
	cin >> t;
	c.centro=LeerPunto();
	
	return c;
}

// FIXME: Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(Circulo c)
{
	cout << c.radio << "-";
	EscribirPunto(c.centro);
}

// FIXME: Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, Punto centro, double radio)
{
	c.radio=radio;
	c.centro=centro;
}

// FIXME: Devuelve del centro de c
Punto Centro (Circulo c)
{
	return c.centro;
}

// FIXME: Devuelve el radio de c
double Radio (Circulo c)
{
	return c.radio;
}

// FIXME: Devuelve el área del círculo c
double Area (Circulo c)
{
	return M_PI * c.radio * c.radio;
}

// FIXME: Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (Punto p, Circulo c)
{
	if(Distancia(p,c.centro)< c.radio)
		return true;

	else
		return false;
	
}

// FIXME: Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (Circulo c1, Circulo c2)
{
	return Distancia(c1.centro,c2.centro)-c1.radio-c2.radio;
}
