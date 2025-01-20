#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T Data;
	Node* NextNode;
};

template <typename T>
class SinglyLinkedList
{
private: 
	Node<T>* Head = nullptr;

public :
	SinglyLinkedList();

	void Insert_FirstNode(T Data);
	void Insert_LastNode(T Data);
	void Delete_FirstNode();
	void Delete_LastNode();



	void Print_LinkedList();
};

template<typename T>
inline SinglyLinkedList<T>::SinglyLinkedList()
{
	
}

template<typename T>
inline void SinglyLinkedList<T>::Insert_FirstNode(T Data)
{
	Node<T>* NewNode = new Node<T>;
	NewNode->Data = Data;
	NewNode->NextNode = Head;
	Head = NewNode;
}

template<typename T>
inline void SinglyLinkedList<T>::Insert_LastNode(T Data)
{
	Node<T>* i = Head;
	while (nullptr != i)
	{
		if (nullptr == i->NextNode)
		{
			Node<T>* NewNode = new Node<T>;
			NewNode->Data = Data;
			NewNode->NextNode = nullptr;
			i->NextNode = NewNode;
			break;
		}

		i = i->NextNode;
	}
}

template<typename T>
inline void SinglyLinkedList<T>::Delete_FirstNode()
{
	if (Head != nullptr)
	{
		Node<T>* tempNode = Head;
		Head = tempNode->NextNode;

		delete tempNode;
	}
}

template<typename T>
inline void SinglyLinkedList<T>::Delete_LastNode()
{
	Node<T>* i = Head;
	while (nullptr != i)
	{
		if (nullptr == i->NextNode->NextNode)
		{
			Node<T>* NewNode = i->NextNode;
			delete i->NextNode->NextNode;
			i->NextNode = nullptr;
			break;
		}

		i = i->NextNode;
	}
}

template<typename T>
inline void SinglyLinkedList<T>::Print_LinkedList()
{
	Node<T>* i = Head;
	while (nullptr != i)
	{
		cout << i->Data << "=>";
		i = i->NextNode;
	}
	cout << endl;
}