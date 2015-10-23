#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct tipoRegistro {
   char nombre[32];
   int edad;
   float altura;
};

int main() {
   tipoRegistro pepe;
   tipoRegistro pepe2;
   ofstream fsalida("prueba.dat",
      ios::out | ios::binary);

   strcpy(pepe.nombre, "Jose Luis");
   pepe.edad = 32;
   pepe.altura = 1.78;

   fsalida.write(reinterpret_cast<char *>(&pepe),
      sizeof(tipoRegistro));
   fsalida.close();

   ifstream fentrada("prueba.dat",
      ios::in | ios::binary);

   fentrada.read(reinterpret_cast<char *>(&pepe2),
      sizeof(tipoRegistro));
   cout << pepe2.nombre << endl;
   cout << pepe2.edad << endl;
   cout << pepe2.altura << endl;
   fentrada.close();

   return 0;
}
