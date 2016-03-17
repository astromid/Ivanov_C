#include <iterator>
using namespace std;

template <typename T> struct node
{
	T data;
	node *next;
};

template <typename T> class List
{
	node<T> *head;
	node<T> *end;
	int len;

public:
	class f_list_iterator : public iterator<forward_iterator_tag, T, ptrdiff_t, T*, T&>
	{
	public:

		node<T>* f_iterator;
		node<T>* f_iterator_head;

		f_list_iterator()	//constructor
		{
			this->f_iterator = nullptr;
			this->f_iterator_head = nullptr;
		}

		f_list_iterator(const f_list_iterator& fIt)	//copy-constructor
		{
			this->f_iterator = fIt.f_iterator;
			this->f_iterator_head = fIt.f_iterator_head;
		}

		bool operator!=(f_list_iterator fIt)
		{
			if (this->f_iterator->next != fIt.f_iterator->next)
			{
				return true;
			}
			else return false;
		}

		bool operator==(f_list_iterator fIt)
		{
			if (this->f_iterator->next == fIt.f_iterator->next)
			{
				return true;
			}
			else return false;
		}

		f_list_iterator& operator++()
		{
			if (this->f_iterator->next != nullptr)
			{
				this->f_iterator = (this->f_iterator)->next;
				return *this;
			}
			else
			{
				cout << "Failed to increment iterator." << endl;
				return *this;
			}
		}

		T& operator*()
		{
			return this->f_iterator->data;
		}
		
		void operator=(f_list_iterator fIt)
		{
			this->f_iterator = fIt->f_iterator;
		}

		void operator=(node<T>* pointer)
		{
			this->f_iterator = pointer;
		}
	};

	class bid_list_iterator : public f_list_iterator
	{
	public:

		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		void operator=(const bid_list_iterator& bIt)
		{
			this->f_iterator = bIt->f_iterator;
			this->f_iterator_head = bIt->f_iterator_head;
		}

		void operator=(node<T>* pointer)
		{
			this->f_iterator = pointer;
			if (this->f_iterator_head == nullptr)
			{
				this->f_iterator_head = pointer;
			}
		}

		bid_list_iterator& operator--()
		{
			if (this->f_iterator != this->f_iterator_head)
			{
				node<T>* tmp = new node<T>;
				tmp = this->f_iterator;
				this->f_iterator = this->f_iterator_head;
				while (this->f_iterator->next != tmp)
				{
					this->f_iterator++;
				}
				return *this;
			}
			else return *this;
		}
	};

	List()
	{
		head = nullptr;
		end = nullptr;
		len = 0;
	}

	~List()
	{
		while (head != end)
		{
			node<T> *tmp = head->next;
			delete head;
			head = tmp;
		}
	}

	node<T>* get_head()
	{
		return head;
	}

	node<T>* get_end()
	{
		return end;
	}

	void append(T new_element)	//add node in the end of the list
	{
		node<T> *new_node = new node<T>;
		new_node->data = new_element;
		if (head == nullptr)
		{
			head = new_node;
			end = new_node;
		}
		else
		{
			end->next = nullptr;
			end = new_node;
		}
		len++;
	}

	void insert(T new_element, int index)	//insert node in this index
	{
		node<T> *new_node = new node<T>;
		new_node->data = new_element;
		if (index == 0)
		{
			new_node->next = head;
			head = new_node;
		}
		else
		{
			int i = 0;
			node<T> *curr = head;
			while (i < index - 1)
			{
				curr = curr->next;
				i++;
			}
			new_node->next = curr->next;
			curr->next = new_node;
		}
		len++;
	}

	void remove(int index)	//remove node in this index
	{
		int i = 0;
		node<T> *curr = head;
		while (i < index - 1)
		{
			curr = curr->next;
			i++;
		}
		node<T> *prev = curr;
		curr = curr->next;
		prev->next = curr->next;
		delete curr;
		len--;
	}

	T operator[](int index)	//read
	{
		int i = 0;
		node<T> *curr = head;
		while (i < index)
		{
			curr = curr->next;
			i++;
		}

		return curr->data;
	}
};