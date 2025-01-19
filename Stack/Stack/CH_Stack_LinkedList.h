#pragma once

template<typename T>
struct Node
{
public :
	T Data;
	Node* NextNode;
};

template<typename T>
class CH_Stack_LinkedList
{
private :
	Node<T>* StackStorage = nullptr;
	int StackStorageSize = 0;
public :
	void Init();
	void Push(T data);
	T Pop();
	void print_stack();

};

template<typename T>
inline void CH_Stack_LinkedList<T>::Init()
{
}

template<typename T>
inline void CH_Stack_LinkedList<T>::Push(T data)
{
	Node<T>* NewDataNode = new Node<T>;
	NewDataNode->Data = data;
	NewDataNode->NextNode = StackStorage;
	StackStorage = NewDataNode;
}

template<typename T>
inline T CH_Stack_LinkedList<T>::Pop()
{
	if (nullptr == StackStorage)
	{
		return T();
	}
	else
	{
		Node<T>* Temp = StackStorage;
		T ReturnData = Temp->Data;
		StackStorage = StackStorage->NextNode;
		delete Temp;

		return ReturnData;
	}
}

template<typename T>
inline void CH_Stack_LinkedList<T>::print_stack()
{
	for (Node<T>* p = StackStorage; p != NULL; p = p->NextNode)
		printf("%d-> ", p->Data);

	printf("NULL \n");
}