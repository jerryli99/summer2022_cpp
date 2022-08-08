#pragma once

/*
	This is a Linkedlist interface. Can be used when creating a
	single, double, circular, etc linkedlists.
*/
namespace j_model {

template<class T>
class ILinkedList {
 public:
	ILinkedList() = default;
	virtual ~ILinkedList() = default;

	//virtual void AddAtIndex(unsigned index, const T& data) = 0;
	virtual void AddFront(const T& data) = 0;
	virtual void AddEnd(const T& data) = 0;

	//virtual void RemoveAtIndex(unsigned index) = 0;
	virtual void RemoveFront() = 0;
	virtual void RemoveEnd() = 0;

	virtual bool contains(const T& data) = 0;
};

} //namespace j_model
