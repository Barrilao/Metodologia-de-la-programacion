#include <iostream>
#include <cstring>
#include "matriz_operaciones.h"

using namespace std;

enum Operacion{
	AND,OR,NOT,TRS,DESCONOCIDO
};

Operacion Lectura(const char operacion[]){
	Operacion tipo=DESCONOCIDO;
	if (!strcmp(operacion,"AND"))
    		tipo = AND;
  	else if (!strcmp(operacion,"OR"))
    		tipo = OR;
  	else if (!strcmp(operacion,"NOT"))
    		tipo = NOT;
  	else if (!strcmp(operacion,"TRS"))
    		tipo = TRS;

  	return tipo;
}

int main(int argc, char* argv[]){
  	if (argc == 1){
    		cerr << "ERROR: Debe introducir la operación\n";
		return 1;
    	}
  	else{
    		Operacion oper =Lectura(argv[1]);
    		const bool ES_DESCONOCIDO = oper==DESCONOCIDO;

    		if (ES_DESCONOCIDO){
 			cerr << "ERROR: La operacion no es correcta\n";
        		return 2;
		}
    		else
    		{
      			const bool ES_NOT = oper==NOT;
      			const bool ES_TRS = oper==TRS;
      			MatrizBit m;
      			MatrizBit res;
			if (ES_NOT||ES_TRS){
        			if (argc == 2){
          				if(!Leer(cin, m)){
            					cerr << "ERROR: Fallo en la lectura\n";
            					return 4;
          				}
        			}
				else if (argc == 3){
          				if (!Leer(argv[2], m)){
            					cerr << "ERROR: Fallo en la lectura\n";
            					return 4;
          				}
        			}
				else{
          				cerr << "ERROR: Numero de argumentos incorrecto\n";
          				return 3;
        			}
				if (ES_NOT ? Inicializar(res, Filas(m), Columnas(m)):Inicializar(res, Columnas(m), Filas(m))){
          				ES_NOT ? Not(res, m) : Traspuesta(res, m);
          				cout << "\n";

          				if(!Escribir(cout, res)){
            					cerr << "ERROR: Hay un problema a la hora de escribir la matriz resultante\n";
            					return 5;
          				}
        			}

      			}
			else{
        			MatrizBit n;
        			if (argc == 2){
          				if(!(Leer(cin, m) && Leer(cin, n))){
            					cerr << "ERROR: Fallo en la lectura\n";
            					return 4;
          				}
        			}
        			else if (argc == 3){
          				if(!(Leer(argv[2], n) && Leer(cin, m))){
            					cerr << "ERROR: Fallo en la lectura\n";
            					return 4;
          				}
        			}
        			else if (argc == 4){
          				if(!(Leer(argv[2], m) && Leer(argv[3], n))){
            					cerr << "ERROR: Fallo en la lectura\n";
            					return 4;
          				}
        			}
        			else{
          				cerr << "ERROR: Numero de argumentos incorrecto\n";
          				return 3;
        			}
				const bool ES_OR = oper == OR;
        			if((Filas(m) == Filas(n)) && (Columnas(m) == Columnas(n))){
          				res = m;
          				ES_OR ? Or(res, m, n) : And(res, m, n);
          				cout << "\n";
					if (!Escribir(cout, res)){
            					cerr << "ERROR: Hay un problema a la hora de escribir la matriz resultante\n";
            					return 5;
					}
        			}
        			else{
          				cerr << "ERROR: Las dimensiones de las matrices no son las mismas\n";
          				return 6;
        			}
      			}
    		}
  	}
}
