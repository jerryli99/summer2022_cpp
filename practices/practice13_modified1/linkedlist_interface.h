#pragma once

/*
	This is a Linkedlist interface. Can be used when creating a
	single, double, circular, etc linkedlists.
*/
namespace my_datastructure {

template<class T>
class LinkedlistInterface {
 public:
	LinkedlistInterface() = default;
	virtual ~LinkedlistInterface() = default;

	//virtual void AddAtIndex(unsigned index, const T& data) = 0;
	virtual void AddFront(const T& data) = 0;
	virtual void AddEnd(const T& data) = 0;

	//virtual void RemoveAtIndex(unsigned index) = 0;
	virtual void RemoveFront() = 0;
	virtual void RemoveEnd() = 0;

	virtual bool contains(const T& data) = 0;
};

} //namespace my_datastructure
