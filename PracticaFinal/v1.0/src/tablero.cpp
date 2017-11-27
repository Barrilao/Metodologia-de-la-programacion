#include <iostream>
#include <iomanip>  
#include <cassert>
#include "tablero.h"

Tablero::Tablero(int f, int c) : m_tablero(f,c)
{
  	m_turno = 1;
  	m_finalizada = false;
}

Tablero::TipoFicha Tablero::get(int f, int c) const
{
  	return static_cast<TipoFicha>(m_tablero.get(f,c));
}

bool Tablero::compruebaFinalizada() const
{
	bool finalizada=true;
 	if(!voluntad(1)||!voluntad(2))
 		finalizada=false;
 	
 	return finalizada;
}

bool Tablero::voluntad(int player) const
{
	bool pasa_turno=true;
	for(int i=0;i<filas();i++)
	{
 		for(int j=0;j<columnas();j++)
		{
 			if(!permiso(i,j,player))
 				pasa_turno=false;
		}
	} 
	return pasa_turno;
}

void Tablero::pasaTurno()
{
	m_turno = m_turno == 1 ? 2 : 1;
}


bool Tablero::permiso(int fila, int columna, int player) const
{
	int fils = filas();
  	int cols = columnas();
  	bool finalizada = true;
	if(get(fila,columna)!=0)
		return true;

  	if (fichasTotales() >= fils*cols)
    		return true;
	if(columna+1<cols-1)	//Derecha
	{
		if(get(fila,columna+1)!=player&&get(fila,columna+1)!=0)
		{
			for(int i=columna+2;i<cols&&get(fila,i)!=0;i++)
			{
				if(get(fila,i)==player)
					finalizada=false;
			}
		}
	}
	if(columna-1>0&&finalizada!=false)	//Izquierda
	{
		if(get(fila,columna-1)!=player&&get(fila,columna-1)!=0)
		{
			for(int i=columna-2;i>=0&&get(fila,i)!=0;i--)
			{
				if(get(fila,i)==player)
					finalizada=false;
			}
		}
	}		
	if(fila-1>0&&finalizada!=false)	//Arriba
	{
		if(get(fila-1,columna)!=player&&get(fila-1,columna)!=0)
		{
			for(int i=fila-2;i>=0&&get(i,columna)!=0;i--)
			{
				if(get(i,columna)==player)
					finalizada=false;
			}
		}
	}			
	if(fila+1<fils-1&&finalizada!=false)	//Abajo
	{
		if(get(fila+1,columna)!=player&&get(fila+1,columna)!=0)
		{
			for(int i=fila+2;i<fils&&get(i,columna)!=0;i++)
			{
				if(get(i,columna)==player)
					finalizada=false;
			}
		}
	}
	if(fila-1>0&&columna-1>0&&finalizada!=false)	//Esquina Superior Izquierda
	{
		if(get(fila-1,columna-1)!=player&&get(fila-1,columna-1)!=0)
		{
			for(int i=2;fila-i>=0&&columna-i>=0&&get(fila-i,columna-i)!=0;i++)
			{
				if(get(fila-i,columna-i)==player)
					finalizada=false;
			}
		}
	}
	if(fila-1>0&&columna+1<cols-1&&finalizada!=false)	//Esquina Superior Derecha
	{
		if(get(fila-1,columna+1)!=player&&get(fila-1,columna+1)!=0)
		{
			for(int i=2;fila-i>=0&&columna+i<cols&&get(fila-i,columna+i)!=0;i++)
			{
				if(get(fila-i,columna+i)==player)
					finalizada=false;
			}
		}
	}
	if(fila+1<fils-1&&columna-1>0&&finalizada!=false)	//Esquina Inferior Izquierda
	{
		if(get(fila+1,columna-1)!=player&&get(fila+1,columna-1)!=0)
		{
			for(int i=2;fila+i<fils&&columna-i>=0&&get(fila+i,columna-i)!=0;i++)
			{
				if(get(fila+i,columna-i)==player)
					finalizada=false;
			}
		}
	}
	if(fila+1<fils-1&&columna+1<cols-1&&finalizada!=false)	//Esquina Inferior Derecha
	{
		if(get(fila+1,columna+1)!=player&&get(fila+1,columna+1)!=0)
		{
			for(int i=2;fila+i<fils&&columna+i<cols&&get(fila+i,columna+i)!=0;i++)
			{
				if(get(fila+i,columna+i))
					finalizada=false;
			}
		}
	}
	return finalizada;
}

int Tablero::fichasTotales() const
{
  	int fichas = 0;

  	for (int i = 0; i < filas(); i++)
    	for (int j = 0; j < columnas(); j++)
      		if (m_tablero.get(i,j) != VACIA)
        		fichas++;

  	return fichas;
}

