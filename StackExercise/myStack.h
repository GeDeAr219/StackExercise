#ifndef H_stackType
#define H_stackType

#include <iostream>
#include<cassert>

template<class T>
class stackType
{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack()const = 0;
	virtual bool isFullStack()const = 0;
	virtual T top()const = 0;
	virtual void pop() = 0;
};
#endif

