#pragma once
#include <fstream>
#include <limits>
#include <map>

using namespace std;

template <typename T, const char* filename>
class f_allocator
{
private:
	fstream memory_file;
	map<T*, size_t> allocated_memory;

public:
	typedef size_t size_type;
	typedef ptrdiff_t diffecence_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T value_type;

	template <typename U, const char* filename>
	struct rebind
	{
		typedef f_allocator<U, filename> other;
	};

	f_allocator()
	{
		this->memory_file(filename, fstream::app);
	}

	f_allocator(const f_allocator& f_al)
	{
		this->memory_file = f_al.memory_file;
		this->allocated_memory = f_al.allocated_memory;
	}

	template <typename U, const char* filename>
	f_allocator(const f_allocator<U, filename>& f_al)
	{
		this->memory_file = f_al.memory_file;
		this->allocated_memory = f_al.allocated_memory;
	}

	~f_allocator()
	{
		for each (const auto item in this->allocated_memory)
		{
			this->memory_file.write(reinterpret_cast<const char *>(item.first), item.second);
		}
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
		this->allocated_memory.insert(ret, num);
		return ret;
	}

	void deallocate(pointer p, size_type num)
	{
		::operator delete((void*)p);
		this->allocated_memory.erase(p);
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

//операции сравнения определены только если они связаны с одним и тем же файлом
template <typename T, typename U, const char* filename>
bool operator== (const f_allocator<T, filename>& f_al1, const f_allocator<U, filename>& f_al2)
{
	if (f_al1->memory_file == f_al2->memory_file)
	{
		return true;
	}
	else return false;
}

template <typename T, typename U, const char* filename>
bool operator!= (const f_allocator<T, filename>& f_al1, const f_allocator<U, filename>& f_al2)
{
	return !(f_al1 == f_al2);
}