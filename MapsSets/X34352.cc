#include <map>
#include <iostream>
#include <string>
using namespace std;

//*it.first = it-> first

int main() {
	map <char, string> m;
	char op;
	string s;
	while (cin >> op >> s) {
		map <char, string>::const_iterator it = m.find(s); //buscamos si la string ya está en el map
		if (op == 'a') { //incrementar string del siguiente
			if (it == m.end()) m.insert(make_pair(s, 1)); //limitamos el recorrido
				else m[s] = it-> second + 1; //incrementamos el string
		}

		else if (op == 'f') { //escribir frecuencia
			if (it == m.end()) cout << 0 << endl;
			else cout << it-> second << endl; //escribimos el segundo elemento del par al que apunta it

		}
	}
}