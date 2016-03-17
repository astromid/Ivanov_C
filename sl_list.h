#pragma once

template <typename T> struct node
{
	T data;
	node* next;
};

template <typename T> class sl_list
{
	node<T>* head;
	node<T>* end;
	int len;

public:
	sl_list()
	{
		head = nullptr;
		end = nullptr;
		len = 0;
	}

	~sl_list()
	{
		while (head != end)
		{
			node<T> *tmp = head->next;
			delete head;
			head = tmp;
		}
	}

	node<T>* get_head()
	{
		return head;
	}

	node<T>* get_end()
	{
		return end;
	}

	void insert(T new_element, int index)
	{
		node<T>* new_node = new node<T>;
		new_node->data = new_element;
		if (head == nullptr)
		{
			head = new_node;
			new_node->next = nullptr;
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
				if (index == len)
				{
					end = curr->next;
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

	T operator[](int index)
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
