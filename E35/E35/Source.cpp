// Victoria Martin Rojo
// A43

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(int a, int b) {
    while (b != 0) {
        int aux = b;
        b = a % b;
        a = aux;
    }

    return a;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    cin >> a >> b;

    if (a == 0 && b == 0)
        return false;

    int sol = resolver(a, b);
    // escribir sol
    cout << sol << endl;

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}