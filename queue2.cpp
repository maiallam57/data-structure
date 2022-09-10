#include <iostream>
using namespace std;
struct node {
	int data;
	struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
void Enqueue(int val) 
{
    if (rear == NULL)
    {
        rear = new node;
        rear->next = NULL;
        rear->data = val;
        front = rear;
    }
    else{
        temp = new node;
        rear->next = temp;
        temp->data = val;
        temp->next = NULL;
        rear = temp;
    }
}
void Dequeue() {
    temp = front;
    if (front == NULL) {
        cout << "Queue is empty" << endl;
    }
    else if (temp->next != NULL) {
        temp = temp->next;
        cout << "Element deleted from queue is : " << front->data << endl;
        free(front);
        front = temp;
    }
    else {
        cout << "Element deleted from queue is : " << front->data << endl;
        free(front);
        front = NULL;
        rear = NULL;
    }
}
void Display()
{
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    cout << "Queue Assignment 2" << endl << endl;
    cout << "            ********************************************************" << endl;
    cout << "            ********************************************************" << endl<<endl;
    Enqueue(2);
    Display();
    Enqueue(4);
    Display();
    Enqueue(6);
    Display();
    Dequeue();
    Display();
}

