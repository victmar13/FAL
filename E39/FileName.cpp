//Victoria Martin Rojo
//A43

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


//N =  max digitos entre n y  m
//coste O(log(N))

//DEFINICION RECURSIVA SOLUCION NO FINAL
/*sumarNF(n, m){
        caso base: resto de (n + m)/10 -> modulo cuando llega al ultimo numero de la secuencia ->   si   n < 10 y m < 10   coste constante ya q es return

        caso recursivo:  sumarNF (n/10, m/10)* 10 + (n+m)%10      si  RCasos                    }                          llamada recursiva y operacion constante
*/

// función que resuelve el problema

int sumaNoFinal(int n, int m) { // coste O(log(N), N = max num de digitos entre m y n 
    if (n < 10 && m < 10) {  
        return(n + m) % 10;
    }
    else { return (sumaNoFinal(n / 10, m / 10) * 10) + ((n + m) % 10); } //si uno de los dos numeros es >10 se pasa la misma funcion pero m y n /10 y a esto se le multiplica *10 en el ultimo caso cada vuelta y se le suma el modulo 10 de la suma del ultimo numero quehemos pasado
}

//DEFINICION RECURSIVA SOLUCION FINAL
// 
//N =  max digitos entre n y  m
//coste O(log(N))

/*sumarF(n, m,i, pot)
        caso base: (n + m)%10 * pot + i;                         si   n < 10 y m < 10

        caso recursivo: sumarF(n/10, m/10, i + (n + m)%10 * pot ,pot*10)      si  RCasos                    }
*/

int sumaFinal(int n, int m, int i, int pot) {// se empieza desde atras (el ultimo numero de la cadena  i = 0, pot = 1 al inicio
    if (n < 10 && m < 10) {
        return i + (n + m) % 10 * pot;
    }
    else { return sumaFinal(n / 10, m / 10, i + (n + m) % 10 * pot, pot * 10); }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;

    cin >> n >> m;

    int solNoFinal = sumaNoFinal(n, m);
    int solFinal = sumaFinal(n, m, 0, 1);
    // escribir sol
    cout << solNoFinal << " " << solFinal << "\n";

}

int main() {
    // Para la entrada por fichero.

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}