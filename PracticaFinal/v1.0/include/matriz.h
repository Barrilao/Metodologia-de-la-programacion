#ifndef _MATRIZ_H_
#define _MATRIZ_H_

class Matriz {
    	int m_datos[10][10];
    	int m_filas, m_columnas;
  	public:
    	Matriz();
    	Matriz(int f, int c);
    	int filas() const {return m_filas;}
    	int columnas() const {return m_columnas;}
    	int get(int f, int c) const;
    	void set(int f, int c, int v);
    	void reset();
};

#endif
