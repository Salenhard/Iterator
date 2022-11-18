#pragma once
#include <iostream>
#include "SeqList.h"
#include "Iterator.h"
#include "LinkedList/Node.h"
template <class T>
class SeqListIterator: public Iterator<T> {
	SeqList<T>* listPtr;
	Node<T>* prevPtr, *currPtr;

public:

	SeqListIterator(SeqList<T>& lst) {
		this->setList(lst);
	}

	virtual void next(){
		if (currPtr == nullptr)
			return;
		this->prevPtr = this->currPtr;
		this->currPtr = this->currPtr->get_next();
		if (this->currPtr == nullptr)
			this->iterationComplete = 1;
	}

	virtual void reset() {
		this->iterationComplete = this->listPtr->llist.empty();
		if (this->listPtr->llist.get_head() == nullptr)
			return;
		this->prevPtr = nullptr;
		this->currPtr = this->listPtr->llist.get_head();
	}

	virtual T& data() {
		if ((this->listPtr->llist.empty()) || (this->currPtr == nullptr))
		{
			std::cerr << "Error: недопустимая ссылка!";
			exit(1);
		}
		return this->currPtr->get_data();
	}

	void setList(SeqList<T> &lst) {
		this->listPtr = &lst;
		reset();
	}
};

