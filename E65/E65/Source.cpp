//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;


struct tSol {
	vector<char> sol;
	vector<bool> marcas;
};

void escribirSol(vector<char> const& v) {
	for (char c : v)cout << c;
	cout << "\n";
}

void vars(int m, int n, int k, tSol& v) {
	for (char i = 'a'; i < ('a' + m); i++) {
		v.sol[k] = i;
		if (!v.marcas[i - 'a']) { //solucion valida?
			v.marcas[i - 'a'] = true; //letra utilizada
			if (k == n - 1) { //Si ha completado el tam max de k 
					escribirSol(v.sol);
			}

			else {
				vars(m, n, k + 1, v);
			}
			v.marcas[i - 'a'] = false;
		}
	}
}

bool resuelveCaso() {
	int m, n;
	cin >> m >> n;
	if (!cin) { return false; }

	//soluciones
	tSol s;
	s.sol.resize(n);
	s.marcas.assign(m, false);
	vars(m, n, 0, s);
	cout << "\n";
	return true;
}

int main() {

	while (resuelveCaso()) {}

	return 0;
}