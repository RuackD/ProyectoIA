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
    vector<int> sol_50_5 = ejecucion(aviones, n_aviones, 50, 5);
    vector<int> sol_100_10 = ejecucion(aviones, n_aviones, 100, 10);
    vector<int> sol_200_20 = ejecucion(aviones, n_aviones, 200, 20);
    cout << "Solución con 50 iteraciones y 5 reinicios: ";
    for (int i = 0; i < n_aviones; i++) {
        cout << sol_50_5[i] << " "; 
    }
    cout << endl;
    cout << "Costo de la solución con 50 iteraciones y 5 reinicios: " << fun_eval(sol_50_5, aviones, n_aviones) << endl;
    cout << "Solución con 100 iteraciones y 10 reinicios: ";
    for (int i = 0; i < n_aviones; i++) {
        cout << sol_100_10[i] << " ";   
    }
    cout << endl;
    cout<<"Costo de la solución con 100 iteraciones y 10 reinicios: " << fun_eval(sol_100_10, aviones, n_aviones) << endl;
    cout << "Solución con 200 iteraciones y 20 reinicios: ";
    for (int i = 0; i < n_aviones; i++) {
        cout << sol_200_20[i] << " ";                   
    }
    cout << endl;
    cout<<"Costo de la solución con 200 iteraciones y 20 reinicios: " << fun_eval(sol_200_20, aviones, n_aviones) << endl;
}