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


int superficieInic(tDatos const& d, int presupuesto) {
	int i = 0; int sumaSuperf = 0; int sumaCoste = 0;
	while (i < d.objetos.size() && sumaCoste + d.objetos[i].coste <= presupuesto) {
		sumaSuperf += d.objetos[i].superficie;
		sumaCoste += d.objetos[i].coste;
		++i;
	}
	return sumaSuperf;
}

int estimar(tDatos const& d, int pos, tSol& s) {
	int i = pos + 1, sumaCoste = s.costeAct, sumaSuperf = 0;
	//mientras no nos pasemos del vector y el coste que llevemos mas el del obj sig no se pase de presupuesto
	while (i < d.objetos.size() && sumaCoste + d.objetos[i].coste <= d.presupuesto) {
		sumaCoste += d.objetos[i].coste;
		sumaSuperf += d.objetos[i].superficie;
		i++;
	}
	if (i < d.objetos.size() && sumaCoste < d.presupuesto) {
		//superficie a llenar * presupuesto que nos queda por gastar / el presupuesto que teniamos
		// Esta superficie * coste/ coste == superficie-> superficie que nos queda por rellenar la rellenamos
		sumaSuperf += d.objetos[i].superficie * (d.presupuesto - sumaCoste) / d.objetos[i].coste + 1;
	}
	return sumaSuperf;
}

void resolver(tDatos const& d, int pos, tSol& s, int superfMejor) { //, vector<int> const& acum
	// tomamos el objeto
	s.sol[pos] = true;
	s.costeAct += d.objetos[pos].coste;
	s.superficieAct += d.objetos[pos].superficie;
	if (s.costeAct <= d.presupuesto) { // lo que llevamos menor que lo que podemos gastar
		if (pos == s.sol.size() - 1) {//es sol
			if (s.superficieAct > superfMejor) {//sol mejor
				superfMejor = s.superficieAct;
				s.solMejor = s.sol;
			}
		}
		else {//no es solucion
			//seguimos rellenando el vector sol con el siguiente
			resolver(d, pos + 1, s, superfMejor);
		}
	}
	//recupera valores
	s.costeAct -= d.objetos[pos].coste;
	s.superficieAct -= d.objetos[pos].superficie;
	//caso de que no compre el objeto
	s.sol[pos] = false;
	//no hay que validarlo, solo añadir el siguiente objeto 
	if (pos == s.sol.size() - 1) {//es sol
		if (s.superficieAct > superfMejor) {//sol mejor
			superfMejor = s.superficieAct;
			s.solMejor = s.sol;
		}
	}
	else {//no es solucion
		//seguimos rellenando el vector sol con el siguiente, hacemos estimacion
		if (estimar(d, pos, s) + s.superficieAct > superfMejor) { resolver(d, pos + 1, s, superfMejor); }
	}// si la estimacion mas lo que llevamos no nos da una mejor solucion, ni nos interesa
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