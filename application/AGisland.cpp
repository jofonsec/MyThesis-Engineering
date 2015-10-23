#include <smp>
#include <eo>
#include <Individuo.h>
#include <IndiInit.h>
#include <localizacionEval.h>
#include <localizacionEvalPenal.h>
#include <individuoCruza.h>
#include <individuoCruza1.h>
#include <individuoCruza2.h>
#include <individuoMutacion1.h>
#include <individuoMutacion.h>
#include <escenario.h>
#include <sys/time.h>

#include <GnuplotMonitor.h>

using namespace paradiseo::smp;


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

    double DisReal[200][200];
    double vecAnclas[NoAnclas*2];

//Configuracion parametros algoritmo
    unsigned int POP_SizeIsla1 = parser.createParam((unsigned int)(100), "PopSizeIsla1", "Tamano de la poblacion de la isla 1",'P',"Parametros Algoritmo").value();
    unsigned int POP_SizeIsla2 = parser.createParam((unsigned int)(100), "PopSizeIsla2", "Tamano de la poblacion de la isla 2",'D',"Parametros Algoritmo").value();
    unsigned int POP_SizeIsla3 = parser.createParam((unsigned int)(100), "PopSizeIsla3", "Tamano de la poblacion de la isla 3",'F',"Parametros Algoritmo").value();
    unsigned int POP_SizeIsla4 = parser.createParam((unsigned int)(100), "PopSizeIsla4", "Tamano de la poblacion de la isla 4",'G',"Parametros Algoritmo").value();
    unsigned int numberGeneration = parser.createParam((unsigned int)(5000), "MaxGen", "Criterio de parada, Numero maximo de generaciones",'m',"Parametros Algoritmo").value();
    unsigned int Nc = parser.createParam((unsigned int)(2), "Nc", "Constante del operador SBX",'C',"Parametros Algoritmo").value();
    double Pcruza = parser.createParam((double)(0.87), "Pcruza", "Probabilidad de cruzamiento SBX",'X',"Parametros Algoritmo").value();
    double Pmutation = parser.createParam((double)(0.85), "Pmutacion", "Probabilidad de mutacion de la encapsulacion de SVN y Swap",'Y',"Parametros Algoritmo").value();
    double Pmutation1 = parser.createParam((double)(0.85), "Pmutacion1", "Probabilidad de mutacion de SVN",'Z',"Parametros Algoritmo").value();
    double Pmutation2 = parser.createParam((double)(0.5), "Pmutacion2", "Probabilidad de mutacion de Swap",'W',"Parametros Algoritmo").value();
    double sizeTorneo = parser.createParam((double)(8), "SizeTorneo", "Tamano del torneo para seleccion de individuos",'L',"Parametros Algoritmo").value();
    double sizeElist = parser.createParam((double)(2), "SizeElist", "Cantidad de individuos que se conservan",'B',"Parametros Algoritmo").value();
    double sizeTorneo1 = parser.createParam((double)(2), "SizeTorneo1", "Tamano del torneo para seleccion de individuos del elitismo",'Q',"Parametros Algoritmo").value();

//Politicas de migracion
    unsigned int Intercambio1 = parser.createParam((unsigned int)(1000), "Intercambio1", "Define cada cuantas generaciones migran individuos de la isla 1",'1',"Politicas de Migracion").value();
    unsigned int Intercambio2 = parser.createParam((unsigned int)(1000), "Intercambio2", "Define cada cuantas generaciones migran individuos de la isla 2",'2',"Politicas de Migracion").value();
    unsigned int Intercambio3 = parser.createParam((unsigned int)(1000), "Intercambio3", "Define cada cuantas generaciones migran individuos de la isla 3",'3',"Politicas de Migracion").value();
    unsigned int Intercambio4 = parser.createParam((unsigned int)(1000), "Intercambio4", "Define cada cuantas generaciones migran individuos de la isla 4",'4',"Politicas de Migracion").value();
    unsigned int torneoIsla = parser.createParam((unsigned int)(20), "torneoIsla", "Tamano del torneo para seleccionar los individuos a migrar",'5',"Politicas de Migracion").value();
    unsigned int selecIsla = parser.createParam((unsigned int)(3), "selecIsla", "Cantidad de individuos seleccionados en el torneo",'6',"Politicas de Migracion").value();

