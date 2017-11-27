#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "tablero.h"

class Jugador {
    	char m_nombre[50];
    	int m_turno;
    	int m_puntos;
  	public:
    	Jugador(char *nombre, int turno);
    	const char* nombre() const {return m_nombre;}
    	int turno() const {return m_turno;}
    	int puntos() const {return m_puntos;}
    	void escogePosicion(Tablero& tab) const;
    	void sumaPuntos(const Tablero& tab);
};

#endif
