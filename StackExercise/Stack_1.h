#ifndef H_Stack_1
#define H_Stack_1
#include<iostream>
#include<cassert>
#include "myStack.h"
using namespace std;

template <class T>
class Stack_1: public stackType<T> 
{
public:
	const Stack_1<T>& operator=(const Stack_1<T>&);
	void initializeStack();
	bool isEmptyStack()const;
	bool isFullStack()const;
	void push(const T& newItem);
	T top() const;
	void pop();
	bool operator==(const Stack_1<T>& otherStack)const;
	Stack_1(int stackSiz = 100);
	Stack_1(const Stack_1<T>& otherStack);
	~Stack_1();
private:
	int maxStackSize;
	int stackTop;
	T* list;
	void copyStack(const Stack_1<T>& otherStack);

};

template<class T>
void Stack_1<T>::initializeStack() {
	stackTop = 0;
}
template<class T>
bool Stack_1<T>::isEmptyStack() const {
	return (stackTop == 0);
}
template<class T>
bool Stack_1<T>::isFullStack() const {
	return(stackTop == maxStackSize);
}
template<class T>
void Stack_1<T>::push(const T& newItem) {
	if (!isFullStack()) {
		list[stackTop] = newItem;
		stackTop++;
	}
	else {
		cout << "can not add to full stack." << endl;
	}
}
template<class T>
 T Stack_1<T>::top() const {
	 assert(stackTop != 0);
	 return list[stackTop - 1];
}
 template<class T>
 void Stack_1<T>::pop() {
	 if (!isEmptyStack())
		 stackTop--;
	 else
		 cout << "Cannot remove from an empty stack." << endl;
 }
 template<class T>
 Stack_1<T>::Stack_1(int Stacksize) {
	 if (Stacksize <= 0) {
		 cout << "Size of the array to hold the stack must "
			 << "be positive." << endl;
		 cout << "Creating an array of size 100." << endl;
		 maxStackSize = 100;
	 }
	 else
		 maxStackSize = Stacksize;
	 stackTop = 0;
	 list = new T[maxStackSize];
 }
 template <class T>
 Stack_1<T>::~Stack_1() {
	 delete[] list;
 }
 template<class T>
 void Stack_1<T>::copyStack(const Stack_1<T>& otherStack) {
	 delete[]list;
	 maxStackSize = otherStack.maxStackSize;
	 stackTop = otherStack.stackTop;
	 list = new T[maxStackSize];
	 for (int i = 0; i < stackTop; i++)
	 {
		 list[i] = otherStack.list[i];
	 }
 }
 template <class T>
 Stack_1<T>::Stack_1(const Stack_1<T>& otherStack) {
	 list = NULL;
	 copyStack(otherStack);
 }
 template<class T>
 const Stack_1<T>& Stack_1<T>:: operator=(const Stack_1<T>&otherStack) {
	 if (this != &otherStack)
		 copyStack(otherStack);
	 return *this;
 }
 template<class T>
 bool Stack_1<T>::operator==(const Stack_1<T>& otherStack) const {
	 if (this == &otherStack)
		 return true;
	 else if (maxStackSize != otherStack.maxStackSize || stackTop != otherStack.stackTop)
		 return false;
	 else {
		 for (int i = 0; i < stackTop; i++)
		 {
			 if (list[i] != otherStack.list[i])
				 return false;
			 return true;
		 }
	 }
 }

#endif 

 