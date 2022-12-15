#include <iostream>
#include <map>
using namespace std;

int main() {
map<string, int> m;
char codigo;
string s;

while (cin >> codigo >> s) {
	map<string, int>::iterator it = m.find(s);
	if (codigo == 'a') { //sumar 1 a la frecuencia
		if (it == m.end()) m.insert(make_pair(s, 1)); //primera aparicion del elemento, lo añadimos al map
		else ++(it -> second); //si ya esta, sumamos 1 a la frecuencia
	}
	else if (codigo == 'e') { //restar 1 a la frecuencia
		if (it != m.end()) {
			 if (it -> second == 1) m.erase(it);
			 else --(it -> second); //para que la frecuencia no baje de 0
		}
	}

	else if (codigo == 'f') { //imprimir la frecuencia
		if (it == m.end()) cout << 0 << endl;
		else cout << it -> second << endl;
	}

}



}