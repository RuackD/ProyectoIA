#include "leerInstancia.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "funaux.h"
using namespace std;

/**
 * @brief Implementación del algoritmo Hill Climbing para el Aircraft Landing Problem (ALP).
 *
 * Este archivo contiene la implementación del algoritmo de búsqueda local Hill Climbing
 * con mejora más pronunciada (best-improvement), aplicado al problema de planificación
 * de aterrizajes de aviones (Aircraft Landing Scheduling Problem).
 * 
 * El algoritmo parte desde una solución inicial aleatoria factible, genera su vecindario
 * aplicando movimientos locales simples (variación de tiempos de aterrizaje) y se desplaza
 * hacia el mejor vecino factible que presente una mejora en el valor objetivo. En caso de 
 * alcanzar un óptimo local, se aplica una estrategia de reinicios aleatorios para intentar 
 * escapar de mínimos locales.
 * 
 * Funciones implementadas:
 * 
 * - movimiento: Genera el vecindario de una solución actual, modificando individualmente
 *               los tiempos de aterrizaje de cada avión en ±1 unidad de tiempo, verificando
 *               factibilidad para cada vecino generado.
 * 
 * - hillClimbing: Ejecuta el algoritmo Hill Climbing con reinicios aleatorios. Devuelve la 
 *                 mejor solución encontrada tras un número determinado de iteraciones y 
 *                 reinicios, evaluando factibilidad y costo total mediante funciones auxiliares.
 */




void movimiento(const vector<int>& solucion, vector<vector<int>>& vecinos,
                const vector<Avion>& aviones, int n_aviones) {

    const int delta = 1;
    vector<vector<int>> vecinos_n;

    for (int i = 0; i < n_aviones; i++) {
        vector<int> vecino1 = solucion;
        vecino1[i] = solucion[i] + delta;

        vector<int> vecino2 = solucion;
        vecino2[i] = solucion[i] - delta;

        if (factible(vecino1, aviones, n_aviones)) {
            vecinos_n.push_back(vecino1);
        }

        if (factible(vecino2, aviones, n_aviones)) {
            vecinos_n.push_back(vecino2);
        }
    }

    vecinos = vecinos_n;
}

vector<int> hillClimbing(const vector<Avion>& aviones,
                         int n_aviones,
                         int max_iter,
                         int restarts) {
    vector<vector<int>> soluciones_guardadas;
    vector<int> mejor_solucion;
    double mejor_costo = max_iter;
    double costo_actual;

    for (int r = 0; r < restarts; r++) {
        vector<int> sol_actual = sol_aleatoria(aviones, n_aviones);
        soluciones_guardadas.push_back(sol_actual);
        costo_actual = fun_eval(sol_actual, aviones, n_aviones);
        int iter = 0;

        while (iter < max_iter) {
            vector<vector<int>> vecinos;
            movimiento(sol_actual, vecinos, aviones, n_aviones);

            vector<int> mejor_vecino = sol_actual;
            double mejor_vecino_costo = costo_actual;
            bool hay_mejora = false;

            for (const auto& vecino : vecinos) {
                double costo_vecino = fun_eval(vecino, aviones, n_aviones);
                if (costo_vecino < mejor_vecino_costo) {
                    mejor_vecino = vecino;
                    mejor_vecino_costo = costo_vecino;
                    hay_mejora = true;
                }
            }

            if (!hay_mejora) break;

            sol_actual = mejor_vecino;
            costo_actual = mejor_vecino_costo;
            iter++;
        }

        if (costo_actual < mejor_costo) {
            mejor_solucion = sol_actual;
            mejor_costo = costo_actual;
        }
    }

    return mejor_solucion;
}
