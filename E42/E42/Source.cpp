//Victoria Martin Rojo
//A43

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


//N =  max digitos entre n y  m
//coste O(log(N))



// funcio´n que resuelve el problema
long long int fib(int n, int x, long long int n1, long long int n2) {  // coste O(log(N))  hay dos funciones recursivas 
    if (n == x) return n2;
    else return fib(n, x + 1, n1 + n2, n1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;
    if (!cin || n > 89) {
        return false;
    }

    cout << fib(n, 0, 1, 0) << "\n";


    return true;
}

int main() {
    // Para la entrada por fichero.

    while (resuelveCaso());


    return 0;
}