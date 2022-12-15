#include <iostream>
using namespace std;

#include "vectorIOint.hh"

/* Buscar  */    
int busqueda_lin(const vector<int>& v, int x)
/* Pre: cierto */
/* Post: el resultado indica la posicion de x en v */
{
  int tam = v.size();
  int i = 0;
  bool b = false;
  while (i < tam and not b) {
    if (v[i] == x) b = true; 
    else ++i;
  }
  return i;
}

int main()
{
  vector<int> v;
  leer_vector_int(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int x;
  cin >> x; 
  int pos = busqueda_lin(v,x);
  if (pos >= 0 and pos <= v.size() -1) cout << "El elemento " << x << " esta en el vector en la posicion " << pos << endl;
  cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribir_vector_int(v);
}
