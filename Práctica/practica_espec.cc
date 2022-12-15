/** 
    \file practica_espec.cc
    \brief archivo base del programa
*/

#include "Area_almacenaje.hh"
#include "Cjt_Contenedores.hh"
#include "Cjt_Huecos.hh"

//main del programa principal
/** @mainpage Aquest és el programa principal de la pràctica de PRO2.

*/


int main()
{
    string comando = "";
    cin >> comando;
    string m;    //matricula de un contenedor
    int l;       //longitud de un contenedor
    int N, M, H; //hileras, plazas del segmento, pisos
    Contenedor c;
    Cjt_Contenedores s;

    while (comando != "fin")
    {
        if (comando == "crea_terminal")
        {
            cin >> N >> M >> H;
            //crear terminal
            Terminal t(N,M,H);

        }
        cin >> comando;
    
    while (comando != "fin" and comando != "crea_terminal")
    {
        if (comando == "inserta_contenedor" or comando == "i")
        {
            cin >> m >> l; //inserta un contenedor en el map excepto que ya este
            //si esta en la area de espera es -1,0,0
            c = Contenedor(m, l);
            if (t.existe_contenedor(m) //primero area almacenaje
            {
               cout << "El contenedor " << c.matricula() << " ya existe." << endl;
            }
            else  
            {
                t.insertar_contenedor(c); //hará cout de la primera posicion ocupada
                //dentro de esta funcion estara la de rellenar huecos
            }
        }

        else if (comando == "retira_contenedor" or comando == "r")
        {
            cin >> m; //retira contenedor del map excepto que no este
            if (t.existe_contenedor(m)) {
                t.retirar_contenedor(m);
            }
            else cout << "El contenedor " << m << " no existe." << endl;
        }

        else if (comando == "donde")
        {
            cin >> m; //busca el contenedor
            //area de almacenaje: ubicacion con menor M
            //area espera: -1,0,0
            //no existe: -1,-1,-1
            if (t.existe_contenedor(m))
            {
                t.posicion_contenedor(m); //buscar en el map, devolvera ubicacion
            }
           else cout << "-1" << " " << "-1" << " " << "-1" << endl;
        }

        else if (comando == "longitud")
        {
            cin >> m; //muestra la longitud de un contenedor
            //error si no existe la matricula
            if (t.existe_contenedor(m))
            {
               c = t.obten_contenedor(m);
               cout << c.longitud << endl;  
            }

            else {
                cout << "El contenedor " << m << " no existe" << endl;
            }
        }

        else if (comando == "contenedor_ocupa") //dificil
        {
            int i, j, k; //posicion en el map
            cin >> i >> j >> k;
            //devuelve la matricula del contenedor situado en esa posicion
            //error si hay un hueco en esa posicion o esta fuera de los limites
            if ((i > t.filas_al() or j > t.plazas_al() or k > t.pisos_al())or (i < 0 or j < 0 or k < 0)) {
                cout << "Fuera de los límites." << endl;
            }
            else {
                cout << t.contenedor_ocupa (i, j, k) << endl; //retorna string
            }
        }

        else if (comando == "num_hileras")
        {
            //imprime el numero de hileras de la terminal
            cout << t.filas_al() << endl;
        }

        else if (comando == "num_plazas")
        {
            //imprime el numero de plazas de la terminal
            cout << t.plazas_al() << endl;
        }

        else if (comando == "num_pisos")
        {
            //imprime el numero de pisos de la terminal
            cout << t.pisos_al() << endl;
        }

        else if (comando == "area_espera")
        {
            //imprimir el area de espera
            t.imprimir_area_espera();
        }

        else if (comando == "contenedores")
        {
            //imprimir los contenedores del conjunto en orden de matricula, con su ubicacion y su longitud
            t.imprimir_contenedores();
        }

        else if (comando == "area_almacenaje")
        {
            //imprime el area de almacenaje por hileras, imprimiendo tambien los contenedores de cada hilera
            //las hileras con M > 9 se vuelven a repetir desde el 0
            t.imprimir_area_almacenaje();
        }

        else if (comando == "huecos")
        {
            //imprime los huecos de la terminal, primero su ubicacion y luego la longitud del hueco
            t.imprimir_huecos();
        }
        cin >> comando;
     }
    }
}