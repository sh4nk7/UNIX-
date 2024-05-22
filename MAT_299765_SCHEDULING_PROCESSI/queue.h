
#ifndef QUEUE_H
#define QUEUE_H

#include "collection.h"
#include "assert.h"

template <class T> class Queue : public Collection<T>
{
	public:
		
		Queue<T>() : Collection<T>() {}
		
		Queue<T>(Collection<T>& c) : Collection<T>(c) {}
		
		// restituisce, senza rimuovere, l'elemento di testa
		T& peek() const
		{
			Assert(this->head != NULL, "Errore reperimento elemento da coda: coda vuota");
			return this->head->info;
		}
		
		// inserisce un elemento in coda
		void add(const T& t) 
		{
			Node<T>* nuovo = new Node<T>(t);
			if (this->head == NULL)
				this->head = nuovo;
			else
				this->tail->next = nuovo;
			
			this->tail = nuovo;
			this->cnt++;	
		}
		
		// rimuove l'elemento di testa, restituendolo
		T remove()
		{
			Assert(this->head != NULL, "Errore rimozione elemento da coda: coda vuota");
			
			Node<T>* temp = this->head;
			T t = temp->info;
			this->head = this->head->next;
			delete temp;
			this->cnt--;
			
			return t;
		}
};

#endif
