#include <iostream> //para utilizar cout cin
#include <vector> //trabajar con vectores
#include <math.h> // funciones matematicas
#include <stdlib.h> //libreria estandar
#include <time.h> //numeros aleatorios
#include <fstream> //trabajar con archivos

using namespace std;

int main() {
    double _min=0.0, _max=20.0;// Dato private
    int t=1000; //generación actual, Dato private
    int T=1000; //total de generaciones, es fijo, Dato private
    int noAnclas=2;// Dato private
    int nodos=10; //Total de nodos, es fijo, Dato private
    double s = pow(_max-_min, 2); //Calculo del area de trabajo, es fijo
    double idealDistance = sqrt(s/nodos); // es la distancia ideal, es fijo
    double r; //Es el radio aproximado, se calcula por generacion
    double f, theta=0;

    double x[20] = {0.184942, 16.0967, 16.1406, 11.1411, 15.3417, 1.33183, 18.9813, 14.9858, 2.68624, 14.7337, 16.2609, 19.3292, 15.2098, 18.197, 9.68169, 6.8862, 11.3004, 6.95822, 12.3374, 11.984};
    double x_m[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    r = idealDistance * (1-(t/T));

    for(int i=noAnclas; i<nodos; i++){
        //generar numeros aleatorios
        f = (double)rand() / RAND_MAX;
        theta = 0 + f * (360-0);

        x_m[i*2] = x[i*2] + r * cos(theta);
        x_m[i*2+1] = x[i*2+1] + r * sin(theta);
    }

    std::cout<< "vector original " << std::endl;
    //motras vector
    for (int i=0; i<nodos*2; i++){
        std::cout << " " << x[i] ;
    }
    std::cout << std::endl;
    std::cout<< "vector mutado " << std::endl;
    //motras vector
    for (int i=0; i<nodos*2; i++){
        std::cout << " " << x_m[i] ;
    }


}
