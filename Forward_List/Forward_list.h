#pragma once

#include<iostream>
#include<conio.h>
using std::endl;
using std::cout;
using std::cin;

#define PRINT

template<typename T>
class Element
{
private:
	T Data;
	Element* pNext;
public:
	Element(T Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
#ifdef PRINT
		cout << "DefEConstructor >> \t" << this << endl;
#endif//PRINT

	}
	Element(Element* pNext = nullptr)
	{

#ifdef PRINT
		cout << "EConstructor >> \t" << this << endl;
#endif//PRINT

	}
	~Element()
	{

#ifdef PRINT
		cout << "EDestructor >> \t" << this << endl;
#endif//PRINT
	}

	template<typename T>
	friend class ForwardList;

};
template<typename T>
class ForwardList
{

private:
	Element<T>* Head;
	size_t SIZE = 0;

public:
	ForwardList()
	{
		this->Head = nullptr;
#ifdef PRINT
		cout << "DefLConstructor >> \t" << this << endl;
#endif//PRINT
	}
	ForwardList(size_t size)
	{
		this->Head = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			push_front(NULL);
		}
#ifdef PRINT
		cout << "LConstructor >> \t" << this << endl;
#endif//PRINT
	}
	ForwardList(size_t size, T Data)
	{
		this->Head = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			push_front(Data);
		}
#ifdef PRINT
		cout << "LConstructor >> \t" << this << endl;
#endif//PRINT
	}

	~ForwardList()
	{
		/*Element<T>* Iterator = Head;
		while (Iterator)
		{
			Head = Head->pNext;
			delete Iterator;
			Iterator = Head;
		}
		delete Iterator;
		delete Head;*/
		clear();

#ifdef PRINT
		cout << "LDestructor >> \t" << this << endl;
#endif//PRINT
	}

	void push_front(T Data = NULL)
	{
		/*Element<T>* New = new Element<T>(Data,Head); // Creat new element of list
		New->pNext = Head;	// Address first element of list save in Head
		this->Head = New;	// Affter all, head point to our new element*/
		Head = new Element<T>(Data, Head);
		this->SIZE++;
		/*
		0)
		"----"
		|Head| --> First element -->... --> N element
		"----"
					----Creat "New" element---
		1)
			 "----------"
			 |New->pNext| --> Head(First element)
			 "----------"
		2)
		"----"
		|Head| --> New --> pNext(Addres first element befor creat and push element) --> N element
		"----"
		*/
	}
	void push_back(T Data = NULL)
	{
		/*
		if (!Head)     //Nead == nullptr
		{
			push_front(Data);
			return;
		}
		Element<T>* New = new Element<T>(Data); //	1) New element = nullptr;
		Element<T>* Iterator = this->Head;      //	2)Iterstorand Head-- > first element;
		while (Iterator->pNext)
		{
			Iterator = Iterator->pNext;
		}
		//	3) Iterator in the end of list ;
		Iterator->pNext = New;     //Last element point to nullptr
		// Now we point last element(now penultimate) to new last element(New -->nullptr)
		this->SIZE++;
		*/
		insert(SIZE, Data);
	}
	void clear()
	{
		while (SIZE)
		{
			pop_front();
		}
	}
	void erase(size_t index)
	{
		if (index > SIZE || SIZE == 0)return;
		else if (index == 0)
		{
			pop_front();
			return;
		}

		Element<T>* Iterator = this->Head;
		for (size_t i = 0; i < index - 1; i++)
		{
			Iterator = Iterator->pNext;
		}

		Element<T>* To_Delete = Iterator->pNext;

		Iterator->pNext = To_Delete->pNext;

		delete To_Delete;
		SIZE--;
	}
	void insert(size_t index, T Data)
	{
		if (index > SIZE)
		{
			push_back(Data); return;
		}
		else if (this->SIZE == 0 || index == 0)
		{
			push_front(Data); return;
		}
		Element<T>* Iterator = this->Head;
		for (size_t i = 0; i < index - 1; i++)
		{
			Iterator = Iterator->pNext;
		}

		Element<T>* New = new Element<T>(Data, Iterator->pNext);

		Iterator->pNext = New;

		SIZE++;
	}

	void pop_front()
	{
		if (!Head) { return; }
		Element<T>* Iterator = this->Head;
		Head = Head->pNext;
		delete Iterator;
		SIZE--;
	}
	void pop_back()
	{
		erase(SIZE - 1);
	}
	void print()
	{
		cout << endl;
		size_t i = 0;
		for (Element<T>* Iterator = Head; Iterator; Iterator = Iterator->pNext, i++)
		{
			cout << Iterator << '\t' << Iterator->Data << "\t Index >> " << i << '\t' << Iterator->pNext << endl;
		}
		cout << endl << "Size >> " << SIZE << endl;
	}
	void set_element(size_t index, T Data)
	{
		if (SIZE == 0 || index > SIZE)return;

		Element<T>* Iterator = Head;
		for (size_t i = 0; i < index; i++)
		{
			Iterator = Iterator->pNext;
		}
		Iterator->Data = Data;
	}
	T& operator[](size_t index)
	{
		size_t i = 0;
		Element<T>* Node = Head;
		while (Node)
		{
			if (i != index)
			{
				Node = Node->pNext; i++;
			}
			else return Node->Data;
		}
	}
};

