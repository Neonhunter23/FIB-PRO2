node_pila* copia_node_pila_it(node_pila* m) 
    /* Pre: cert */
    /* Post: si m és NULL, el resultat és NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */
{
	if (m == NULL) return NULL;

	node_pila* first; //dos punteros a nodo pila
	node_pila* aux;
	first = aux = new node_pila; //apuntan a un nuevo nodo que añadiremos a la pila
	aux->info = m->info; //tienen las caracteristicas del nodo de mas arriba
	m = m->seguent; //m pasa a apuntar al siguiente

	while(m != NULL) { //else devuelve un nodo NULL
		aux->seguent = new node_pila; //el siguiente pasa a ser uno nuevo
		aux = aux->seguent; //pasamos al siguiente
		aux->info = m->info; //copiamos la cadena de m
		m = m->seguent; //avanzamos m
	}
	aux->seguent = NULL; //se para
	return first; //primer nodo de la cadena copiada
} 



Pila& operator=(const Pila& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
{
	//si habla de parametro implicito, es this
	if (this != &original) {
		altura = original.altura; //la altura se copia
		esborra_node_pila_it(primer_node);
		primer_node = copia_node_pila_it(original.primer_node); //el nodo de original pasa a ser el del p.i
	}
	return *this;
}