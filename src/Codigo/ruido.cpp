//g++ -std=c++11 -o ruido ruido.cpp
//sed -i "1,2d" *.sav
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <random>

int main() {
    std::mt19937 generador;
    std::normal_distribution<double> normal(0,1);
    double DisReal[100][100];
    double DisRSSI[100][100];
    double anclas[20];
    int nodos=100;
    int NoAnclas=10;

    //Obtener anclas desde archivo txt
    std::ifstream fin;
    fin.open("Anclas.txt");

    if(!fin.is_open()){
        std::cout << "Error mientras se intentaba leer el archivo "<< "Anclas.txt" << ". Por favor verificar que exista!" << std::endl;
        exit(1);
    }
    else {
        for (int i =0 ; i < NoAnclas; i++)
            fin >> anclas[i*2] >> anclas[i*2+1];
    fin.close();
    }

    //Obtener matriz de distancia desde txt
    fin.open("Matriz.txt");

    if(!fin.is_open()){
        std::cout << "Error mientras se intentaba leer el archivo "<< "Matriz.txt" << ". Por favor verificar que exista!" << std::endl;
        exit(1);
    }
    else {
        for (int i = 0 ; i < nodos; i++){
            for(int j = 0; j < nodos; j++)
            fin >> DisReal[i][j];
        }
    fin.close();
    }

    for (int i=0; i<nodos; i++){
        for (int j=0; j<nodos ; j++){
            //Aplicar ruido gaussiano a las distancias
            DisRSSI[i][j]= 0;
        }
    }

    for (int i=0; i<nodos; i++){
        for (int j=NoAnclas; j<nodos ; j++){
            //Aplicar ruido gaussiano a las distancias
            DisRSSI[i][j]= DisReal[i][j]*(1.0+0.1*normal(generador));
        }
    }

    std::fstream dataMa;
    dataMa.open("MatrizOfCopy.txt", std::ios::out);

    for (int i=0; i < nodos; i++){
        for (int j=0; j < nodos ; j++){
            dataMa << DisRSSI[i][j] << "  ";
        }
        dataMa << std::endl;
    }
    dataMa.close();
}
