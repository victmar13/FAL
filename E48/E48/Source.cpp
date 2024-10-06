//Victoria Martin Rojo
//A43

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Funcion que busca la posicion mas a la izquierda del elemento

int menorNumIzq(vector < int> const& v, int ini, int fin) {
	if (ini == fin) return ini; // vector vacio
	else if (ini + 1 >= fin) return ini; // vector 1 elemento
	else { // Vector de dos o mas elementos
		int mitad = (ini + fin - 1) / 2;
		if (v[mitad] > v[mitad+1]) return menorNumIzq(v, mitad + 1, fin); // -> "\"
		else return menorNumIzq(v, ini, mitad + 1);  // incluye la mitad -> "/"
	}
}
// Funcion que busca la posicion mas a la derecha del elemento
int menorNumDr(vector <int> const& v, int ini, int fin) {
	if (ini >= fin) return ini; // vector vacio
	else if (ini + 1 == fin) return ini; // vector un elemento
	else { // vector 2 o mas elementos
		int mitad = (ini + fin) / 2;
		if (v[mitad-1] < v[mitad]) return menorNumDr(v, ini, mitad); // -> "/"
		else return menorNumDr(v, mitad, fin); // Incluye el elemento mitad -> "\"
	}
}
bool resuelveCaso() {
	int numelem;
	cin >> numelem;
	if (!cin || numelem == -1) return false;
	vector < int > v(numelem);
	for (int& n : v) cin >> n;
	
	if (!numelem) cout << 0 << endl;
	// Busca en el lado izquierdo
	else {
		int posIz = menorNumIzq(v, 0, (int)v.size());
		int posDer = menorNumDr(v, 0, (int)v.size());
		cout << abs(posDer - posIz) + 1 << endl;
	}
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}