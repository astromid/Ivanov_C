#pragma once

using namespace std;

template <typename T>
class f_allocator
{
public:
	typedef size_t size_type;
	typedef ptrdiff_t diffecence_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T value_type;
};
