#pragma once
#include "f_iterator.h"

template <typename T>
class bid_iterator :
	public f_iterator<T>
{
public:

	typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;

	node<value_type>* head_ptr;

	bid_iterator()
	{
		head_ptr = nullptr;
		curr_ptr = nullptr;
	}

	bid_iterator(const bid_iterator& bIt)
	{
		head_ptr = bIt.head_ptr;
		curr_ptr = bIt.curr_ptr;
	}

	bid_iterator(const f_iterator& fIt, const f_iterator& fIt_head)
	{
		head_ptr = fIt_head->curr_ptr;
		curr_ptr = fIt->curr_ptr;
	}

	bid_iterator(node<value_type>* head_pointer, node<value_type>* curr_pointer)
	{
		head_ptr = head_pointer;
		curr_ptr = curr_pointer;
	}

	~bid_iterator() {}

	bid_iterator& operator--()
	{
		if (this->curr_ptr != this->head_ptr)
		{
			node<value_type>* tmp = new node<value_type>;
			tmp = this->curr_ptr;
			this->curr_ptr = this->head_ptr;
			while (this->curr_ptr->next != tmp)
			{
				this->operator++();
			}
			return *this;
		}
		else
		{
			cout << "Failed to decrement the iterator." << endl;
			return *this;
		}
	}

	bid_iterator& operator--(int)								//postfix overload
	{
		return this->operator--();
	}
};