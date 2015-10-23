#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

//Codigo para generar el escenario de prueba

int main() {
    double a=0.0, b=20.0; //listo
    double f, f1; //Dentro de cpp
    double distancia=0.0; //Dentro de cpp
    double radio=3.8; //listo
    int nodos = 100, nodosconectados=0, NoAnclas=20; //listo .h
    srand(81); //listo .cpp
    double DisReal[nodos][nodos]; //Creo que debe ir en el .h como private
    vector<double> xt, yt, mejor, anclas(NoAnclas); //listo .cpp, Creo que debe ir en el .h como private

    for (int i=0; i<nodos; i++){
        f = (double)rand() / RAND_MAX;
        f1 = (double)rand() / RAND_MAX;
        xt.push_back(a + f * (b-a));
        yt.push_back(a + f1 * (b-a));

        //cout << "xt [" << i <<"] es igual a: " << xt[i] << endl;
        //cout << "yt [" << i <<"] es igual a: " << yt[i] << endl;
    }

    // vector nodo anclas
    cout << anclas.size() << endl;
    int limite = anclas.size();
    for (unsigned i= 0 ; i < limite/2 ; i++){
        anclas[i*2] = xt[i];
        anclas[i*2+1] = yt[i];
        //anclas.insert(anclas.begin(), xt[i]);
        //anclas.insert(anclas.begin(), yt[i]);
    }
    cout << anclas.size() << endl;
        //Mostrar vector
    for (unsigned i=0 ; i < anclas.size()/2 ; i++){
        cout <<" Nodo " << i <<" : " << anclas[i*2] <<" y " << anclas[i*2+1] << endl;
    }
    cout << anclas.size() << endl;

    // Libreria fstream
    fstream dataarch;
    dataarch.open("estadistica.txt", ios::out);

    for(int i=0;i<nodos;i++){
    dataarch<<xt[i] <<"    " << yt[i]<< endl;
    }
    dataarch.close();


    // Generar matriz de distancia
        //Matrix of zeros
    for (int i=0; i<nodos; i++){
        for (int j=0; j<nodos ; j++){
        DisReal[i][j]=0;
        }
    }
        //Llenar con distancia real
    for (int i=0; i<nodos; i++){
        nodosconectados = 0; //reinicia
        for (int j=0; j<nodos ; j++){
            if(j>i){
                distancia = sqrt(pow(xt[i] - xt[j],2) + pow(yt[i] - yt[j],2));
                if (distancia < radio){
                    nodosconectados = nodosconectados + 1; //cuenta cuantos nodos tiene conectado
                    std::cout <<"distancia " << distancia << " vs " << radio << std::endl;
                    DisReal[i][j]= distancia;
                }
            }
        }
         mejor.push_back(nodosconectados);
    }
    std::cout <<"nodos conectados " << nodosconectados << std::endl;
    //Mostrar vector mejor
//    for (int i=0 ; i < 10 ; i++){
//        //if (mejor[i] > 3)
//        cout <<" Nodo " << i <<" tiene conectado: " <<mejor[i] << endl;
//    }

    //Mostrar matriz
    // Libreria fstream
    fstream dataMa;
    dataMa.open("matriz.txt", ios::out);

    for (int i=0; i < nodos; i++){
        for (int j=0; j < nodos ; j++){
            dataMa << DisReal[i][j] << "  ";
        }
        dataMa << endl;
    }
    dataMa.close();

//    double fRand(double fMin, double fMax)
//    {
//    double f = (double)rand() / RAND_MAX;
//    return fMin + f * (fMax - fMin);
//    }
}