//Parametros de guardado
    unsigned int setGeneracion = parser.createParam((unsigned int)(100), "setGeneracion", "Cada cuantas generaciones se guarda la poblacion",'T',"Guardar Datos").value();
    unsigned int setTime = parser.createParam((unsigned int)(0), "setTime", "Cada cuantos segundos se guarda la configuracion",'I',"Guardar Datos").value();

//Grafica
    std::string InPut = parser.createParam(std::string("Estadistica.txt"), "Input", "Archivo que contiene el Fitness, Media, DevStand",'o',"Salida - Grafica").value();
    bool graficaGnuplot = parser.createParam((bool)(0), "Gnuplot", "Grafica el Fitness y Media, 0 desactivado y 1 activado",'g',"Salida - Grafica").value();
    bool grafIsla = parser.createParam((bool)(1), "grafIslas", "Grafica el Fitness de cada isla",'i',"Salida - Grafica").value();

//Termina la ejecucion al consultar la ayuda
    if (parser.userNeedsHelp())
         {
             parser.printHelp(std::cout);
             exit(1);
         }
//Verifica el ingreso de las probabilidades
    if ( (Pcruza < 0) || (Pcruza > 1) ) throw std::runtime_error("Pcruza Invalido");
    if ( (Pmutation < 0) || (Pmutation > 1) ) throw std::runtime_error("Pmutation encapsulación Invalido");
    if ( (Pmutation1 < 0) || (Pmutation1 > 1) ) throw std::runtime_error("Pmutation de SVN Invalido");
    if ( (Pmutation2 < 0) || (Pmutation2 > 1) ) throw std::runtime_error("Pmutation de Swap Invalido");

//Parametro de tiempo
    struct timeval ti, tf;
    double tiempo;

/**CARGAR EL ESCENARIO**/
//Escenario
    //Lee desde archivo
    escenario *pEscenario = new escenario(nodos, NoAnclas);
    //Matriz de distancia
    for (int i=0; i<nodos ; i++)
        {for (int j=0; j<nodos; j++)DisReal[i][j] = pEscenario->obtenerDisRSSI(i,j);}
    //Posicion Nodos anclas
    for (int i=0 ; i<NoAnclas*2 ; i++)vecAnclas[i] = pEscenario->obtenerAnclas(i);

/**--------------------------------------------------------------**/

/**Partes comunes de todas las islas**/

//Define la representación (Individuo)
    Individuo cromosoma;

//Para la inicialización del cromosoma, primero se debe definir como se generaran los genes
//Se utilizara un generador uniforme, (valor min, valor max)
    eoUniformGenerator<double> uGen(_min, _max);

//Crear el inicializador para los cromosomas, llamado random
    IndiInit random(nodos*2,uGen);

//Generar una subclase de la clase de la función de evaluación
    localizacionEvalPenal Fitness;

//Es otro criterio de parada en el cual se define el minimo de generaciones y cuantas generaciones sin mejoras
    //eoSteadyFitContinue<Individuo> parada(10,2);

/*CRUZA*/
    // Generar los limites para cada gen
    std::vector<double> min_b;
    std::vector<double> max_b;
    for(int i=0; i<nodos*2; i++) {
            min_b.push_back(_min);
            max_b.push_back(_max);
        }
    eoRealVectorBounds bounds(min_b, max_b);

    //Inicializar operador de cruce SBX
    individuoCruza crossover(bounds, Nc);

    //Cargar cantidad nodos anclas al operador
    crossover.setNoAnclas(NoAnclas);

/*MUTACION*/
    //Subclase de mutacion paper IEEE
    individuoMutacion mutationA(NoAnclas,numberGeneration,nodos,_min,_max);

    //Mutacion incluida en EO, permite llegar mas rapido a un fitness de 600
    individuoMutacion0 mutationB;

    //Combina operadores de mutacion con su respectivo peso
    eoPropCombinedMonOp<Individuo> mutation(mutationA, Pmutation1);
    mutation.add(mutationB, Pmutation2);

//Define un objeto de encapsulación (it contains, the crossover, the crossover rate, the mutation and the mutation rate) -> 1 line
    eoSGATransform<Individuo> encapsulacion(crossover, Pcruza, mutation, Pmutation); //0.87