void Tablero::insertar(int fila,int columna)
{
  	TipoFicha ficha = turnoActual() == 1 ? FICHA_J1 : FICHA_J2;
  	bool permiso=false;	
	if(ficha==FICHA_J2)							//Jugador 2
	{
		m_tablero.set(fila,columna,ficha);
		if(columna+1<columnas()-1&&get(fila,columna+1)==1)	//Derecha
		{
			for(int i=columna+2;i<columnas()&&get(fila,i)!=0;i++)
			{
				if(get(fila,i)==2)
					permiso=true;	
			}
			if(permiso){
				for(int i=columna+1;i<columnas()&&get(fila,i)!=2;i++)
				{
					m_tablero.set(fila,i,ficha);
				}
			}
		}
		if(columna-1>0&&get(fila,columna-1)==1)	//Izquierda
		{
			permiso=false;
			for(int i=columna-2;i>=0&&get(fila,i)!=0;i--)
			{
				if(get(fila,i)==2)
					permiso=true;	
			}
			if(permiso){
				for(int i=columna-1;i>=0&&get(fila,i)!=2;i--)
				{
					m_tablero.set(fila,i,ficha);
				}
			}				
		}
		if(fila-1>0&&get(fila-1,columna)==1)	//Arriba
		{
			permiso=false;
			for(int i=fila-2;i>=0&&get(i,columna)!=0;i--)
			{
				if(get(i,columna)==2)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=fila-1;i>=0&&get(i,columna)!=2;i--)
				{
					m_tablero.set(i,columna,ficha);	
				}
			}
		}
		if(fila+1<filas()-1&&get(fila+1,columna)==1)	//Abajo
		{
			permiso=false;
			for(int i=fila+2;i<filas()&&get(i,columna)!=0;i++)
			{
				if(get(i,columna)==2)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=fila+1;i<filas()&&get(i,columna)!=2;i++)
				{
					m_tablero.set(i,columna,ficha);
				}
			}
		}
		if(fila-1>0&&columna-1>0&&get(fila-1,columna-1)==1)	//Esquina Superior Izquierda
		{
			permiso=false;
			for(int i=2;fila-i>=0&&columna-i>=0&&get(fila-i,columna-i)!=0;i++)
			{
				if(get(fila-i,columna-i)==2)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=1;fila-i>=0&&columna-i>=0&&get(fila-i,columna-i)!=2;i++)
				{
					m_tablero.set(fila-i,columna-i,ficha);
				}
			}

		}
		if(fila-1>0&&columna+1<columnas()-1&&get(fila-1,columna+1)==1)	//Esquina Superior Derecha
		{
			permiso=false;
			for(int i=2;fila-i>=0&&columna+i<columnas()&&get(fila-i,columna+i)!=0;i++)
			{
				if(get(fila-i,columna+i)==2)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=1;fila-i>=0&&columna+i<columnas()&&get(fila-i,columna+i)!=2;i++)
				{
					m_tablero.set(fila-i,columna+i,ficha);
				}
			}
		}
		if(fila+1<filas()-1&&columna-1>0&&get(fila+1,columna-1)==1)	//Esquina Inferior Izquierda
		{
			permiso=false;
			for(int i=2;fila+i<filas()&&columna-i>=0&&get(fila+i,columna-i)!=0;i++)
			{
				if(get(fila+i,columna-i)==2)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=1;fila+i<filas()&&columna-i>=0&&get(fila+i,columna-i)!=2;i++)
				{
					m_tablero.set(fila+i,columna-i,ficha);
				}
			}
		}
		if(fila+1<filas()-1&&columna-1<columnas()-1&&get(fila+1,columna+1)==1)	//Esquina Inferior Derecha
		{
			permiso=false;
			for(int i=2;fila+i<filas()&&columna+i<columnas()&&get(fila+i,columna+i)!=0;i++)
			{
				if(get(fila+i,columna+i)==2)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=1;fila+i<filas()&&columna+i<columnas()&&get(fila+i,columna+i)!=2;i++)
				{
					m_tablero.set(fila+i,columna+i,ficha);
				}
			}
		}
	}
	else
	{									//Jugador 1
		m_tablero.set(fila,columna,ficha);
		if(columna+1<columnas()-1&&get(fila,columna+1)==2)	//Derecha
		{
			permiso=false;
			for(int i=columna+2;i<columnas()&&get(fila,i)!=0;i++)
			{
				if(get(fila,i)==1)
					permiso=true;	
			}
			if(permiso)
			{
				for(int i=columna+1;i<columnas()&&get(fila,i)!=1;i++)
				{
					m_tablero.set(fila,i,ficha);
				}
			}
		}
		if(columna-1>0&&get(fila,columna-1)==2)	//Izquierda
		{
			permiso=false;
			for(int i=columna-2;i>=0&&get(fila,i)!=0;i--)
			{
				if(get(fila,i)==1)
					permiso=true;	
			}
			if(permiso){
				for(int i=columna-1;i>=0&&get(fila,i)!=1;i--)
				{
					m_tablero.set(fila,i,ficha);
				}
			}				
		}
		if(fila-1>0&&get(fila-1,columna)==2)	//Arriba
		{
			permiso=false;
			for(int i=fila-2;i>=0&&get(i,columna)!=0;i--)
			{
				if(get(i,columna)==1)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=fila-1;i>=0&&get(i,columna)!=1;i--)
				{
					m_tablero.set(i,columna,ficha);	
				}
			}
		}
		if(fila+1<filas()-1&&get(fila+1,columna)==2)	//Abajo
		{
			permiso=false;
			for(int i=fila+2;i<filas()&&get(i,columna)!=0;i++)
			{
				if(get(i,columna)==1)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=fila+1;i<filas()&&get(i,columna)!=1;i++)
				{
					m_tablero.set(i,columna,ficha);
				}
			}
		}
		if(fila-1>0&&columna-1>0&&get(fila-1,columna-1)==2)	//Esquina Superior Izquierda
		{
			permiso=false;
			for(int i=2;fila-i>=0&&columna-i>=0&&get(fila-i,columna-i)!=0;i++)
			{
				if(get(fila-i,columna-i)==1)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=1;fila-i>=0&&columna-i>=0&&get(fila-i,columna-i)!=1;i++)
				{
					m_tablero.set(fila-i,columna-i,ficha);
				}
			}

		}
		if(fila-1>0&&columna+1<columnas()-1&&get(fila-1,columna+1)==2)	//Esquina Superior Derecha
		{
			permiso=false;
			for(int i=2;fila-i>=0&&columna+i<columnas()&&get(fila-i,columna+i)!=0;i++)
			{
				if(get(fila-i,columna+i)==1)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=1;fila-i>=0&&columna+i<columnas()&&get(fila-i,columna+i)!=1;i++)
				{
					m_tablero.set(fila-i,columna+i,ficha);
				}
			}
		}
		if(fila+1<filas()-1&&columna-1>0&&get(fila+1,columna-1)==2)	//Esquina Inferior Izquierda
		{
			permiso=false;
			for(int i=2;fila+i<filas()&&columna-i>=0&&get(fila+i,columna-i)!=0;i++)
			{
				if(get(fila+i,columna-i)==1)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=1;fila+i<filas()&&columna-i>=0&&get(fila+i,columna-i)!=1;i++)
				{
					m_tablero.set(fila+i,columna-i,ficha);
				}
			}
		}
		if(fila+1<filas()-1&&columna-1<columnas()-1&&get(fila+1,columna+1)==2)	//Esquina Inferior Derecha
		{
			permiso=false;
			for(int i=2;fila+i<filas()&&columna+i<columnas()&&get(fila+i,columna+i)!=0;i++)
			{
				if(get(fila+i,columna+i)==1)
					permiso=true;
			}
			if(permiso)
			{
				for(int i=1;fila+i<filas()&&columna+i<columnas()&&get(fila+i,columna+i)!=1;i++)
				{
					m_tablero.set(fila+i,columna+i,ficha);
				}
			}
		}
	}
  	m_turno = m_turno == 1 ? 2 : 1;
  	m_finalizada = compruebaFinalizada();
}

