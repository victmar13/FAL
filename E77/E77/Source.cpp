// Nombre y apellidos del alumno Victoria Martin ROjo
// Usuario del juez de clase A 43
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
//*******************************
// Aqui explicacion del algoritmo de vuelta atras. Como es el vector solucion y como se obtiene
//
//
//*******************************

using namespace std;
// Para una cancion
struct tSol {
    vector<int> sol1;
    vector<int> sol2;
    int sumaT1 = 0, sumaT2 = 0;
    vector<bool> escuchada;
};

struct cancion {
    int duracion, satisfaccion;
};

// Para los datos de entrada
struct tDatos {
    int numCanciones;  // Numero de canciones
    int tIda; // Duracion del viaje de ida
    int tVuelta;  // Duracion del viaje de vuelta
    vector<cancion> canciones;  // Duracion y puntuacion de cada cancion // [0] es la duracion y [1] es la satisfaccion
};

// Aqui las funciones implementadas por el alumno

void resolver(const tDatos& d, tSol& s, int& SatisfMax, int SatisfActual, vector<int> const& SatisfMaxAct, int const& duracionTot, vector<int> const& minAcum) {
    //es solucion
    if (s.sumaT1 == d.tIda && s.sumaT2 == d.tVuelta) {
        //es solucion valida
        if (SatisfActual > SatisfMax) {
            SatisfMax = SatisfActual;
        }
        return;
    }
    
    for (int i = 0; i < d.numCanciones; i++) {
        // si cancion no se ha cogido aun
        if (!s.escuchada[i]) {
            if (SatisfActual + SatisfMaxAct[i + 1] > SatisfMax && duracionTot > ((d.tIda-s.sumaT1)+(d.tVuelta - s.sumaT2)) && (minAcum[i+1] + s.sumaT1 <= d.tIda || minAcum[i+1] + s.sumaT2 <= d.tVuelta)) { //podas
            //cabe en el viaje de ida

                if (d.canciones[i].duracion + s.sumaT1 <= d.tIda) {
                    s.sol1.push_back(i);
                    s.escuchada[i] = true;
                    SatisfActual += d.canciones[i].satisfaccion;
                    s.sumaT1 += d.canciones[i].duracion;
                    resolver(d, s, SatisfMax, SatisfActual, SatisfMaxAct, duracionTot - d.canciones[i].duracion, minAcum);
                    s.sol1.pop_back();
                    s.escuchada[i] = false;
                    SatisfActual -= d.canciones[i].satisfaccion;
                    s.sumaT1 -= d.canciones[i].duracion;
                }
                //cabe en el viaje de vuelta
                if(d.canciones[i].duracion + s.sumaT2 <= d.tVuelta) {
                    s.sol2.push_back(i);
                    s.escuchada[i] = true;
                    SatisfActual += d.canciones[i].satisfaccion;
                    s.sumaT2 += d.canciones[i].duracion;
                    resolver(d, s, SatisfMax, SatisfActual, SatisfMaxAct, duracionTot - d.canciones[i].duracion, minAcum);
                    s.sol2.pop_back();
                    s.escuchada[i] = false;
                    SatisfActual -= d.canciones[i].satisfaccion;
                    s.sumaT2 -= d.canciones[i].duracion;
                }
            }
            
        }
     
    }
}





bool  resuelveCaso() {
    // lectura de datos
    tDatos d;
    tSol s;
    cancion c;
    int duracionTotal = 0; // duracion de todas las canciones que no hemos puesdto aun
    cin >> d.numCanciones >> d.tIda >> d.tVuelta;
    if (d.numCanciones == 0 && d.tIda == 0 && d.tVuelta == 0) return false;
   // int minDuracion = d.tIda + d.tVuelta + 1; // minimo de las duraciones
    for (int i = 0; i < d.numCanciones; ++i){
        cin >> c.duracion >> c.satisfaccion;
        d.canciones.push_back(c);
        /*if (c.duracion < minDuracion) {
            minDuracion = c.duracion;
        }*/
        duracionTotal += c.duracion; // para poda de que haya mas tiempo de canciones que tiempo de viaje en total
    }
    //acum de minimos
    vector<int> minAcum(d.numCanciones);
    minAcum[d.numCanciones-1] = d.canciones[d.numCanciones-1].duracion;
    for (int i = d.numCanciones - 2; i >= 0; i--) {
        if (d.canciones[i].duracion < minAcum[i+1]) {
            minAcum[i] = d.canciones[i].duracion;
        }
        else {
            minAcum[i] = minAcum[i + 1];
        }
    }
    minAcum.push_back(0);

    //Acumulado de satisfacciones
    vector<int> SatisfMaxAcum(d.numCanciones + 1);
    SatisfMaxAcum[d.numCanciones] = 0;
    for (int i = d.numCanciones - 1; i >= 0; i--) {
        SatisfMaxAcum[i] = SatisfMaxAcum[i + 1] + d.canciones[i].satisfaccion;
    }

    int SatisfMax = 0, satisfAct = 0;
    s.escuchada.assign(d.numCanciones, false);

    resolver(d, s, SatisfMax, satisfAct, SatisfMaxAcum, duracionTotal, minAcum);

    // escribir sol
    if (SatisfMax == 0)
        cout << "Imposible\n";
    else
        cout << SatisfMax << "\n";

    // llamada a VA


    // Escribir resultado


    return true;
}


int main() {

    while (resuelveCaso()) {} //Resolvemos todos los casos

    return 0;
}




