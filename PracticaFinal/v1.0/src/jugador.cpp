#include <iostream>
#include <cstring>  
#include <cassert>
#include "jugador.h"

Jugador::Jugador(char *nombre, int turno)
{
  	strcpy(m_nombre, nombre);
  	m_turno = turno;
  	m_puntos = 0;
}

void Jugador::escogePosicion(Tablero& tab) const
{
  	assert(m_turno == tab.turnoActual());

  	int cols = tab.columnas() - 1;
  	int fils = tab.filas() - 1;
  	char c;
  	int f;
  	if(tab.voluntad(m_turno))
	{
  		std::cout << "No se puede insertar ficha, pasa turno ";
  		tab.pasaTurno();
  	}
  	else
	{
  		tab.prettyPrint();
  	do
	{
    	do
		{
      		std::cout << m_nombre << ", escoja una columna (a-" << static_cast<char>('a'+cols) << "): ";
      		std::cin >> c;
    	}while (c < 'a' || c > 'a'+cols);
    	do
		{
      		std::cout << m_nombre << ", escoja una fila (0-" << fils << "): ";
      		std::cin >> f;
    	}while (f < 0 || f > fils);
    }while(tab.permiso(f,(c-'a'),m_turno));
  	std::cout << std::endl;	
 	tab.insertar(f,(c-'a'));
  }
}

void Jugador::sumaPuntos(const Tablero& tab)
{
  	m_puntos += tab.puntuacion(m_turno);
}
