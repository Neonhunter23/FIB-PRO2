/** 
    \file program.cc
    \brief archivo base del programa
*/

#include "Terminal.hh"
using namespace std;
//main del programa principal
/** @mainpage Documentació de la pràctica: Gestió d'una terminal de contenidors
    @brief Aquesta és la pàgina principal de la documentació de la pràctica
*/

int main()
{
    gestiona_terminal();
}

void gestiona_terminal()
{
    //Obtenir la comanda
    string comando = "";

    string m;    //matricula de un contenedor
    int l;       //longitud de un contenedor
    int N, M, H; //hileras, plazas del segmento, pisos
    Contenedor c;
    Cjt_Contenedores s;
    Terminal t;

    while (cin >> comando and comando != "fin")
    {
        if (comando == "crea_terminal") //done
        {
            cin >> N >> M >> H;
            cout << "#crea_terminal " << N << " " << M << " " << H << endl;
            //crear terminal
            t = Terminal(N, M, H);
        }

        else if (comando == "inserta_contenedor" or comando == "i") //creo que done
        {
            cin >> m >> l; //inserta un contenedor en el map excepto que ya este
            //si esta en la area de espera es -1,0,0

            if (comando == "inserta_contenedor") cout << "#inserta_contenedor " << " " << m << " " << l << endl;
            else cout << "#i " << " " << m << " " << l << endl;

            c = Contenedor(m, l);
            if (t.existe_contenedor(m)) //primero area almacenaje
            {
                cout << "error: el contenedor ya existe" << endl;
            }
            else
            {
                t.insertar_contenedor(c); //hará cout de la primera posicion ocupada
            }
        }

        else if (comando == "retira_contenedor" or comando == "r")
        {
            cin >> m; //retira contenedor del map excepto que no este

            if (comando == "retira_contenedor") cout << "#retira_contenedor " << " " << m << endl;
            else cout << "#r " << " " << m << endl;

            if (t.existe_contenedor(m))
            {
                t.retirar_contenedor(m);
            }
            else
                cout << "error: el contenedor no existe." << endl;
        }

        else if (comando == "donde") //done
        {
            cin >> m; //busca el contenedor en el map
            //area de almacenaje: ubicacion con menor M
            //area espera: -1,0,0
            //no existe: -1,-1,-1

            cout << "#donde " << m << endl;
            if (t.existe_contenedor(m))
            {
                t.posicion_contenedor(m); //buscar en el map, devolvera ubicacion
            }
            else cout << "<-1,-1,-1>" << endl;
        }

        else if (comando == "longitud") //done
        {
            cin >> m; //muestra la longitud de un contenedor
            //error si no existe la matricula

            cout << "#longitud " << m << endl;
            if (t.existe_contenedor(m))
            {
                t.foo(); //busca en el map el contenedor, imprime su longitud
            }

            else cout << "error: el contenedor no existe" << endl;
        }

        else if (comando == "contenedor_ocupa") //dificil
        {
            int i, j, k; //posicion en el map
            cin >> i >> j >> k;

            cout << "#contenedor_ocupa " << i << " " << j << " " << k << endl;

            //devuelve la matricula del contenedor situado en esa posicion
            //error si hay un hueco en esa posicion o esta fuera de los limites
            if ((i > t.filas_al() or j > t.plazas_al() or k > t.pisos_al()) or (i < 0 or j < 0 or k < 0))
            {
                cout << "error: ubicacion fuera de rango" << endl;
            }
            else cout << t.contenedor_ocupa(i, j, k) << endl; //retorna string o nada si hay un hueco
        }

        else if (comando == "num_hileras") //done
        {
            cout << "#num_hileras" << endl;
            //imprime el numero de hileras de la terminal
            cout << t.filas_al() << endl;
        }

        else if (comando == "num_plazas") //done
        {
            cout << "#num_plazas" << endl;
            //imprime el numero de plazas de la terminal
            cout << t.plazas_al() << endl;
        }

        else if (comando == "num_pisos") //done
        {
            cout << "#num_pisos" << endl;
            //imprime el numero de pisos de la terminal
            cout << t.pisos_al() << endl;
        }

        /*
        else if (comando == "area_espera") //todavia no
        {
            
            //imprimir el area de espera
            t.imprimir_area_espera();
        }
        */

        else if (comando == "contenedores") //done
        {
            cout << "#contenedores" << endl;
            //imprimir los contenedores del conjunto en orden de matricula, con su ubicacion y su longitud
            t.imprimir_contenedores();
        }

        else if (comando == "area_almacenaje")
        {
            cout << "#area_almacenaje" << endl;
            //imprime el area de almacenaje por hileras, imprimiendo tambien los contenedores de cada hilera
            //las hileras con M > 9 se vuelven a repetir desde el 0
            t.imprimir_area_almacenaje();
        }

        else if (comando == "huecos")
        {
            cout << "#huecos" << endl;
            //imprime los huecos de la terminal, primero su ubicacion y luego la longitud del hueco
            t.imprimir_huecos();
        }
    }
}
