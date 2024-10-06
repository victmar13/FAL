//Victoria Martin Rojo
//A43

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


//N =  max digitos entre n y  m
//coste O(log(N))



// función que resuelve el problema

bool comprobacion_precedentes(int n, int dig) { // coste O(log(N), N = max num de digitos entre m y n 
    if (n < 10 ) {
        if (n == 0 || dig % n != 0) { return false; }
        else return true;
    }
    else {
        dig += n % 10;
        if (n % 10 == 0 || dig % (n / 10 % 10) != 0) {
            return false;
        }
        else return comprobacion_precedentes(n / 10, dig);
    }
       
}


bool comprobacion_sucedentes(int n, int dig) { // coste O(log(N), N = max num de digitos entre m y n 
    if (n < 10) {
        if (n == 0 ) { return false; }
        else return true;
    }
    else {
        dig -= n % 10;
        if (n % 10 == 0 || dig % (n % 10) != 0) {
            return false;
        }
        else return comprobacion_sucedentes(n / 10, dig);
    }

}
int suma_componentes(int n, int dig) {
    if (n < 10) { return dig += n; }
    else return suma_componentes(n / 10, dig + n % 10);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    bool sol1 = comprobacion_precedentes(n, 0);
    int dig = suma_componentes(n, 0);
    bool sol2 = comprobacion_sucedentes(n, dig );
    // escribir sol
    if (sol1 && sol2) {
        cout << "SI\n";
    }
    else { cout << "NO\n"; }
   

}

int main() {
    // Para la entrada por fichero.

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}