#include <map>
#include <iostream>
#include <string>
using namespace std;

//*it.first = it-> first

int main() {
	map<string, int> m; 
	char op;
	string s;
	while (cin >> op >> s) {
		map<string, int>::iterator it = m.find(s); //buscamos si la string ya está en el map
		if (op == 'a') { //incrementar string del siguiente
			if (it == m.end()) m.insert(make_pair(s, 1)); //limitamos el recorrido
				else ++(it -> second); //incrementamos la frecuencia
		}

		else if (op == 'f') { //escribir frecuencia
			if (it == m.end()) cout << 0 << endl;
			else cout << it-> second << endl; //escribimos el segundo elemento del par al que apunta it

		}
	}
}