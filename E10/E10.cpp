//Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*{true}
proc equilibrio ( vector <int > v ) dev int p
{−1 ≤ p < v.size() ∧ numUnos(v, p + 1) = numCeros(v, p + 1)
∧∀k : p < k < v.size() : numUnos(v, k + 1) 6= numCeros(v, k + 1)}
donde numUnos(v, j) = #i : 0 ≤ i < j : v[i] = 1 y numCeros(v, j) = #i : 0 ≤ i < j : v[i] = 0.*/

using namespace std;

//funcion que resuelve el problema
int resolver(vector<int> const& v) { //coste O(n)cada vuelta tiene coste 1, como damos n vueltas dependiendo del tamaño del vector elcoste dependera tambien del tamaño del vector por lo q es O(n)
    int cont = -1;
    int ceros = 0;
    int unos = 0;
    int tam = v.size();

    for (int i = 0; i < tam; i++) {
        if (v[i] == 0) {
            ceros++;
        }

        else if (v[i] == 1) {
            unos++;
        }

        if (ceros == unos) {
            cont == i;
        }
    }

    return cont;
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {

    //leer los datos de la entrada
    int tam;
    vector<int> lista(tam);
    for (int i = 0; i < tam; i++) {
        cin >> lista[i];
    }

    int sol = resolver(lista);
    cout << sol << endl;

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