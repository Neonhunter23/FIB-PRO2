#include "Estudiant.hh"
#include <iostream>
#include <vector>

using namespace std;

/* Leer vector */
void leer_vector_est(vector <Estudiant>& v) { // version accion
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  Estudiant e1;
  for (int i=0; i<numEst;++i) {
    e1.llegir();
	v[i] = e1;
	}
}

/* Escribir vector */
void escribir_vector_est(const vector <Estudiant>& v) {
  for (int i=0; i<v.size();++i)
    v[i].escriure();
}

vector<Estudiant> simp_vec(const vector <Estudiant>& v) {
	vector <Estudiant> w;
	Estudiant e = v[0];
	Estudiant f;
	for (int i = 1; i < v.size(); ++i) {
		f = v[i];
		if (e.consultar_DNI() == f.consultar_DNI()) {
			if (e.te_nota() and f.te_nota()) {
				if (e.consultar_nota() < f.consultar_nota()) e.modificar_nota(f.consultar_nota());
			}
			else if (f.te_nota()) e.afegir_nota(f.consultar_nota());
		}
		else{
		w.push_back(e);
		e = f;
		}
		
	}
	w.push_back(e);
	return w;
}



int main(){
vector <Estudiant> v;
leer_vector_est(v);
vector <Estudiant> w = simp_vec(v);
escribir_vector_est(w);
}
