//nombre alumno victoria martin
//usuario juez a43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>

using namespace std;


// Solucion recursiva lineal final
void conversor(int n, string& dig) {
	//caso base
	if (n < 2) {
		dig = to_string(n % 2) + dig;
	}
	//caso recursivo
	else {
		dig = to_string(n % 2) + dig;
		conversor(n / 2, dig);
	}
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuración, y escribiendo la respuesta   

bool resuelveCaso() {
    //leer los datos de la entrada
    int num;
    cin >> num;

    if (num < 0 || !cin) {
        return false;
    }

	string sol = "";
	conversor(num, sol);
	cout << sol << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	};


    return 0;
}