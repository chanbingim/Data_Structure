#include "Queue.h"

int main()
{
	LinearQueue<int> Queue;
	Queue.Insert_Node(100);
	Queue.Print_LinkedList();

	Queue.Insert_Node(200);
	Queue.Print_LinkedList();

	Queue.Insert_Node(300);
	Queue.Print_LinkedList();

	Queue.Insert_Node(400);
	Queue.Print_LinkedList();

	Queue.Delete_Node();
	Queue.Print_LinkedList();

	Queue.Delete_Node();
	Queue.Print_LinkedList();

	Queue.Delete_Node();
	Queue.Print_LinkedList();
	return 0;
}