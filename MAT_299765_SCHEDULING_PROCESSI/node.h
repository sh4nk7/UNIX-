
#ifndef NODE_H
#define NODE_H

template <class T> class Node 
{
	public:
		T info;
		Node<T>* next;
		Node<T>(const T& t) { info = t; next = NULL; }
};

#endif
