#include <iostream>
#include <queue>
using namespace std;

void calcular_min_max (queue<int> q, int& min, int& max) {
	max = -1000, min = 1000;
	while (not q.empty()) {
		if (max < q.front()) max = q.front();
		if (min > q.front()) min = q.front();
		q.pop();
	}
}

int main() {
	int n, max = -1000, min = 1000;
	double ac = 0;
	queue<int> q;
	while (cin >> n and n >= -1001 and n <= 1000) {
		if (n != -1001) {
			q.push(n);
			if (n > max) max = n;
			if (n < min) min = n;
			ac += n;
		}
		else if (not q.empty()) {
			int last = q.front();
			q.pop();
			ac -= last; //el que se borra no se cuenta en la media
			if (last == max or last == min) calcular_min_max (q,min,max);
		}

		if (q.empty()) {
			cout << '0' << endl;
			max = -1000, min = 1000;
		}
		else cout << "min " << min << "; max " << max << "; media " << (ac/q.size()) << endl;
	}
}