#include <iostream>

class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList(int val = -1)
	{
		this->_val = val;
		this->_next = nullptr;
		this->_prev = nullptr;
	}

		/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		MyLinkedList* cur = this->_next;
	
		while (cur != this && index)
		{
			cur = cur->_next;
			index--;
		}

		if (index > 0)
			return -1;

		return cur->_val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		MyLinkedList* node = new MyLinkedList(val);

		if (this->_next = this)
		{
			this->_next = node;
			node->_next = this;
			this->_prev = node;
			node->_prev = this;
		}
		else
		{
			node->_next = this->_next;
			node->_prev = this;
			this->_next->_prev = node;
			this->_next = node;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		MyLinkedList* cur = this->_prev;
		MyLinkedList* node = new MyLinkedList(val);
		
		node->_next = cur->_next;
		node->_prev = cur;
		cur->_next->_prev = node;
		cur->_next = node;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		MyLinkedList* cur = this->_next;

		while (cur != this && index)
		{
			cur = cur->_next;
			index--;
		}

		if (index > 0)
			return;

		cur = cur->_prev;
		MyLinkedList* node = new MyLinkedList(val);

		node->_next = cur->_next;
		node->_prev = cur;
		cur->_next->_prev = node;
		cur->_next = node;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		MyLinkedList* cur = this->_next;

		while (cur != this && index)
		{
			cur = cur->_next;
			index--;
		}

		if (index > 0)
			return;
		
		MyLinkedList* prev = cur->_prev;
		prev->_next = cur->_next;
		cur->_next->_prev = prev;

		delete cur;
		cur = nullptr;
	}

private:
	int _val;
	MyLinkedList* _next;
	MyLinkedList* _prev;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */