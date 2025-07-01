#include "leerInstancia.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
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
    for (int i = 0; i < n_aviones; i++) {
        if (solucion[i] < aviones[i].e_time || solucion[i] > aviones[i].l_time) {
            return false;
        }

        for (int j = 0; j < n_aviones; j++) {
            if (solucion[i] < solucion[j] && solucion[j] < solucion[i] + aviones[i].s_times[j])
                    return false;

                if (solucion[j] < solucion[i] && solucion[i] < solucion[j] + aviones[j].s_times[i])
                    return false;
        }
    }
    return true;
}

vector<int> sol_aleatoria(const vector<Avion>& aviones, const int n_aviones) {
    vector<int> solucion(n_aviones);

    for (int i = 0; i < n_aviones; i++) {
        int E = aviones[i].e_time;
        int L = aviones[i].l_time;

        solucion[i] = E + rand() % (L - E + 1);
    }

    while (!factible(solucion, aviones, n_aviones)) {
        for (int i = 0; i < n_aviones; i++) {
            int E = aviones[i].e_time;
            int L = aviones[i].l_time;
            solucion[i] = E + rand() % (L - E + 1);
        }
    }

    return solucion;
}

