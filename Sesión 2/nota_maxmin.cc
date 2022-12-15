#include "vectorIOestudiant.hh"
#include <iostream>
#include <vector>

using namespace std;


 void max_min(const vector<Estudiant>& v, double& x, double& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
 	Estudiant e;
 	x = 0; 
	y = e.nota_maxima(); //no pasará de 10
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].te_nota()) { //ojo
		if (v[i].consultar_nota() > x) x = v[i].consultar_nota(); //guardamos en x la nota maxima
		if (v[i].consultar_nota() < y) y = v[i].consultar_nota(); //guardamos en y la nota minima
		}
	}
	
 }


 int main(){
 	vector<Estudiant> v;
 	leer_vector_est(v);
 	double x, y;
 	max_min(v,x,y);

 	cout << "nota max: " << x << " " << "nota min: " << y << endl;
 }