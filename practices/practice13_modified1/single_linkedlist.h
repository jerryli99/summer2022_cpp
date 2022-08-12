#pragma once

#include "linkedlist_interface.h"
#include "single_linkedlist_node.h"

namespace j_model {

template<class T>
class SingleLinkedlist : public LinkedlistInterface<T> {
public:
	SingleLinkedlist() = default;
	virtual ~SingleLinkedlist();

	void AddFront(const T& data) override;
	void AddEnd(const T& data) override;
	
	void RemoveFront() override;
	void RemoveEnd() override;

	bool contains(const T& data) override;

	void print_list();

	unsigned get_size() const;

private:
	SingleLinkedlistNode<T>* m_head{ nullptr };
	unsigned m_size{ 0 };
}; //end of SingleLinkedList class declaration


//SingleLinkedList class implementation
template<class T>
SingleLinkedlist<T>::~SingleLinkedlist() {

	SingleLinkedlistNode<T>* curr_tmp_node = m_head;
	SingleLinkedlistNode<T>* next_tmp_node = nullptr;

	while (curr_tmp_node != nullptr) {
		next_tmp_node = curr_tmp_node->get_next_node();
		delete curr_tmp_node;
		curr_tmp_node = next_tmp_node;
	}
	m_head = nullptr;
	std::cout << "All nodes removed from linkedlist.\n";
}

template<class T>
void SingleLinkedlist<T>::AddFront(const T& data) {
	//create node
	SingleLinkedlistNode<T>* new_node = new SingleLinkedlistNode(data);

	//add node at front
	new_node->set_next_node(m_head);
	m_head = new_node;
	m_size++;
}

template<class T>
void SingleLinkedlist<T>::AddEnd(const T& data) {
	//create node
	SingleLinkedlistNode<T>* new_node = new SingleLinkedlistNode(data);
	new_node->set_next_node(nullptr);

	//Add node at the beginning of the linkedlist.
	if (m_head == nullptr) {
		m_head = new_node;
	}
	//Add node at the end of the linked list.
	else {
		SingleLinkedlistNode<T>* last_node = m_head;

		while (last_node->get_next_node() != nullptr) {
			last_node = last_node->get_next_node();
		}
		last_node->set_next_node(new_node);
	}
	m_size++;
}

template<class T>
void SingleLinkedlist<T>::RemoveEnd() {

	SingleLinkedlistNode<T>* curr_tmp_node = m_head;
	SingleLinkedlistNode<T>* prev_tmp_node = nullptr;

	if (get_size() == 0) {
		std::cout << "No nodes to remove.\n";
		return;
	}

	while (curr_tmp_node->get_next_node() != nullptr) {
		prev_tmp_node = curr_tmp_node;
		curr_tmp_node = curr_tmp_node->get_next_node();
	}
	prev_tmp_node->set_next_node(nullptr);
	delete curr_tmp_node;
	m_size--;
}

template<class T>
void SingleLinkedlist<T>::RemoveFront() {

	SingleLinkedlistNode<T>* tmp_node = m_head;

	if (get_size() == 0) {
		std::cout << "No nodes to remove.\n";
		return;
	}

	m_head = m_head->get_next_node();
	delete tmp_node;
	m_size--;
}

//for style: https://google.github.io/styleguide/cppguide.html#Conditionals
template<class T>
bool SingleLinkedlist<T>::contains(const T& data) {

	SingleLinkedlistNode<T>* tmp_node = m_head;

	while (tmp_node != nullptr) {
		if (tmp_node->get_node_data() == data) return true;
		tmp_node = tmp_node->get_next_node();
	}
	return false;
}

template<class T>
void SingleLinkedlist<T>::print_list() {

	SingleLinkedlistNode<T>* tmp_node = m_head;
	
	while (tmp_node != nullptr) {
		std::cout << tmp_node->get_node_data() << "-->";
		tmp_node = tmp_node->get_next_node();
	}

	if (tmp_node == nullptr) std::cout << "nullptr\n";
}

template<class T>
unsigned SingleLinkedlist<T>::get_size() const {
	return m_size;
}

} //namespace j_model