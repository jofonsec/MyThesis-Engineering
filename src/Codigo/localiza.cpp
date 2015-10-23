#include <localizacionEval.h>
#include <vector>
using namespace std;

void localizacionEval::operator()(Individuo & _Individuo){

double fitness = 0.0, DisEstimada = 0.0;
vector<double> _NoAncla;
double DisReal[8][8];

//Iniciar los vectores de prueba
double noancla[]={4,3};
_NoAncla.insert(_NoAncla.begin(), noancla, noancla+2);

//Iniciar la Matriz de Distancias Reales
    for (int i=0; i < 8; i++){
        for (int j=0; j<8 ; j++){
            DisReal[i][j]=0; // Se genera una matriz con puros ceros para luego reemplazar los valores correspondientes
        }
    }
    DisReal[0][1]=2.5; DisReal[0][2]=4; DisReal[0][6]=2.5; DisReal[0][7]=2.1;
    DisReal[1][2]=2.6; DisReal[2][3]=2.1; DisReal[2][4]=2.2; DisReal[3][4]=2.1;
    DisReal[3][5]=2.0; DisReal[4][5]=1.5; DisReal[6][7]=1.8;

    for (int i= 0; i< _NoAncla.size()/2; i++){
        for (int j= 0; j < _Individuo1.size()/2; j++){
            if (DisReal[i][j] != 0){
                DisEstimada = sqrt(pow(_NoAncla[i*2] - _Individuo1[j*2],2) + pow(_NoAncla[i*2+1] - _Individuo1[j*2+1],2));
                fitness = abs (DisEstimada - DisReal[i][j]) + fitness;
            }
        }
    }

    for (int i= _NoAncla.size()/2; i<_Individuo1.size()/2;i++){
        for(int j=0; j< _Individuo1.size()/2; j++){
            if (DisReal[i][j] != 0){
                        DisEstimada = sqrt(pow(_Individuo1[i*2] - _Individuo1[j*2],2) + pow(_Individuo1[i*2+1] - _Individuo1[j*2+1],2));
                        fitness = abs(DisEstimada - DisReal[i][j]) + fitness;
            }
        }
    }

}
