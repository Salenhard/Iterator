#pragma once

template<class T>
class Iterator
{	
protected:
	int iterationComplete;
public:
	Iterator() : iterationComplete{ 0 }
	{}
	virtual void next() = 0;
	virtual void reset() = 0;
	virtual T& data() = 0;
	virtual int endOfList() const {
		return iterationComplete;
	}
};

