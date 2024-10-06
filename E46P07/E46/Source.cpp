//Victoria Martin Rojo
//A43

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


//N =  max digitos entre n y  m
//coste O(log(N))



// funcio´n que resuelve el problema
long long int hermite(int n, int y){  // coste O(log(N))  hay dos funciones recursivas 
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 2 * y;
    }
    else {
        return 2 * y * hermite(n - 1, y) - 2 * (n - 1) * hermite(n - 2, y);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, y;

    cin >> n;
    if (n < 0 || n > 10) {
        return false;
    }
    cin >> y;
    if (y < 1 || y>20) {
        return false;
    }
    if (n == 0) {
        cout << "1\n";
    }
    else if(n == 1) {
        cout << 2 * y << "\n";
    }
    else {
        cout << hermite(n, y) << "\n";
    }

    return true;
}

int main() {
    // Para la entrada por fichero.

    while (resuelveCaso());
        

    return 0;
}