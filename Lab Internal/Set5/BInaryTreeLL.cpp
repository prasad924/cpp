//Binary Tree using Linked Lists
#include<iostream>
using namespace std;
class TreeNode {
	public:
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};
class BinaryTree {
	public:
	void insert(int value) {
		insert(root, value);
	}
	void Inorder() {
		cout<<"The elements of the binary tree are : ";
		Inorder(root);
	}
	private:
	TreeNode *root = NULL;
	void insert(TreeNode*& root, int value) {
		if(root == NULL) {
			root = new TreeNode(value);
		}
		else {
			if(value <= root->data) {
				insert(root->left, value);
			}
			else {
				insert(root->right, value);
			}
		}
	}
	void Inorder(TreeNode*& root) {
		if(root != NULL) {
			Inorder(root->left);
			cout<<root->data<<" ";
			Inorder(root->right);
		}
	}
};
int main() {
	BinaryTree bt;
	int elements[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
	int numElements = sizeof(elements)/sizeof(elements[0]);
	for(int i = 0; i < numElements; ++i) {
		bt.insert(elements[i]);
	}
	bt.Inorder();
	return 0;
}

