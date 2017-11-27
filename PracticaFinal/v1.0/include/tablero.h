#ifndef _TABLERO_H_
#define _TABLERO_H_

#include "matriz.h"

class Tablero {
    	Matriz m_tablero;
    	int m_turno;
    	bool m_finalizada;
  	public:
    	enum TipoFicha {VACIA,    ///<  Representa una ficha o casilla vacia
                     	FICHA_J1, ///<  Representa una ficha del jugador 1
                     	FICHA_J2  ///<  Representa una ficha del jugador 2
                    	};
    	Tablero(int f, int c);  //@pre 4 <= f,c <= 20, 3 <= fichas < min{f,c} - 1
    	int filas() const {return m_tablero.filas();}
    	int columnas() const {return m_tablero.columnas();}
    	int turnoActual() const {return m_turno;}
    	bool finalizada() const {return m_finalizada;}
    	TipoFicha get(int f, int c) const;
    	bool compruebaFinalizada() const;
    	bool voluntad(int player) const;
    	void pasaTurno() ;
    	bool permiso(int fila, int columna, int player) const;
    	int fichasTotales() const;
    	void insertar(int fila,int columna);   // las columnas empiezan en 1
    	int ganador() const;  // 0 empate(o no finalizado), 1 j1, 2 j2
   		int puntuacion(int player) const; // @pre: la partida debe estar finalizada
    	void prettyPrint() const;
    	void vaciar();
};

#endif
