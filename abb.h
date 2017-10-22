#ifndef ABB_H
#define ABB_H

#include <stdbool.h>

typedef struct abb abb_t;
typedef struct abb_iter abb_iter_t;

typedef int (*abb_comparar_clave_t) (const char *, const char *);
typedef void (*abb_destruir_dato_t) (void *);


/*				PRIMITIVAS DEL ABB 				*/


/*Pre: Debe recibir una función de comparar clave, y de destruir dato.	*
 *Post: Se devuelve un abb creado.										*/
abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato);


/*Pre: Debe recibir el abb, la clave y el dato a agregar en el abb.			*
 *Post: Se devuelve true caso se pudo guardar correctamente el dato 	*
 *en el abb, false caso contrario.										*/
bool abb_guardar(abb_t *arbol, const char *clave, void *dato);


/*Pre: Debe recibir el abb y la clave del dato a borrar.	*
 *Post: Se devuelve el dato que fue borrado del abb.		*
 *Si no se encontró el dato, se devuelve NULL.				*/
void *abb_borrar(abb_t *arbol, const char *clave);


/*Pre: Debe recibir el abb y la clave del dato que se quiere obtener.	*
 *Post: Se devuelve el dato buscado en funcion de la clave recibida.	*/
void *abb_obtener(const abb_t *arbol, const char *clave);


/*Pre: Debe recibir el abb y la clave que se desea buscar.			*
 *Post: Devuelve true caso se pudo encontrar la clave en el abb.	*
 *Devuelve false caso contrario.									*/
bool abb_pertenece(const abb_t *arbol, const char *clave);


/*Pre: Debe recibir el abb.												*
 *Post: Se recibe la cantidad de datos que hay almacenados en el abb.	*/
size_t abb_cantidad(abb_t *arbol);

/*Pre: Debe recibir el abb.						*
 *Post: Se destruye el arbol y todos sus nodos. */
void abb_destruir(abb_t *arbol);



/*			PRIMITIVA ITERADOR INTERNO INORDER - ABB 		*/


/*Pre: Debe recibir el arbol, la función visitar, y la variable extra.							 *
 *Post: Se recorrió todo el abb inorder aplicando visitar, y modificando extra de ser necesario. */
void abb_in_order(abb_t *arbol, bool visitar(const char *, void *, void *), void *extra);


/*			PRIMITIVAS ITERADOR EXTERNO INORDER - ABB 		*/



/*Pre: Debe recibir el abb.								*
 *Post: Se devolvió el iterador externo inorder del abb */
abb_iter_t *abb_iter_in_crear(const abb_t *arbol);


/*Pre: Debe recibir el iterador.									*
 *Post: Devuelve true caso se pudo avanzar con el iter en el abb.	*
 *Devuelve false caso contrario.									*/
bool abb_iter_in_avanzar(abb_iter_t *iter);


/*Pre: Debe recibir el iterador.													*
 *Post: Se devuelve la clave del del dato que se encuentra el iterador actualmente. */
const char *abb_iter_in_ver_actual(const abb_iter_t *iter);


/*Pre: Debe recibir el iterador.								*
 *Post: Devuelve true caso el iterador esta al final del abb.	*
 *Devuelve false caso contrario.								*/
bool abb_iter_in_al_final(const abb_iter_t *iter);


/*Pre: Debe recibir el iterador.				 *
 *Post: Destruye el iterador creado previamente. */
void abb_iter_in_destruir(abb_iter_t* iter);








#endif	//ABB_H 
