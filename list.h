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
        int nodes;

    public:
		List() {
			start = nullptr;
			nodes=0;
		}
		T front() {
			if(start==nullptr) {
                cout << "lista vacia";
            }
            else {
                return start->data;
            }
		}
		T back() {
			if(start==nullptr){
				cout<<"lista vacia";
			}
			else {
                return start->prev->data;
            }

		}
		void push_front(T value) {
			Node<T> *nuevo= new Node<T>();
			nuevo->data= value;

			if(start== nullptr){
				start= nuevo;
				start->prev= nuevo;
				start->next=nuevo;
			}
			else{
				start->prev->next=nuevo;
				nuevo->next=start;
				nuevo->prev=start->prev;
				start->prev=nuevo;
			}
            start=nuevo;
			nodes++;
		}
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
				start->prev->next=nuevo;
				start->prev=nuevo;
			}
			nodes++;
		
		}
        void pop_front(){
			if(start==nullptr){
				cout<<"lista vacia";
			}
			else if(start->next==start){
				start= nullptr;
				}
			else{
				//auto* aux=start;
				start->prev->next=start->next;
				start->next->prev=start->prev;
				start=start->next;
				//delete (aux);
			}
			nodes--;
        }
        void pop_back(){
			if(start==nullptr){
				cout<<"lista vacia";
			}
			else if(start->next==start){
				start= nullptr;
				}
                else{
                    //	auto* aux=start;
                        start->prev->prev->next=start;
                        start->prev->prev=start->prev;
                    //	delete (aux);

                    }nodes--;
        }

        T get(int position){
        	auto* aux=start;
			for(int i=0;i<position;i++){
				aux=aux->next;
			}
			return(aux->data);
        }
        void concat(List<T> &other){
        	start->prev->next = other.start;
        	other.start->prev=start->prev;
        }
        bool empty(){
        	return(nodes==0);
        }
        int size(){
			return(nodes);
        }
        void clear(){
			while(nodes > 0){
				pop_back();
			}
			nodes=0;
        }
		Iterator<T> begin() {
			return Iterator<T>(start);
		}
        Iterator<T> end(){
        	return Iterator<T>(start->prev);
        }

        ~List(){}
};

#endif