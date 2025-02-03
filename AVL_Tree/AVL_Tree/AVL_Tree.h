#pragma once

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
struct AVL_Node
{
	AVL_Node* Parent;
	T Data;
	int iHeight;

	AVL_Node* LeftAVL_Node;
	AVL_Node* RightAVL_Node;
};


template <typename T>
class AVL_Tree
{
private :
	AVL_Node<T>* Root = nullptr;

	int GetBalanceFactor(AVL_Node<T>* _Node);
	AVL_Node<T>* Insert_Node(AVL_Node<T>* _ParentNode, T _Data);
	void Print_Tree(AVL_Node<T>* _Node);
	AVL_Node<T>* Find_Data(AVL_Node<T>* _Node, T Data);

public :
	void Init();
	void Insert_Node(T _Data);
	T Delete_Node(T _Data);

	void R_Rotation(AVL_Node<T>* _Node);
	void L_Rotation(AVL_Node<T>* _Node);
	void UpdateBF(AVL_Node<T>* _Node);

	AVL_Node<T>* FindData(T _Data);
	AVL_Node<T>* FindMinLeafNode(AVL_Node<T>* _Node);
	AVL_Node<T>* FindMaxLeafNode(AVL_Node<T>* _Node);
	void Print_Tree();
};

template<typename T>
inline int AVL_Tree<T>::GetBalanceFactor(AVL_Node<T>* _Node)
{
	int iLBF(- 1), iRBF(- 1);
	if (_Node->LeftAVL_Node != nullptr)
	{
		iLBF = _Node->LeftAVL_Node->iHeight;
	}

	if (_Node->RightAVL_Node != nullptr)
	{
		iRBF = _Node->RightAVL_Node->iHeight;
	}

	return iLBF - iRBF;
}

template<typename T>
inline AVL_Node<T>* AVL_Tree<T>::Insert_Node(AVL_Node<T>* _ParentNode,T _Data)
{
	if(nullptr != _ParentNode)
	{
		int iLeftHegiht(-1), iRightHegith(-1);
		if (_ParentNode->Data > _Data)
		{
			_ParentNode->LeftAVL_Node = Insert_Node(_ParentNode->LeftAVL_Node,_Data);
			if (_ParentNode->LeftAVL_Node != nullptr)
			{
				iLeftHegiht = _ParentNode->LeftAVL_Node->iHeight;
				_ParentNode->LeftAVL_Node->Parent = _ParentNode;
			}
		}
		else
		{
			_ParentNode->RightAVL_Node = Insert_Node(_ParentNode->RightAVL_Node,_Data);
			if (_ParentNode->RightAVL_Node != nullptr)
			{
				iRightHegith = _ParentNode->RightAVL_Node->iHeight;
				_ParentNode->RightAVL_Node->Parent = _ParentNode;
			}
		}

		_ParentNode->iHeight = max(iLeftHegiht, iRightHegith) + 1;
	}
	else
	{
		AVL_Node<T>* NewNode = new AVL_Node<T>;
		NewNode->Data = _Data;
		NewNode->iHeight = 0;
		NewNode->LeftAVL_Node = nullptr;
		NewNode->RightAVL_Node = nullptr;

		return NewNode;
	}

	return _ParentNode;
}

template<typename T>
inline void AVL_Tree<T>::Init()
{
	Root = nullptr;
}

template<typename T>
inline void AVL_Tree<T>::Insert_Node(T _Data)
{
	if (nullptr == Root)
	{
		AVL_Node<T>* NewNode = new AVL_Node<T>;
		NewNode->Data = _Data;
		NewNode->iHeight = 0;
		NewNode->Parent = nullptr;
		NewNode->LeftAVL_Node = nullptr;
		NewNode->RightAVL_Node = nullptr;

		Root = NewNode;
	}
	else
	{
		Insert_Node(Root, _Data);
		UpdateBF(Root);
	}
}

template<typename T>
inline T AVL_Tree<T>::Delete_Node(T _Data)
{
	int iReturnVal = 0;
	AVL_Node<T>* TempNode = FindData(_Data);
	AVL_Node<T>* TempLeafNode = nullptr;

	if (nullptr == TempNode)
	{
		cout << "Not Find Data" << endl;
		return T();
	}
	else
	{
		if (nullptr != TempNode->LeftAVL_Node)
		{
			TempLeafNode = FindMinLeafNode(TempNode);
			TempLeafNode->Parent->LeftAVL_Node = nullptr;
		}
		else if (nullptr != TempNode->RightAVL_Node)
		{
			TempLeafNode = FindMaxLeafNode(TempNode);
			TempLeafNode->Parent->RightAVL_Node = nullptr;
		}
		else
		{
			TempLeafNode = TempNode;
			if (TempLeafNode->Parent->LeftAVL_Node == TempNode)
			{
				TempLeafNode->Parent->LeftAVL_Node = nullptr;
			}
			else if (TempLeafNode->Parent->RightAVL_Node == TempNode)
			{
				TempLeafNode->Parent->RightAVL_Node = nullptr;
			}
		}

		if (TempLeafNode)
		{
			if (TempLeafNode != TempNode)
			{
				T TempData = TempLeafNode->Data;
				TempLeafNode->Data = TempNode->Data;
				TempNode->Data = TempData;
			}
		
			iReturnVal = TempLeafNode->Data;

			delete TempLeafNode;
		}
	}

	UpdateBF(Root);
	return iReturnVal;
}

