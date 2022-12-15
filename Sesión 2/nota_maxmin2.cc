#include "vectorIOestudiant.hh"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (Estudiant e1, Estudiant e2) { //criterio de ordenacion para escoger el DNI mas pequeño
	return e1.consultar_DNI() < e2.consultar_DNI();
}

 void max_min(const vector<Estudiant>& v, double& x, double& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
 	Estudiant e;
 	double nota_max = 0;
 	double nota_min = e.nota_maxima();
 	
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].te_nota()) { //ojo
			if (v[i].consultar_nota() > nota_max) {
			nota_max = v[i].consultar_nota();
			x = i; //guardamos en x la posicion de la nota maxima
			}
			if (v[i].consultar_nota() < nota_min){
			nota_min = v[i].consultar_nota();
			y = i; //guardamos en y la posicion de la nota minima
			}
		}
	}
	
 }


 int main(){
 	vector<Estudiant> v;
 	leer_vector_est(v);
 	sort(v.begin(), v.end(), cmp);
 	double x, y;
 	max_min(v,x,y);

 	cout << "estudiante con nota max: " << v[x].consultar_DNI() << " " << v[x].consultar_nota() << endl; 
 	cout << "estudiante con nota min: " << v[y].consultar_DNI() << " " << v[y].consultar_nota() << endl; 
 	
 }