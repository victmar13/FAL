//Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//coste O(n)

using namespace std;

//función que resuelve el problema
pair<int, vector<string>> resolver(vector<pair<string, pair<int, int>>> const& v) {
    vector<string> pisos;
    int cont = 0;
    //v[i].first = piso nombre (string) || v[i].second.first = altura piso || 
    //v[i].second.second = altura piso disponible;
    int max = -1;
    int tam = v.size();
    for (int i = tam - 1; i >= 0; i--) {
        if (v[i].second.second > max) {
      
           max = v[i].second.first;
           cont++;
           pisos.push_back(v[i].first);
        }
        else if (v[i].second.first > max) {
            max = v[i].second.first;
        }

   }
    return { cont, pisos };
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuración, y escribiendo la respuesta   


bool resuelveCaso() {
    //leer los datos de la entrada
    int tam;
    cin >> tam;
    if (!tam)
        return false;

    vector<pair<string, pair<int, int>>> lista(tam);

    for (int i = 0; i < tam; i++) {
        cin >> lista[i].first;
        cin >> lista[i].second.first;
        cin >> lista[i].second.second;
    }

    pair<int, vector<string>> sol = resolver(lista);
    if (sol.first > 0) {
        cout << sol.first << endl;
        int _tam = sol.second.size();
        for (int i = 0; i < _tam; i++) {
            cout << sol.second[i] << " ";
        }
        cout << endl;
   }
    else { cout << "Ninguno" << endl; }
    // for de sol
    // endl

    return true;

}

int main() {
    // Para la entrada por fichero.


    while (resuelveCaso())
        ;


    return 0;
}


