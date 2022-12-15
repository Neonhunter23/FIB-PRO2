#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<stack<string>> v(n); //jope, que largo
	string s;
	int cat, x; //
	while (cin >> m and m != -4) {
		if (m == -1) {
			cin >> s >> cat; //leemos libro y la pila donde lo dejamos
			v[cat-1].push(s); //cat-1 porque esta indexada en el vector
		}
		if (m == -2) {
			cin >> x >> cat; //retirar un numero de libros x de una categoria
			if (x <= v[cat-1].size()) //limite de altura de la pila
				for (int i = 0; i < x; ++i) v[cat-1].pop();
		}
		if (m == -3) {
			cin >> cat;
			cout << "Pila de la categoria " << cat << endl;
			stack<string> t = v[cat-1]; //cola auxiliar para escribir
			for (int i = 0; i < v[cat-1].size(); ++i) {
				cout << t.top() << endl;
				t.pop();
			}
			cout << endl;
		}
	}
}


