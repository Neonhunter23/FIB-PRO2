#include <stack>
#include <iostream>
using namespace std;

//meter en la pila los abiertos, y cuando salga un cerrado, compararlo con el top para ver si son del mismo tipo
//despues de los ( o [ tiene que ir un ) o ], no puede haber mezclas

int main() {
	char c;
	cin >> c;
	stack<char> s;
	bool corr = true;
	

	while (c != '.' and corr) {
	if (c == '(' or c == '[') s.push(c); //metemos en la pila los parentesis abiertos
	else if (not s.empty() and (((s.top() == '(') and (c == ')')) or ((s.top() == '[') and (c == ']')))) s.pop();
	else corr = false;
	cin >> c;
	}

	if (c == '.' and not s.empty()) corr = false;
	if (corr) cout << "Correcte" << endl;
	else cout << "Incorrecte" << endl;
}