#include <stack>
#include <iostream>
using namespace std;
//pista:
//no todo lo que se lea en la entrada se tiene que poner en una pila
	//2 casos: par e impar
	//leer la mitad, y luego ir comparando el top con el nuevo numero
	//si son iguales, hacemos pop del top, y comparamos el nuevo top con el nuevo numero
	//si es impar, hay un numero en medio, y lo tenemos que saltar

int main() {
	int n,m;
	cin >> n;
	int mig = n / 2;
	stack <int> s;
	for (int i = 0; i < mig; ++i) { //para leer stacks, leemos una secuencia de numeros y la metemos en el stack
		cin >> m;
		s.push(m);
	}
	if (n % 2 != 0) cin >> m; //saltamos el numero del medio
	bool pal = true;
	for (int i = 0; i < mig and pal; ++i) { //salimos si ya no es pal
		cin >> m;
		if (s.top() == m) s.pop();
		else pal = false;

	}
	if (pal) cout << "SI" << endl;
	else cout << "NO" << endl;
}