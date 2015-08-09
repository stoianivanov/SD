#pragma once
template < typename T>
struct node
{
	T data;
	node<T>* next;


	node(const T& x, node<T> * n = nullptr)
	{
		data = x;
		next = n;
	}
	/*~node()
	{
		if (next)
		{
			delete next;
		}
	}
	*/ 
	node(const node<T>&h)
	{
		next = n->next ? new node(*n.next) : 0;
		data = n.data;
	}
};