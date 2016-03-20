#pragma once
#include "bid_iterator.h"
#include "node.h"

template <typename T> class sl_list
{
	node<T>* head;
	node<T>* tail;
	int len;

public:
	sl_list()
	{
		head = nullptr;
		tail = nullptr;
		len = 0;
	}

	~sl_list()
	{
		while (head != tail)
		{
			node<T> *tmp = head->next;
			delete head;
			head = tmp;
		}
	}

	f_iterator<T> begin()
	{
		return f_iterator<T>(this->head);
	}

	f_iterator<T> end()
	{
		return f_iterator<T>(this->tail);
	}

	bid_iterator<T> bbegin()
	{
		return bid_iterator<T>(head, head);
	}

	bid_iterator<T> bend()
	{
		return bid_iterator<T>(head, tail);
	}

	void insert(T new_element, int index)
	{
		node<T>* new_node = new node<T>;
		new_node->data = new_element;
		if (head == nullptr)
		{
			head = new_node;
			new_node->next = nullptr;
			tail = new_node;
		}
		else
		{
			if (index == 0)
			{
				new_node->next = head;
				head = new_node;
			}
			else
			{
				int i = 0;
				node<T>* curr = head;
				while (i < index - 1)
				{
					curr = curr->next;
					i++;
				}
				new_node->next = curr->next;
				curr->next = new_node;
				if (index == len)
				{
					tail = curr->next;
				}
			}
		}
		len++;
	}

	void remove(int index)
	{
		int i = 0;
		node<T>* curr = head;
		while (i < index - 1)
		{
			curr = curr->next;
			i++;
		}
		node<T>* prev = curr;
		curr = curr->next;
		prev->next = curr->next;
		delete curr;
		len--;
	}

	T& operator[](int index)
	{
		int i = 0;
		node<T>* curr = head;
		while (i < index)
		{
			curr = curr->next;
			i++;
		}
		return curr->data;
	}
};