//Define el método de selección, selecciona un individuo por cada torneo (en el parentesis se define el tamaño del torneo)
    eoDetTournamentSelect<Individuo> torneo(sizeTorneo);

//Define un "eoSelectPerc" con el torneo como parametro por defecto (permite seleccionar el mejor individuo)
    eoSelectPerc<Individuo> seleccion(torneo);

//Define una estrategia de reemplazo por cada generación
    //eoGenerationalReplacement<Individuo> reemplazo;

////Otra estrategia de reemplazo con elitismo
    eoElitism<Individuo> reemplazo(sizeElist,false); //antes 0.6

   //Para utilizar eoElitism se define un eoDetTournamentTruncate para seleccionar los individuos para el elitismo
        eoDetTournamentTruncate<Individuo> Trunca(sizeTorneo1);// antes 2

/*CARGA DATOS A FITNESS*/
//Cargar la matriz de distancias, cantidad nodos anclas y total de nodos
    Fitness.guardarDisReal(DisReal, NoAnclas, nodos, radio);

//Cargar posiciones nodos anclas
    Fitness.guardarAnclas(vecAnclas);

/**--------------------------------------------**/

/**Isla 1**/

//Define un objeto de encapsulación (it contains, the crossover, the crossover rate, the mutation and the mutation rate) -> 1 line
    //eoSGATransform<Individuo> encapsulacion1(crossover, 0.9, mutation, 0.1); //0.87

//Criterio de parada
    eoGenContinue<Individuo> parada1(numberGeneration);

//Contenedor de clases
    eoCheckPoint<Individuo> PuntoChequeo1(parada1);

//Define una poblacion de Individuos
    eoPop<Individuo> poblacion1;

//Llena la población y evalua cada cromosoma
    for(int i=0 ; i<POP_SizeIsla1 ; i++)
    {
        random(cromosoma);
        Fitness(cromosoma);
        poblacion1.push_back(cromosoma);
    }

/*POLITICAS DE MIGRACION*/
//Debe enviar a los individuos cada cien generaciones
eoPeriodicContinue<Individuo> criterio(Intercambio1);//100000
//Es un torneo entre 20 individuos
eoDetTournamentSelect<Individuo> selectOne1(torneoIsla); //20
//Selecciona 3 individuos usando el torneo determinista
eoSelectNumber<Individuo> who(selectOne1, selecIsla); //3

//La clase politicas de trabajo
MigPolicy<Individuo> migPolicy;
//Define las politicas especificadas
migPolicy.push_back(PolicyElement<Individuo>(who,criterio));

/*POLITICAS DE INTEGRACION*/
//Es una estrategia de reemplazo
eoPlusReplacement<Individuo> intPolicy;

/**Contador de generacion**/
//Cargar el valor de la generacion actual al operador de mutación
    //Se inicializa el contador de generaciones
    eoIncrementorParam<unsigned> generationCounter1("Gen.");
    //Se carga el contador de generaciones al operador de mutación
    mutationA.setGen(& generationCounter1);
/**--------------------------------------------**/


/** Guardar datos de la población en archivos **/
    //Se carga el contador de generaciones al objeto eoCheckpoint para contar el número de generaciones
    PuntoChequeo1.add(generationCounter1);
    //Genera un archivo para guardar parametros
    eoState estado1;
    //Guardar todo lo que necesites a la clase hija estado
    estado1.registerObject(poblacion1);
    //estado1.registerObject(parser);
    //Guarda el tiempo de ejecucion desde la primera generacion
    eoTimeCounter time1;
    PuntoChequeo1.add(time1);
    //Define cada cuantas generaciones se guarda la poblacion
    eoCountedStateSaver GuardarEstado1(setGeneracion,estado1,"IslaOne-Generation");
    //Siempre se debe agregar a la clase hija de eoCheckPoint para que se ejecute en cada generacion
    PuntoChequeo1.add(GuardarEstado1);

/**DATOS ESTADISTICOS**/
//Muestra el mejor fitness de cada generación
    eoBestFitnessStat<Individuo> Elmejor1("Mejor Fitness");
    //La media (average) y stdev (standard deviation)
    eoSecondMomentStats<Individuo> SegundoStat1("Average & Stdev");
    //Se agrega al eoCheckPoint
    PuntoChequeo1.add(Elmejor1);
    PuntoChequeo1.add(SegundoStat1);
    // Guarda los parametros a un archivo
    eoFileMonitor fileMonitor1("Resumen1.xg", " ");
    PuntoChequeo1.add(fileMonitor1);
    fileMonitor1.add(time1);
    fileMonitor1.add(Elmejor1);           //Mejor fitness
    fileMonitor1.add(SegundoStat1);       //Media y desviacion estandar

