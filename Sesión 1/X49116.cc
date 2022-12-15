#include <iostream>
#include <vector>
using namespace std;

struct parint
{
	int prim, seg;
};

parint max_min1(const vector<int> &v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
{
	parint a;
	a.prim = v[0];
	a.seg = v[0];
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > a.prim)
			a.prim = v[i];
		if (v[i] < a.seg)
			a.seg = v[i];
	}
	return a;
}

pair<int, int> max_min2(const vector<int> &v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
{
	pair<int, int> b;
	b.first = v[0];
	b.second = v[0];
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > b.first)
			b.first = v[i];
		if (v[i] < b.second)
			b.second = v[i];
	}
	return b;
}

void max_min3(const vector<int> &v, int &x, int &y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
	x = v[0];
	y = v[0];
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > x)
			x = v[i];
		if (v[i] < y)
			y = v[i];
	}
}
