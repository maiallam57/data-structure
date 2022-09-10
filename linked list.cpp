#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* node) {
    cout << endl;
    if (node == NULL)
        cout << "NULL";

    while (node != NULL) {
        cout << node->data << ", ";
        node = node->next;
    }
}

void push(Node** head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void insertInTheMiddle(Node** head, int key, int new_data) {
    Node* temp = *head;
    Node* prev = temp;
    if (head == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }
    if (temp != NULL && temp->data == key) {
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head)->next;
        (*head)->next = new_node;
    }
    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head)->next;
        (*head)->next = new_node;
    }

}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            cout << "the element does't exist\n";

        prev->next = temp->next;
        delete temp;
    }
}

int main()
{
    cout << "AHMED MAGDY MAKLAD		20018\n";
    cout << "MOHAMED HAZEM			20073\n";
    cout << "MAI MOHAMED ALLAM		20099\n";
    cout << "******************************************\n\n";

    Node* head = NULL;

    push(&head, 30);
    push(&head, 50);
    push(&head, 5);
    push(&head, 20);
    push(&head, 70);
    push(&head, 10);

    cout << "\nThe Created Linked list is: ";
    printList(head);
    cout << "\n******************************************\n\n";

    cout << "\nLinked List after Deletion of 20: ";
    deleteNode(&head, 20);
    printList(head);
    cout << "\n******************************************\n\n";

    cout << "\nLinked List after Deletion of an element not exist in the list: ";
    deleteNode(&head, 60);
    printList(head);
    cout << "\n******************************************\n\n";

    cout << "\nLinked List after Insertion of 100: ";
    insertInTheMiddle(&head, 30, 100);
    printList(head);


    return 0;
}
