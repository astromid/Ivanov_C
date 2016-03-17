#pragma once
#include <iterator>
#include "sl_list.h"
using namespace std;

template <typename T>
class f_iterator
{
public:
	
	typedef forward_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
	
	node<T>* curr_ptr;

	f_iterator()
	{
		curr_ptr = nullptr;
	}

	f_iterator(const f_iterator& fIt)
	{
		curr_ptr = fIt.curr_ptr;
	}

	~f_iterator() {}

	bool operator!=(f_iterator fIt)
	{
		if (this->curr_ptr == nullptr || fIt.curr_ptr == nullptr)
		{
			if (this->curr_ptr == nullptr && fIt.curr_ptr == nullptr)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			if (this->curr_ptr->next != fIt.curr_ptr->next)
			{
				return true;
			}
			else return false;
		}
	}

	bool operator==(f_iterator fIt)
	{
		if (this->curr_ptr == nullptr || fIt.curr_ptr == nullptr)
		{
			if (this->curr_ptr == nullptr && fIt.curr_ptr == nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (this->curr_ptr->next == fIt.curr_ptr->next)
			{
				return true;
			}
			else return false;
		}

	}

	f_iterator& operator++()
	{
		if (this->curr_ptr->next != nullptr)
		{
			this->curr_ptr = (this->curr_ptr)->next;
			return *this;
		}
		else
		{
			cout << "Failed to increment the iterator." << endl;
			return *this;
		}
	}

	f_iterator& operator++(int)									//postfix overload
	{
		return this->operator++();
	}

	T& operator*()
	{
		return this->curr_ptr->data;
	}

	void operator=(f_iterator fIt)
	{
		this->curr_ptr = fIt->curr_ptr;
	}

	void operator=(node<T>* pointer)
	{
		this->curr_ptr = pointer;
	}
};
