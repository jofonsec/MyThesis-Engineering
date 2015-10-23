#include "escenario.h"

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

escenario::escenario()
{
    //ctor
    _aleatorio = aleatorio; //Define la semilla para los numeros aleatorios ejemplo srand(81)
    _nodos = nodos; //Total de nodos, Se encuentra delimitado por un total de 500 nodos
    _minimo = minimo; // Dimension minima del espacio
    _maximo = maximo; // Dimension maxima del espacio
    _radio = radio; // Radio de comunicación
    _NoAnclas = NoAnclas; // Total nodos anclas
    double f=0.0, f1=0.0;
    double distancia=0.0;
    vector<double> xt, yt, anclas(_NoAnclas*2);
    srand(_aleatorio);

    //Generar las coordenadas de forma aleatoria
    for (int i=0; i<_nodos; i++){
        f = (double)rand() / RAND_MAX;
        f1 = (double)rand() / RAND_MAX;
        xt.push_back(_minimo + f * (_maximo-_minimo));
        yt.push_back(_minimo + f1 * (_maximo-_minimo));
    }

    //Generar vector de coordenadas nodos anclas
    for (int i=0 ; i < anclas.size()/2 ; i++){
        anclas[i*2] = xt [i];
        anclas[i*2+1] = yt[i];
    }

    //Matrix of zeros
    for (int i=0; i<_nodos; i++){
        for (int j=0; j<_nodos ; j++){
        DisReal[i][j]=0;
        }
    }

    //Llenar con distancia real
    for (int i=0; i<_nodos; i++){
        for (int j=0; j<_nodos ; j++){
            if(j>i){
                distancia = sqrt(pow(xt[i] - xt[j],2) + pow(yt[i] - yt[j],2));
                if (distancia < _radio)
                    DisReal[i][j]= distancia;
            }
        }
    }
}
