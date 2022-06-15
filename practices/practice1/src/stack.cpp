#include "stack.h"
#include "bag.h"

#include <iostream>
#include <vector>

template <class T>
Stack<T>::Stack(size_t stack_capacity) : Bag<T>(stack_capacity) {}

template <class T>
Stack<T>::~Stack() {}

template<class T>
void Stack<T>::AddTwice(const T& stack_item) {
	size_t item_size = sizeof(Bag<T>::m_bag_storage[0]);

	if ((item_size > Bag<T>::m_max_storage) || 
		(2 * item_size * Bag<T>::m_bag_storage.size()) > Bag<T>::m_max_storage) {
		throw "Stack exceeds user defined capacity!";
	}

	Bag<T>::m_bag_storage.push_back(stack_item);
	Bag<T>::m_bag_storage.push_back(stack_item);
}

template<class T>
void Stack<T>::Display() const
{
	for (auto& element : Bag<T>::m_bag_storage) {
		std::cout << element << "\n";
	}
}

template <class T>
bool Stack<T>::IsEmpty() {
	if (Bag<T>::m_bag_storage.size() == 0) {
		std::cout << "Stack is Empty.\n";
		return true;
	}
	return false;
}


//Old Code
/*
//TODO: Could use vector instead of array.
template <class T>
Stack<T>::Stack(int stack_capacity) : m_max_size(stack_capacity) {
	m_stack = new T[m_max_size];
	m_top = 0;
}

template <class T>
Stack<T>::~Stack() { 
	delete[] m_stack; 
}

template <class T>
void Stack<T>::Add(const T& stack_item) {
	if (IsFull()) {
		StackFull();
	}
	else {
		m_stack[m_top++] = stack_item;
	}
}

//TODO: need to fix
template <class T>
T* Stack<T>::Delete(T& stack_item) {
	if (IsEmpty()) {
		StackEmpty();
		return 0;
	} 
	//not completed.
	stack_item = m_stack[m_top--];

	return &stack_item;
}

template <class T>
bool Stack<T>::IsFull() {
	if (m_top == m_max_size) {
		return true;
	}
	return false;
}

template <class T>
bool Stack<T>::IsEmpty() {
	if (m_top == 0) {
		return true;
	}
	return false;
}

template <class T>
const int& Stack<T>::GetTopIndex() {
	return m_top;
}

//TODO: this function needs improvement, such as resizing array. 
template <class T>
void Stack<T>::StackFull() {
	std::cout << "Stack is full.\n";
}

template <class T>
void Stack<T>::StackEmpty() {
	std::cout << "Stack is empty.\n";
}

*/