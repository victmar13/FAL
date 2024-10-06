
#include <iostream>
#include <vector>
using namespace std;

const int MAX_OBJS = 20;

// Lista con los objetos a portar 
typedef struct {
	int tamanios[MAX_OBJS];  // Array en cuyas primeras posiciones se guardan
	// los tama�os de los objetos
	int n_objetos;           // Numero de objetos
	vector<int> usado;
} tObjetos;



/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/

int min_numero_de_cajas(const tObjetos& objetos, int capacidad_caja, int cont, int suma, vector<bool> & usado, int maxCont){
	for (int i = 0; i < objetos.n_objetos; i++) {
		if (!usado[i]) {
			suma += objetos.tamanios[i];
			usado[i] = true;
			if (suma < capacidad_caja) {
				min_numero_de_cajas(objetos, capacidad_caja, cont, suma, usado, maxCont);
			}
			else {
				if (suma == capacidad_caja) {
					min_numero_de_cajas(objetos, capacidad_caja, cont++, 0, usado, maxCont);
					suma -= objetos.tamanios[i];
					usado[i] = false;
				}
				else {
					suma -= objetos.tamanios[i];
					if (i != objetos.n_objetos - 1){
						min_numero_de_cajas(objetos, capacidad_caja, cont, suma, usado, maxCont);
					}
					
					usado[i] = false;

				}
				if (i == objetos.n_objetos - 1) {
					cont++;
				}
			}
		}
		suma -= objetos.tamanios[i];
		usado[i] = false;
	}

	if (cont < maxCont)
		maxCont == cont;
	return maxCont;
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso() {
	int capacidad;
	cin >> capacidad;
	if (capacidad != -1) {
		tObjetos objetos;
		cin >> objetos.n_objetos;
		for (int i = 0; i < objetos.n_objetos; i++) {
			cin >> objetos.tamanios[i];
		}
		vector<bool>usado(objetos.n_objetos, false);
		cout << min_numero_de_cajas(objetos, capacidad, 0, 0, usado, objetos.n_objetos) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}