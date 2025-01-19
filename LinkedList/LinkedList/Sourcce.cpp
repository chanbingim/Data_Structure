#include <iostream>
#include "SinglyLinkedList.h"
#include "CircleLinkedList.h"

using namespace std;

int main()
{
	/*CircleLinkedList<int> LinkedList;
	LinkedList.Insert_FirstNode(100);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_FirstNode(200);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_FirstNode(300);
	LinkedList.Print_LinkedList();

	LinkedList.Delete_FirstNode();
	LinkedList.Print_LinkedList();

	LinkedList.Delete_LastNode();
	LinkedList.Print_LinkedList();*/

	SinglyLinkedList<int> LinkedList;

	LinkedList.Insert_LastNode(400);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_FirstNode(100);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_FirstNode(200);
	LinkedList.Print_LinkedList();

	LinkedList.Insert_LastNode(300);
	LinkedList.Print_LinkedList();

	LinkedList.Delete_FirstNode();
	LinkedList.Print_LinkedList();

	LinkedList.Delete_LastNode();
	LinkedList.Print_LinkedList();
	return 0;
}