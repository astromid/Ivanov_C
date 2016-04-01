#include "bid_iterator.h"



template <typename T>
bid_iterator<T>::bid_iterator()
{
	head_ptr = nullptr;
	curr_ptr = nullptr;
}

template<typename T>
bid_iterator<T>::bid_iterator(const bid_iterator & bIt)
{
	head_ptr = bIt.head_ptr;
	curr_ptr = bIt.curr_ptr;
}

template <typename T>
bid_iterator<T>::~bid_iterator()
{
	delete head_ptr;
	delete curr_ptr;
}

template<typename T>
bid_iterator<T> & bid_iterator<T>::operator--()
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

template<typename T>
void bid_iterator<T>::operator=(const bid_iterator & bIt)
{
	head_ptr = bIt->head_ptr;
	curr_ptr = bIt->curr_ptr;
}

template<typename T>
void bid_iterator<T>::operator=(node<T>* pointer)
{
	this->curr_ptr = pointer;
	if (this->head_ptr == nullptr)
	{
		this->head_ptr = pointer;
	}
}
