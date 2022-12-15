#include "LlistaIOParInt.hh"

int main() {
	list<ParInt> l;
	LlegirLlistaParInt(l);

	int x;
	cin >> x; //elemento que queremos ver repetido

	int apariciones = 0, ac = 0;

	for (list<ParInt>::iterator it = l.begin(); it != l.end(); ++it) {
		int a = (*it).primer(); //queremos contar las veces que aparece el primer elemento del par
		if (a == x) {
			++apariciones;
			ac += (*it).segon(); //suma total de su segundo elemento
		}
	}
	cout << x << " " << apariciones << " " << ac << endl;
} 