#include "vectorIOestudiant.hh"
#include "Estudiant.hh"
#include <iostream>
#include <vector>

using namespace std;

void redondear_vector_est (vector<Estudiant>& v){
	int n = v.size();
	for (int i = 0; i < n; ++i) {
	if (v[i].te_nota())
	 v[i].modificar_nota(((int) (10. * (v[i].consultar_nota() + 0.05))) / 10.0);
	}
	
}



int main(){
	vector <Estudiant> v;
	leer_vector_est(v);
	redondear_vector_est(v);
	escribir_vector_est(v);
}