#include "Estudiant.hh"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const Estudiant a, Estudiant b) {
	if (a.consultar_nota() == b.consultar_nota()) return a.consultar_DNI() < b.consultar_DNI();
	return a.consultar_nota() > b.consultar_nota();
}

int main() {
	int m, n, s;
	cin >> m >> n >> s;

	vector<int> assig_num(s);
	for (int i = 0; i < s; ++i) cin >> assig_num[i];

	vector<double> notas(n);
	vector<Estudiant> est(m);
	int DNI;
	for (int i = 0; i < m; ++i) {
		cin >> DNI;

		for (int j = 0; j < n; ++j) cin >> notas[j];

		double res = 0;
		for (int k = 0; k < s; ++k) res += notas[assig_num[k]-1];
		res /= s;

		est[i] = Estudiant (DNI);
		est[i].afegir_nota(res);
	}

	sort(est.begin(), est.end(), cmp);
	for (int i = 0; i < m; ++i) est[i].escriure();
}