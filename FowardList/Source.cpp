#include <iostream>
using namespace std;
template <typename T>
class List
{
public:
	List();
	~List();
	void Push_back(T data);
	void Push_front(T data);
	int GetCount() { return count; }
	T& operator[](const int index);
	void Pop_front();
	void Pop_back();
	void insert(T value, int index);
	void RemoverAt(int index);
	int Look_for(T value);
	void Clear();

private:
	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int count;
	Node<T>* head;
};
template <typename T>
List<T>::List()
{
	count = 0;
	head = nullptr;
}
template <typename T>
List<T>::~List()
{
	Clear();
}
template<typename T>
void List<T>::Push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	count++;
}
template<typename T>
void List<T>::Push_front(T data)
{
	head = new Node<T>(data, head);
	count++;
}
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}
template<typename T>
void List<T>::Pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	count--;
}
template<typename T>
void List<T>::Pop_back()
{
	RemoverAt(count - 1);
}
template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		Push_front(value);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;
		count++;
	}
}
template<typename T>
void List<T>::RemoverAt(int index)
{
	if (index == 0)
	{
		Pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		count--;
	}
}
template<typename T>
int List<T>::Look_for(T value)
{
	Node<T>* previous = this->head;
	for (int i = 0; i < GetCount(); i++)
	{
		if (previous->data == value)
		{
			return i + 1;
		}
		previous = previous->pNext;
	}
	return 0;
}
template<typename T>
void List<T>::Clear()
{
	while (count)
	{
		Pop_front();
	}
}
int main()
{
	srand(time(NULL));
	List<int>obj;
	int getc;
	cout << "Enter the number of values: ";
	cin >> getc;
	for (int i = 0; i < getc; i++)
	{
		obj.Push_back(rand() % 10);
	}
	for (int i = 0; i < obj.GetCount(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << endl;
	obj.insert(122, 1);
	for (int i = 0; i < obj.GetCount(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << endl;
	obj.RemoverAt(1);
	for (int i = 0; i < obj.GetCount(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << endl;
	cout << "The position of the found element: " << obj.Look_for(7);
}

