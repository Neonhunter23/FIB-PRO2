#include "vectorIOestudiant.hh"
#include <iostream>
#include <vector>

using namespace std;

/* Buscar  */    
int busqueda_lin_vest(const vector<Estudiant>& v, int x)
/* Pre: cierto */
/* Post: el resultado indica la posicion de x en v */
{
  int tam = v.size();
  int i = 0;
  bool b = false;
  while (i < tam and not b) {
    if (v[i].consultar_DNI() == x) b = true; 
    else ++i;
  }
  return i;
}

int main()
{
  vector<Estudiant> v;
  leer_vector_est(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int x;
  cin >> x; 
  int pos = busqueda_lin_vest(v,x);
  if (pos == v.size()) cout << "El estudiante no está en el vector" << endl;
  else if (v[pos].te_nota()) cout << "El estudiante está en el vector, y su nota es " << v[pos].consultar_nota() << endl;
  else cout << "El estudiante está en el vector, pero no tiene nota" << endl;
}
