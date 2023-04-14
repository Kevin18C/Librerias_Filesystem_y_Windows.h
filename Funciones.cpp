//
// Created by kevin on 12/04/2023.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include "archivos.h"
#include "string"


using namespace std;

string ruta;

void crearArchivos(){
    int cantidad;
    string Nombre_archivo;
    int texto;

    cout<<"Ingresa la cantidad de archivos a crear:"<<endl;
    cin>>cantidad;

    cin.ignore();
    cout<<"Ingrese el nombre del archivo:"<<endl;
    getline(cin, Nombre_archivo);

    int i = cantidad;

    ofstream file;
    int Directorio;

    cout<<"En donde desea Guardar el archivo:"<<endl;
    cout<<"1.Escritorio"<<endl;
    cout<<"2.Descargas"<<endl;
    cout<<"3.Documentos"<<endl;
    cout<<"4.Imagenes"<<endl;
    cout<<"5.Videos"<<endl;
    cout<<"6.Musica"<<endl;

    cin>>Directorio;


    switch(Directorio){
        case 1:
            ruta = "C:\\Users\\kevin\\Desktop\\";
            break;
        case 2:
            ruta = "C:\\Users\\kevin\\Downloads\\";
            break;
        case 3:
            ruta = "C:\\Users\\kevin\\Documents\\";
            break;
        case 4:
            ruta = "C:\\Users\\kevin\\Pictures\\";
            break;
        case 5:
            ruta = "C:\\Users\\kevin\\Videos\\";
            break;
        case 6:
            ruta = "C:\\Users\\kevin\\Music\\";
            break;

        default:
            cout << "Opción inválida. No se pudo guardar el archivo." << endl;
            break;
    }

    cout<<"Desea agregar texto al archivo (Si=1/No=2):"<<endl;
    cin>>texto;
    if(texto == 1){
        int respuesta;
        cout<<"Puede poner el texto en todos los archivos o ingresar texto diferente por cada archivo:"<<endl;
        cout<<"1.Texto para todo los archivos"<<endl;
        cout<<"2.Escribir texto para cada archivo"<<endl;
        cin>>respuesta;

        if(respuesta == 2){
            for (i = 0; i < cantidad; i++){
                string texto1;
                cin.ignore();
                cout<<"Ingrese el texto que desee en el archivo:"<<endl;
                getline(cin, texto1);
                file.open(ruta + Nombre_archivo + to_string(i) + ".txt");
                file << texto1;

                file.close();

                cout << "Archivos creados: "   + to_string(i) << endl;
            }
        }else if(respuesta == 1){
            string texto1;
            cin.ignore(); // Agregar cin.ignore() para eliminar el carácter de nueva línea
            cout << "Ingrese el texto que desee en el archivo:" << endl;
            getline(cin, texto1); // Leer una línea completa de texto

            for (i = 0; i < cantidad; i++) {
                file.open(ruta + Nombre_archivo + to_string(i) + ".txt");
                file << texto1;
                file.close();

                cout << "Archivo creado: " + Nombre_archivo + to_string(i) + ".txt" << endl;
            }
        }

    }else if(texto == 2) {
        for (i = 0; i < cantidad; i++) {
            file.open(ruta + Nombre_archivo + to_string(i) + ".txt");
            file.close();

            cout << "Archivos creados: " + to_string(i) << endl;
        }
    }
}

int contarArchivos() {
    WIN32_FIND_DATA findData;
    HANDLE hFind;

    hFind = FindFirstFile((ruta + "*").c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cout << "No se encontraron archivos en el directorio especificado." << endl;
        return 0;
    }

    int numArchivos = 0;

    do {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
            !(findData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) &&
            (findData.cFileName[0] != '.')) { // Excluir directorios, archivos ocultos y archivos con nombre que empiecen con '.'
            numArchivos++;
        }
    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
    cout<<"Cantidad de archivos en el Directorio:"<<numArchivos;
    return numArchivos;
}
