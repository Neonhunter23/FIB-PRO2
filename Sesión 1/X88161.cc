#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct equip {
    int num_eq;
    int tot_points = 0;
    int gols_marcats = 0;
    int gols_rebuts = 0;
};

bool cmp (equip e1, equip e2) { //criterio de ordenacion por puntos
    if (e1.tot_points != e2.tot_points) return e1.tot_points > e2.tot_points; //primero va el que mas puntos tenga
    else {
        if ((e1.gols_marcats - e1.gols_rebuts) != (e2.gols_marcats - e2.gols_rebuts)) return (e1.gols_marcats - e1.gols_rebuts) > (e2.gols_marcats - e2.gols_rebuts); 
        //la diferencia de goles es importante
        return e1.num_eq < e2.num_eq; //finalmente se ordenan por numero
    }
}

int main () {
    int n;
    cin >> n;
    
    vector<equip> results;
    for (int i = 0; i < n; ++i) {
        equip aux;
        aux.num_eq = i+1;
        results.push_back(aux); //se van añadiendo nuevos equipos cada vez
    }
    
    for (int i = 0; i < n; ++i) {
        pair<int,int> partit; //cada partido es un pair de los dos equipos

        for (int j = 0; j < n; ++j) {
            cin >> partit.first >> partit.second; //first es el local, second el visitante
            if (i != j) { //un equipo no puede enfrentarse a si mismo
                results[i].gols_marcats += partit.first; //recuento de goles en casa
                results[i].gols_rebuts += partit.second; //recibidos del primer equipo son los marcados del segundo
                results[j].gols_marcats += partit.second; //goles visitante
                results[j].gols_rebuts += partit.first; //recibidos del segundo son los marcados del primero

                if (partit.first > partit.second) results[i].tot_points += 3; //ganador local
                else if (partit.first < partit.second) results[j].tot_points += 3; //ganador visitante
                else {
                    results[i].tot_points += 1; //empate
                    results[j].tot_points += 1;
                } 
            }
        }
    }

    sort(results.begin(), results.end(), cmp); //ordenacion de los equipos

    for (int i = 0; i < n; ++i) { //resultados en pantalla
        cout << results[i].num_eq << ' ' << results[i].tot_points << ' ' << results[i].gols_marcats << ' ' << results[i].gols_rebuts << endl;
    }

}
