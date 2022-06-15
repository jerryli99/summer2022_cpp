/*
	Description:
		Users can define the bag capacity in bytes.
		The bag uses std::vector<T> for storage. 
		Users can add and delete items with push and pop, 
		clear all elements, and inspect storage size.

	Updated: 6/14/22
*/

#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <vector>

template <class T>
class Bag {
 public:
	Bag(size_t bag_capacity);
	~Bag();

	virtual void Add(const T& bag_item);
	virtual void Delete();
	virtual void ClearAll();
	virtual void Display() const;

	virtual bool IsEmpty();
	virtual size_t StorageSize();

 protected:
	std::vector<T> m_bag_storage;
	size_t m_max_storage; //max storage in bytes.

};

#endif


//bool IsFull();
//virtual bool Contains(T& bag_item);
//private:
	//T* m_bag_array;
	//int m_top;
	//void Resize();
	//void Empty();