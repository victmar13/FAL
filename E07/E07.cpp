//Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//coste O(n)

using namespace std;

//función que resuelve el problema
void resolver(vector<int> const& v, vector<int>& sol, int ini) {

    int tam = v.size();
    int max = v[0];

    for (int i = 1; i < tam; i++) {
        if (v[i] > max) {
            sol.push_back(ini + i);
            max = v[i];
        }
    }

}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuración, y escribiendo la respuesta   

bool resuelveCaso() {
    //leer los datos de la entrada
    int ini;
    int  fin;
    cin >> ini >> fin;
    int tam = fin - ini + 1 ;
    vector<int> lista(tam);
    for (int i = 0; i < tam; i++) {
        cin >> lista[i];
    }


    vector<int> sol;
    resolver(lista, sol, ini);
     int tam2 = sol.size();
     for (int i = 0; i < tam2; i++) {
         cout << sol[i] << " ";
     }
     cout << "\n";
     // for de sol
     // endl

        return true;

}

int main() {
   // Para la entrada por fichero.
    
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    return 0;
}