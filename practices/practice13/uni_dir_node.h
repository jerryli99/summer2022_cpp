#pragma once

#include "node.h"
/*
   UniDirNodes & Singlelinkedlist:

          next        next        next
   [item]----->[item]----->[item]-----> ....
   
*/
namespace j_model {

template<class T>
class UniDirNode : public Node<T> {
 public:
	UniDirNode() = default;
	UniDirNode(const T& data);
	UniDirNode(const T& data, UniDirNode<T>* next);
	virtual ~UniDirNode();

	UniDirNode<T>* get_next_node() const;

	void set_next_node(UniDirNode<T>* next);

private:
	UniDirNode<T>* m_next{ nullptr };
}; //end of UniDirNode class declaration


//UniDirNode class implementation
template<class T>
UniDirNode<T>::~UniDirNode() { std::cout << "UniDirNode delete\n"; };

template<class T>
UniDirNode<T>::UniDirNode(const T& data) : Node<T>{ data } {};

template<class T>
UniDirNode<T>::UniDirNode(const T& data, UniDirNode<T>* next) : Node<T>{ data }, m_next{ next } {};

template<class T>
UniDirNode<T>* UniDirNode<T>::get_next_node() const {
	return m_next;
}

template<class T>
void UniDirNode<T>::set_next_node(UniDirNode<T>* next) {
	m_next = next;
}

} // namespace j_model