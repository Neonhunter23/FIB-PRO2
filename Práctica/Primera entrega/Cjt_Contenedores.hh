/** @file Cjt_Contenedores.hh
    @brief Especificació de la classe Cjt_Contenedores.
*/

#ifndef _CJT_CONTENEDORES
#define _CJT_CONTENEDORES

#ifndef NO_DIAGRAM
#include <list>
#endif

#include "Contenedor.hh"
#include "Area_almacenaje.hh"
using namespace std;

/** @class Cjt_Contenedores
    @brief Representa el conjunt de contenidors de l'Àrea d'almacenaje
*/

class Cjt_Contenedores
{

public:
    //Constructores

    /** @brief Creadora sense arguments
    \pre <em>Cert</em>
    \post El resultat es un conjunt de contenidors buit.
*/
    Cjt_Contenedores();

    //Destructora

    /** @brief Destructora
    \pre <em>Cert</em>
    \post Destrueix un objecte Cjt_Contenedores.
*/

    ~Cjt_Contenedores();

    //Consultores

    /** @brief Consultora d'existència
        \pre <em>m</em> és una matrícula vàlida.
        \post Retorna <em>Cert</em> si el contenidor amb matrícula <em>m</em> existeix al conjunt.
    */

    bool existe(string m) const; //buscar en el map

    //Entrada/sortida

    /** @brief Afegir contenidor al conjunt
        \pre Al conjunt no hi havia un contenidor amb matrícula <em>m</em>. El conjunt no está ple.
        \post S'ha afegit un contenidor al conjunt.
    */

    void afegir_cont();

    /** @brief Impressió del conjunt de contenidors
        \pre El conjunt no està buit.
        \post Imprimeix el conjunt  de conenidors de l'Àrea d'almacenaje, ordenats per matrícula.
    */

    void imprimir() const; //llamado desde terminal

private:
    list<Contenedor> l;
};

#endif