#pragma once
#include <fstream>
#include <limits>
#include <string>
#include <cstdio>

using namespace std;

template <typename T>
class f_allocator
{
public:
	string default_filename = "memory.txt";
	string al_filename = "al_memory.txt";
	fstream memory_file;
	fstream al_memory;

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

	f_allocator() {}

	f_allocator(const f_allocator& f_al) {}

	template <typename U>
	f_allocator(const f_allocator<U>& f_al) {}

	~f_allocator()
	{
		this->al_memory.open(al_filename, fstream::in);
		this->memory_file.open(default_filename, fstream::app);
		while(this->al_memory.good())
		{
			string str1, str2;
			int ptr, num;
			this->al_memory >> str1 >> str2;
			if (str1 != "" && str2 != "")
			{
				ptr = stoi(str1);
				num = stoi(str2);
				this->memory_file.write(reinterpret_cast<const char *>(ptr), num);
			}
		}
		this->memory_file.close();
		this->al_memory.close();
		remove(al_filename.c_str());
		cout << "ALLOCATOR DESTROYED" << endl;
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
		cout << "MEMORY ALLOCATED" << endl;
		this->al_memory.open(al_filename, fstream::app);
		this->al_memory << (int)ret << " " << num << endl;
		this->al_memory.close();

		return ret;
	}

	void deallocate(pointer p, size_type num)
	{
		::operator delete((void*)p);
		cout << "MEMORY DEALLOCATED" << endl;
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
	return true;
}

template <typename T, typename U>
bool operator!= (const f_allocator<T>& f_al1, const f_allocator<U>& f_al2)
{
	return false;
}