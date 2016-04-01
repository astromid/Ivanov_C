#include "sl_list.h"



template<typename T>
node<T>* sl_list<T>::get_head()
{
	return head;
}

template<typename T>
node<T>* sl_list<T>::get_end()
{
	return end;
}

template<typename T>
void sl_list<T>::insert(T new_element, int index)
{
	node<T>* new_node = new node<T>;
	new_node->data = new_element;
	if (head == nullptr)
	{
		head = new_node;
		end = new_node;
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
		}
	}
	len++;
}

template<typename T>
void sl_list<T>::remove(int index)
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

template<typename T>
T sl_list<T>::operator[](int index)
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


