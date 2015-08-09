#pragma once
#include "Node.h"

template <typename T>
class List
{
protected:
	node<T> *first, *last;
	size_t size = 0;
public:
	List()
	{
		first = nullptr;
		last = nullptr;
		size = 0;
	}
	List(const T& x)
	{
		first = last = new node<T>(x);
		size = 1;
	}
	List(const List<T>& x)
	{
		if (x.isEmpty())
		{
			first = last = size = 0;
		}
		else
		{
			first = new node<Y>(*x.first);
			size = x.size;
			last = first;
			while (last->next)
			{
				last = last->next;
			}
		}
	}
	~List()
	{
		delete first;
	}
	void clear()
	{
		delete first;
		first = last = size = 0;
	}

	List<T>&operator=(const List<T>& x)
	{
		if (this != &x)
		{
			clear();
			if (!x.isEmpty())
			{
				first = new node<T>(*x.first);
				size = x.size;
				for (last = first; last->next; last = last->next);
			}
		}
		return *this;
	}
	size_t getSize() const
	{
		return size;
	}
	bool isEmpty() const
	{
		return size == 0;
	}
	void addFront(const T&x)
	{
		first = new node<T>(x, first);
		if (!size)
		{
			last = first;
		}
		++size;
	}

	void addLast(const T& x)
	{
		if (isEmpty())
		{
			first = last = new node<T>(x);
		}
		 else
		 {
			 last = last->next = new node<T>(x);

		 }
		++size;
	}
	T removeFirst()
	{
		if (isEmpty())
		{
			throw "List is empty";
		}

		T data = first->data;
		node<T>* n = first;
		first = first->next;
		--size;
		n->next = nullptr;
		delete n;
		if (!size)
		{
			last = nullptr;
		}
		return data;
	}
	T removeLast()
	{
		if (isEmpty())
		{
			throw " List is empty";
		}

		if (size == 1)
		{
			return removeFirst();
		}
		
		node<T>* n = getAt(size - 2);
		T data = n->next->data;
		--size;
		last = n;
		delete n->next;
		n->next = NULL;
		return data;

	}
	const T& operator[](size_t pos) const
	{
		if (pos >= size)
		{
			throw "Invalid possition!!";
		}
		return (const_cast<List<T>*>(this)->getAt(pos))->data;
	}

	 T& operator[](size_t pos) 
	{
		if (pos >= size)
		{
			throw "Invalid possition!!";
		}
		return (const_cast<List<T>*>(this)->getAt(pos))->data;
	}
	T removeAt(size_t pos)
	{
		if (pos >= size)
		{
			throw " Invalid possition";
		}
		if (pos == 0)
		{
			return removeFirst();
			
		}

		node<T>* n = getAt(pos - 1);
		T data = n->next->data;
		node<T>* toRemove = n->next;
		n->next = toRemove->next;
		toRemove->next = nullptr;
		delete toRemove;
		--size;
		return data;
	}
	void insertAt(size_t pos, const T& x)
	{

		if (pos == 0)
		{
			addFront(x);
		}
		else if (pos==size)
		{
			addLast(x);
		}
		else
		{
			node<T> * n getAt(pos - 1);
			node<T>* new Elem = new node<T>(x, n->next);
			n->next = new node;

		}
		++size;
	}
	template <typename U>
	void forEach(U& f)
	{
		for (node<T>* n = first; n != nullptr; n = n->next)
			f(n->data);

	}

protected:
	node<T>* getAt(size_t idx)
	{
		node<T>* n = first;
		if (idx >= size)
		{
			return nullptr;
		}
		while (idx > 0)
		{
			--idx;
			n = n->next;
		}
		return n;
	}


	
};
