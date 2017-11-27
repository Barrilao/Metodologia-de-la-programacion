#ifndef _PUNTO_
#define _PUNTO_

struct Punto {
    double x,y;
};

Punto LeerPunto();
void EscribirPunto (Punto p);
void InicializarPunto (Punto& p, double cx, double cy);
double GetX (Punto p);
double GetY (Punto p);
double Distancia (Punto p1, Punto p2);
Punto PuntoMedio (Punto p1, Punto p2);
Punto Menor (Punto p1, Punto p2);
Punto Mayor (Punto p1, Punto p2);

#endif
