#include "Estudiant.hh"
#include <vector>

 void simplificar_vector(vector<Estudiant>& v, int& pos) {
 /* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
 /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */
 	int n = v.size();
 	pos = 0;
 	for (int i = 1; i < n; ++i) {
 		if (v[i].consultar_DNI() == v[pos].consultar_DNI()) {
 			if (v[i].te_nota()) {
 				if (v[pos].te_nota() and v[i].consultar_nota() > v[pos].consultar_nota()) 
 					v[pos].modificar_nota(v[i].consultar_nota());
 				else if (not v[pos].te_nota())
 					v[pos].afegir_nota(v[i].consultar_nota());
 			}
 		}
 		else {
 				++pos;
 				swap(v[pos], v[i]);
 		}
 	}
 }


