#include <iostream>
using namespace std;

int main() {
	int n, x, sec, tot = 0; 
	cin >> n >> x; //decimos cuantas secuencias hacemos y el numero limite
	
	for (int i = 1; i <= n; ++i) { //para decir a cada iteracion el numero de la secuencia
		while (cin >> sec and sec != x) { //solo nos importan los numeros antes del limite
			tot += sec; //acumulacion
		}
			string s;
			getline(cin, s);
			cout << "La suma de la secuencia " << i << " es " << tot << endl;
			tot = 0; //reseteamos el total para la siguente secuencia
		}
	}

