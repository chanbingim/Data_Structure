#pragma once

template <typename T>
class CH_Stack
{
private :
	T* StackStorage = nullptr;
	int StackStorageIndex = 0;
	int StackStorageSize = 0;
public:
	CH_Stack();
	CH_Stack(int _StackSize = 10);

	void Push(T data);

	T Pop();

	bool IsEmpty();
	int GetStackSzie();
	int GetIndexNumber();
};

template<typename T>
inline CH_Stack<T>::CH_Stack()
{

}

template<typename T>
inline CH_Stack<T>::CH_Stack(int _StackSize)
{
	StackStorage = new T[_StackSize];
	StackStorageSize = _StackSize;
}

template<typename T>
inline void CH_Stack<T>::Push(T data)
{
	if (nullptr == StackStorage)
	{
		return;
	}
		
	StackStorage[StackStorageIndex] = data;
	++StackStorageIndex;
}

template<typename T>
inline T CH_Stack<T>::Pop()
{
	if (StackStorageIndex <= 0)
	{
		return T(-987654321);
	}

	T Temp = StackStorage[StackStorageIndex - 1];
	--StackStorageIndex;

	return Temp;
}

template<typename T>
inline bool CH_Stack<T>::IsEmpty()
{
	if (StackStorage)
		return true;

	return false;
}

template<typename T>
inline int CH_Stack<T>::GetStackSzie()
{
	return StackStorageSize;
}

template<typename T>
inline int CH_Stack<T>::GetIndexNumber()
{
	return StackStorageIndex;
}
