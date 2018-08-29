#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;
    
    public:
		Iterator() {
			current(nullptr);
		};
		Iterator(Node<T>* node) {
			current(node);
		};
         
		///current es el puntero
		Iterator<T> operator=(Iterator<T> node) {
			//igualando 2 it
		};
		bool operator!=(Iterator<T> cmp) {
		//!=               
		};
		Iterator<T> operator++() {
			current = current->next;
		///devueleve el mismo objeto
			return *this;
		};
		Iterator<T> operator--() {
			current = current->prev;
			return *this;
		};
		T operator*();
		//contenido del iterador
};

#endif