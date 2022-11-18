#pragma once
#include"List.h"
#include"LinkedList/LinkedList.h"

template<class T>
class SeqListIterator;

template<class T>
class SeqList{

protected:
	int size;
	LinkedList<T> llist;

public:

	SeqList() {
		llist = LinkedList<T>();
		size = 0;
	}

	int find(const T& item) {
		Node<T>* temp = llist.get_head();

		if (temp == nullptr)   //���� ������ ������
			return 0;
		if (temp->get_data() == item) // ���� ������ �������� ������ ��������
			return 1;
		else {
			while (temp->get_next() != nullptr) {
				temp = temp->get_next();
				if (temp->get_data() == item)
					return 1;
			}
			return 0;
		}
	}

	T getData(const int& pos) {
		if (pos > this->size)
			return;
		else {
			Node<T> tempPtr = llist.get_head();
			for (int i = 0; i <= pos; i++);
			tempPtr = tempPtr->get_next();
			return tempPtr->get_data();
		}
	}

	void insertItem(T& item) {
		llist.insertRear(item);
		this->size++;
	}

	void deleteItem(const T& item) {
		// a / ptr / b	- �������� ����, ��� �����������
		// ����� ��������� a � b � �������� ������ ptr
		Node<T>* ptr;
		while (ptr->get_data() != item) {
			if (ptr->get_next != nullptr)
				ptr->get_next();
			else {
				std::cerr << "Error: item is not found!";
				exit(1);
			}
		}

		Node<T>* a = ptr->get_prev();			// �������� ����� ptr
		Node<T>* b = ptr->get_next();			// �������� ����� ptr

		if (a)
			a->set_next(b);
		else									// ���� ����� ������� �������� ����
			llist.set_head(b);						// ��������� �� ������ ��������� � ����. ����

		if (b)									// ���� ������� �����, ����� ���������� ����
			b->set_prev(a);

		return b;								// ���������� ��������� �� ����, ��������� �� ��������

		ptr->set_next(nullptr);					// �������� ��������� ���� �� ������
		ptr->set_prev(nullptr);

		delete ptr;								// ������� ������
		this->size--;
	}

	void clearList() {
		Node<T>* temp = llist.get_head();
		while (!llist.empty()) {
			if (temp->get_next()->get_next() != nullptr) {
				temp = temp->get_next();
			}
			else {
				llist.del_ellement(temp->get_next());
				temp = temp->get_prev();
			}
			if (temp == llist.get_head()) {
				llist.del_ellement(temp);
			}
		}
		this->size = 0;
	}

	T deleteFront() {
		Node<T>* tempPtr = llist.get_head();
		T temp;
		llist.set_head() = tempPtr->get_next();
		temp = tempPtr->get_data();
		delete tempPtr;
		this->size--;
		return temp;
	}

	friend class SeqListIterator<T>;
};

