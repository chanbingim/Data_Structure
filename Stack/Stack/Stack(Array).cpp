#include <iostream>
#include "CH_Stack.h"
#include "CH_Stack_LinkedList.h"

using namespace std;

int main()
{
	CH_Stack_LinkedList<int> stack;
	stack.Init();

	stack.Push(100);
	stack.print_stack();

	stack.Push(200);
	stack.print_stack();

	stack.Push(300);
	stack.print_stack();

	stack.Push(400);
	stack.print_stack();

	stack.Pop();
	stack.print_stack();

	stack.Pop();
	stack.print_stack();



	/*CH_Stack<int> Stack(5);
	Stack.Push(20);
	Stack.Push(100);
	Stack.Push(200);
	Stack.Push(300);

	cout << Stack.GetStackSzie() << endl;
	cout << Stack.Pop() << endl;

	cout << "===========================" << endl;
	cout << Stack.GetStackSzie() << endl;
	cout << Stack.Pop() << endl;

	cout << "===========================" << endl;
	cout << Stack.GetStackSzie() << endl;
	cout << Stack.Pop() << endl;

	cout << "===========================" << endl;
	cout << Stack.GetStackSzie() << endl;
	cout << Stack.Pop() << endl;

	cout << "===========================" << endl;
	cout << Stack.GetStackSzie() << endl;
	cout << Stack.Pop() << endl;*/

	return 0;
}