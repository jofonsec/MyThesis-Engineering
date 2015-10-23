#include <eo>
#include <escenario.h>
#include <boost/tuple/tuple.hpp>

#include "gnuplot-iostream.h"

int main (int argc, char* argv[]){

//Primero se debe definir un parser que lee desde la linea de comandos o un archivo
    eoParser parser(argc, argv);
//Se definen los parametros, se leen desde el parser y le asigna el valor
    //Datos necesarios del escenario de prueba
    double _min = parser.createParam((double)(0.0), "ValorMinimo", "Delimitacion area de trabajo",'M',"Parametros Escenario").value();
    double _max = parser.createParam((double)(20.0), "ValorMaximo", "Delimitacion area de trabajo",'S',"Parametros Escenario").value();
    unsigned int NoAnclas = parser.createParam((unsigned int)(10), "Anclas", "Numero de nodos anclas",'A',"Parametros Escenario").value();
    unsigned int nodos = parser.createParam((unsigned int)(100), "Nodos", "Total de nodos",'N',"Parametros Escenario").value();
    double radio = parser.createParam((double)(5), "Radio", "Radio de comunicacion",'R',"Parametros Escenario").value();
    unsigned int semilla = parser.createParam((unsigned int)(84), "Semilla", "Semilla para escenarios aleatorios",'E',"Parametros Escenario").value();

    int unknow=nodos-NoAnclas;
    double DisReal[nodos][nodos];
    double vecAnclas[NoAnclas*2];

//Termina la ejecucion al consultar la ayuda
    if (parser.userNeedsHelp())
         {
             parser.printHelp(std::cout);
             exit(1);
         }

/**GENERACIÓN DEL ESCENARIO**/
//Escenario
    //Genera de forma aleatoria
    escenario *pEscenario = new escenario(_min, _max, radio, nodos, semilla, NoAnclas);
    //Posicion Nodos anclas
    pEscenario->guardarAnclas();
    //Guardar las posiciones de todos los nodos
    pEscenario->guardarNodos();
    //Matriz de distancia RSSI
    pEscenario->guardarDisRSSI();
    //Matriz de distancia Real
    pEscenario->guardarDisReal();
/**--------------------------------------------------------------**/

/**GRAFICAR EL ESCENARIO**/
    Gnuplot gp;
    double unknowX[nodos],unknowY[nodos];
    std::vector<std::pair<double, double> > xy_pts_anclas;
    std::vector<std::pair<double, double> > xy_pts_unknow;

    //Cargar valores
    //Posicion de todos los nodos
    for (int i=0 ; i<nodos ; i++){
        unknowX[i] = pEscenario->obtenerPX(i);
        unknowY[i] = pEscenario->obtenerPY(i);
    }

    //Posicion de nodos anclas
    for(int i=0; i<NoAnclas; i++) xy_pts_anclas.push_back(std::make_pair(unknowX[i], unknowY[i]));
    //Posicion de nodos desconocidos
	for(int i=NoAnclas; i<nodos; i++) xy_pts_unknow.push_back(std::make_pair(unknowX[i], unknowY[i]));

    gp << "set yrange [0:"<<_max+4<<"]\n";
    //gp << "set autoscale\n";
    gp << "set title 'Escenario' font 'Bookman,20'\n";
    gp << "set encoding iso_8859_1\n"; //Define los acentos para postscript
    gp << "set grid\n";
    gp << "set xlabel 'metros'\n";
    gp << "set ylabel 'metros'\n";
    gp << "set key font 'Helvetica,18'\n";//Modifica la leyenda
    gp << "set terminal postscript enhanced color font 'Helvetica,15'\n";//Cambia de terminal
    gp << "set output '| ps2pdf - Escenario.pdf'\n";//guarda en pdf
    gp << "set style line 1 lc rgb '#00DD00' pt 7 ps 1.5 \n";
    gp << "set style line 2 lc rgb 'blue' pt 6 ps 1.5 \n";
    gp << "plot '-' with points ls 1 title 'Nodos Anclas',"
       << "'-' with points ls 2 title 'Posición Real'\n";

    gp.send1d(xy_pts_anclas);
    gp.send1d(xy_pts_unknow);

  return EXIT_SUCCESS;
}
