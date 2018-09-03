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
			if(start==nullptr){
				cout<<"lista vacia";
				return(nullptr);
			}
			else {
				return (start->data);
			}
		};                                                                                    
		T back() {
			if(start==nullptr){
				cout<<"lista vacia";
				return(nullptr);
			}
			else{
				start=start->prev;
				return(start->data);
			}
		};
		void push_front(T value) {
			Node<T> * nuevo= new Node<T>();
			nuevo->data= nuevo;
			if(start== nullptr){
				start= nuevo;
				start->prev= nuevo;
				start->next=nuevo;
			}
			else{
				nuevo->prev=start->prev;
				nuevo->next=start;
				start->prev=nuevo;
				start=nuevo->prev;
				start->next=nuevo;
				start=nuevo;
			}
		};
		void push_back(T value) {
			Node<T> * nuevo = new Node<T>();
			nuevo->data = value;
			if (start == nullptr) {
				start= nuevo;
				start->prev= nuevo;
				start->next=nuevo;
			}
			else {
				nuevo->next=start;
				nuevo->prev=start->prev;
				start=start->prev;
				start->next= nuevo;
				start=start->next;
				start=start->next;
				start->prev=nuevo;
			}
		
		};
        void pop_front(){
        };
        void pop_back();

        T get(int position){
			for(int i=0;i<position;i++){
				start=start->next;
			}
			return(start->data);
        };
        void concat(List<T> &other){
        	start=start->prev;
        	start->next=&other;
        };
        bool empty(){
        	return(start== nullptr);
        };
        int size(){
        	int c=0;
			<T> *aux;
			aux=&start;
			while(start->next!= aux){
				c++;
				start = start ->next;
			}
			return(c);
        };
        void clear();
		Iterator<T> begin() {
			return Iterator(current);
		};
        Iterator<T> end(){
        	return (Iterator(nullptr));
        };

        ~List();
};

#endif