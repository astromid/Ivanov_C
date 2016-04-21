#pragma once
#include "sl_list.h"

template <typename T>
class stack
{
	sl_list<T>* container;

public:

	typedef size_t size_type;
	typedef ptrdiff_t diffecence_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T value_type;

	stack()
	{
		this->container = new sl_list<T>();
	}

	~stack()
	{
		delete this->container;
	}

	bool empty() const
	{
		if (this->container->size() == 0)
		{
			return true;
		}
		else return false;
	}

	size_type size() const
	{
		return this->container->size();
	}

	value_type& top()
	{
		return this->container->operator[](this->container->size() - 1);
	}

	void push(const value_type& val)
	{
		this->container->insert(val, this->container->size());
	}

	void pop()
	{
		this->container->remove(this->container->size() - 1);
	}
};
