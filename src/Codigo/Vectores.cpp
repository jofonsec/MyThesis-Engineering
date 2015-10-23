#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    vector<double> _Nodobaliza;
    double DisEstimada;

    double DisReal[8][8];

    for (int i=0; i < 8; i++){
        for (int j=0; j<8 ; j++){
            DisReal[i][j]=0;
        }
    }

    DisReal[0][1]=2.5;
    DisReal[0][2]=4.0;
    DisReal[0][6]=2.5;
    DisReal[0][7]=2.1;
    DisReal[1][2]=2.6;
    DisReal[2][3]=2.1;
    DisReal[2][4]=2.2;
    DisReal[3][4]=2.1;
    DisReal[3][5]=2.0;
    DisReal[4][5]=1.1;
    DisReal[6][7]=1.8;

    //Mostrar una matriz

    for (int i=0; i < 8; i++){
        cout << "|";
        for (int j=0; j<8 ; j++){
            cout << DisReal[i][j]<< "|";
        }
        cout << endl;
    }

    double prue[] = {1,1,1,1,8,2.7,9.5,4.2,7.5,4.8,8.5,6,4,5.5,2.5,4.5};
    _Nodobaliza.insert(_Nodobaliza.begin(), prue, prue+16);

    //Mostrar un vector
    for(int i=0; i < _Nodobaliza.size(); i++){
        cout << _Nodobaliza[i] << "|";
    }

    cout << endl;
    DisEstimada = sqrt(pow(3-5.5,2));

    cout << DisEstimada << endl;
return 0;
}
