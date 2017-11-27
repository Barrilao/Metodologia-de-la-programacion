#include "punto.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	Punto min, max, p;
	
	cout << "Introduzca el numero de puntos ";
	cin >> n;
	
	cout << "Introduzca el punto 1: ";
	min=LeerPunto();
	max=min;
	
	
	for(int i=2;i<=n;i++)
	{
		cout << "Introduzca el punto " << i << ": ";
		p=LeerPunto();
		min=Menor (min,p);
		max=Mayor (max,p);
	} 
	
	cout << "El rectangulo que delimita los puntos es: ";
	EscribirPunto(min); 
	cout << "- "; 
	EscribirPunto(max);
	cout << endl;

}
