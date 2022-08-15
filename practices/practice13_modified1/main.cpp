#include "linkedlist_interface.h"
#include "single_linkedlist_node.h"
#include "single_linkedlist.h"

#include <iostream>
#include <vector>

using namespace my_datastructure;

//for quick testing purposes
class Item {
public:
	Item(unsigned item_id) : m_item_id{ item_id } {
		if (item_id > 999 || item_id < 0) throw "Not a valid item id.\n";
	};
	~Item() = default;

	friend bool operator==(const Item& left, const Item& right) {
		return (left.m_item_id == right.m_item_id);
	}

	friend std::ostream& operator<<(std::ostream& output, const Item& item) {
		return output << "[Item id: " << item.m_item_id << "]";
	}

private:
	unsigned m_item_id{ 0 }; // 3-digit
};



int main() {
	//Test1
	SingleLinkedlist<int>* test1 = new SingleLinkedlist<int>();
	test1->AddEnd(1);
	test1->AddFront(2);
	test1->AddEnd(3);
	test1->print_list();
	delete test1;

	std::cout << "\n\n";
	//Test2
	SingleLinkedlist<Item>* test2 = new SingleLinkedlist<Item>();

	
	for (int i = 0; i < 10; i++) {
		test2->AddFront(*(new Item(i)));
	}

	/*
	When i < 10000, it throws exception
	for (int i = 0; i < 10000; i++) {
		test2->AddFront(*(new Item(i)));
	}
	*/
	test2->print_list();

	std::cout << "Does the linkedlist contains Item with id: 1? " 
		      << (test2->contains(*(new Item(1))) ? "Yes\n" : "No\n");

	test2->RemoveEnd();
	test2->RemoveFront();
	test2->RemoveEnd();
	test2->RemoveFront();

	test2->RemoveEnd();
	test2->RemoveFront();
	test2->RemoveEnd();
	test2->RemoveFront();

	test2->RemoveEnd();
	test2->RemoveFront();
	test2->RemoveEnd();
	test2->RemoveFront();

	std::cout << "Does the linkedlist contains Item with id: 1? "
			  << (test2->contains(*(new Item(9))) ? "Yes\n" : "No\n");

	test2->print_list();

	delete test2;
}
