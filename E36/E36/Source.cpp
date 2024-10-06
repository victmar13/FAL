//Victoria Martin Rojo
//A43

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Solucion recursiva lineal no final
int sumaDigitos(int n) {
	//caso base
	if (n < 10) {
		return n;
	}
	//caso recursivo
	else return sumaDigitos(n / 10) + n % 10;
}

// SOlucion recursiva lineal final
/*int sumaDigitosFinal(int n, int tot) {
	//caso base
	if (n == 0) {
		return tot;
	}
	//caso recursivo
	else return sumaDigitosFinal(n / 10, tot + n % 10);

}*/

bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, numero;
	cin >> tam >> numero;
	if (!cin) return false;
	// resolver y escribir los resultados
	int suma = sumaDigitos(numero);
	for (int i = 0; i < tam; ++i) {
		cin >> numero;
		//no final
		if (sumaDigitos(numero) == suma) cout << numero << " ";
		//final
		//if (sumaDigitosFinal(numero, 0) == suma) cout << numero << " ";

	}
	cout << "\n";
	return true;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	return 0;
}
