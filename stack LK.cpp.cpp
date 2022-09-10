#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct stacknode {
    string data;
    stacknode* next;
};

stacknode* newnode(string data) {
    stacknode* top = NULL;
    stacknode* stack_node = new stacknode();
    stack_node ->data = data;
    stack_node->next = NULL;
    return stack_node;
}
bool isEmpty(stacknode* top) {
    if (top == NULL)
        return true;
    else
        return false;
}
void push(stacknode**top, string data) {
    stacknode* node = newnode(data);
    node->next = *top;
    *top = node;

}
stacknode* top;
string pop(stacknode** top) {
    if (isEmpty(*top))
        return "- 1";
    stacknode* temp = *top;
    *top = (*top)->next;
    string x = temp->data;
    free(temp);
    return (x);
}
bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (expr[i]) {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

int main()
{
    string s;
    for (int i = 0; i < 13; i++) {
        cin >> s;
        push(&top, s);
    }
    cout << "The Reverse Word : " << endl;
    while (!isEmpty(top)) {

        cout << pop(&top)<< endl;
    }

    string expr;
    cin>>expr;
    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
