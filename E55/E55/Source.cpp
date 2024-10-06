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
using lli = long long int;
//*******************************
// Explicacion del algoritmo empleado
// Coste del algoritmo. Incluye recurrencia y desplegado de la recurrencia
//
// Y no olvides poner comentarios en el codigo
//*******************************

// Aqui las funciones implementadas por el alumno
int resuelve(vector<int> const& v, lli ini, lli fin, int viajes) {
    //caso base
    if (ini == fin - 1) return ini;
    else {
        int mitad = (ini + fin) / 2;
        int peso = 0, pesoMax = 0, cont = 1;
        //bucle cogiendo las obras poniendo de peso maximo la mitad
        for (int i = 0; i < v.size(); i++) {
            if ((peso + v[i]) <= mitad) { peso += v[i]; }
            else { cont++; peso = v[i]; }
            if (peso > pesoMax) { pesoMax = peso; }
        }
        if (cont > viajes) { // hacemos mas viajes de lso permitidos, necesitamos mas peso
            return resuelve(v, mitad + 1, fin, viajes);
        }
        else if (cont < viajes) { // hacemos viajes de menos, podemos quitarles peso
            return resuelve(v, ini, mitad, viajes);
        }
        else { return pesoMax; }
    }
}


bool resuelveCaso()
{
    int numElem, viajes;
    cin >> numElem >> viajes;
    if (numElem == 0 && viajes == 0) return false;
    vector<int> v(numElem);
    lli pesoMax = 0, sumaPesos = 0;
    for (int i = 0; i < numElem; i++) {
        cin >> v[i];
        if (v[i] > pesoMax) pesoMax = v[i];
        sumaPesos += v[i];
    }

    // Aqui codigo del alumno
    int sol = resuelve(v, pesoMax, sumaPesos, viajes);
    
    cout << sol << "\n";
    return true;

}

int main() {

    while (resuelveCaso())
        ;

    return 0;
}
