#include <iostream>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include "archivos.h"
#include "Funciones.cpp"


using namespace std;

int main(){
    crearArchivos();
    contarArchivos();

    return 0;
}