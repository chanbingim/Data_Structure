#pragma once
#include <iostream>
using namespace std;

#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct QueueNode
{
	T Data;
	QueueNode* NextNode;
};

template <typename T>
class LinearQueue
{
private:
	QueueNode<T>* Head = nullptr;
	QueueNode<T>* Tail = nullptr;
public:
	LinearQueue();

	void Insert_Node(T Data);
	void Delete_Node();

	void Print_LinkedList();
};

template<typename T>
inline LinearQueue<T>::LinearQueue()
{

}

template<typename T>
inline void LinearQueue<T>::Insert_Node(T Data)
{
	if (nullptr == Head && nullptr == Tail)
	{
		QueueNode<T>* NewNode = new QueueNode<T>;
		NewNode->Data = Data;
		NewNode->NextNode = nullptr;

		Head = NewNode;
		Tail = NewNode;
	}
	else
	{
		QueueNode<T>* NewNode = new QueueNode<T>;
		Tail->NextNode = NewNode;
		NewNode->Data = Data;
		NewNode->NextNode = nullptr;
		Tail = NewNode;
	}
}

template<typename T>
inline void LinearQueue<T>::Delete_Node()
{
	if (nullptr == Head)
	{
		return;
	}
	else
	{
		QueueNode<T>* NewNode = Head;
		if (nullptr == NewNode->NextNode)
		{
			Tail = nullptr;
			Head = nullptr;
		}
		else
			Head = NewNode->NextNode;

		delete NewNode;
	}
}

template<typename T>
inline void LinearQueue<T>::Print_LinkedList()
{
	QueueNode<T>* i = Head;
	while (nullptr != i)
	{
		cout << i->Data << "=>";
		if (i->NextNode == Head)
			break;

		i = i->NextNode;
	}
	cout << endl;
}