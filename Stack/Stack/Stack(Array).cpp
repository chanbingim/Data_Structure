#include <iostream>
#include "CH_Stack.h"

using namespace std;

int main()
{
	CH_Stack<int> Stack(5);
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
	cout << Stack.Pop() << endl;

	return 0;
}