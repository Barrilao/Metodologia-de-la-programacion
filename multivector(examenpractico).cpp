/*
 * Programa: multivector.cpp
 *
 * Este programa lee una estructura bidimensional de números y 
 * la escribe en la salida estándar seguida de las sumas por 
 * filas y total. Un ejemplo de ejecución es:
 * 
 *      Introduzca la estructura:
 *      5
 *      2   4 7
 *      5   3 8 9 2 2
 *      0
 *      1   4
 *      4   1 3 6 7
 *
 *      La estructura que ha introducido es:
 *      5
 *      2 4 7
 *      5 3 8 9 2 2
 *      0
 *      1 4
 *      4 1 3 6 7
 *      El resultado de las sumas es el siguiente:
 *      Las sumas por filas: 11 24 0 4 17 
 *      La suma total es: 56
 * 
 * Observe que se ha introducido el número de filas seguido de cada 
 * una de ellas. Una fila es un número de elementos seguida de los 
 * elementos que la componen. La estructura dinámica que contendrá 
 * este ejemplo tiene la siguiente forma:
 * 
 *        nfilas ncolumnas datos
 *            ___  ___  ___
 *            | 5 | *  | * |
 *            ¯¯¯¯¯/¯¯¯¯¯¯\¯¯
 *                /        \
 *               |          |
 *               v          v
 *              ___         ___
 *             | 2 |       | *-|---> | 4 | 7 |
 *             -----       -----
 *             | 5 |       | *-|---> | 3 | 8 | 9 | 2 | 2 |
 *             -----       -----
 *             | 0 |       | X |
 *             -----       -----
 *             | 1 |       | *-|---> | 4 |
 *             -----       -----
 *             | 4 |       | *-|---> | 1 | 3 | 6 | 7 |
 *             ¯¯¯¯¯       ¯¯¯¯¯
 *
 * Para resolver el problema debe completar la función que falta teniendo en
 * cuenta que debe ser un código compatible con el resto del programa. 
 * 
 * El programa está terminado a falta de la función "Leer", que se encarga de
 * crear y cargar los datos de una estructura como la presentada.
 *
 * Escriba la función que falta y someta todo el archivo multivector.cpp como 
 * solución al examen.
 *
*/


#include <iostream>
using namespace std;

struct MultiVector
{
    int nfilas;       // Número de filas de la estructura
    int *ncolumnas;   // Número de elementos de cada fila
    double **datos;   // Datos de la estructura
};

void Leer (MultiVector& mv){
	int filas, columnas, numero;
	cin >> filas;
	mv.nfilas=filas;
	mv.datos=new double*[mv.nfilas];
	mv.ncolumnas= new int[mv.nfilas];
	for(int i=0;i<mv.nfilas;++i){
		cin >> columnas;
		mv.ncolumnas[i]=columnas;
		mv.datos[i]=new double [columnas];
		for(int j=0;j<columnas;++j){
			cin >> numero;
			mv.datos[i][j]=numero;
		}
	}
	
}

void Escribir (const MultiVector& mv)
{
  cout << mv.nfilas << endl;
  for (int i=0; i<mv.nfilas; ++i) {
    cout << mv.ncolumnas[i]<< ' ';
    for (int j=0; j<mv.ncolumnas[i]; j++) {
      cout << mv.datos[i][j];
      if (j<mv.ncolumnas[i]-1) 
        cout << ' ';
    }
    cout << endl;
  }
}

void Sumas (const MultiVector& mv)
{
  double sumatotal= 0.0;;
  cout << "Las sumas por filas: ";
  for (int i=0;i<mv.nfilas;++i) {
    double suma= 0.0;
    for (int j=0;j<mv.ncolumnas[i]; j++) {
      suma+= mv.datos[i][j];
    }
    cout << suma << ' ';
    sumatotal+= suma;
  }
  cout << endl;
  cout << "La suma total es: " << sumatotal << endl;
}

void Destruir (MultiVector& mv)
{
  if (mv.nfilas>0) {
    for (int i=0; i<mv.nfilas; ++i)
      delete[] mv.datos[i];
    delete[] mv.datos;
    delete[] mv.ncolumnas;
  }
  mv.nfilas= 0;
  mv.ncolumnas= 0;
  mv.datos= 0;
}

int main()
{
  MultiVector mv;

  cout << "Introduzca la estructura:" << endl;
  Leer(mv);      // Lee desde cin, reservando memoria dinámica
  cout << "La estructura que ha introducido es:" << endl;
  Escribir(mv);
  cout << "El resultado de las sumas es el siguiente:" << endl;
  Sumas(mv);
  Destruir (mv); // Libera la memoria dinámica

  if (mv.nfilas!=0)
    cerr << "Algo va mal... el multivector no se ha quedado vacío" << endl;
}
