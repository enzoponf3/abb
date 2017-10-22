#include "abb.h"

typedef struct abb_nodo{
	struct abb_nodo izq;
	struct abb_nodo der;
	const char* clave;//Lo puse cons por el cmp que recibe ambos const
	void* dato;
}abb_nodo_t;

struct abb{
	abb_destruir_dato_t destructor;
	abb_comparar_clave_t cmp;
	struct abb raiz;
	size_t cant_nodos;
}abb_t;


struct abb_iter{

}abb_iter_t;


/*				PRIMITIVAS DEL ABB 				*/

abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato){
	abb_t* abb = malloc(sizeof(abb_t));
	if(!abb)
		return NULL;

	abb->destructor = destruir_dato;
	abb->cmp = cmp;
	abb->cant_nodos = 0;
	abb->raiz = NULL;
	return abb;	
}

abb_nodo_t* crear_hijo(const char *clave, void *dato){
	abb_nodo_t* hijo_nuevo = malloc(sizeof(abb_nodo_t));
	if(!hijo_nuevo)
		return false;

	hijo_nuevo->izq = NULL;
	hijo_nuevo->der = NULL;
	strcpy(clave,hijo_nuevo->clave);
	hijo_nuevo->dato = dato;
	return hijo_nuevo;
}


bool abb_guardar(abb_t *arbol, const char *clave, void *dato){/*Toy quemado, Ver como hacer guardar recursivamente si llama a abb y no a abb_nodo_t*/
	if(!arbol->raiz)
		arbol->raiz = hijo_nuevo;
	else{
		if(arbol->cmp(clave,arbol->raiz->clave) > 0) // menor que el nodo que se ve
			abb_guardar(arbol->der,clave,dato);
		if(arbol->cmp(clave,arbol->raiz->clave) < 0)
			abb_guardar(arbol->izq,clave,dato);	
		if()		
	}

	
}


void *abb_borrar(abb_t *arbol, const char *clave){
	
}


void *abb_obtener(const abb_t *arbol, const char *clave){
	
}


bool abb_pertenece(const abb_t *arbol, const char *clave){
	
}


size_t abb_cantidad(abb_t *arbol){
	return abb->cant_nodos;
}


void abb_destruir(abb_t *arbol){

}


/*			PRIMITIVA ITERADOR INTERNO INORDER - ABB 		*/

void abb_in_order(abb_t *arbol, bool visitar(const char *, void *, void *), void *extra){

}


/*			PRIMITIVAS ITERADOR EXTERNO INORDER - ABB 		*/


abb_iter_t *abb_iter_in_crear(const abb_t *arbol){

	
}


bool abb_iter_in_avanzar(abb_iter_t *iter){
	
}


const char *abb_iter_in_ver_actual(const abb_iter_t *iter){
	
}


bool abb_iter_in_al_final(const abb_iter_t *iter){
	
}


void abb_iter_in_destruir(abb_iter_t* iter){
	
}
