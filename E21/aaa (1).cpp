//Victoria Martin Rojo
//A43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>


using namespace std;

vector<int> resolver(vector<int> const& v1, vector<int> const& v2) { // 
	int tam1 = v1.size();
	int tam2 = v2.size();
	vector<int> sol;
	int pos1 = 0, pos2 = 0;
	while (pos1 < tam1 && pos2 < tam2) {
		if (v1[pos1] < v2[pos2]) {
			sol.push_back(v1[pos1]);
			pos1++;
		}
		else if (v2[pos2] < v1[pos1]) {
			sol.push_back(v2[pos2]);
			pos2++;
		}

		else { pos2++; pos1++; }
	}

	for (int i = pos1; i < tam1; i++) {
		sol.push_back(v1[i]);
	}

	for (int i = pos2; i < tam2; i++) {
		sol.push_back(v2[i]);
	}

	return sol;
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	
	vector<int> lista1;

	int num;
	cin >> num;
	while(num != 0){
		lista1.push_back(num);
		cin >> num;
	}
	
	vector<int> lista2;
	int num2;
	cin >> num2;
	while (num2 != 0) {
		lista2.push_back(num2);
		cin >> num2;
	}

	vector<int> sol = resolver(lista1, lista2);
	int tam = sol.size();
	for (int i = 0; i < tam; i++) {
		cout << sol[i] << " ";
	}
	cout << "\n";
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