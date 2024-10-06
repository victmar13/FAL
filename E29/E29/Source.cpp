//nombre alumno victoria martin
//usuario juez a43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

//función que resuelve el problema
vector<int> resolver(vector<int> const& v, int longit) { // 
    int tam = v.size();
    int max = 0;
    int llanos = 0;
    int cont = 1;
    int numMax = 0;
    vector<int> sol;
    for (int i = tam-1; i > 0; i--) {
        if (v[i - 1] == v[i] && v[i] >= numMax) {
            cont++;
        }
        else {
            if (cont >= longit) {
                sol.push_back(i + cont - 1 );
                llanos++;
                if (cont > max) {
                    max = cont;
                }
            }
            cont = 1;
        }
        if (v[i] > numMax) {
            numMax = v[i];
        }

    }
   if (cont >= longit) {
        sol.push_back(cont-1);
        llanos++;
        if (cont > max) {
            max = cont;
        }
    }
    sol.push_back(llanos);
    sol.push_back(max);
    return sol;
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuración, y escribiendo la respuesta   

bool resuelveCaso() {
    //leer los datos de la entrada
    int tam, longitud;
    cin >> tam >> longitud;

    if (longitud <= 1 || tam <= 0 || !cin) {
        return false;
    }

    vector<int> lista(tam);
    for (int i = 0; i < tam; i++) {
        cin >> lista[i];
    }

    vector<int> sol = resolver(lista, longitud);
    int tam2 = sol.size();
    cout << sol[tam2 - 1] << " " << sol[tam2 - 2] << " ";
    for (int i = 0; i < tam2 - 2; i++) {

        cout << sol[i] << " ";
    }
    cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.

    while (resuelveCaso());


    return 0;
}