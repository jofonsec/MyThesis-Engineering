#include <vector>

#ifndef ESCENARIO_H
#define ESCENARIO_H


class escenario
{
    public:
        escenario(double minimo, double maximo, double radio, int nodos, int aleatorio, int NoAnclas); //constructor de la clase
    private:
        double DisReal[500][500];
        vector<double> anclas;
};

#endif // ESCENARIO_H
