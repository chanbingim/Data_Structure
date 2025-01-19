#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct CircleListNode
{
	T Data;
	CircleListNode* NextNode;
};

template <typename T>
class CircleLinkedList
{
private:
	CircleListNode<T>* Head = nullptr;
	CircleListNode<T>* Tail = nullptr;
public:
	CircleLinkedList();

	void Insert_FirstNode(T Data);
	void Insert_LastNode(T Data);
	void Delete_FirstNode();
	void Delete_LastNode();

	void Print_LinkedList();
};

template<typename T>
inline CircleLinkedList<T>::CircleLinkedList()
{

}

template<typename T>
inline void CircleLinkedList<T>::Insert_FirstNode(T Data)
{
	CircleListNode<T>* NewNode = new CircleListNode<T>;
	NewNode->Data = Data;

	if (nullptr == Head)
	{
		NewNode->NextNode = NewNode;
		Head = NewNode;
		Tail = NewNode;
	}
	else
	{
		NewNode->NextNode = Head;
		Tail->NextNode = NewNode;
		Head = NewNode;
		
	}
}

template<typename T>
inline void CircleLinkedList<T>::Insert_LastNode(T Data)
{
	CircleListNode<T>* i = Head;
	CircleListNode<T>* NewNode = new CircleListNode<T>;
	NewNode->Data = Data;

	if (nullptr == Head)
	{
		NewNode->NextNode = NewNode;
		Head = NewNode;
		Tail = NewNode;
		return;
	}

	while (nullptr != i)
	{
		if (nullptr == i->NextNode)
		{
			NewNode->NextNode = Head;
			Tail = Head->NextNode;
			Head->NextNode = NewNode;
			break;
		}

		i = i->NextNode;
	}
}

template<typename T>
inline void CircleLinkedList<T>::Delete_FirstNode()
{
	if (Head != nullptr)
	{
		CircleListNode<T>* tempNode = Head;
		Head = tempNode->NextNode;
		Tail->NextNode = Head;

		delete tempNode;
	}
}

template<typename T>
inline void CircleLinkedList<T>::Delete_LastNode()
{
	CircleListNode<T>* i = Head;
	while (nullptr != i)
	{
		if (Head == i->NextNode->NextNode)
		{
			delete i->NextNode;
			i->NextNode = Head;
			Tail = i;
			break;
		}

		i = i->NextNode;
	}
}

template<typename T>
inline void CircleLinkedList<T>::Print_LinkedList()
{
	CircleListNode<T>* i = Head;
	while (nullptr != i)
	{
		cout << i->Data << "=>";
		if (i->NextNode == Head)
			break;

		i = i->NextNode;
	}
	cout << endl;
}