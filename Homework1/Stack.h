#pragma once 
#include <iostream>

template <typename T>
struct Elem
{
	T data;
	Elem<T>* prev;
};

template <typename T>
class Stack
{
private:
	Elem<T>* top;

	void copy(const Stack<T>&);
	void free();
public:
	Stack() :top(NULL){}
	~Stack();
	Stack(const Stack<T>&);
	Stack <T>& operator=(const Stack<T>&);
	bool isEmpty()const
	{
		return top == NULL;
	}

	void push(const T& newElem)
	{
		Elem<T>* pn = new Elem<T>;
		pn->data = newElem;
		pn->prev = top;
		top = pn;
	}
	void pop()
	{
		if(isEmpty())
		{
			throw "The stack is empty";
		}
		Elem<T>* prev = top->prev;
		delete top;
		top = prev;
	}
	T peek()
	{
		if (isEmpty())
		{
			throw "The stack is empty";
		}
		return top->data;
	}
};

template <typename T>
Stack<T>::~Stack()
{
	free();
}

template<typename T>
void Stack<T>::copy(const Stack<T>& other)
{
	Elem<T>* last = el;
	el->data = other->data;
	
	while (other->prev != NULL)
	{
		var temp = new elem<T>;
		temp->data = stack->data;
		temp->prev = stack->prev;
		stack = stack->prev;
	}
}

template <typename T>
Stack<T>::Stack(const Stack <T>& other)
{
	copy(other);
}

template< typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != other)
	{
		free();
		copy(other);
	}

	return *this;
}



template <typename T>
void Stack<T>::free()
{
	while (top)
	{
		Elem<T>* prev = top->prev;
		delete top;
		top = prev;
	}
}