template<typename T>
inline void AVL_Tree<T>::R_Rotation(AVL_Node<T>* _Node)
{
	if (Root == _Node)
		return;

	AVL_Node<T>* ParentNode = _Node->Parent;
	AVL_Node<T>* TempNode = _Node->LeftAVL_Node;
	if (nullptr != ParentNode)
	{
		_Node->LeftAVL_Node = ParentNode;
		_Node->Parent = ParentNode->Parent;

		ParentNode->RightAVL_Node = TempNode;
		if (TempNode != nullptr)
			TempNode->Parent = ParentNode;

		ParentNode->Parent = _Node;
		if (Root == ParentNode)
			Root = _Node;
	}
}

template<typename T>
inline void AVL_Tree<T>::L_Rotation(AVL_Node<T>* _Node)
{
	if (Root == _Node)
		return;

	AVL_Node<T>* ParentNode = _Node->Parent;
	AVL_Node<T>* TempNode = _Node->RightAVL_Node;

	if (nullptr != ParentNode)
	{
		_Node->RightAVL_Node = ParentNode;
		_Node->Parent = ParentNode->Parent;

		ParentNode->LeftAVL_Node = TempNode;
		if (TempNode != nullptr)
			TempNode->Parent = ParentNode;
		ParentNode->Parent = _Node;

		if (Root == ParentNode)
			Root = _Node;
	}
}

template<typename T>
inline void AVL_Tree<T>::UpdateBF(AVL_Node<T>* _Node)
{
	if (nullptr == _Node)
		return;
	else
	{
		if (nullptr != _Node->LeftAVL_Node)
		{
			UpdateBF(_Node->LeftAVL_Node);
		}
		if (nullptr != _Node->RightAVL_Node)
		{
			UpdateBF(_Node->RightAVL_Node);
		}
	}

	int iBF = GetBalanceFactor(_Node);
	if (-1 > iBF &&  0 >= GetBalanceFactor(_Node->RightAVL_Node))
	{
		if(_Node->RightAVL_Node != nullptr)
			R_Rotation(_Node->RightAVL_Node);
	}
	else if (1 < iBF && 0 <= GetBalanceFactor(_Node->LeftAVL_Node))
	{
		if (_Node->LeftAVL_Node != nullptr)
			L_Rotation(_Node->LeftAVL_Node);
	}
	else if (-1 > iBF && 0 < GetBalanceFactor(_Node->RightAVL_Node))
	{
		if (_Node->LeftAVL_Node != nullptr)
		{
			R_Rotation(_Node->RightAVL_Node);
			L_Rotation(_Node->RightAVL_Node);
		}
	}
	else if (1 < iBF && 0 > GetBalanceFactor(_Node->LeftAVL_Node))
	{
		if (_Node->LeftAVL_Node != nullptr)
		{
			L_Rotation(_Node->LeftAVL_Node);
			R_Rotation(_Node->LeftAVL_Node);
		}
	}
}

template<typename T>
inline AVL_Node<T>* AVL_Tree<T>::FindData(T _Data)
{
	AVL_Node<T>* TempNode = Find_Data(Root, _Data);

	if (TempNode)
	{
		return TempNode;
	}
	return nullptr;
}

template<typename T>
inline AVL_Node<T>* AVL_Tree<T>::FindMinLeafNode(AVL_Node<T>* _Node)
{
	if (nullptr == _Node)
		return nullptr;

	if (nullptr == _Node->LeftAVL_Node)
		return _Node;

	return  FindMinLeafNode(_Node->LeftAVL_Node);
}

template<typename T>
inline AVL_Node<T>* AVL_Tree<T>::FindMaxLeafNode(AVL_Node<T>* _Node)
{
	if (nullptr == _Node)
		return nullptr;

	if (nullptr == _Node->RightAVL_Node)
		return _Node;

	return  FindMaxLeafNode(_Node->RightAVL_Node);
}

template<typename T>
inline void AVL_Tree<T>::Print_Tree()
{
	Print_Tree(Root);
}

template<typename T>
inline void AVL_Tree<T>::Print_Tree(AVL_Node<T>* _Node)
{
	if (nullptr == _Node)
		return;

	cout << _Node->Data << " => ";
	
	Print_Tree(_Node->LeftAVL_Node);
	Print_Tree(_Node->RightAVL_Node);
}

template<typename T>
inline AVL_Node<T>* AVL_Tree<T>::Find_Data(AVL_Node<T>* _Node, T _Data)
{
	if (_Node == nullptr)
		return nullptr;

	AVL_Node<T>* TempNode = _Node;
	if (_Node->Data != _Data)
	{
		if (_Node->Data > _Data)
			TempNode = Find_Data(_Node->LeftAVL_Node, _Data);
		else
			TempNode = Find_Data(_Node->RightAVL_Node, _Data);
	}
	
	return TempNode;
}
