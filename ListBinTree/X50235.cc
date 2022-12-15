#include "BinTree.hh"

bool poda_subarbre(BinTree<int>& a, int x) {
	if (not a.empty()) {
		if (x == a.value()) {
			a = BinTree<int>(); //machacas el arbol con uno vacio
		 	return true; //caso general, podamos el arbol entero
		}
		else {
			BinTree<int> esq = a.left(); //la raiz es el hijo izq
			BinTree<int> dret = a.right(); //la raiz es el hijo der
			bool b = poda_subarbre(esq, x); //comprobar si la nueva raiz es el valor
			if (b) {
				a = BinTree<int>(a.value(), esq, dret); //se actualiza el arbol con sus valores anteriores pero con una rama podada
				return true;
			}
			else {
				bool c = poda_subarbre(dret, x);
					a = BinTree<int> (a.value(), esq, dret);
					return c; //el arbol del hijo izq ya seguira igual
			}
		}

	}
	return false;
}

