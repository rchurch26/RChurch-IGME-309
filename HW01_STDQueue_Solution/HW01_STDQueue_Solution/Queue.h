#pragma once
#include <iostream>
#include <typeinfo>

template <class Placeholder>
struct Queue
{
	//Rule of Three
	//Constructor
	Queue()
	{
		std::cout << "Queue Constructor Called" << std::endl;
		arr = new Placeholder[1];
		arrSize = 1;
		queueSize = 0;
	}
	//Copy Constructor
	Queue(const Queue& other)
	{
		std::cout << "Copy Constructor Called" << std::endl;
		arrSize = other.arrSize;
		queueSize = other.queueSize;
		arr = new Placeholder[arrSize];
		std::copy(other.arr, other.arr + other.arrSize, arr);
	}
	//Copy Assignment Operator
	Queue& operator = (const Queue& other)
	{
		std::cout << "Copy Assignment Operator Called" << std::endl;
		if (this == &other)
		{
			return *this;
		}
		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
			arrSize = 0;
			queueSize = 0;
		}
		arrSize = other.arrSize;
		queueSize = other.queueSize;
		arr = new Placeholder[arrSize];
		std::copy(other.arr, other.arr + other.arrSize, arr);
		return *this;
	}
	//Destructor
	~Queue()
	{
		delete[] arr;
		arr = nullptr;
		arrSize = 0;
		queueSize = 0;
	}

	//Methods
	//Push Method
	void Push(Placeholder info)
	{

	}
	//Pop Method
	void Pop()
	{
		if (queueSize <= 0)
		{
			return NULL;
		}
		queueSize--;
	}
	//Print Method
	void Print()
	{
		for (int i = 0; i < queueSize - 1; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << arr[queueSize - 1] << std::endl;
	}
	//GetSize Method
	int GetSize()
	{
		return queueSize;
	}
	//IsEmpty Method
	bool IsEmpty()
	{
		if (queueSize = 0)
		{
			return true;
		}
		return false;
	}
private:
	//Variables
	Placeholder* arr;
	int arrSize;
	int queueSize;
};