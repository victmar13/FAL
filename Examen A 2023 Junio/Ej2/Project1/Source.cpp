//Victoria Martin Rojo
//A43

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


//N =  max digitos entre n y  m
//coste O(log(N))

using lli = long long int;

// funcio´n que resuelve el problema
lli buscarMenorFalta(vector<lli> const& v, lli inicio, lli ini, lli fin) {
    //caso base
    if (ini == fin - 1) {
        if (v[ini] == inicio + ini) {
            return inicio + fin;
        }
        else return inicio + ini;
    }
    //caso recursivo
    else {

        lli mitad = (fin + ini - 1) / 2;
            if (v[mitad] == inicio + mitad) {// todos los anteriores tambien coinciden con sus posiciones, esta mas a la derecha
                return buscarMenorFalta(v, inicio, mitad + 1 , fin);
            }
            else { return buscarMenorFalta(v, inicio, ini, mitad ); }// falta algun numero antes 
       
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli ini;
    lli tam;
    cin >> tam >> ini;
    vector<lli> v(tam);
    lli maximo = 0;
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
        if (v[i] > maximo) maximo = v[i];
    }
    lli sol;
    if (tam == 0) {
        sol = ini;
    }
    else if (tam == 1) {
        if (v[0] == ini) sol = ini + 1;
        else sol = ini;
    }
    else sol = buscarMenorFalta(v, ini, 0, tam);
    if (sol == maximo) { sol++; }
    cout << sol << "\n";


    return true;
}

int main() {
    // Para la entrada por fichero.
    int nCasos; 
    cin >> nCasos;
    for (int i = 0; i < nCasos; i++) {
        resuelveCaso();
    }

    return 0;
}