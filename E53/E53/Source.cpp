//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno
// Usuario del juez de clase
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//*******************************
// Explicacion del algoritmo empleado
// Coste del algoritmo. Incluye recurrencia y desplegado de la recurrencia
//
// Y no olvides poner comentarios en el codigo
//*******************************

// Aqui las funciones implementadas por el alumno
pair<bool, pair<int, int>> resuelve(vector<int> const& v1, vector<int> const& v2, int ini, int fin, int min) {
    int mitad; 
    mitad = (ini + fin) / 2;
    //caso base
    if (ini >= fin ) {
        if (v1[ini] == v2[ini]) {
            return { true, {ini, 0} };
        }
        else if (fin == v1.size() - 1)return { false, {v1.size() - 1, v1.size()}};
        else return { false, {ini - 1, ini} };
    }
    //caso recursivo
    else {
        if (abs(v1[mitad] - v2[mitad]) != 0) {
            if (abs(v1[mitad] - v2[mitad]) < min) {
                min = abs(v1[mitad] - v2[mitad]);
            }
            if (mitad != 0 && abs(v1[mitad - 1] - v2[mitad - 1]) <= min) {
                return resuelve(v1, v2, ini, mitad, min);
            }
            else if (mitad != v1.size() - 1 && abs(v1[mitad + 1] - v2[mitad + 1]) < min) {
                return resuelve(v1, v2, mitad + 1, fin, min);
            }
            else { return { false, {mitad - 1, mitad} }; }
        }
        else { return { true, {mitad, mitad} }; }
    }
}


bool resuelveCaso()
{
    int numElem;
    cin >> numElem;
    if (numElem == 0) return false;
    vector<int> v1(numElem);
    vector<int> v2(numElem);
    for (int& i : v1) cin >> i;
    for (int& i : v2) cin >> i;

    // Aqui codigo del alumno
    int min = INT_MAX;//abs(v1[0] - v2[0]);
    pair<bool, pair<int, int>> sol = resuelve(v1, v2, 0, numElem - 1, min);
    if (sol.first) {
        cout << "SI " << sol.second.first;
    }
    else cout << "NO " << sol.second.first << " " << sol.second.second;
    cout << "\n";
    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}