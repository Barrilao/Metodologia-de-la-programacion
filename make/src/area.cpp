#include "circulo.h"
#include "punto.h"
#include <iostream>

using namespace std;

int main()
{
   Circulo c;

   cout << "Introduzca un circulo en formato radio-(x,y): ";
   c= LeerCirculo();
   cout << "El area del circulo es: " << Area(c) << endl;

}
