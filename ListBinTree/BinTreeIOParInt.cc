#include "BinTreeIOParInt.hh"

void read_bintree_parint (BinTree<ParInt>& a) { //preorden: raiz, hijo izq, hijo der
	ParInt p;
	if (p.llegir()) { //si no es 00, entonces es falso, tambien llegir es bool
		BinTree<ParInt> t, s; //dos arboles auxiliares que seran los hijos de a
		read_bintree_parint(t); //leer hijo izq
		read_bintree_parint(s); //leer hijo der
		a = BinTree<ParInt> (p, t, s);

	}
}

void write_bintree_parint (const BinTree<ParInt>& a) { //inorden: hijo izq, raiz, hijo der
	if (not a.empty()) {
		write_bintree_parint(a.left());
		a.value().escriure();
		write_bintree_parint(a.right());
	}
	
}