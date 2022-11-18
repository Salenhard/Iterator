#pragma once
#include "Node.h"							// шаблонный класс узла списка

template <class T>
class List2									// шаблонный класс для создания списка
{ 					// данные методы используются другими, пользователю не нужен к ним доступ, но я исп. их в LinkedList
private:
	void add_first(Node<T>*& h, T& temp)	// добавление головы списка
	{
		h = new Node<T>(temp);				// выделяем память под h = узлу списка. Заполняем поле data = temp
	}

	void add_end(Node<T>*& h, T& temp)		// добавление эллемета, усли голова уже есть
	{
		Node<T>* ptr = h;					// чтобы head не поменялся

		while (ptr->get_next() != nullptr)	// доходим до последнего эллемента списка
		{
			ptr = ptr->get_next();
		}

		Node<T>* t = new Node<T>(temp);		/*	создаём след. узел
												инициализируем указатель на шаблонный класс узла
												выделяем под него память
												в поле data записываем temp	*/
		t->set_prev(ptr);					// для нового узла предидущий - поседний
		ptr->set_next(t);					// для последнего следующий - новый
	}

public:

	void add(Node<T>* &h, T& temp)			// добавление эллемента в список
	{
		if (h == nullptr)					// если спусок пуст, то заполняем первый эллемент
		{
			add_first(h, temp);
		}
		else								// если спусок не пуст добавляем в конец
		{
			add_end(h, temp);
		}
	}


	void del(Node<T>*& h)					// очистка списка
	{
		delete h;							// вызовется деструктор Node
	}

};