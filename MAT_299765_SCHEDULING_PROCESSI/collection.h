
#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>

#include "node.h"

using namespace std;

template <class T> class Collection 
{
	private:
		void init() { head = NULL; curr = NULL; tail = NULL; cnt = 0; }
	
	protected:
		Node<T>* head;
		Node<T>* curr;
		Node<T>* tail;
		int cnt;
		
	public:
		
		Collection<T>() { init(); };
		
		Collection<T>(Collection<T>& c)
		{
			init();
			
			Node<T>* nuovo;
			for (c.moveToStart(); c.hasNext(); c.next())
			{
				T& t = c.getValue();
				nuovo = new Node<T>(t);
				if (head == NULL)
					head = nuovo;
				else
					tail->next = nuovo;
				tail = nuovo;
				cnt++;
			}
		}
		
		int size() const { return cnt; }
		
		bool isEmpty() const { return cnt == 0; }
		
		void moveToStart() { curr = head; }
		
		void moveToEnd() { curr = tail; }
		
		bool hasNext() { return curr != NULL; }
		
		void next() 
		{ 
			if (curr != NULL)
				curr = curr->next;
		}
		
		// restituisce l'elemento puntato da curr
		T& getValue() { return curr->info; }
};

template <class T>
ostream& operator << (ostream& out, Collection<T>& l)
{	
	Collection<T> temp = l;
	int count = 0;
	
	out << "[";
	for (temp.moveToStart(); temp.hasNext(); temp.next())
	{
		count++;
		out << temp.getValue();
		if (count < temp.size())
			out << ", ";
	}
	out << "]";
	return out;
}

#endif
