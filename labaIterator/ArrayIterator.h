/*#pragma once
#include"Iterator.h"

template<class T>
class ArrayIterator:public Iterator<T>
{	
private:
	int startIndex;
	int currentInedex;
	int finishIndex;

	Array<T>* arr;

public:
	ArrayIterator(Array<T>& arr, int start = 0, int finish = -1);
	virtual void Next();	
	virtual void Next();
	virtual T& Data();

};
*/
