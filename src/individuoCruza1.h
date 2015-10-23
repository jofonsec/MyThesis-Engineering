#include <eoOp.h>
#include <Individuo.h>
// Se genera un hijo (segmentCruza) de la clase eoOrderXover, y el template se define para el cromosoma Individuo el cual fue definido en el archivo queen.h como un eoInit<Minimizing..> lo que lo define como un eoVector.
typedef eoSegmentCrossover<Individuo> segmentCruza;
