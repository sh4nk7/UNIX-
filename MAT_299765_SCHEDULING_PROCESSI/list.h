

#ifndef LIST_H
#define LIST_H

#include "node.h"
#include "collection.h"
#include "assert.h"

template <class T> class List : public Collection<T>
{
	public:
		
		List<T>() : Collection<T>() {}
		
		List<T>(Collection<T>& c) : Collection<T>(c) {} 
		
		// inserisce un elemento in coda
		void append(const T& t) 
		{
			Node<T>* nuovo = new Node<T>(t);
			if (this->head == NULL)
				this->head = nuovo;
			else
				this->tail->next = nuovo;
			
			this->tail = nuovo;
			this->cnt++;
		}
		
		// rimuove l'elemento puntato da curr
		void removeCurr()
		{
			Assert(this->cnt > 0, "Errore rimozione elemento da lista: lista vuota");
			Assert(this->curr != NULL, "Errore rimozione elemento da lista: posizione elemento non valida");
			
			if (this->curr == this->head)
			{
				this->head = this->head->next;
				delete this->curr;
				this->curr = this->head;
			}
			else
			{
				Node<T>* prev = this->head;
				while (prev->next != this->curr)
				{
					prev = prev->next;
				}
				prev->next = this->curr->next;
				delete this->curr;
				this->curr = prev->next;
			}
			this->cnt--;
		}
};

#endif
