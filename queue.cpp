#include <iostream>
using namespace std;
#define max_size 10

int front = -1, rear = -1; 
int Queue[max_size];
bool isFull()
{
	if(front == 0 && rear == max_size - 1) 
	{
		return true;
	}
	else {
		return false;
	}
}
bool isEmpty() 
{
	if (front == -1)
	{
		return true;
	}
	else {
		return false;
	}
}
void Enqueue(int value) 
{
	if (isFull())
	{
		cout << "The Queue is Full" << endl;
	}
	else {
		if (front == -1)
			front = 0;
		rear++;
		Queue[rear]=value;
		cout <<"the value is :"<< value << endl;

	}
}
int Dequeue() {
	int value;
	if (isEmpty())
	{
		cout << "The Queue is Empty" << endl;
		return -1;
	}
	else {
		value = Queue[front];
		if (front >= rear) {
			front = -1;
			rear = -1;
		}
		else {
			front++;
		}
		cout << "The deleted element in the queue is: " << value << endl;
		return (value);

	}
}
	void Display() 
	{
		int i;
		if (isEmpty())
		{
			cout << "The Queue is Empty" << endl;
		}
		else {
			cout << endl<<"Front :  " << front << endl;
			cout << endl<< "The Queue Elements are :  " << endl;
			for (i = front; i <= rear; i++)
				cout << Queue[i] << "\t";
			cout << endl<<"Rear :  " << rear << endl;
		}
	}


int main()
{
	cout << "Queue Assignment 1" << endl << endl;
	cout << "            ********************************************************" << endl;
	cout << "            ********************************************************" << endl << endl;
	Dequeue();
	cout << " Queue " << endl;
    Enqueue(2);
	Display();
    Enqueue(5);
	Display();
	Enqueue(7);
	Display();
	Dequeue();
	Display();
	Enqueue(3);
	Display();
	Enqueue(1);
	Display();
	Enqueue(9);
	Display();
	Enqueue(10);
	Display();
	Enqueue(4);
	Display();
	Enqueue(6);
	Display();
	Dequeue();
	Display();
	Enqueue(2);
	Display();
	Enqueue(1);
	Display();
	isFull();

	return 0;
}

