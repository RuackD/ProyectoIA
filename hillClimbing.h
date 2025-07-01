#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

#include "leerInstancia.h"
#include <vector>
using namespace std;

// Declara la función que genera vecinos factibles de una solución
void movimiento(const vector<int>& solucion, vector<vector<int>>& vecinos,
                const vector<Avion>& aviones, int n_aviones);

// Declara la función principal del algoritmo de búsqueda local Hill Climbing
vector<int> hillClimbing(const vector<Avion>& aviones,
                         int n_aviones,
                         int max_iter,
                         int restarts);

#endif // HILLCLIMBING_H
