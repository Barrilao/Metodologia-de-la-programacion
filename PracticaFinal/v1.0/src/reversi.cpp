#include <iostream>
#include "tablero.h"
#include "jugador.h"
using namespace std;

int main()
{
  	const int MAX = 10;
  	int f, c;
  	char nombre_j1[50];
  	char nombre_j2[50];

  	cout << "Introduzca filas: ";
  	do
	{
    	cin >> f;
  	}while(f < 0 || f > MAX);
  	cout << "Introduzca columnas: ";
  	do{
    	cin >> c;
 	}while(c < 0 || c > MAX);

  	cout << "Introduzca el nombre del primer jugador: ";
  	cin >> nombre_j1;
  	cout << "Introduzca el nombre del segundo jugador: ";
  	cin >> nombre_j2;
  	cout << endl;

  	Tablero tab(f,c);
  	Jugador j1(nombre_j1, 1), j2(nombre_j2, 2);
  	int ganadas_j1, ganadas_j2, empates;
  	bool jugar;

  	jugar = true;
  	ganadas_j1 = ganadas_j2 = empates = 0;
  	while (jugar)
	{
    	while(!tab.finalizada())
		{
      		if(tab.turnoActual() == 1)
        		j1.escogePosicion(tab);
      		else
        		j2.escogePosicion(tab);
    	}
    	tab.prettyPrint();
    	if(tab.ganador() == 1)
		{
      		ganadas_j1++;
      		j1.sumaPuntos(tab);
    	}
    	else if(tab.ganador() == 2)
		{
      		ganadas_j2++;
      		j2.sumaPuntos(tab);
    	}
    	else
      		empates++;

    	cout << "\n-- Resultados tras la partida --\n";
    	cout << j1.nombre() << ": " << ganadas_j1 << " ganadas que acumulan " << j1.puntos() << " puntos.\n";
    	cout << j2.nombre() << ": " << ganadas_j2 << " ganadas que acumulan " << j2.puntos() << " puntos.\n";

    	char c;
    	cout << "\nJugar de nuevo? (S/N): ";
    	do
		{
      		cin >> c;
      		c = tolower(c);
    	}while (c != 's' && c != 'n');
    	cout << endl;

    	if (c == 's')
      		tab.vaciar();
    	else
      		jugar = false;
  	}
  	cout << "Resultados finales:\n";
  	cout << j1.nombre() << ": " << ganadas_j1 << " ganadas que acumulan " << j1.puntos() << " puntos.\n";
  	cout << j2.nombre() << ": " << ganadas_j2 << " ganadas que acumulan " << j2.puntos() << " puntos.\n";
  	cout << empates << " empates.\n";
}
