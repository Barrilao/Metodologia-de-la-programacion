#include "punto.h"
#include <iostream>

using namespace std;

int main()
{
	double total=0;
	Punto p1, p2;
	int n;

	cout << "Introduzca el número de puntos consecutivos de los que quiere saber su trayectoria: ";
	cin >> n;
	
	cout << "Introduzca el punto 1: ";
	p1=LeerPunto();
	
	for(int i=2;i<=n;i++)
	{
		cout << "Introduzca el punto " << i << ": ";
		p2=LeerPunto();
		total=total+Distancia(p1,p2);
		p1=p2;
	}
	
	cout << "La longitud del trayecto es: " << total <<  endl;
}
