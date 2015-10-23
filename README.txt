#INSTALLATION
#Instalación

Antes de la instalación se debe contar con CMake, ParadisEO y la libreria boost C++
A continuación se describen los pasos para su instalación
	1)Ser usuario root
	2)apt-get install libboost-all-dev
	3)apt-get install cmake
	4)Para PardisEO revisar Anexo A Tesis


Verificar que Gnuplot tenga instalado el visor 'wxt', si no cuenta con él ejecutar
apt-get install gnuplot-x11

#Agregar al archivo CMakelist.txt la ubicación de ParadisEO

#Para la compilación del trabajo seguir los siguientes pasos

##En la línea de comandos, ir al sub-directorio build del trabajo si no existe crear la carpeta, luego ingresar los siguientes comandos:

###Para Linux
> cmake .. (On Unix) //Para identificar el compilador y chequear las dependencias
> make //Para compilar el código
> make install //Para cargar los archivos de configuración y escenarios de pruebas
> cd application //Es la carpeta donde se compila el código

###Dentro de la carpeta build/application se encuentran las Matriz1(R5), Matriz2(R4), Matriz3(R3), Matriz4(R2). Para ejecutar el algoritmo
se debe cambiar el nombre de cualquiera de estos archivo por el nombre Matriz.
###Para la ejecución es de obligación contar con los archivos: Anclas, Matriz y Allposition (son todas las posiciones reales de todos 
los nodos, se utiliza solo para mostrar los resultados gráficamente).

> ./nombrecodigo @nombre.param // Se ejecuta el código con el correspondiente archivo de configuración

###Para Windows 
> cmake .. -G "MinGW Makefiles" o cmake .. -G"Visual Studio 9 2008" //todo depende del compilador que se utilice.
> make (On Window) //Para compilar el código
