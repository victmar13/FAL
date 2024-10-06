//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

void escribirSol(vector<char> const& v) {
	for (char c : v)cout << c;
	cout << "\n";
}

void vars(int m, int n, int k, vector<char>& v) {
	for (char i = 'a'; i < ('a' + m); i++) {
		v[k] = i;
		if (k == n - 1) { //Si ha completado el tam max de k 
			escribirSol(v);
		}
		else {
			vars(m, n, k + 1, v);
		}
	}
}

bool resuelveCaso() {

	int m, n;
	cin >> m >> n;
	if (!cin) { return false; }

	//soluciones
	vector<char> v(n);
	vars(m, n, 0, v);
	cout << "\n";
	return true;
}

int main() {

	while (resuelveCaso()) {}

	return 0;
}