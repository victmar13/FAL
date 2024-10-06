//Victoria Martin Rojo
//A43

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Solucion recursiva lineal no final
int transformando(int n) {
	//caso base
	if (n < 10) {
		if (n % 2 == 0) { return n + 1; }
		else return n - 1;
	}
	//caso recursivo
	else {
		int digito;
		if (n % 2 == 0) { digito = n % 10 + 1; }
		else digito = n % 10 - 1;
		return transformando(n / 10) * 10 + digito;
	}
}

// SOlucion recursiva lineal final
/*int transformandoFinal(int n, int nuevo, int pot) {
	//caso base
	int digito;
	if (n % 2 == 0) {
		digito = n % 10 + 1;
	}
	else digito = n % 10 - 1;
	if (n < 10) {
		return digito * pot + nuevo;
	}
	//caso recursivo
	else return transformandoFinal(n / 10, digito * pot + nuevo, 10 * pot);

}*/

bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	cin >> num;
	if (!cin) return false;
	// resolver y escribir los resultados
	//no final
	int suma = transformando(num);

	//final
	//int suma = transformandoFinal(num, 0, 1);
	
	cout << suma << "\n";
	return true;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	return 0;
}