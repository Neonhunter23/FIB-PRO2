#include "Cjt_estudiants.hh"
#include <iostream>
#include <vector>

using namespace std;

double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

// -1: añadir un nuevo estudiante, excepto si ya estaba antes o el conjunto estaba lleno
// -2: consultar nota a partir del dni, excepto si no esta en el conjunto o su nota no es valida
// -3: modificar la nota de un estudiante, excepto si no esta en el conjunto
// -4: redondear nota de todos los estudiantes del conjunto
// -5: escribir el conjunto
// -6: se termina el programa (condicion while)

int main() {
	Cjt_estudiants a;
	a.llegir();
	int n;
	cin >> n;

	int dni, size;
	double nota;
	Estudiant e;

	while (n != -6) {

		if (n == -1) {
			cin >> dni >> nota;
			e = Estudiant(dni);
			if (nota >= 0 and nota <= 10) e.afegir_nota(nota);
			if (a.existeix_estudiant(dni)) cout << "el estudiante " << dni << " ya estaba" << endl << endl;
			else if (a.mida() == 5) cout << "el conjunto esta lleno" << endl << endl;
			else a.afegir_estudiant(e);
		}

		else if (n == -2) {
			cin >> dni;
			if (a.existeix_estudiant(dni)) {
				e = a.consultar_estudiant(dni);
				if (e.te_nota()) cout << "el estudiante " << dni << " tiene nota " << e.consultar_nota() << endl << endl;
				else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
			} 
			else cout << "el estudiante " << dni << " no esta" << endl << endl;
		}

		else if (n == -3) {
			cin >> dni >> nota;
			if (a.existeix_estudiant(dni)) {
				e = a.consultar_estudiant(dni);
				if (e.te_nota()) e.modificar_nota(nota);
				else e.afegir_nota(nota);
				a.modificar_estudiant(e);
			}
			else cout << "el estudiante " << dni << " no esta" << endl << endl;
		}

		else if (n == -4) {
			size = a.mida();
			for (int i = 1; i <= size; ++i) {
				e = a.consultar_iessim(i);
				if (e.te_nota()) {
					e.modificar_nota(redondear(e.consultar_nota()));
					a.modificar_iessim(i, e);
				}
			}
		}

		else if (n == -5) {
			a.escriure();
			cout << endl;
		}

		cin >> n;

	}
}