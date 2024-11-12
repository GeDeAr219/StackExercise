// StackExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Stack_1.h"
#include"LinkStack.h"
using namespace std;

int main()
{
	cout << "///////////////////STACK/////////////////////////////" << endl;
    int x;
    Stack_1<int> stack1(50);
    Stack_1<int> stack2(50);
    Stack_1<int> stack(100);
    stack1.initializeStack();
    stack1.push(23);
    stack1.push(45);
    stack1.push(38);
	stack2 = stack1;

	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	x = stack2.top();
	stack2.pop();
	stack2.push(23);

	cout << "**** After pop and push operations on stack2 ****"
		<< endl;
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	stack2.push(11);

	cout << "**** After another push operation on stack2 ****" << endl;
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	cout << "///////////////////LINKED-STACK/////////////////////////////" << endl;

	LinkStack<int> stack4;
	LinkStack<int> stack5;
	LinkStack<int> stack6;
	int y;

	stack4.push(23);
	stack4.push(45);
	stack4.push(38);

	stack5 = stack4;

	if (stack4 == stack5)
		cout << "stack4 and stack5 are identical" << endl;
	else
		cout << "stack4 and stack5 are not identical" << endl;

	y = stack5.top();
	stack5.pop();
	stack5.push(32);

	cout << "**** After pop and push operation on stack5 ****" << endl;
	if (stack4 == stack5)
		cout << "stack4 and stack5 are identical" << endl;
	else
		cout << "stack4 and stack5 are not identical" << endl;

	stack5.push(11);

	cout << "**** After another push operation on stack5****" << endl;
	if (stack4 == stack5)
		cout << "stack4 and stack5 are identical" << endl;
	else
		cout << "stack4 and stack5 are not identical" << endl;

	return 0;
}


