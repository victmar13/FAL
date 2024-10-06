//Victoria Martin Rojo
//A43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>


using namespace std;

pair<int, pair<int, int>> resolver(vector<int> const& v, int perdida) { // 

	int cont = 0, maxSeq = 0, maxPosIni, maxPerdida = 0, maxPerdidaFinal = 0;
	int tam = v.size();
	for (int i = 0; i < tam; i++) {
		if (v[i] < perdida) {
			cont++;
			if (v[i] < maxPerdida) {
				maxPerdida = v[i];
			}
		}
		else {
			if (cont >= maxSeq && cont != 0) {
				maxSeq = cont;
				maxPosIni = i - cont;
				maxPerdidaFinal = maxPerdida;
			}
			else if (cont == maxSeq && maxPerdida <= maxPerdidaFinal) {
				maxSeq = cont;
				maxPosIni = i - cont;
				maxPerdidaFinal = maxPerdida;
			}
			
			cont = 0;
			maxPerdida = 0;
		}
	}
	if (cont == maxSeq && maxPerdida <= maxPerdidaFinal) {
		maxSeq = cont;
		maxPosIni = tam  - cont;
		maxPerdidaFinal = maxPerdida;
	}

	return{ maxSeq, {maxPosIni, maxPerdidaFinal} };
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	int tam, perdida;
	cin >> tam;
	if (tam == 0) { return false; }
	cin >> perdida;
	vector<int> beneficios(tam);
	for (int i = 0; i < tam; i++) {
		cin >> beneficios[i];
	}
	//sol = {tam secuencia mas larga de perdidas menores que "perdida", { inicio secuencia, máxima perdida}}
	pair<int, pair<int, int>> sol = resolver(beneficios, perdida); 
	if (sol.first == 0) {
		cout << "SIN PERDIDAS";
	}
	else cout << sol.first << " " << sol.second.first << " " << sol.second.second;
	cout << "\n";
	return true;
}
int main() {
	// Para la entrada por fichero.

	while (resuelveCaso());

	return 0;
}