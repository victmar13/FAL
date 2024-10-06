//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;
struct tObjetos {
	int coste, superficie;
};
struct tDatos {
	int numObjs, presupuesto;
	vector<tObjetos> objetos;
};

// Para ordenar los objetos hacemos una clase comparador que
// sobrecarga el operador parentesis
class comparador {
public:
	bool operator()(tObjetos obj1, tObjetos obj2) {
		return(float)obj1.superficie / obj1.coste > (float)obj2.superficie / obj2.coste;
	}
};

//Escribe la solución
ostream& operator << (ostream& salida, vector<bool> const& v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i]) cout << i << " ";
	}
	cout << "\n";
	return salida;
}

struct tSol {
	vector<bool> sol;
	int costeAct;
	int superficieAct;
	vector<bool> solMejor;
};

//Estimar mayor superficie a conseguir desde este momento 
int estimar(tDatos const& d, tSol& s, int pos) {
	int i = pos + 1; int sumaCoste = s.costeAct; int sumaSuperf = 0;
	while (i < d.objetos.size() && sumaCoste + d.objetos[i].coste <= d.presupuesto) {
		sumaCoste += d.objetos[i].coste;
		sumaSuperf += d.objetos[i].superficie;
		++i;
	}
	//Como la division es entera se suma 1 al resultado para asignar una cota superior a la variable entera
	if (i < d.objetos.size() && sumaCoste < d.presupuesto) {
		sumaSuperf += d.objetos[i].superficie * (d.presupuesto - sumaCoste) / d.objetos[i].coste + 1;
	}
	return sumaSuperf;
}

bool esSolucionMejor() {
	return true;
}

void resolver(tDatos const& d, int pos, tSol& s, int superfMejor) { //, vector<int> const& acum
	// se toma el objeto
	s.sol[pos] = true;
	s.costeAct += d.objetos[pos].coste;
	s.superficieAct += d.objetos[pos].superficie;
	if (s.costeAct <= d.presupuesto) { // Es valida
		if (pos == s.sol.size() - 1) { // es solucion
			if (s.superficieAct > superfMejor) { // es solucion mejor
				s.solMejor = s.sol;
				superfMejor = s.superficieAct;
			}
		}
		else {
			resolver(d, pos + 1, s, superfMejor);
		}
	}
	s.costeAct -= d.objetos[pos].coste; //  volvemos a tener el valor anterior
	s.superficieAct -= d.objetos[pos].superficie;
	//no se toma el objeto
	s.sol[pos] = false;
	//si no se toma el objetp normalmente no hay que actualizar el coste, ni comprobar que es valida
	if (pos == s.sol.size() - 1) {
		if (s.superficieAct > superfMejor) {
			s.solMejor = s.sol;
			superfMejor = s.superficieAct;
		}
	}
	else {
		if (estimar(d, s, pos) + s.superficieAct > superfMejor) {
			resolver(d, pos + 1, s, superfMejor);
		}
	}
}

int superficieInic(tDatos const& d, int presupuesto) {
	int i = 0; int sumaSuperf = 0; int sumaCoste = 0;
	while (i < d.objetos.size() && sumaCoste + d.objetos[i].coste <= presupuesto) {
		sumaSuperf += d.objetos[i].superficie;
		sumaCoste += d.objetos[i].coste;
		++i;
	}
	return sumaSuperf;
}

bool resuelveCaso() {
	tDatos d;
	cin >> d.numObjs;
	if (!cin || d.numObjs == 0) { return false; }
	cin >> d.presupuesto;
	//datos de cada objeto
	for (int i = 0; i < d.numObjs; i++) {
		tObjetos aux;
		cin >> aux.coste >> aux.superficie;
		d.objetos.push_back(aux);
	}
	sort(d.objetos.begin(), d.objetos.end(), comparador());
	tSol s;
	s.sol.resize(d.numObjs);
	s.costeAct = 0;
	s.superficieAct = 0;
	int superficieMejor = superficieInic(d, d.presupuesto);

	resolver(d, 0, s, superficieMejor);
	cout << superficieMejor << "\n";
	return true;
}

int main() {

	while (resuelveCaso()) {}

	return 0;
}