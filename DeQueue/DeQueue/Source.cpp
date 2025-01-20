#include "Dequeue.h"

int main()
{
	Dequeue<int> Dequeue;
	Dequeue.Push_Front(100);
	Dequeue.Print_DeQueue();
	Dequeue.Push_Front(200);
	Dequeue.Print_DeQueue();
	Dequeue.Push_Front(300);
	Dequeue.Print_DeQueue();

	Dequeue.Push_Back(400);
	Dequeue.Print_DeQueue();
	Dequeue.Push_Back(500);
	Dequeue.Print_DeQueue();
	Dequeue.Push_Back(600);
	Dequeue.Print_DeQueue();

	cout << Dequeue.Pop_Front() << endl;
	cout << Dequeue.Pop_Front() << endl;

	cout << Dequeue.Pop_Back() << endl;
	cout << Dequeue.Pop_Back() << endl;
	return 0;
}