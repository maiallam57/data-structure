#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* left, * right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void Inorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    Inorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    Inorder(node->right);
}
// insert data
struct Node* insert(struct Node* root, int key)
{
    //if tree is empty , creat a new node
    if (root == NULL)
        return newNode(key);

    else if (key < root->data) {
        return insert(root->left, key);
    }
    else if (key > root->data)
        return insert(root->right, key);

}
//search

bool search(struct Node* root, int key)
{
    if (root == NULL)
        return false;

    if (key == root->data)
        return true;

    else if (key < root->data)
        return search(root->left, key);

    else
        return search(root->right, key);
}

void printSearch(Node* root, int key)
{
    bool x = search(root, key);
    if (x == true)
        cout << "node " << key << " is found" << endl;
    else
        cout << "node " << key << " is not found" << endl;
}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);

    }
    else {
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            delete(root);

            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);

    }
    return root;
}
int main()
{

    struct Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    printSearch(root, 6);
    printSearch(root, 13);
    printSearch(root, 100);

    Inorder(root);

    cout <<endl <<"delete 3 " << endl;
    deleteNode(root, 3);
 Inorder(root);
    cout << "\n delete 7 " << endl;
    deleteNode(root, 7);
 Inorder(root);

    cout << "\n delete 8 " << endl;
    deleteNode(root, 8);
     Inorder(root);
}
