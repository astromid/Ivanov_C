#pragma once
#include <fstream>
#include <limits>

using namespace std;

template <typename T>
class f_allocator
{
private:
	fstream memory_file;

public:
	typedef size_t size_type;
	typedef ptrdiff_t diffecence_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T value_type;

	template <typename U>
	struct rebind
	{
		typedef f_allocator<U> other;
	};

	f_allocator()
	{

	}

	f_allocator(const f_allocator& f_al)
	{
		this->memory_file = f_al->memory_file;
	}

	template <typename U>
	f_allocator(const f_allocator<U>& f_al)
	{

	}

	~f_allocator()
	{

	}

	pointer address(reference x) const
	{
		return &x;
	}

	const_pointer address(const_reference x) const
	{
		return x;
	}

	pointer allocate(size_type n, const_pointer = 0)
	{

	}

	void deallocate(pointer p, size_type)
	{

	}

	size_type max_size()
	{

	}

	void construct(pointer p, const value_type& x)
	{

	}

	void destroy(pointer p)
	{

	}
};
