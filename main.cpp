#include <iostream>
#include <stdlib.h>
#include "leerInstancia.h"
#include "hillClimbing.h"
#include "funaux.h"
#include <vector>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){
    srand(time(NULL));
    if (argc < 2) {
            cerr << "Escribe bien el input" << endl;
            return 1;
        }    
    string nombreArchivo = argv[1];
    vector<Avion> aviones;
    int n_aviones;   
    instances(nombreArchivo,aviones,n_aviones);

    clock_t start_10 = clock();
    vector<int> sol_10 = ejecucion(aviones, n_aviones, 100,10);
    clock_t end_10 = clock();
    double tiempo_10 = double(end_10 - start_10) / CLOCKS_PER_SEC;
    double costo_10 = fun_eval(sol_10, aviones, n_aviones);
    guardarSalida("sol_10.txt", sol_10);
    cout << "valor objetivo 10 repes = " << costo_10 << ", tiempo de ejecución = " << tiempo_10 << "s" << endl;

    clock_t start_50 = clock();
    vector<int> sol_50 = ejecucion(aviones, n_aviones, 100, 50);
    clock_t end_50 = clock();
    double tiempo_50 = double(end_50 - start_50) / CLOCKS_PER_SEC;
    double costo_50 = fun_eval(sol_50, aviones, n_aviones);
    guardarSalida("sol_50.txt", sol_50);
    cout << "valor objetivo 50 repes = " << costo_50 << ", tiempo de ejecución = " << tiempo_50 << "s" << endl;
    
    clock_t start_100 = clock();
    vector<int> sol_100 = ejecucion(aviones, n_aviones, 100, 100);
    clock_t end_100 = clock();
    double tiempo_100 = double(end_100 - start_100) / CLOCKS_PER_SEC;
    double costo_100 = fun_eval(sol_100, aviones, n_aviones);
    guardarSalida("sol_100.txt", sol_100);
    cout << "valor objetivo 100 repes= " << costo_100 << ", tiempo de ejecución = " << tiempo_100 << "s" << endl;

    cout << "Soluciones guardadas en archivos de salida." << endl;
    return 0;
}