#ifndef H_LinkStack
#define H_LinkStack
#include <iostream>
#include<cassert>
#include "myStack.h"
using namespace std;

template <class T>
struct nodeType{
	T info;
	nodeType<T>* link;
};
template <class T>
class LinkStack : public stackType <T> {
public:
	const LinkStack<T>& operator=(const LinkStack<T>&);
	bool isEmptyStack()const;
	bool isFullStack() const;
	void initializeStack();
	void push(const T& newItem);
	T top() const;
	void pop();
	bool operator==(const LinkStack<T>& otherStack)const;
	LinkStack();
	LinkStack(const LinkStack<T>& otherStack);
	~LinkStack();
private:
	nodeType<T>* stackTop;
	void copyStack(const LinkStack<T>& otherStack);
};
template<class T>
LinkStack<T>::LinkStack() {
	stackTop = NULL;
}
template <class T>
bool LinkStack<T>::isEmptyStack()const {
	return(stackTop == NULL);
}
template<class T>
bool LinkStack<T>::isFullStack() const {
	return false;
}
template <class T>
void LinkStack<T>::initializeStack() {
	nodeType<T> *temp;
	while (stackTop != NULL) {
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
}
template <class T>
void LinkStack<T>::push(const T& newElement) {
	nodeType<T> *newNode;
	newNode = new nodeType<T>;
	newNode->info = newElement;
	newNode->link = stackTop;
	stackTop = newNode;
}
template <class T>
T LinkStack<T>::top() const {
	assert(stackTop != NULL);

	return stackTop->info;
}
template<class T>
void LinkStack<T>::pop() {
	nodeType<T>* temp;
	if (stackTop != NULL) {
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
	else
		cout << "cannot reove from an empty stack" << endl;
}
template<class T>
void LinkStack<T>::copyStack(const LinkStack<T>& otherStack) {
	nodeType<T>* newNode, * current, * last;
	if (stackTop != NULL)
		initializeStack();
	if (otherStack.stackTop == NULL)
		stackTop = NULL;
	else
	{
		current = otherStack.stackTop;
		stackTop = new nodeType<T>;
		stackTop->info = current->info;
		stackTop->link = NULL;
		last = stackTop;
		current = current->link;
		while (current != NULL) {
			newNode = new nodeType<T>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}
template<class T>
LinkStack<T>::LinkStack(const LinkStack<T>& otherSTACK) {
	stackTop = NULL;
	copyStack(otherSTACK);
}
template<class T>
LinkStack<T>::~LinkStack() {
	initializeStack();
}
template<class T>
const LinkStack<T>& LinkStack<T>:: operator=(const LinkStack<T>& otherStack) {
	if (this != &otherStack)
		copyStack(otherStack);
	return *this;
}
template<class T>
bool LinkStack<T>:: operator ==(const LinkStack<T>& otherStack)const {
	nodeType<T>* current1 = stackTop;
	nodeType<T>* current2 = otherStack.stackTop;
	if (this == &otherStack)
		return true;
	else
	{
		while (current1 != NULL && current2 != NULL) {
			if (current1->info != current2->info)
				return false;
			current1 = current1->link;
			current2 = current2->link;
		}
		if (current1 != NULL || current2 != NULL)
			return false;
		return true;
	}
}
#endif

