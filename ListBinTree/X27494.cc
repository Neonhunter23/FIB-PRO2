#include <iostream>
#include <list>
using namespace std;

void recalcular_max_min(list<int>& l, int& min, int& max) {
    if (not l.empty()) {
        max = *l.begin(); //los dos iguales al primer elemento de la lista
        min = *l.begin();
        for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
            if (*it > max) max = *it;
            if (*it < min) min = *it;
        }
    }
}

void borra_elemento(list<int>& l, int& n, double& total) {
    if (not l.empty()) {
        list<int>::iterator it = l.begin();
        while (it != l.end()) {
            if ((*it) == n) {
                it = l.erase(it);
                total -= n;
                return;
            }
            else ++it;
        }
    }
}

int main() {
    int op, n, min, max;
    double total = 0;
    list<int> l;
    while (cin >> op >> n and op != 0 and n != 0) {
        if (op == -1) { //valor valido
            if (l.empty()) {
                min = max = n;
            }
            else {
                if (max < n) max = n;
                if (min > n) min = n;
            }
            l.push_back(n);
            total += n;
        }
        else if (op == -2) { //invalidar apariciones siguientes
            borra_elemento(l, n, total);
            if (max == n or min == n) recalcular_max_min(l, min, max);
        }
        if (not l.empty()) cout << min << " " << max << " " << total/l.size() << endl;
        else cout << 0 << endl;
    }
}