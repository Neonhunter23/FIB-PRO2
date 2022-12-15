/** @file Area_espera.hh
    @brief Especificació de la classe Area_espera.
*/

#ifndef _AREA_ESPERA
#define _AREA_ESPERA

#ifndef NO_DIAGRAM
#include <list>
#endif

#include "Cjt_Huecos.hh"
#include "Area_almacenaje.hh"
#include "Contenedor.hh"
using namespace std;

/** @class Area_espera
    @brief Representa una àrea d'espera on estarán els contenidors que no estiguin a l'àrea d'almacenaje
*/

class Area_espera
{

public:
    //Constructores

    /** @brief Creadora sense arguments
    \pre <em>Cert</em>
    \post El resultat és una Area de espera buida.
*/

    Area_espera();

    //Destructora

    /** @brief Destructora
    \pre <em>Cert</em>
    \post Destrueix un objecte Area_espera.
*/
    ~Area_espera();

    //Consultores

    /** @brief Consultora de l'existència d'un contenidor a l'Àrea d'espera
    \pre <em>m</em> és una matrícula vàlida.
    \post El resultat indica si existeix un Contenidor al paràmetre implícit amb matrícula = <em>m</em>.

*/

    bool existe_matricula(string m) const;

    //Modificadores

    /** @brief Insertar contenidor a l'Àrea d'espera
    \pre El contenidor té una ubicació vàlida a l'Area de almacenaje.
    \post S'ha insertat un contenidor a l'area d'espera i la seva ubiació ha canviat a -1,0,0.
*/
    void insertar_contenedor_area(Contenedor c) const;

    /** @brief Retirar contenidor de l'Àrea d'espera
    \pre L'Àrea d'espera no és buida. El contenidor hi és a l'Àrea d'espera.
    \post S'ha retirat el contenidor de l'Àrea d'espera.
*/

    void retirar_contenedor_area(Contenedor c) const;

    //Entrada/sortida

    /** @brief Escriptura de l'àrea d'espera
    \pre <em>Cert</em>
    \post El resultat és el contingut de l'àrea d'espera, ordenada pels contenidors més nous primer.
*/

    void imprimir() const; //llamado desde terminal

private:
    list<Contenedor> l;
};

#endif