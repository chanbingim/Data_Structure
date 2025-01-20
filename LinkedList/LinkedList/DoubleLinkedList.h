#pragma once
#include <iostream>

template<typename T>
struct DoubleListNode
{
	DoubleListNode* Parent;
	T Data;
	DoubleListNode* Child;
};

template<typename T>
class DoubleLinkedList
{
private :
	DoubleListNode<T>* Head = nullptr;
	DoubleListNode<T>* Tail = nullptr;
public :
	DoubleLinkedList();
	void Insert_FirstNode(T _Data);
	void Insert_LastNode(T _Data);
	void Delete_FirstNode();
	void Delete_LastNode();

	void Print_DoubleLinkedList();
};

template<typename T>
inline DoubleLinkedList<T>::DoubleLinkedList()
{
}

template<typename T>
inline void DoubleLinkedList<T>::Insert_FirstNode(T _Data)
{
	DoubleListNode<T>* NewNode = new DoubleListNode<T>;
	NewNode->Parent = nullptr;
	NewNode->Child = Head;
	NewNode->Data = _Data;
	
	if (nullptr != Head)
	{
		Head->Parent = NewNode;
	}
	else
	{
		Tail = NewNode;
	}

	Head = NewNode;
}

template<typename T>
inline void DoubleLinkedList<T>::Insert_LastNode(T _Data)
{
	DoubleListNode<T>* NewNode = new DoubleListNode<T>;
	NewNode->Parent = Tail;
	NewNode->Child = nullptr;
	NewNode->Data = _Data;

	if (nullptr != Tail)
	{
		Tail->Child = NewNode;
	}
	else
	{
		Head = NewNode;
	}

	Tail = NewNode;
}

template<typename T>
inline void DoubleLinkedList<T>::Delete_FirstNode()
{
	if (nullptr == Head)
		return;
	else
	{
		DoubleListNode<T>* TempNode = Head;
		TempNode->Child->Parent = nullptr;
		Head = TempNode->Child;
		delete TempNode;
	}
}

template<typename T>
inline void DoubleLinkedList<T>::Delete_LastNode()
{
	if (nullptr == Tail)
		return;
	else
	{
		DoubleListNode<T>* TempNode = Tail;
		TempNode->Parent->Child = nullptr;
		Tail = TempNode->Child;
		delete TempNode;
	}
}

template<typename T>
inline void DoubleLinkedList<T>::Print_DoubleLinkedList()
{
	DoubleListNode<T>* temp = Head;
	while (temp != nullptr)
	{
		cout << temp->Data << "=>";

		temp = temp->Child;
	}
	cout << endl;
}