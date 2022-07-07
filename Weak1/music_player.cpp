#include <iostream>

template<typename T>
struct cir_list_node
{
	T *data;
	cir_list_node* next;
	cir_list_node* prev;

	~cir_list_node()
	{
		delete data;
	}
};

template <typename T>
struct cir_list
{
	public :
		using node = cir_list_node<T>;
		using node_ptr = node*;

		cir_list() : n(0)
		{
			head = new node{NULL, NULL, NULL};
			head->next = head;
			head->prev = head;
		}

		size_t size() const
		{
			return n;
		}

		void insert(const T& value)
		{
			node_ptr newNode = new node {new T(value, NULL, NULL)};
			n++;
			auto tmp = head->prev;
			tmp->next = newNode;
			newNode->prev = tmp;
		}

	private :
		node_ptr head;
		size_t n;
};