#include <iostream>
#include "stack.h"

int main()
{
	stack<int> NewStack;
	cout << "Is stack empty? : " << NewStack.empty() << endl;
	NewStack.push(0);
	NewStack.push(1);
	cout << "Is stack empty? : " << NewStack.empty() << endl;
	cout << "Stack size:" << NewStack.size() << endl;
	cout << "Stack top element:" << NewStack.top() << endl;
	NewStack.pop();
	cout << "Stack top element:" << NewStack.top() << endl;
	NewStack.pop();
	system("pause");
	return 0;
}