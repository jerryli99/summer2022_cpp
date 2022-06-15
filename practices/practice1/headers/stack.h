#ifndef STACK_H
#define STACK_H

#include "bag.h"

template <class T>
class Stack : public Bag<T> {
 public:
	 Stack(size_t stack_capacity);
	 ~Stack();

	 void AddTwice(const T& stack_item);
	 void Display() const;

	 bool IsEmpty();

 private:
	 size_t m_max_storage;
};

#endif

//Old Code
/*
//TODO: make functions in the Bag class virtual.
//      let Stack class inherit Bag, and then override
//      Add, Delete, etc.
template <class T>
class Stack {
 public:
	Stack(int stack_capacity);
	~Stack();

	void Add(const T& stack_item);
	T* Delete(T& stack_item);

	bool IsFull();
	bool IsEmpty();

	const int& GetTopIndex();

 private:
	 int m_top;
	 int m_max_size;
	 T* m_stack;

	 void StackFull();
	 void StackEmpty();
};

#endif

*/