#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;


    public:
		List() {
			start = nullptr;
		};
		T front() {
			return start->data;
		};                                                                                    
		T back() {
		
		
		
		};
		void push_front(T value) {
		
		};
		void push_back(T value) {
			Node<T> * nuevo = new Node();
			nuevo->data = value;
			if (List != nullptr) {
				Node<T> aux1, aux2;
				while (next != start) {
					if next

				}
			}
			else {
				List = value;
				nuevo->next=nuevo;
				nuevo->prev=nuevo;
			}
		
		};
        void pop_front();
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void clear();
		Iterator<T> begin() {

		
		};
        Iterator<T> end();

        ~List();
};

#endif