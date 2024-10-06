//nombre alumno victoria martin
//usuario juez a43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

//función que resuelve el problema
pair<int, int> resolver(vector<int> const& v, int vagones) { // 
    int tam = v.size();
    int max = 0;
    int pos = 0;
    int total = 0;
    for (int i = 0; i < vagones; i++) { //coste O(vagones)
        total += v[i];
    }

    max = total;
    for (int i = 1; i <= tam - vagones; i++) { //coste O(n) + 1 del if por vuelta -> O(2n)
        total = total + v[i + vagones - 1] - v[i - 1];
        if (total >= max) {
            max = total;
            pos = i;
        }
    }
    //total O(2n +vagones) siendo vagones el numero cogido en los datos de estrada y n el taaño del vector
    return { pos, max };
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuración, y escribiendo la respuesta   

bool resuelveCaso() {
    //leer los datos de la entrada
    int tam, vagones;
    cin >> tam >> vagones;

    vector<int> lista(tam);
    for (int i = 0; i < tam; i++) {
        cin >> lista[i];
    }

    pair<int, int> sol = resolver(lista, vagones);



        cout << sol.first << " " << sol.second << "\n";
    
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