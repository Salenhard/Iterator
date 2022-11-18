#pragma once

template<class T>
class List
{
	int size;
	
public:

	List()
	{
		this->size = 0;
	}

	int getSize() {
		return this->size;
	}

	int listEmpty() {
		return this->size == 0;
	}

	virtual int find(T& item) = 0;

	virtual void insertItem(const T& item) = 0;
	virtual void deleteItem(const T& item) = 0;
	virtual void clearList() = 0;
};

