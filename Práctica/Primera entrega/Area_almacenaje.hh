/** @file Area_almacenaje.hh
    @brief Especificació de la classe Area_almacenaje
*/

#ifndef _AREA_ALMACENAJE
#define _AREA_ALMACENAJE

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

#include "Area_espera.hh"
#include "Cjt_Huecos.hh"
#include "Ubicacion.hh"
using namespace std;

/** @class Area_almacenaje
    @brief Representa una àrea d'almacenaje de contenidors amb tres paràmetres que indicaran les seves dimensions.
*/

class Area_almacenaje
{

public:
    //Constructores

    /** @brief Creadora sense arguments
    \pre <em>Cert</em>
    \post El resultat és una Area de almacenaje buida.

*/
    Area_almacenaje();

    /** @brief Creadora amb atributs
    \pre <em>N</em>,<em>M</em>,<em>H</em> son > 0
    \post El resultat és una Area de almacenaje de dimensions <em>N</em>,<em>M</em>,<em>H</em>.

*/
    Area_almacenaje(int N, int M, int H);

    //Destructora

    /** @brief Destructora
    \pre <em>Cert</em>
    \post Destrueix un objecte Area_almacenaje.
*/
    ~Area_almacenaje();

    //Consultores

    /** @brief Consultora de la posició d'un contenidor
        \pre <em>m</em> és una matrícula vàlida.
        \post Retorna la ubicació d'un contenidor a l'Àrea d'almacenaje.
    */

    void posicion(string m) const; //recorrer matriz 3D

    /** @brief Consultora del contenidor que ocupa una ubicació
        \pre <em>m</em> és una matrícula válida.
        \post Retorna la matrícula del contenidor que ocupa una ubicació dins de l'Àrea d'almacenaje.
    */

    string ocupa(int i, int j, int k) const;

    /** @brief Consultora de files
        \pre <em>N</em> és > 0.
        \post Retorna les files de l'Àrea d'almacenaje.
    */

    int filas() const;

    /** @brief Consultora de places
        \pre <em>M</em> és > 0.
        \post Retorna les places de l'Àrea d'almacenaje.
    */

    int plazas() const;

    /** @brief Consultora de pisos
        \pre <em>H</em> és > 0.
        \post Retorna els pisos de l'Àrea d'almacenaje.
    */

    int pisos() const;

    //Modificadores

    /** @brief Modificadora d'inserció
        \pre El contenidor a insertar no hi és a l'Àrea d'almacenaje. El nombre de contenidors a l'Àrea d'almacenaje es menor que la mida màxima permesa.
        \post S'ha insertat un contenidor a l'Àrea d'almacenaje.
    */

    void insertar();

    /** @brief Modificadora d'extracció
        \pre L'Àrea d'almacenaje no és buida.
        \post S'ha retirat un contenidor de l'Àrea d'almacenaje.
    */

    void retirar();

    //Entrada/sortida

    /** @brief Escriptura de l'Area de almacenaje
        \pre <em>Cert</em>
        \post S'ha escrit la terminal en ordre de matricula, amb la seva ubicació i longitud.
    */

    void imprimir(); //llamado desde terminal

private:
    int N;
    int M;
    int H;
    map<string, Ubicacion> aa;
};

#endif