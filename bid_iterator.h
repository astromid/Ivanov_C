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

	node<T>* head_ptr;

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

	~bid_iterator() {}

	bid_iterator& operator--()
	{
		if (this->curr_ptr != this->head_ptr)
		{
			node<T>* tmp = new node<T>;
			tmp = this->curr_ptr;
			this->curr_ptr = this->head_ptr;
			while (this->curr_ptr->next != tmp)
			{
				this->curr_ptr++;
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

	void operator=(const bid_iterator& bIt)
	{
		head_ptr = bIt->head_ptr;
		curr_ptr = bIt->curr_ptr;
	}

	void operator=(node<T>* pointer)
	{
		this->curr_ptr = pointer;
		if (this->head_ptr == nullptr)
		{
			this->head_ptr = pointer;
		}
	}

};

