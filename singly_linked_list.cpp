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
	List()
	{
		head = nullptr;
		len = 0;
	}
	void append(T new_element)
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
			end->next = new_node;
			end = new_node;
		}
		len++;
	}
	T operator[](int N)
	{
		int i = 0;
		node<T> *temp = head;
		while (i < N)
		{
			temp = temp->next;
			i++;
		}
		return temp->data;
	}
};