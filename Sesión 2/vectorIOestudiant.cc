#include "vectorIOestudiant.hh"

/* Leer vector */
void leer_vector_est(vector<Estudiant>& v) { // version accion
  cout<<"Escribe el tamaño del vector:"<<endl;
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  Estudiant e1;
  cout<<"Escribe los elementos del vector:"<<endl;  
  for (int i=0; i<numEst;++i) {
    e1.llegir();
	v[i] = e1;
	}
}

/* Escribir vector */
void escribir_vector_est(const vector<Estudiant>& v) {
  for (int i=0; i<v.size();++i)
    v[i].escriure();
  	cout << endl;
}
