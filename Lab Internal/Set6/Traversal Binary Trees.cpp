//Binary Tree using Linked Lists
#include<iostream>
using namespace std;
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	Node(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};
class BinaryTree {
	public:
	Node *insert(int value) {
		Node *new_node = new Node(value);
	}
	void inorder(Node* temp) {
		if(temp != NULL) {
			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
		}
	}
	void preorder(Node *temp) {
		if(temp != NULL) {
			cout<<temp->data<<" ";
			preorder(temp->left);
			preorder(temp->right);
		}
	}
	void postorder(Node *temp) {
		if(temp != NULL) {
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<" ";
		}
	}
};
int main() {
	BinaryTree bt;
	Node *root = bt.insert(11);
	root->left = bt.insert(22);
	root->right = bt.insert(33);
	root->left->left = bt.insert(44);
	root->left->right = bt.insert(55);
	root->right->left = bt.insert(66);
	root->right->right = bt.insert(77);
	cout<<"The elements of the binary tree in In-Order Traversal are : ";
	bt.inorder(root);
	cout<<endl;
	cout<<"The elements of the binary tree in Pre-Order Traversal are : ";
	bt.preorder(root);
	cout<<endl;
	cout<<"The elements of the binary tree in Post-Order Traversal are : ";
	bt.postorder(root);
	cout<<endl;
	return 0;
}

