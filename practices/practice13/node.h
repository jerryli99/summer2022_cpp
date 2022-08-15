#pragma once

#include <iostream>
/*
	Use Node as a base class.
	Can have other types of nodes derived from class Node.
	For example:
	 TreeNode that contains 2 data blocks with five *next pointers.
	 BiDirection Node that has 1 data and contains next and previous pointers, etc.

	Originally, I think having a node class is enough, but then what if 
	there could be different types of nodes like the above?

	I need more abstraction. That is why I have this class Node.
	
	prefixes: uni- (one), bi- (two), tri- (three), quad- (four)

	For Single linked list, I have a UniDirNode;
	for Double linked list, I have a BiDirNode;
*/
namespace j_model {

template<class T>
class Node {
 public:
	Node() = default;
	Node(const T& data);
	virtual ~Node();

	virtual T get_node_data() const;

	virtual void set_node_data(const T& data);

 private:
	//data container can be any type, like [3,4]; Item({1,2,3,4}); Tuple(3,4); etc.
	T m_data_container;
};

//Node class implementation
template<class T>
Node<T>::Node(const T& data) : m_data_container{ data } {};

template<class T>
Node<T>::~Node() { std::cout << "Node delete\n"; };

template<class T>
T Node<T>::get_node_data() const {
	return m_data_container;
}

template<class T>
void Node<T>::set_node_data(const T& data) {
	m_data_container = data;
}

} //namespace j_model