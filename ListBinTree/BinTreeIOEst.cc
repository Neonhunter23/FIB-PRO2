#include "BinTreeIOEst.hh"

void read_bintree_est (BinTree<Estudiant>& a) {
	Estudiant e;
	e.llegir();
	if (e.consultar_DNI() != 0 or e.consultar_nota() != 0) {
		BinTree<Estudiant> t, s;
		read_bintree_est(t);
		read_bintree_est(s);
		a = BinTree<Estudiant>(e, t, s); //preorden: raiz, left, right
	}

}

void write_bintree_est (const BinTree<Estudiant>& a) {
	if (not a.empty()) { //inorden: left, raiz, right
		write_bintree_est(a.left());
		if (a.value().te_nota()) a.value().escriure(); //se escriben las notas de los elementos del bintree
		else cout << a.value().consultar_DNI() << "-1" << endl; //si no tiene nota
		write_bintree_est(a.right());
	}

}