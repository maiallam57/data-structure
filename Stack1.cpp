#include <iostream>
using namespace std;

const int max_size = 5;
int stack[max_size];
int top = -1;

bool isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

bool isFuLL() {
	if (top >= max_size - 1)
		return true;
	else
		return false;
}

void display() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return;
	}
	for (int i = top; i >= 0; i--) {
		cout << stack[i] << endl;
	}
	cout << "===========================" << endl;
}
void push(int item) {
	if (isFuLL()) {
		cout << "Stack is FULL" << endl;
	}
	else {
		top++;
		stack[top] = item;
	}
}

void Top() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return;
	}
	else if (isFuLL()) {
		cout << "Stack is FULL" << endl;
		return;
	}
	
	else {
		cout << "TOP ELEMENT " << stack[top] << endl;

	}
}
void Pop() {
	int temp;
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return;
	}
	temp = stack[top];
	top--;
	cout << temp << " HAS BEEN DELETED." << endl;
}
int main()
{
	push(2);
	push(10);
	push(5);
	display();
	Pop();
	display();
	push(7);
	display();
	Top();
	isEmpty();
	
}


