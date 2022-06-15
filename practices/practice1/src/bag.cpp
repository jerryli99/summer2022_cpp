/*
	Description:
		An implementation of Bag ADT based on std::vector<T>

	Updated: 6/14/22
*/

#include "bag.h"

template <class T>
Bag<T>::Bag(size_t bag_capacity) : m_max_storage(bag_capacity) {}

template <class T>
Bag<T>::~Bag() {}

template <class T>
void Bag<T>::Add(const T& bag_item) {
	size_t item_size = sizeof(m_bag_storage[0]);

	if ((item_size > m_max_storage) || 
		(item_size * m_bag_storage.size()) > m_max_storage) {
		throw "Bag exceeds user defined capacity!";
	}
	m_bag_storage.push_back(bag_item);
}

template <class T>
void Bag<T>::Delete() {
	m_bag_storage.pop_back();
}

template <class T>
void Bag<T>::ClearAll() {
	m_bag_storage.clear();
}

template<class T>
void Bag<T>::Display() const
{
	for (auto& element : m_bag_storage) {
		std::cout << element << "\n";
	}
}

template <class T>
bool Bag<T>::IsEmpty() {
	if (m_bag_storage.size() == 0) {
		std::cout << "Bag is empty!\n";
		return true;
	}
	return false;
}

template <class T>
size_t Bag<T>::StorageSize() {
	return (m_bag_storage.size() * sizeof(m_bag_storage[0]));
}





// Old Code
// 
//TODO: Could use vector instead of array. 6/8/22
/*
template <class T>
Bag<T>::Bag(int bag_capacity) : m_max_size(bag_capacity) {
	m_bag_array = new T[m_max_size];
	m_top = 0;

}
*/

/*
template <class T>
void Bag<T>::Add(const T& bag_item) {
	if (IsFull()) {
		Resize();
	}
	m_bag_array[m_top++] = bag_item;
}
*/


//Since changed to vector, no need to use m_top. 6/11/22
//TODO: need to complete the Delete function 6/8/22
/*
template <class T>
T* Bag<T>::Delete(T& bag_item) {
	int count_removes = 0;

	//T* tmp = new T[m_max_size];

	if (IsEmpty()) {
		Empty();
	}

	for (int i = 0; i < m_top; i++) {
		if (bag_item == m_bag_array[i]) {
			count_removes++;
		//	tmp[i] = m_bag_array[i + 1];
		}
		//tmp[i] = m_bag_array[i];
	}
	std::cout << "Remove times: "<< count_removes <<"\n";
	m_top = m_top - count_removes;

	delete[] m_bag_array;
	m_bag_array = tmp;
	m_top = m_top - count_removes;

	return &bag_item;
}

template <class T>
bool Bag<T>::IsFull() {
	if (m_top == m_max_size) {
		return true;
	}
	return false;
}


template <class T>
bool Bag<T>::IsEmpty() {
	if (m_top == 0) {
		return true;
	}
	return false;
}


template <class T>
bool Bag<T>::Contains(T& bag_item) {
	for (int i = 0; i < m_top; i++) {
		if (bag_item == m_bag_array[i]) {
			return true;
		}
	}
	return false;
}

template <class T>
const int& Bag<T>::GetTopIndex() {
	return m_top;
}


template <class T> 
void Bag<T>::Resize() {
	int updated_size = m_max_size * 2;
	T* tmp = new T[updated_size];

	for (int i = 0; i < m_top; i++) {
		tmp[i] = m_bag_array[i];
	}

	delete[] m_bag_array;
	m_bag_array = tmp;
	tmp = nullptr;
	m_max_size = updated_size;
}

template <class T>
void Bag<T>::Empty() {
	std::cout << "Bag is empty.\n";
}
*/