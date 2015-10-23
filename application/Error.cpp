#include <eo>
#include <graphError.h>

int main (int argc, char* argv[]){
//Primero se debe definir un parser que lee desde la linea de comandos o un archivo
    eoParser parser(argc, argv);
//Se definen los parametros, se leen desde el parser y le asigna el valor
    //Datos necesarios para generar la grafica de Error
    std::string filename = parser.createParam(std::string("generacion"), "filename", "Ingresar el nombre general del archivo .sav",'o',"Graficar Error").value();
    double max = parser.createParam((double)(20.0), "ValorMaximo", "Delimitacion del area de trabajo",'S',"Graficar Error").value();
    unsigned int noAnclas = parser.createParam((unsigned int)(10), "Anclas", "Numero de nodos anclas",'A',"Graficar Error").value();
    unsigned int nodos = parser.createParam((unsigned int)(100), "Nodos", "Total de nodos",'N',"Graficar Error").value();
    unsigned int setGeneracion = parser.createParam((unsigned int)(100), "setGeneracion", "Cada cuantas generaciones se guardo la poblacion",'T',"Graficar Error").value();
    unsigned int numberGeneration = parser.createParam((unsigned int)(1000), "MaxGen", "Numero maximo de generaciones",'G',"Graficar Error").value();

    graphError error(filename, setGeneracion, numberGeneration, nodos, noAnclas, max);

  return EXIT_SUCCESS;
}
