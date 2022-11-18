#pragma once

#include "List2.h"					// класс для создания очереди
#include "Node.h"                   // шаблонный класс узла списка
#include <time.h>					// класс который я исп. для получения случайного числа
#include <iostream>					// стандартные потоки ввода / вывода

template <typename T>				/*	шаблонный класс для кработы со списками	
										т.к. класс наследуется от Node и List в нём будет весь их функционал
									*/
class LinkedList : public Node<T>, public List2<T>
{
private:
	Node<T>* head;					// указатель на головной узел

public:	
	LinkedList() {					// конст. по умолч.
		set_head(nullptr);
	}


	LinkedList(Node<T>*& h) {		// конст. с указателем на голову
		set_head(h);
	}



	void insertRear(T& temp)
	{
		if (this->head != nullptr) {
			Node<T>* tempPtr = new Node<T>(temp);
			tempPtr->set_next(this->head);
			this->head->set_prev(tempPtr);
			this->head = tempPtr;
		}

		else {
			this->head = new Node<T>(temp);
		}
	}



	void add(Node<T>*& h, T& temp)		// переопределение (запоминаем head)
	{
		if (h == nullptr)				// если спусок пуст, то заполняем первый эллемент
		{
			this->add_first(h, temp);	// добавляем в список (т.к метод protected я могу его использовать в наследнике, но немогу в объектах)
		}
		else							// если спусок не пуст добавляем в конец
		{
			this->add_end(h, temp);		// добавляем в список (т.к метод protected я могу его использовать в наследнике, но немогу в объектах)
		}

		if (this->head == nullptr)			// если голова списка не установлена
			set_head(searc_head(h));	// ищем и запоминаем первый эллемент (голова списка)
	}


	Node<T>*& get_head()				// получение указателя на голову
	{
		return head;
	}


	void set_head(Node<T>* h)			// установка указателя на голову
	{
		head = h;
	}


	void sort()										// сортировка списка по возрастанию
	{
		if (empty())								// проверка очереди на пустоту
			throw std::invalid_argument("List is empty");

		Node<T>* temp;								// указатель на текущий узел
		Node<T>* a;									// указатель на след. узел

		bool flag = true;

		while (flag)								// пока порядок эллементов списка меняется (пока не отсортирован)
		{
			temp = head;							// текущий узел
			a = temp->get_next();					// след. узел

			flag = false;

			while (a)								// пока не дошли до конца
			{
				if (temp->get_data() > a->get_data())
				{									// если надо - меняем данные в узлах местами
					swap(temp, a);					// меняем значения узлов местами
					flag = true;					// запоминаем, что изменяли порядок
				}

				temp = temp->get_next();			// переходим к след. узлам
				a = a->get_next();
			}
		}
	}


	void swap(Node<T>*& _1, Node<T>*& _2)		// престановка данных в узлах _1, _2 местами
	{
		T temp = _1->get_data();				// тут всё стандартно
		_1->set_data(_2->get_data());
		_2->set_data(temp);
	}


	Node<T>* del_ellement(Node<T>*& ptr)		// удаление ptr - узла списка
	{	
		// a / ptr / b	- фрагмент узла, для наглядности
		// нужно соеденить a и b и очистить память ptr

		Node<T>* a = ptr->get_prev();			// эллемент перед ptr
		Node<T>* b = ptr->get_next();			// эллемент после ptr

		if (a)
			a->set_next(b);
		else									// если хотим удалить головной узел
			set_head(b);						// указатель на голову переходит к след. узлу
		
		if (b)									// если удаляем любой, кроме последнего узла
			b->set_prev(a);

		return b;								// возвращаем указатель на узел, следующий за удалённым
		
		ptr->set_next(nullptr);					// отделяем удаляемый узел от списка
		ptr->set_prev(nullptr);

		delete ptr;								// очищаем память
	}


	void remove_dupl()							// удаление дубликатов
	{
		if (empty())							// проверка на пустоту списка
			throw std::invalid_argument("List is empty");

		Node<T>* ptr = get_head();
		bool b = false;							// флаг удаления узла

		while (ptr->get_next() != nullptr)		// преверка след. узла на существование
		{
			b = false;							// обнуление флага

			if (ptr->get_data() == (ptr->get_next())->get_data())
			{
				del_ellement(ptr->get_next());	// уделение узла
				b = true;						// запоминаем, что удаляли узел
			}
			if (!b)								// если удаления не было
				ptr = ptr->get_next();			// ptr переходит на след. узел, иначе остаётся на прежнем
		}

	}


	Node<int>* searc_head(Node<T>*& ptr)		// поиск головы списка ptr - указатель на любой узел списка
	{
		if (ptr == nullptr)
			throw std::invalid_argument("NULL pointer");

		Node<T>* h = ptr;						// чтобы ptr не стал указывать на голову (чтобы не менялся)

		while (h->get_prev())					// идём до первого элемента (головы списка)
		{
			h = h->get_prev();
		}

		return h;								// возвращаем указатель на голову
	}


	void add(int n)								/*	добавление n-го кол-ва узлов случайными числами
													возвращение указателя на голову списка */
	{
		int r = 0;								// случ. число

		srand(time(NULL));						// для рандома

		for (int i = 0; i < n; i++)				// n раз добавляем новый узел
		{
			r = (-25 + rand() % (50 - 0 + 1));	// рандом [-25 ; 25]
			this->add(head, r);
		}
	}


	int empty()								// проверка на пустоту списка (true, если пусто)
	{
		if (head == nullptr)
			return 1;
		else
			return 0;
	}

};