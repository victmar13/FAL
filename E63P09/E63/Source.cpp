// Victoria Martin Rojo
// A43


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDato {
    bool cumple;
    int num, nReps = 0;
};
// función que resuelve el problema
tDato resolver(vector <int> const& v, int ini, int fin) {
    tDato sol;
    if (ini >= fin) {
        sol.cumple = false;
        sol.nReps = 0;
        sol.num = 0;
        return sol;
    }
    if (ini + 1 == fin) {       //1 elemento
        sol.cumple = true;
        sol.nReps++;
        sol.num = v[ini];
        return sol;
    }
    else {
        //2 o mas elementos
        int mitad = (ini + fin) / 2;

        tDato solIzda = resolver(v, ini, mitad);
        tDato solDcha = resolver(v, mitad, fin);

        //sol.cumple = solIzda.cumple || solDcha.cumple;

        if (solIzda.nReps < solDcha.nReps) {
            for (int i = ini; i < mitad; i++) {
                if (solDcha.num == v[i]) solDcha.nReps++;
            }
            sol.cumple = solDcha.nReps > (fin - ini) / 2;

            sol.num = solDcha.num;
            sol.nReps = solDcha.nReps;
        }
        else if (solIzda.num == solDcha.num) {
            sol.nReps = solIzda.nReps + solDcha.nReps;
            sol.num = solDcha.num;
        }
        else {
            for (int i = mitad; i < fin; i++) {
                if (solIzda.num == v[i]) solIzda.nReps++;
            }
            sol.cumple = solIzda.nReps > (fin - ini) / 2;

            sol.num = solIzda.num;
            sol.nReps = solIzda.nReps;
        }

        return sol;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num = 0;
    cin >> num;
    vector <int> v;
    while (num != 0) {
        v.push_back(num);
        cin >> num;
    }

    tDato sol = resolver(v, 0, v.size());
    if (sol.cumple) cout << sol.num << endl;
    else cout << "NO" << endl;
}

int main() {
    // Para la entrada por fichero.

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}