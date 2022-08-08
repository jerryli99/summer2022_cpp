#pragma once

#include "I_linkedlist.h"
#include "uni_dir_node.h"

#include <assert.h>

namespace j_model {

template<class T>
class SingleLinkedList : public ILinkedList<T> {
public:
	SingleLinkedList() = default;
	virtual ~SingleLinkedList();

	//void AddAtIndex(unsigned index, const T& data) override;
	void AddFront(const T& data) override;
	void AddEnd(const T& data) override;
	
	//void RemoveAtIndex(unsigned index, const T& data) override;
	void RemoveFront() override;
	void RemoveEnd() override;

	bool contains(const T& data) override;

	void print_list();

	unsigned get_size() const;

private:
	UniDirNode<T>* m_head{ nullptr };
	unsigned m_size{ 0 };
}; //end of SingleLinkedList class declaration


//SingleLinkedList class implementation
template<class T>
SingleLinkedList<T>::~SingleLinkedList() {
	UniDirNode<T>* curr_tmp_node = m_head;
	UniDirNode<T>* next_tmp_node = nullptr;

	while (curr_tmp_node != nullptr) {
		next_tmp_node = curr_tmp_node->get_next_node();
		delete curr_tmp_node;
		curr_tmp_node = next_tmp_node;
	}
	m_head = nullptr;
}

template<class T>
void SingleLinkedList<T>::AddFront(const T& data) {
	//create node
	UniDirNode<T>* new_node = new UniDirNode(data);

	//add node at front
	new_node->set_next_node(m_head);
	m_head = new_node;
	m_size++;
}

template<class T>
void SingleLinkedList<T>::AddEnd(const T& data) {
	//create node
	UniDirNode<T>* new_node = new UniDirNode(data);
	new_node->set_next_node(nullptr);

	//Add node at the beginning of the linkedlist.
	if (m_head == nullptr) {
		m_head = new_node;
	}
	//Add node at the end of the linked list.
	else {
		UniDirNode<T>* last_node = m_head;

		while (last_node->get_next_node() != nullptr) {
			last_node = last_node->get_next_node();
		}
		last_node->set_next_node(new_node);
	}
	m_size++;
}

template<class T>
void SingleLinkedList<T>::RemoveEnd() {
	UniDirNode<T>* curr_tmp_node = m_head;
	UniDirNode<T>* prev_tmp_node = nullptr;

	while (curr_tmp_node->get_next_node() != nullptr) {
		prev_tmp_node = curr_tmp_node;
		curr_tmp_node = curr_tmp_node->get_next_node();
	}
	prev_tmp_node->set_next_node(nullptr);
	delete curr_tmp_node;
	m_size--;
}

template<class T>
void SingleLinkedList<T>::RemoveFront() {
	UniDirNode<T>* tmp_node = m_head;
	m_head = m_head->get_next_node();
	delete tmp_node;
	m_size--;
}

template<class T>
bool SingleLinkedList<T>::contains(const T& data) {
	UniDirNode<T>* tmp_node = m_head;

	//for style: https://google.github.io/styleguide/cppguide.html#Conditionals
	while (tmp_node != nullptr) {
		if (tmp_node->get_node_data() == data) return true;
		tmp_node = tmp_node->get_next_node();
	}
	return false;
}

template<class T>
void SingleLinkedList<T>::print_list() {
	UniDirNode<T>* tmp_node = m_head;
	
	while (tmp_node != nullptr) {
		std::cout << tmp_node->get_node_data() << "-->";
		tmp_node = tmp_node->get_next_node();
	}

	if (tmp_node == nullptr) std::cout << "nullptr\n";
}

template<class T>
unsigned SingleLinkedList<T>::get_size() const {
	return m_size;
}

} //namespace j_model