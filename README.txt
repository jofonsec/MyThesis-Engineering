#INSTALLATION
#Instalaci�n

Antes de la instalaci�n se debe contar con CMake, ParadisEO y la libreria boost C++
A continuaci�n se describen los pasos para su instalaci�n
	1)Ser usuario root
	2)apt-get install libboost-all-dev
	3)apt-get install cmake
	4)Para PardisEO revisar Anexo A Tesis


Verificar que Gnuplot tenga instalado el visor 'wxt', si no cuenta con �l ejecutar
apt-get install gnuplot-x11

#Agregar al archivo CMakelist.txt la ubicaci�n de ParadisEO

#Para la compilaci�n del trabajo seguir los siguientes pasos

##En la l�nea de comandos, ir al sub-directorio build del trabajo si no existe crear la carpeta, luego ingresar los siguientes comandos:

###Para Linux
> cmake .. (On Unix) //Para identificar el compilador y chequear las dependencias
> make //Para compilar el c�digo
> make install //Para cargar los archivos de configuraci�n y escenarios de pruebas
> cd application //Es la carpeta donde se compila el c�digo

###Dentro de la carpeta build/application se encuentran las Matriz1(R5), Matriz2(R4), Matriz3(R3), Matriz4(R2). Para ejecutar el algoritmo
se debe cambiar el nombre de cualquiera de estos archivo por el nombre Matriz.
###Para la ejecuci�n es de obligaci�n contar con los archivos: Anclas, Matriz y Allposition (son todas las posiciones reales de todos 
los nodos, se utiliza solo para mostrar los resultados gr�ficamente).

> ./nombrecodigo @nombre.param // Se ejecuta el c�digo con el correspondiente archivo de configuraci�n

###Para Windows 
> cmake .. -G "MinGW Makefiles" o cmake .. -G"Visual Studio 9 2008" //todo depende del compilador que se utilice.
> make (On Window) //Para compilar el c�digo
