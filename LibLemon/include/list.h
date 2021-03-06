#pragma once

#include <stdlib.h>

template<typename T>
class ListNode
{
public:
	ListNode* next = NULL;
	ListNode* prev = NULL;
	T obj;
};

template<typename T>
class List {
public:
	List()
	{
		front = NULL;
		back = NULL;
		num = 0;
	}

	~List() {
		while(num) remove_at(0);
	}

	void clear() {
		for(int i = 0; i < num; i++){
			remove_at(i);
		}
		front = NULL;
		back = NULL;
		num = 0;
	}

	void add_back(T obj) {
		ListNode<T>* node = new ListNode<T>();
		node->next = NULL;
		node->prev = NULL;
		node->obj = obj;
		
		if (!front) {
			front = node;
		}
		else if (back) {
			back->next = node;
			node->prev = back;
		}
		back = node;
		num++;
	}

	void add_front(T obj) {
		ListNode<T>* node = new ListNode<T>();
		node->next = NULL;
		node->prev = NULL;
		node->obj = obj;

		if (!back) {
			back = node;
		}
		else if(front) {
			front->prev = node;
			node->next = front;
		}
		front = node;
		num++;
	}

	T operator[](unsigned pos) {
		return get_at(pos);
	}

	T get_at(unsigned pos) {
		if (num <= 0 || pos >= num || front == NULL) return front->obj; // Need to do something when item not in list

		ListNode<T>* current = front;

		for (unsigned int i = 0; i < pos && i < num && current->next; i++) current = current->next;

		return current->obj;
	}
	
	void replace_at(unsigned pos, T obj) {
		if (num < 0 || pos >= num) return ;

		ListNode<T>* current = front;

		for (unsigned int i = 0; i < pos; i++) current = current->next;

		current->obj = obj;
	}

	unsigned get_length() {
		return num;
	}

	T remove_at(unsigned pos) {
		if (num <= 0 || pos >= num) {
			T temp;
			return temp;
		} // Need to do something when item not in list;

		ListNode<T>* current = front;

		for (unsigned int i = 0; i < pos && i < num && current->next; i++) current = current->next;

		T obj = current->obj;

		if (current->next && current->prev) current->next->prev = current->prev;
		if (current->prev && current->next) current->prev->next = current->next;
		if (pos == 0) front = current->next;
		if (pos == --num) back = current->prev;

		free(current);
		return obj;
	}

	T get_front()
	{
		return front->obj;
	}

	T get_back()
	{
		if(back)
			return back->obj;
	}
public:
	ListNode<T>* front;
	ListNode<T>* back;
	unsigned num;
};