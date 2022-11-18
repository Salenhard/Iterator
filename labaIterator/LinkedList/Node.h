#pragma once
template <typename T>
class Node							// шаблонный класс узла списка
{
private:
	T data;							// данные узла списка
	Node* prev;						// указатель на пред. узел
	Node* next;						// указатель на след. узел

public:
	Node()							// констр. по умолч
	{
		set_prev(nullptr);
		set_next(nullptr);
	}


	Node(const T& temp)					// констр. по умолч
	{
		set_data(temp);
		set_prev(nullptr);
		set_next(nullptr);
	}


	~Node()							// деструктор
	{
		if (next != nullptr)		// пока не дошли до последнего эллемента
		{
			delete next;			// удаляем след. эллемент
			next = nullptr;			// на всякий случай (чтобы случайно не исп. рандомную память)
			prev = nullptr;			// на всякий случай (чтобы случайно не исп. рандомную память)
		}
	}


	void set_data(const T& temp)			// устанавливаем данные (по ссылке, для экономии памяти)
	{
		data = temp;
	}


	T& get_data()					// возвращаем данные
	{
		return data;
	}


	void set_prev(Node* temp)		// устанавливаем указатель на пред. узел
	{
		prev = temp;
	}


	Node* &get_prev()				// возвращаем указатель на пред. узел
	{
		return prev;
	}


	void set_next(Node* temp)		// устанавливаем указатель на след. узел
	{
		next = temp;
	}


	Node* &get_next()					// возвращаем указатель на след узел.
	{
		return next;
	}

};