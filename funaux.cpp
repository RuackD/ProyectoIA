#include "leerInstancia.h"
#include "hillClimbing.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

/**
 * @brief Funciones auxiliares para el problema de Aircraft Landing Scheduling.
 *
 * Este archivo implementa las funciones de evaluación y factibilidad de soluciones,
 * así como la generación de soluciones iniciales aleatorias factibles para ser usadas
 * como punto de partida en algoritmos de optimización local como Hill Climbing.
 * 
 * Funciones implementadas:
 * 
 * - fun_eval: Calcula el costo total de penalización asociado a una solución, considerando
 *             penalizaciones por aterrizaje anticipado o tardío respecto al tiempo objetivo.
 * 
 * - factible: Verifica si una solución cumple con las restricciones del problema, es decir,
 *             que cada avión aterrice dentro de su ventana de tiempo permitida, y que se
 *             respete la separación mínima entre cada par de aviones según su orden de aterrizaje.
 * 
 * - sol_aleatoria: Genera una solución inicial aleatoria que cumple con todas las restricciones
 *                  del problema. La solución es factible y puede ser utilizada como estado inicial
 *                  para un proceso de búsqueda local.
 */



double fun_eval(const vector<int>& solucion, const vector<Avion>& aviones, const int n_aviones) {
    double valor = 0.0;
    for (int i = 0; i < n_aviones; i++) {
        if (solucion[i] < aviones[i].t_time) {
            double margen = aviones[i].t_time - solucion[i];
            valor += margen * aviones[i].e_pen;
        }
        else if (solucion[i] > aviones[i].t_time) {
            double margen = solucion[i] - aviones[i].t_time;
            valor += margen * aviones[i].l_pen;
        }
    }
    return valor;
}

bool factible(const vector<int>& solucion, const vector<Avion>& aviones, const int n_aviones) {

    vector<int> indices(n_aviones);
    for (int i = 0; i < n_aviones; ++i){
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&solucion](int a, int b) {
        return solucion[a] < solucion[b];
    });

    for (int i = 0; i < n_aviones; ++i) {
        int tiempo_llegada = solucion[i];
        if (tiempo_llegada < aviones[i].e_time || tiempo_llegada > aviones[i].l_time){
            return false;
        }
        for (int i = 0; i < n_aviones - 1; ++i){
            int avion1 = indices[i];
            int avion2 = indices[i + 1];
            int tiempo1 = solucion[avion1];
            int tiempo2 = solucion[avion2];
            if (tiempo2 - tiempo1 < aviones[avion1].s_times[avion2]){
                return false;
            }
        }
    }

    return true;
}

vector<int> sol_aleatoria(const vector<Avion>& aviones, const int n_aviones) {
    vector<int> solucion(n_aviones);
    bool es_factible = false;

    while (!es_factible) {
        for (int i = 0; i < n_aviones; i++) {
            int E = aviones[i].e_time;
            int L = aviones[i].l_time;
            if(E == L) {
                solucion[i] = E; // Si E y L son iguales, solo hay una opción
                continue;
            }
            else if(E<L){
                int random_value = E + rand() % (L - E + 1);
                solucion[i] = random_value; // Genera un valor aleatorio entre E y L
            }
            else{
                cerr << "Error: E_i no puede ser mayor que L_i para el avión " << i + 1 << endl;
                return vector<int>(); // Retorna un vector vacío en caso de error
            }
        }
        es_factible = factible(solucion, aviones, n_aviones);
    }
    return solucion;
}

vector<int> ejecucion(vector<Avion>& aviones, int n_aviones, int max_iter, int restarts) {
    vector<int> mejor_solucion = hillClimbing(aviones, n_aviones, max_iter, restarts);
    return mejor_solucion;
}

void guardarSalida(const string& nombreArchivoSalida, const vector<int>& solucion) {
    ofstream salida(nombreArchivoSalida);
    if (!salida.is_open()) {
        cerr << "Error al abrir archivo de salida: " << nombreArchivoSalida << endl;
        return;
    }

    for (size_t i = 0; i < solucion.size(); ++i) {
        salida << "hora de aterrizaje avión n" << (i + 1) << ": " << solucion[i] << endl;
    }

    salida.close();
}
