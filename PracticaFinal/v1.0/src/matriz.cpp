#include <cassert>
#include "matriz.h"

Matriz::Matriz() : m_filas(0), m_columnas(0)
{
}

Matriz::Matriz(int f, int c)
{
 	assert (f >= 0 && f <= 10 && c >= 0 && c <= 10);
  	m_filas = f;
  	m_columnas = c;
  	reset();
}

int Matriz::get(int f, int c) const
{ 	
  	return m_datos[f][c];
}

void Matriz::set(int f, int c, int v)
{
  	assert (f >= 0 && f < m_filas && c >= 0 && c < m_columnas);
  	m_datos[f][c] = v;
}

void Matriz::reset()
{
  	for (int i = 0; i < m_filas; i++)
    	for (int j = 0; j < m_columnas; j++)
    	{
      		if((i==(m_filas/2)-1&&j==(m_columnas/2)-1)||(i==m_filas/2&&j==m_columnas/2))
						m_datos[i][j]=2;		//fichas blancas
					else if((i==(m_filas/2)-1&&j==m_columnas/2)||(i==m_filas/2&&j==(m_columnas/2)-1))
						m_datos[i][j]=1;		//fichas negras
					else					
						m_datos[i][j]=0;  	//casilla vacia
		}
}
