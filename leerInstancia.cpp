#include "leerInstancia.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

/**
 * @brief Lectura y carga de datos desde archivo para el Aircraft Landing Problem (ALP).
 *
 * Este archivo implementa la función encargada de leer una instancia del problema de
 * planificación de aterrizajes desde un archivo de texto. Extrae la cantidad total de
 * aviones, sus ventanas de aterrizaje, penalizaciones por anticipación o retraso, y 
 * las matrices de separación requeridas entre pares de aviones.
 * 
 * Cada línea del archivo contiene los datos necesarios para describir completamente
 * un avión y sus restricciones individuales y relacionales. Esta función transforma esa 
 * información en una estructura de datos (`vector<Avion>`) que será utilizada por los 
 * algoritmos de optimización.
 * 
 * Funciones implementadas:
 * 
 * - instances: Carga todos los aviones desde el archivo especificado, inicializando cada
 *              estructura `Avion` con sus tiempos relevantes y el vector de separaciones
 *              requeridas respecto a los demás aviones.
 */

void instances(const string &nombreArchivo, vector<Avion> &aviones, int& n_aviones) {

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    int c_avi = 0;
    int f_time;
    archivo>>n_aviones>>f_time;
    getline(archivo, linea);


    for(int j = 0; j < n_aviones; j++){
        c_avi++;
        Avion a_act;
        
        a_act.id = c_avi;

        archivo>>a_act.a_time>>a_act.e_time>>a_act.t_time>>a_act.l_time>>a_act.e_pen>>a_act.l_pen;


        for(int i = 0; i < n_aviones; i++){    
            int separacion;       
            archivo>>separacion;
            a_act.s_times.push_back(separacion);

        }
        aviones.push_back(a_act);
    };
    archivo.close();
}