//Inicializacion Isla 1
Island<eoEasyEA,Individuo> island1(poblacion1, intPolicy, migPolicy, PuntoChequeo1, Fitness, seleccion, encapsulacion, reemplazo, Trunca);

/**--------------------------------------------**/

/**Isla 2**/

//Define un objeto de encapsulación (it contains, the crossover, the crossover rate, the mutation and the mutation rate) -> 1 line
    //eoSGATransform<Individuo> encapsulacion2(crossover, 0.1, mutation, 0.9); //0.87

//Criterio de parada
    eoGenContinue<Individuo> parada2(numberGeneration);
//Contenedor de clases
    eoCheckPoint<Individuo> PuntoChequeo2(parada2);

//Define una poblacion de Individuos
    eoPop<Individuo> poblacion2;

//Llena la población y evalua cada cromosoma
    for(int i=0 ; i<100 ; i++)
    {
        random(cromosoma);
        Fitness(cromosoma);
        poblacion2.push_back(cromosoma);
    }

/*POLITICAS DE MIGRACION*/
//Debe enviar a los individuos cada cien generaciones
eoPeriodicContinue<Individuo> criterio2(Intercambio2);//1000
//Es un torneo entre 20 individuos
eoDetTournamentSelect<Individuo> selectOne2(torneoIsla);
//Selecciona 3 individuos usando el torneo determinista
eoSelectNumber<Individuo> who2(selectOne2, selecIsla);


//La clase politicas de trabajo
MigPolicy<Individuo> migPolicy2;
//Define las politicas especificadas
migPolicy2.push_back(PolicyElement<Individuo>(who2,criterio2));

/*POLITICAS DE INTEGRACION*/
//Es una estrategia de reemplazo
eoPlusReplacement<Individuo> intPolicy2;

/**Contador de generacion**/
//Cargar el valor de la generacion actual al operador de mutación
    //Se inicializa el contador de generaciones
    eoIncrementorParam<unsigned> generationCounter2("Gen.");
/**--------------------------------------------**/


/** Guardar datos de la población en archivos **/
    //Se carga el contador de generaciones al objeto eoCheckpoint para contar el número de generaciones
    PuntoChequeo2.add(generationCounter2);
    //Genera un archivo para guardar parametros
    eoState estado2;
    //Guardar todo lo que necesites a la clase hija estado
    estado2.registerObject(poblacion2);
    //Guarda el tiempo de ejecucion desde la primera generacion
    eoTimeCounter time2;
    PuntoChequeo2.add(time2);
    //Define cada cuantas generaciones se guarda la poblacion
    eoCountedStateSaver GuardarEstado2(setGeneracion,estado2,"IslaTwo-Generation");
    //Siempre se debe agregar a la clase hija de eoCheckPoint para que se ejecute en cada generacion
    PuntoChequeo2.add(GuardarEstado2);

/**DATOS ESTADISTICOS**/
//Muestra el mejor fitness de cada generación
    eoBestFitnessStat<Individuo> Elmejor2("Mejor Fitness");
    //La media (average) y stdev (standard deviation)
    eoSecondMomentStats<Individuo> SegundoStat2("Average & Stdev");
    //Se agrega al eoCheckPoint
    PuntoChequeo2.add(Elmejor2);
    PuntoChequeo2.add(SegundoStat2);
    // Guarda los parametros a un archivo
    eoFileMonitor fileMonitor2("Resumen2.xg", " ");
    PuntoChequeo2.add(fileMonitor2);
    fileMonitor2.add(time2);
    fileMonitor2.add(Elmejor2);           //Mejor fitness
    fileMonitor2.add(SegundoStat2);       //Media y desviacion estandar

//Inicializacion Isla 2
Island<eoEasyEA,Individuo> island2(poblacion2, intPolicy2, migPolicy2, PuntoChequeo2, Fitness, seleccion, encapsulacion, reemplazo, Trunca);

/**----------------------------------------------**/

/**Isla 3**/

