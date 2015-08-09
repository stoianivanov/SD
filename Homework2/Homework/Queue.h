#pragma once
#include "Node.h"



template <typename T>
class Queue
{

	
public:
	Queue() :first(nullptr), last(nullptr), size(0){}
	~Queue()
	{
		delete first;
	}
	bool isEmpty() const
	{
		return first == nullptr;
	}

	T dequeue()
	{
		if (!isEmpty())
		{
			node<T>* n = first;
			first = first->next;
			n->next = nullptr;
			T x= n->data;
			delete n;
			--size;
			return x;
		}
			else
			{
				throw "Queue is empty!!!!";
			}
	}
	const T& getFirst() const
	{
		if (!isEmpty())
		{
			return first->data;
		}
		 else 
		 {
			 throw "Queue is empty!!!";
		 }
	}
	void enqueue(const T& elem)
	{
		node<T> *n = new node<T>(elem);
		if (!isEmpty())
		{
			last->next = n;
		}
		else
		{
			first = n;
		}
		++size;
		last = n;
	}
	size_t getSize()const
	{
		return size;
	}
protected:
	node<T>* getAt(size_t pos)
	{
		node<T>* n = first;
		if (pos >= size)
		{
			return nullptr;
		}
		while (pos > 0)
		{
			--pos;
			n = n->next;
		}

		return n;			
	}
public:
	const T& operator[](size_t pos) const
	{
		if (pos >= size)
		{
			throw "Invalid possition";
		}
		return (const_cast<Queue<T>*>(this)->getAt(pos))->data;
	}
	const T& at(size_t pos) const 
	{
		if (pos >= size)
		{
			throw "Invalid possition";
		}
		return (const_cast<Queue<T>*>(this)->getAt(pos))->data;
	}
private:
	node<T>* first;
	node<T>* last;
	size_t size;
};

