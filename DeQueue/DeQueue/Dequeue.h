#pragma once
#include <iostream>

using namespace std;

template<typename T>
struct QueueNode
{
	T Data;
	QueueNode* NextNode;
};

template<typename T>
class Dequeue
{
private :
	QueueNode<T>* Front = nullptr;
	QueueNode<T>* Rear = nullptr;
public :
	void Push_Front(T _Data);
	void Push_Back(T _Data);
	
	T Pop_Front();
	T Pop_Back();
	void Print_DeQueue();
};

template<typename T>
inline void Dequeue<T>::Push_Front(T _Data)
{
	QueueNode<T>* NewNode = new QueueNode<T>;
	NewNode->Data = _Data;

	if (nullptr == Front && nullptr == Rear)
	{
		NewNode->NextNode = nullptr;

		Front = NewNode;
		Rear = NewNode;
	}
	else
	{
		NewNode->NextNode = Front;
		Front = NewNode;
	}
}

template<typename T>
inline void Dequeue<T>::Push_Back(T _Data)
{
	QueueNode<T>* NewNode = new QueueNode<T>;
	NewNode->Data = _Data;

	if (nullptr == Front && nullptr == Rear)
	{
		NewNode->NextNode = nullptr;

		Front = NewNode;
		Rear = NewNode;
	}
	else
	{
		NewNode->NextNode = nullptr;
		Rear->NextNode = NewNode;
		Rear = NewNode;
	}
}

template<typename T>
inline T Dequeue<T>::Pop_Front()
{
	int iReturnData = -1;
	if (nullptr == Front)
	{
		return T();
	}
	else
	{
		QueueNode<T>* NewNode = Front;
		iReturnData = NewNode->Data;
		Front = NewNode->NextNode;

		delete NewNode;
		return iReturnData;
	}
}

template<typename T>
inline T Dequeue<T>::Pop_Back()
{
	int iReturnData = -1;
	if (nullptr == Rear)
	{
		return T();
	}
	else
	{
		QueueNode<T>* ParentNewNode = Front;
		while (Rear != ParentNewNode->NextNode)
		{
			ParentNewNode = ParentNewNode->NextNode;
		}

		QueueNode<T>* NewNode = Rear;
		iReturnData = NewNode->Data;
		ParentNewNode->NextNode = nullptr;
		Rear = ParentNewNode;

		delete NewNode;
		return iReturnData;
	}
}

template<typename T>
inline void Dequeue<T>::Print_DeQueue()
{
	QueueNode<T>* TempNode = Front;
	while (nullptr != TempNode)
	{
		cout << TempNode->Data << "=>";
		TempNode = TempNode->NextNode;
	}
	cout << endl;
}
