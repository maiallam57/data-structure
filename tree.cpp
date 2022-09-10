#include<iostream>
#include<queue>
using namespace std;

// A binary tree node has data, pointer to left child and a pointer to right child 

struct Node
{
   int data;
   Node* left,* right;
};

//Utility function to create a new tree node
Node* newNode(int data)
{

	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void preorder(Node* root) {
	if (root == NULL)
		return;

	//First read the data of child
	cout << root->data << " ";
	//Then recur on left subtree 
	preorder(root->left);
	//Then Recur on the right subtree
	preorder(root->right);
}
void inorder(Node* root) {
	if (root == NULL)
		return;

	//First recur on left subtree 
	inorder(root->left);
	//Then read the data of child
	cout << root->data << " ";
	// Recur on the right subtree
	inorder(root->right);
}
void postorder(Node* root) {
	if (root == NULL)
		return;

	//Then recur on left subtree 
	postorder(root->left);
	//Then Recur on the right subtree
	postorder(root->right);
	//First read the data of child
	cout << root->data << " ";
}
// Iterative method to do level order traversal // line by line 
void Levelorder(Node* root)
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue for level order traversal
	queue<Node*> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (q.empty() == false) {
		// Print front of queue and remove it from queue
		Node* node = q.front();
		cout << node->data << " ";
		q.pop();

		// Enqueue left child 
		if (node->left != NULL)
			q.push(node->left);

		//Enqueue right child 
		if (node->right != NULL)
			q.push(node->right);
	}
}


int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(5);
	root->left->left =newNode(4);
	root->left->right->right = newNode(8);
	root->left->right->left = newNode(7);
	root->right->right = newNode(6);
	root->right->right->left = newNode(9);
	cout << "Preorder traversal of binary tree is:  " << endl;
	preorder(root);
	cout <<endl<< "Inorder traversal of binary tree is:  " << endl;
	inorder(root);
	cout << endl << "Postorder traversal of binary tree is:  " << endl;
	postorder(root);
	cout << endl << "Levelorder traversal of binary tree is:  " << endl;
	Levelorder(root);
	return 0;
}
