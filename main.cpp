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
}
