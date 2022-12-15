/** @file Terminal.hh
    @brief Especificació de la classe Terminal.
*/

#ifndef _TERMINAL
#define _TERMINAL

#ifndef NO_DIAGRAM
#include <iostream>
#endif

#include "Area_almacenaje.hh"
#include "Area_espera.hh"
#include "Cjt_Huecos.hh"
using namespace std;

/** @class Terminal
    @brief Representa una terminal composada d'una àrea de espera i una àrea d'emmagatzemament.
*/

class Terminal
{

public:
    //Constructores

    /** @brief Creadora sense arguments
     \pre <em>Cert</em>
     \post El resultat és una terminal de dimensions 0*0*0, sense Àrea de almacenaje ni d'espera, i amb tot de forats.
    */

    Terminal();

    /** @brief Creadora amb atributs
     \pre <em>N</em>,<em>M</em>,<em>H</em> son > 0.
     \post El resultat és una terminal que té una Àrea d'almacenaje de dimensions <em>N</em>,<em>M</em>,<em>H</em>.
    */

    Terminal(int N, int M, int H);

    //Destructora

    /** @brief Destructora
     \pre <em>Cert</em>
     \post Destrueix un objecte Terminal.
    */

    ~Terminal();

    //Consultores

    /** @brief Consultora de l'existència d' un contenidor de matrícula m a la Terminal
        \pre <em>m</em> és una matrícula vàlida.
        \post El resultat indica si existeix un contenidor de matrícula m al paràmetre implícit.
     */

    bool existe_contenedor(string m) const;

    /** @brief Consultora de la posició d'un contenidor de matrícula m a la Terminal
        \pre <em>m</em> és una matrícula vàlida.
        \post Retorna la ubicació d'un Contenidor a la terminal, que és -1,0,0 si està a l'Àrea d'espera, i -1,-1,-1 si no existeix.
    */

    void posicion_contenedor(string m) const; //llama a area almacenaje.posicion, y luego ubicacion.retornar (string)

    /** @brief Consultora d'un contenidor de la Terminal
        \pre <em>m</em> és una matrícula vàlida.
        \post Retorna el contenidor de matrícula m i longitud l de la Terminal.
    */

    Contenedor obten_contenedor(string m) const;

    /** @brief Consultora de la ubicació d'un contenidor a la Terminal
        \pre <em>i</em>,<em>j</em>,<em>k</em> son > 0 i menors que <em>N</em>,<em>M</em>,<em>H</em>.
        \post Retorna la matrícula del contenidor situat a les coordenades <em>i</em>,<em>j</em>,<em>k</em>.
    */

    string contenedor_ocupa(int i, int j, int k) const; //devolvera una matricula

    /** @brief Consultora de les files de la Terminal
        \pre <em>N</em> és > 0.
        \post Retorna les files de la Terminal, en concret de l'Àrea d'almacenaje.
    */

    int filas_al() const;

    /** @brief Consultora de les places de la Terminal
        \pre <em>M</em> és > 0.
        \post Retorna les places de la Terminal, en concret de l'Àrea d'almacenaje.
    */

    int plazas_al() const;

    /** @brief Consultora dels pisos de la Terminal
        \pre <em>H</em> és > 0.
        \post Retorna els pisos de la Terminal, en concret de l'Àrea d'almacenaje.
    */

    int pisos_al() const;

    //Modificadores

    /** @brief Modificadora d'inserció
        \pre El paràmetre implícit no conté cap contenidor amb la matrícula de c. El nombre de contenidors a l'Àrea d'almacenaje es menor que la mida màxima permesa.
        \post S'ha afegit el contenidor c al paràmetre implícit.
    */

    void insertar_contenedor(Contenedor c);

    /** @brief Modificadora d'extracció
        \pre L'Àrea d'almacenaje no és buida.
        \post S'ha retirat un contenidor de l'Àrea d'almacenaje.
    */

    void retirar_contenedor(string m);

    //Entrada/sortida

    /** @brief Impresora de l'Àrea d'espera
        \pre L'Àrea d'espera no està buida.
        \post S'han escrit tots els contenidors de l'Àrea d'espera.
    */

    void imprimir_area_espera();

    /** @brief Impresora del conjunt de contenidors
        \pre <em>Cert</em>
        \post S'han escrit tots els contenidors de l'Àrea d'almacenaje.
    */

    void imprimir_contenedores();

    /** @brief Impresora de l'Àrea d'almacenaje
        \pre <em>Cert</em>
        \post S'ha escrit tota l'Àrea d'almacenaje al canal de sortida, per coordenades, amb tots els contenidors que hi ha a cada filera.
    */

    void imprimir_area_almacenaje();

    /** @brief Impresora dels forats de l'Àrea d'almacenaje
        \pre <em>Cert</em>
        \post S'han escrit la ubicació de tots els forats de l'Àrea d'almacenaje.
    */

    void imprimir_huecos();

private:
    Area_almacenaje a;
    Area_espera b;
    Cjt_Huecos c;
};

#endif