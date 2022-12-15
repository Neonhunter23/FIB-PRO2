#include "LlistaIOParInt.hh"

// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
void LlegirLlistaParInt(list<ParInt>& l) {
	ParInt p;
	while (p.llegir() and p.primer() != 0 and p.segon() != 0) {
		l.push_back(p); //se puede tambien con iteradores poniendo l.insert(l.end(), p)
	}

}

// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
void EscriureLlistaParInt(const list<ParInt>& l) {
	for (list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it) {
		(*it).escriure(); //escribes el elemento al que apunta el iterador
	}
}



