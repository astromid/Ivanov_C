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

	void append(T new_element)	//���������� ��-�� � ����� ������
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

	void insert(T new_element, int index)	//������� ��-�� � ��������� �������
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

	void remove(int index)	//�������� ��-�� � ��������� �������
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

	T operator[](int index)	//������
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