//Criterio de parada
    eoGenContinue<Individuo> parada3(numberGeneration);
//Contenedor de clases
    eoCheckPoint<Individuo> PuntoChequeo3(parada3);

//Define una poblacion de Individuos
    eoPop<Individuo> poblacion3;

//Llena la población y evalua cada cromosoma
    for(int i=0 ; i<100 ; i++)
    {
        random(cromosoma);
        Fitness(cromosoma);
        poblacion3.push_back(cromosoma);
    }

/*POLITICAS DE MIGRACION*/
//Debe enviar a los individuos cada cien generaciones
eoPeriodicContinue<Individuo> criterio3(Intercambio3);
//Es un torneo entre 20 individuos
eoDetTournamentSelect<Individuo> selectOne3(torneoIsla);
//Selecciona 3 individuos usando el torneo determinista
eoSelectNumber<Individuo> who3(selectOne3,selecIsla);

//La clase politicas de trabajo
MigPolicy<Individuo> migPolicy3;
//Define las politicas especificadas
migPolicy3.push_back(PolicyElement<Individuo>(who3,criterio3));

/*POLITICAS DE INTEGRACION*/
//Es una estrategia de reemplazo
eoPlusReplacement<Individuo> intPolicy3;

/**Contador de generacion**/
//Cargar el valor de la generacion actual al operador de mutación
    //Se inicializa el contador de generaciones
    eoIncrementorParam<unsigned> generationCounter3("Gen.");
/**--------------------------------------------**/


/** Guardar datos de la población en archivos **/
    //Se carga el contador de generaciones al objeto eoCheckpoint para contar el número de generaciones
    PuntoChequeo3.add(generationCounter3);
    //Genera un archivo para guardar parametros
    eoState estado3;
    //Guardar todo lo que necesites a la clase hija estado
    estado3.registerObject(poblacion3);
    //Guarda el tiempo de ejecucion desde la primera generacion
    eoTimeCounter time3;
    PuntoChequeo3.add(time3);
    //Define cada cuantas generaciones se guarda la poblacion
    eoCountedStateSaver GuardarEstado3(setGeneracion,estado3,"IslaThree-Generation");
    //Siempre se debe agregar a la clase hija de eoCheckPoint para que se ejecute en cada generacion
    PuntoChequeo3.add(GuardarEstado3);

/**DATOS ESTADISTICOS**/
//Muestra el mejor fitness de cada generación
    eoBestFitnessStat<Individuo> Elmejor3("Mejor Fitness");
    //La media (average) y stdev (standard deviation)
    eoSecondMomentStats<Individuo> SegundoStat3("Average & Stdev");
    //Se agrega al eoCheckPoint
    PuntoChequeo3.add(Elmejor3);
    PuntoChequeo3.add(SegundoStat3);
    // Guarda los parametros a un archivo
    eoFileMonitor fileMonitor3("Resumen3.xg", " ");
    PuntoChequeo3.add(fileMonitor3);
    fileMonitor3.add(time3);
    fileMonitor3.add(Elmejor3);           //Mejor fitness
    fileMonitor3.add(SegundoStat3);       //Media y desviacion estandar

//Inicializacion Isla 3
Island<eoEasyEA,Individuo> island3(poblacion3, intPolicy3, migPolicy3, PuntoChequeo3, Fitness, seleccion, encapsulacion, reemplazo, Trunca);

/**----------------------------------------------**/

/**Isla 4**/

//Define un objeto de encapsulación (it contains, the crossover, the crossover rate, the mutation and the mutation rate) -> 1 line
    //eoSGATransform<Individuo> encapsulacion3(crossover, 0.1, mutation, 0.1); //0.87


//Criterio de parada
    eoGenContinue<Individuo> parada4(numberGeneration);
//Contenedor de clases
    eoCheckPoint<Individuo> PuntoChequeo4(parada4);

//Define una poblacion de Individuos
    eoPop<Individuo> poblacion4;

//Llena la población y evalua cada cromosoma
    for(int i=0 ; i<100 ; i++)
    {
        random(cromosoma);
        Fitness(cromosoma);
        poblacion4.push_back(cromosoma);
    }

