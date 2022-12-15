/** @file Cjt_Huecos.hh
    @brief Especificació de la classe Cjt_Huecos.
*/

#ifndef _CJT_HUECOS
#define _CJT_HUECOS

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <list>
#endif

#include "Area_almacenaje.hh"
#include "Area_espera.hh"
#include "Cjt_Contenedores.hh"
#include "Segmento.hh"
#include "Ubicacion.hh"

/** @class Cjt_Huecos
    @brief Representa el conjunt de forats del Àrea de almacenaje.
*/

class Cjt_Huecos
{

public:
    //Constructores

    /** @brief Creadora sense arguments
        \pre <em>Cert</em>
        \post El resultat és un conjunt de forats buit.
    */

    Cjt_Huecos();

    //Destructora

    /** @brief Destructora
        \pre <em>Cert</em>
        \post Destrueix un objecte Cjt_Huecos.
    */

    ~Cjt_Huecos();

    //Modificadores

    /** @brief Omplidora de forats
        \pre <em>Cert</em>
        \post Omple els forats amb contenidors amb la estratègia BEST FIT.
    */

    void rellenar_huecos();

    //Entrada/sortida

    /** @brief Impressió dels forats
        \pre El conjunt nno està buit.
        \post Imprimeix els forats de l'Àrea d'almacenaje, ordenats per ubicació y a continuació el seu tamany.
    */

    void imprimir() const; 

private:
    vector<list<Contenedor>> hole;
};

#endif