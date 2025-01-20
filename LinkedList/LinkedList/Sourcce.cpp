#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"
#include "CircleLinkedList.h"

using namespace std;

int main()
{
#pragma region LinkedList
	/*SinglyLinkedList<int> LinkedList;

	LinkedList.Insert_FirstNode(100);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_FirstNode(200);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_LastNode(300);
	LinkedList.Print_LinkedList();

	LinkedList.Delete_FirstNode();
	LinkedList.Print_LinkedList();

	LinkedList.Delete_LastNode();
	LinkedList.Print_LinkedList();*/
#pragma endregion

#pragma region DoubleLinkedList
	//DoubleLinkedList<int> DoubleLinkedList;
	//DoubleLinkedList.Insert_FirstNode(100);
	//DoubleLinkedList.Print_DoubleLinkedList();

	//DoubleLinkedList.Insert_FirstNode(200);
	//DoubleLinkedList.Print_DoubleLinkedList();

	//DoubleLinkedList.Insert_LastNode(300);
	//DoubleLinkedList.Print_DoubleLinkedList();

	//DoubleLinkedList.Delete_FirstNode();
	//DoubleLinkedList.Print_DoubleLinkedList();

	//DoubleLinkedList.Delete_LastNode();
	//DoubleLinkedList.Print_DoubleLinkedList();
#pragma endregion

#pragma region CirCleLinkedList
	CircleLinkedList<int> LinkedList;
	LinkedList.Insert_FirstNode(100);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_FirstNode(200);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_FirstNode(300);
	LinkedList.Print_LinkedList();

	LinkedList.Delete_FirstNode();
	LinkedList.Print_LinkedList();

	LinkedList.Delete_LastNode();
	LinkedList.Print_LinkedList();
#pragma endregion

	return 0;
}