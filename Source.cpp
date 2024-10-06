//Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//coste O(n)

using namespace std;

//función que resuelve el problema
pair<bool, int> resolver(vector<int> const& v) {
    int tam = v.size();
    int suma = 0;
    for (int i = tam - 1; i > 0; i--) {
        if (v[i] == suma) {
            return { true, i };
        }
        suma += v[i];
    }


    return { false, 0};
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuración, y escribiendo la respuesta   

bool resuelveCaso() {
    //leer los datos de la entrada
    int tam;
    cin >> tam;

    vector<int> lista(tam);
    for (int i = 0; i < tam; i++) {
        cin >> lista[i];
    }

    pair<bool, int> sol = resolver(lista);

    if (sol.first) {
        cout << "Si " << sol.second << endl;
    }
    else { cout << "No" << endl; }
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
//4 10 3 5 8 25 12 14 5 7 0 2 7 6 2 3 1 0 8 12 3 1 4 0 8 9 45 5 20 10 1 6 3