#include "f_iterator.h"



template <typename T>
f_iterator<T>::f_iterator()
{
	curr_ptr = nullptr;
}

template<typename T>
f_iterator<T>::f_iterator(const f_iterator & fIt)
{
	curr_ptr = fIt->curr_ptr;
}

template <typename T>
f_iterator<T>::~f_iterator()
{
	delete curr_ptr;
}

template<typename T>
bool f_iterator<T>::operator!=(f_iterator fIt)
{
	if (this->curr_ptr->next != fIt.curr_ptr->next)
	{
		return true;
	}
	else return false;
}

template<typename T>
bool f_iterator<T>::operator==(f_iterator fIt)
{
	if (this->curr_ptr->next == fIt.curr_ptr->next)
	{
		return true;
	}
	else return false;
}

template<typename T>
f_iterator<T> & f_iterator<T>::operator++()
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

template<typename T>
f_iterator<T> & f_iterator<T>::operator++(int)					//postfix overload
{
	return this->operator++();
}

template<typename T>
T & f_iterator<T>::operator*()
{
	return this->curr_ptr->data;
}

template<typename T>
void f_iterator<T>::operator=(f_iterator fIt)
{
	this->curr_ptr = fIt->curr_ptr;
}

template<typename T>
void f_iterator<T>::operator=(node<T>* pointer)
{
	this->curr_ptr = pointer;
}
