#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

void avg (const vector <bool>& asig, const int& n, const int& s) {
	int dni;
	cin >> dni;
	Estudiant e(dni);
	double notas;
	double ac = 0; //suma para hacer la media con el total de asignaturas del estudiante

	for (int i = 0; i < n; ++i) {
		cin >> notas;
		if (asig[i]) ac += notas; //calculamos media solo con las asignaturas que queramos
	}
	ac /= double(s);
	e.afegir_nota(ac);
	e.escriure();
}

void leer_bool (vector <bool>& asig, int s) {
	int n;
	for (int i = 0; i < s; ++i) {
		cin >> n;
		asig[n-1] = true; //ponemos true a las asignaturas que queramos leer
	}
}

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	vector <bool> asig(n, false);
	leer_bool(asig,s);
	for (int i = 0; i < m; ++i) avg(asig, n, s); //calculo de la media de cada estudiante
}