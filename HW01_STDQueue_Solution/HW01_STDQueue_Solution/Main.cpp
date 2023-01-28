#include "Main.h"

int main()
{
	//Test Queue with Integers
	//Create Example Queue
	Queue<int> exQueue;
	//Push Items
	exQueue.Push(26);
	cout << "Pushed!" << endl;
	exQueue.Push(17);
	cout << "Pushed!" << endl;
	exQueue.Push(20);
	cout << "Pushed!" << endl;
	//Print Queue
	exQueue.Print();
	//Pop Item
	exQueue.Pop();
	cout << "Popped!" << endl;
	//Push Items
	exQueue.Push(15);
	cout << "Pushed!" << endl;
	exQueue.Push(4);
	cout << "Pushed!" << endl;
	exQueue.Push(25);
	cout << "Pushed!" << endl;
	//Print Queue
	exQueue.Print();
	//Pop Items
	exQueue.Pop();
	cout << "Popped!" << endl;
	exQueue.Pop();
	cout << "Popped!" << endl;
	//Print Queue
	exQueue.Print();
	//Clear Queue
	unsigned int size = exQueue.GetSize();
	for (unsigned int i = 0; i < size; i++)
	{
		exQueue.Pop();
		cout << "Popped!" << endl;
	}
	//Print Queue
	exQueue.Print();

	//Test Queue with Alberto Class
	//Create Alberto Queue
	Queue<AlbertoClass> albQueue;
	//Push Items
	for (unsigned int i = 20; i < 35; i++)
	{
		//Create Alberto Object for each increment
		AlbertoClass alberto(i);
		//Push Object to Queue
		albQueue.Push(alberto);
		cout << "Pushed!" << endl;
	}
	//Print Items
	albQueue.Print();

	//End Program
	cout << "Press Enter to end" << endl;
	getchar();
}