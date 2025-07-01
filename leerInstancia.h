#ifndef LEERINSTANCIAS_H
#define LEERINSTANCIAS_H

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Avion {
    int id;               // ID del avión (posición en el input)
    int a_time;  // Tiempo en que aparece (solo útil para versión dinámica) appearance
    int e_time;    // E_i: Hora más temprana de aterrizaje earliest
    int t_time;      // T_i: Hora objetivo target
    int l_time;      // L_i: Hora más tardía latest
    double e_pen; // g_i: Costo por llegar antes de T_i penalty
    double l_pen;  // h_i: Costo por llegar después de T_i penalty
    vector<int> s_times; // Arreglo dinámico con la separación entre aviones
};

void instances(const string &nombreArchivo, vector<Avion> &aviones, int& n_aviones);

#endif