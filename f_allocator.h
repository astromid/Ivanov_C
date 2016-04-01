#pragma once
#include <fstream>
#include <limits>

using namespace std;

template <typename T>
class f_allocator
{
private:
	fstream memory_file;
	T* allocated_ptr;
	size_t allocated_num;

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

	f_allocator(fstream m_file)
	{
		this->memory_file = m_file;
	}

	f_allocator(const f_allocator& f_al)
	{
		this->memory_file = f_al.memory_file;
		this->allocated_num = f_al.allocated_num;
		this->allocated_ptr = f_al.allocated_ptr;
	}

	template <typename U>
	f_allocator(const f_allocator<U>& f_al)
	{
		this->memory_file = f_al.memory_file;
		this->allocated_num = f_al.allocated_num;
		this->allocated_ptr = f_al.allocated_ptr;
	}

	~f_allocator()
	{
		this->memory_file.write(reinterpret_cast<const char *>(&(this->allocated_ptr)), this->allocated_num);
	}

	pointer address(reference x) const
	{
		return &x;
	}

	const_pointer address(const_reference x) const
	{
		return &x;
	}

	pointer allocate(size_type num, const_pointer = 0)
	{
		pointer ret = (pointer)(::operator new(num * sizeof(value_type)));
		this->allocated_ptr = ret;
		this->allocated_num = num;
		return ret;
	}

	void deallocate(pointer p, size_type num)
	{
		::operator delete((void*)p);
		this->allocated_ptr = nullptr;
		this->allocated_num = 0;
	}

	size_type max_size()
	{
		return numeric_limits<size_t>::max() / sizeof(value_type);
	}

	void construct(pointer p, const value_type& x)
	{
		new((void*)p)value_type(x);
	}

	void destroy(pointer p)
	{
		p->~T();
	}
};

template <typename T, typename U>
bool operator== (const f_allocator<T>& f_al1, const f_allocator<U>& f_al2)
{
	if (f_al1->memory_file == f_al2->memory_file)
	{
		return true;
	}
	else return false;
}

template <typename T, typename U>
bool operator!= (const f_allocator<T>& f_al1, const f_allocator<U>& f_al2)
{
	return !(f_al1 == f_al2);
}