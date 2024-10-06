// Victoria Martin Rojo
// A43

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int>const& v, int ini, int fin, int personas) {
    if (ini >= fin) {
        if (v[ini] >= personas * (int(v.size()) - ini)) {
            return -1;
        }
        else { return fin; }
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] >= personas * (int(v.size()) - mitad )) {
            return resolver(v, mitad + 1, fin, personas);
        }
        else { return resolver(v, ini, mitad, personas); }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int dias, personas;
    cin >> dias >> personas;
    if (dias <= 0) {
        return false;
    }
    vector<int> v(dias);
    for (int i = 0; i < dias; i++) {
        cin >> v[i];
    }

    int sol = resolver(v, 0, v.size() - 1, personas);
    // escribir sol
    if (sol == -1)
        cout << "SIN RACIONAMIENTO\n";
    else
        cout << sol << endl;

    return true;
}

int main() {

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}