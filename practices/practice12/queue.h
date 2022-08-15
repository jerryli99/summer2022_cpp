#pragma once

#define QUEUE_DEFAULT_CAPACITY 1024

#include <iostream>

/* 
   According to
   https://codingart.readthedocs.io/en/latest/cpp/Scoping.html and
   https://google.github.io/styleguide/cppguide.html#Namespaces
   having "using namespace std" could pullute the namespace.
  
   using namespace std; 
*/


/*
    This Queue class might not be the perfect Queue class, 
    but I wrote this class to first test virtual destructors, 
    and then test how namespaces are used and how templates are used.

    I changed my if-elseif-else indentation style from:
	if () {

	} else if () {

	} else {

	}

	to 

	if () {

	}
	else if () {

	}
	else {

	}
	to improve code readability.
*/

/*
    I made all functions virtual because I might implement 
    a linked list version of queue in the future.
*/

namespace my_queues {
template<class T>
class Queue {
 public:
	Queue(int queue_capacity = QUEUE_DEFAULT_CAPACITY) 
		: m_queue_capacity{ queue_capacity } {

		m_queue_array = new T [m_queue_capacity];
	};

	virtual ~Queue() {
		std::cout << "\nCalling destructor from Queue.\n";
		delete[] m_queue_array;
	};

	virtual void Enqueue(const T& queue_item) {
		if (IsEmpty()) {
			m_front = m_rear = 0;
			m_queue_array[m_rear] = queue_item;
		} 
		else if (IsFull()) {
			Full();
		} 
		else {
			m_queue_array[++m_rear] = queue_item;
		}
		m_current_size++;
	}

	virtual T& Dequeue() {
		int front_index = 0;

		if (IsEmpty()) {
			throw "Queue underflow.";
		} 
		else if (m_front == m_rear) {
			front_index = m_front;
			m_front = m_rear = -1;
		} 
		else {
			front_index = m_front;
			m_front++;
		}
		m_current_size--;

		return m_queue_array[front_index];
	}

	virtual bool IsFull() {
		if (m_rear == m_queue_capacity - 1) {
			return true;
		} 
		return false;
	}

	virtual bool IsEmpty() {
		if (m_front == -1 && m_rear == -1) {
			return true;
		}
		return false;
	}

	//Peek() returns the front pointer
	virtual T& Peek() {
		if (IsEmpty()) {
			throw "Queue underflow.";
		}
		return m_queue_array[m_front];
	}

	virtual void Display() {
		if (IsEmpty()) {
			std::cout << "Empty Queue.\n";
		}
		else {
			for (int i = 0; i < m_current_size; i++) {
				std::cout << m_queue_array[i] << "\n";
			}
		}
	}

	virtual int get_current_size() const {
		return m_current_size;
	}

 protected:
	/*
		so what if I put the destructor in here ?
		 
		~Queue() {
			cout << "\nCalling destructor from Queue.\n";
			 delete[] m_queue_array;
		}

		This gives me a compiler error, saying: MyQueues::Queue<int>::~Queue 
		cannot access protected member declared in class MyQueues::Queue<int>
    */

 private:
	 T* m_queue_array{};
	 int m_front{ -1 };
	 int m_rear{ -1 };
	 int m_queue_capacity{ 0 };
	 int m_current_size{ 0 };

	/*		  
		If this is a library I am writing, I should also consider different people might have 
		different ideas about writing this Resize() function. Hence, I make Resize() virtual but 
		private. I make it private because I don't want to expose access of Resize() to the user; 
		the users only needs to override the private function.  
		
		I originally wrote Resize(), and then I realized there is no need to do that, so I renamed it to Full().
		Since I made it a virtual function, the behavior that Full() will make may vary among the developers. 
		For example, developer 1 can throw his own exceptions and developer 2 can write a resize algorithm, etc. 
		That is why I named the function Full().
	*/

	virtual void Full() {
		std::cout << "private member function Full() from queue.\n";
		std::cout << "Queue overflow.\n";
		exit(EXIT_FAILURE);
	}

}; /* class Queue */
} /* namespace my_queues */
