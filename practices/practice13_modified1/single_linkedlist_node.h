#pragma once

#include <iostream>

namespace j_model {

template<class T>
class SingleLinkedlistNode {
public:
	SingleLinkedlistNode() = default;
	SingleLinkedlistNode(const T& data);
	SingleLinkedlistNode(const T& data, SingleLinkedlistNode<T>* next);

	virtual ~SingleLinkedlistNode();

	virtual T get_node_data() const;
	virtual SingleLinkedlistNode<T>* get_next_node() const;

	virtual void set_node_data(const T& data);
	virtual void set_next_node(SingleLinkedlistNode<T>* next);

private:
	//data container can be any type, like [3,4]; Item({1,2,3,4}); Tuple(3,4); etc.
	T m_data_container;
	SingleLinkedlistNode<T>* m_next{ nullptr };
};

//SingleLinkedListNode class implementation
template<class T>
SingleLinkedlistNode<T>::SingleLinkedlistNode(const T& data) : m_data_container{ data } {}

template<class T>
SingleLinkedlistNode<T>::SingleLinkedlistNode(const T& data, SingleLinkedlistNode<T>* next)
	: m_data_container{ data }, m_next{ next } {}

template<class T>
SingleLinkedlistNode<T>::~SingleLinkedlistNode() { std::cout << "Delete node.\n"; }

template<class T>
T SingleLinkedlistNode<T>::get_node_data() const {
	return m_data_container;
}

template<class T>
SingleLinkedlistNode<T>* SingleLinkedlistNode<T>::get_next_node() const {
	return m_next;
}

template<class T>
void SingleLinkedlistNode<T>::set_node_data(const T& data) {
	m_data_container = data;
}

template<class T>
void SingleLinkedlistNode<T>::set_next_node(SingleLinkedlistNode<T>* next) {
	m_next = next;
}

} //namespace j_model