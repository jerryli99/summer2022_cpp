#pragma once

#include "queue.h"

namespace my_queues {

template<class T>
class CircularQueue : public my_queues::Queue<T>{
 public:
	CircularQueue(int circular_queue_capacity = QUEUE_DEFAULT_CAPACITY) 
		: m_circular_queue_capacity{ circular_queue_capacity } {

		m_circular_queue_array = new T[m_circular_queue_capacity];
};

	virtual ~CircularQueue() {
		std::cout << "\nCalling destructor from CricularQueue.\n";
		delete[] m_circular_queue_array;
	};

	void Enqueue(const T& queue_item) override {
		if (IsEmpty()) {
			m_front = m_rear = 0;
			m_circular_queue_array[m_rear] = queue_item;
		}
		else if (IsFull()) {
			Full();
		}
		else {
			m_rear = (m_rear + 1) % m_circular_queue_capacity;
			m_circular_queue_array[m_rear] = queue_item;
		}
			m_current_size++;
	}

	T& Dequeue() override {
		int front_index = 0;

		if (IsEmpty()) {
			throw "CircularQueue underflow.";
		}
		else if (m_front == m_rear) {
			front_index = m_front;
			m_front = m_rear = -1;
		}
		else {
			front_index = m_front;
			m_front = (m_front + 1) % m_circular_queue_capacity;
		}
		m_current_size--;

		return m_circular_queue_array[front_index];
	}

	bool IsFull() override {
		if (((m_rear + 1) % m_circular_queue_capacity) == m_front) {
			return true;
		}
		return false;
	}

	bool IsEmpty() override {
		if (m_front == -1 && m_rear == -1) {
			return true;
		}
		return false;
	}

	virtual T& Peek() {
		if (IsEmpty()) {
			throw "Queue underflow.";
		}
		return m_circular_queue_array[m_front];
	}

	void Display() {
		if (IsEmpty()) {
			std::cout << "Empty CircularQueue.\n";
		} 
		else {
			for (int i = 0; i < m_current_size; i++) {
				std::cout << m_circular_queue_array[i] << "\n";
			}
		}
	}

	int get_current_size() const override {
		return m_current_size;
	}

 private:
	T* m_circular_queue_array{};
	int m_front{ -1 };
	int m_rear{ -1 };
	int m_circular_queue_capacity{ 0 };
	int m_current_size{ 0 };

	void Full() override {
		std::cout << "private member function Full() from circular_queue.\n";
		std::cout << "CircularQueue overflow.\n";
		exit(EXIT_FAILURE);
	}

}; /* class CircularQueue */
}  /* namespace my_queues */