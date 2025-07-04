#ifndef FUNAUX_H
#define FUNAUX_H

#include "leerInstancia.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

double fun_eval(const vector<int>& solucion, const vector<Avion>& aviones, const int n_aviones);

bool factible(const vector<int>& solucion, const vector<Avion>& aviones, const int n_aviones);

vector<int> sol_aleatoria(const vector<Avion>& aviones, const int n_aviones);

vector<int> ejecucion(vector<Avion>& aviones, int n_aviones, int max_iter, int restarts);

#endif
