#include "CuaIOParInt.hh"
#include <queue>
using namespace std;

//1.tener el hh y el cc en la misma carpeta que el programa
//2.hacer make para compilarlo todo ezpz
//3.si esta bien, comprimirlo haciendo tar -cvf sol.tar ...

void repartir_usuari (queue<ParInt>& c) {
	queue<ParInt> d;
	queue<ParInt> e;
	int sumd = 0;
	int sume = 0;
	while (not c.empty()) { //antes que hacer un for hasta el size, mejor esto
		ParInt a = c.front();
		if (sumd <= sume) {
			d.push(a);
			sumd += a.segon();

		}

		else { 
			e.push(a);
			sume += a.segon();
		}

		c.pop();

	}
	escriureCuaParInt(d);
	cout << endl;
	escriureCuaParInt(e);

}

int main() {
	queue<ParInt> q;
	llegirCuaParInt(q);//como cuaioparint no es una clase, no se hace q.llegir...
	repartir_usuari(q);


}