int Tablero::ganador() const
{
  	int suma1=puntuacion(1);
  	int suma2=puntuacion(2);
  	if(suma1==suma2)
  		return 0;
  	else if(suma1>suma2)
  		return 1;
  	else
  		return 2;

  	
}

int Tablero::puntuacion(int player) const
{
  	assert(m_finalizada);
  	int puntos = 0;
  	for(int i=0;i<filas();i++)
	{
  		for(int j=0;j<columnas();j++)
  		{
  			if(get(i,j)==player)
  				puntos += 1;
		}
  	}
  	return puntos;
}

void Tablero::prettyPrint() const
{
  	int fils = filas();
  	int cols = columnas();
  	std::cout << "   ";
  	for (char i = 97; i < 97 + cols; i++)
    	std::cout << " " << i;
  	std::cout << std::endl;

  	for (int i = 0; i < fils; i++)
	{
    	std::cout << " " << i << " ";
	std::cout << "|";
    	for (int j = 0; j < cols; j++)
		{
      		if (get(i,j) == FICHA_J1)
        		std::cout << "x";
      		else if (get(i,j) == FICHA_J2)
        		std::cout << "o";
      		else
        		std::cout << " ";
      		std::cout << "|";
    	}
    	std::cout << std::endl;
  	}

  	std::cout << std::setfill('=') << std::setw(4 * columnas())
            << " " << std::endl;

  	if (!m_finalizada)
	{
    	if (m_turno == 1)
      		std::cout << "Turno: jugador 1 (x)";
    	else
      		std::cout << "Turno: jugador 2 (o)";
    	std::cout << std::endl;
  	}
  	else 
  	{
    	std::cout << "Partida finalizada. ";
      	if (ganador() == 1)
        	std::cout << "Ganador: jugador 1.\n";
      	else if (ganador() == 2)
        	std::cout << "Ganador: jugador 2.\n";
      	else
        	std::cout << "EMPATE.\n";
  	}
}

void Tablero::vaciar()
{
  	m_tablero.reset();
  	m_turno = 1;
  	m_finalizada = false;
}
