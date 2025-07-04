#include <iostream>
#include <stdlib.h>
#include "leerInstancia.h"
#include "hillClimbing.h"
#include "funaux.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2) {
            cerr << "Escribe bien el input" << endl;
            return 1;
        }    
    string nombreArchivo = argv[1];
    vector<Avion> aviones;
    int n_aviones;   

    instances(nombreArchivo,aviones,n_aviones);
    
    vector<int> mejor_sol = hillClimbing(aviones, n_aviones, 50, 5);
    double mejor_costo = fun_eval(mejor_sol, aviones, n_aviones);
    cout << "Mejor solución encontrada: ";
    for (int i = 0; i < n_aviones; i++) {
        cout << mejor_sol[i] << " ";        
    }
    cout << "\nCosto de la mejor solución: " << mejor_costo << endl;    
}