/*POLITICAS DE MIGRACION*/
//Debe enviar a los individuos cada cien generaciones
eoPeriodicContinue<Individuo> criterio4(Intercambio4);
//Es un torneo entre 20 individuos
eoDetTournamentSelect<Individuo> selectOne4(torneoIsla);
//Selecciona 3 individuos usando el torneo determinista
eoSelectNumber<Individuo> who4(selectOne4,selecIsla);

//La clase politicas de trabajo
MigPolicy<Individuo> migPolicy4;
//Define las politicas especificadas
migPolicy4.push_back(PolicyElement<Individuo>(who4,criterio4));

/*POLITICAS DE INTEGRACION*/
//Es una estrategia de reemplazo
eoPlusReplacement<Individuo> intPolicy4;

/**Contador de generacion**/
//Cargar el valor de la generacion actual al operador de mutación
    //Se inicializa el contador de generaciones
    eoIncrementorParam<unsigned> generationCounter4("Gen.");
/**--------------------------------------------**/


/** Guardar datos de la población en archivos **/
    //Se carga el contador de generaciones al objeto eoCheckpoint para contar el número de generaciones
    PuntoChequeo4.add(generationCounter4);
    //Genera un archivo para guardar parametros
    eoState estado4;
    //Guardar todo lo que necesites a la clase hija estado
    estado4.registerObject(poblacion4);
    //Guarda el tiempo de ejecucion desde la primera generacion
    eoTimeCounter time4;
    PuntoChequeo4.add(time4);
    //Define cada cuantas generaciones se guarda la poblacion
    eoCountedStateSaver GuardarEstado4(setGeneracion,estado4,"IslaFour-Generation");
    //Siempre se debe agregar a la clase hija de eoCheckPoint para que se ejecute en cada generacion
    PuntoChequeo4.add(GuardarEstado4);

/**DATOS ESTADISTICOS**/
//Muestra el mejor fitness de cada generación
    eoBestFitnessStat<Individuo> Elmejor4("Mejor Fitness");
    //La media (average) y stdev (standard deviation)
    eoSecondMomentStats<Individuo> SegundoStat4("Average & Stdev");
    //Se agrega al eoCheckPoint
    PuntoChequeo4.add(Elmejor4);
    PuntoChequeo4.add(SegundoStat4);
    // Guarda los parametros a un archivo
    eoFileMonitor fileMonitor4("Resumen4.xg", " ");
    PuntoChequeo4.add(fileMonitor4);
    fileMonitor4.add(time4);
    fileMonitor4.add(Elmejor4);           //Mejor fitness
    fileMonitor4.add(SegundoStat4);       //Media y desviacion estandar

//Inicializacion Isla 4
Island<eoEasyEA,Individuo> island4(poblacion4, intPolicy4, migPolicy4, PuntoChequeo4, Fitness, seleccion, encapsulacion, reemplazo, Trunca);

/**----------------------------------------------**/

///** Grafica **/
//    GnuplotMonitor grafica(InPut,graficaGnuplot,grafIsla);       //Grafica el fitness y la media
//    grafica.setGen(& generationCounter1); //Carga la generacion
//    PuntoChequeo1.add(grafica);
///**------------------------------------------**/


/**Topologia**/
//Define la topologia
Topology<Ring> topo;
//Inicia el algoritmo con la topologia definida
IslandModel<Individuo> model(topo);
/**--------------------------------------------**/

//Carga las islas
    model.add(island1);
    model.add(island2);
    model.add(island3);
    model.add(island4);

//Tiempo inicial
    gettimeofday(&ti, NULL);

//Corre el algoritmo de islas homogeneas
    model();

//Tiempo Final
    gettimeofday(&tf, NULL);

//Imprime el mejor cromosoma de cada poblacion
    std::cout << std::endl;
    poblacion1.best_element().printOn(std::cout);
    std::cout << std::endl;
    std::cout << std::endl;
    poblacion2.best_element().printOn(std::cout);
    std::cout << std::endl;
    std::cout << std::endl;
    poblacion3.best_element().printOn(std::cout);
    std::cout << std::endl;
    std::cout << std::endl;
    poblacion4.best_element().printOn(std::cout);
    std::cout << std::endl;
    std::cout << std::endl;

//Imprime el tiempo de ejecución del algoritmo
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;

    std::cout <<"Tiempo de ejecucion en milisegundos: " << tiempo << std::endl;

  std::cout << std::endl;
  return EXIT_SUCCESS;


}
