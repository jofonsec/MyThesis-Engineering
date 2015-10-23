#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
double fitness = 0.0, DisEstimada = 0.0;
vector<double> _NoAncla;
vector<double> _Individuo1;
double DisReal[8][8];

//Iniciar los vectores de prueba
double noancla[]={4,3};
_NoAncla.insert(_NoAncla.begin(), noancla, noancla+2);

double individuo1[]={0.4621,0.3671,4.7405,0.903862,0.8937,0.831,4.37,4.4353,1.0068,4.1290,4.64026,0.652335,1.5552,1.8685,2.4977,0.9756};
_Individuo1.insert(_Individuo1.begin(), individuo1, individuo1+16);


//Iniciar la Matriz de Distancias Reales
    for (int i=0; i < 8; i++){
        for (int j=0; j<8 ; j++){
            DisReal[i][j]=0; // Se genera una matriz con puros ceros para luego reemplazar los valores correspondientes
        }
    }

    DisReal[0][1]=2.5; DisReal[0][2]=4; DisReal[0][6]=2.5; DisReal[0][7]=2.1;
    DisReal[1][2]=2.6; DisReal[2][3]=2.1; DisReal[2][4]=2.2; DisReal[3][4]=2.1;
    DisReal[3][5]=2.0; DisReal[4][5]=1.5; DisReal[6][7]=1.8;

cout << "Calculo del error entre nodos anclas y desconocidos"<< endl;

    for (int i= 0; i< _NoAncla.size()/2; i++){
        for (int j= 0; j < _Individuo1.size()/2; j++){
            if (DisReal[i][j] != 0){
                DisEstimada = sqrt(pow(_NoAncla[i*2] - _Individuo1[j*2],2) + pow(_NoAncla[i*2+1] - _Individuo1[j*2+1],2));
                cout << "Distancia estimada del nodo " << i+1 << "," << j+1 << " = "<<DisEstimada<< ", y la distancia real es: "<< DisReal[i][j]<<endl;
                fitness = abs (DisEstimada - DisReal[i][j]) + fitness;
            }
        }
    }

cout << "Calculo del error entre nodos desconocidos"<< endl;

    for (int i= _NoAncla.size()/2; i<_Individuo1.size()/2;i++){
        for(int j=0; j< _Individuo1.size()/2; j++){
            if (DisReal[i][j] != 0){
                        DisEstimada = sqrt(pow(_Individuo1[i*2] - _Individuo1[j*2],2) + pow(_Individuo1[i*2+1] - _Individuo1[j*2+1],2));
                        cout << "Distancia estimada del nodo " << i+1 << "," << j+1 << " = "<<DisEstimada<< ", y la distancia real es: "<< DisReal[i][j]<<endl;
                        fitness = abs(DisEstimada - DisReal[i][j]) + fitness;
            }
        }
    }
    cout << "Error total " << fitness;
}
