//Finding Second Min elemnet from binary tree
#include<iostream>
using namespace std;
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
class BinaryTree {
	public:
	void find_min_util(Node* temp, int &minval, int &second_min_value) {
		if(!temp) return;
		if(temp->data < minval) {
			second_min_value = minval;
			minval = temp->data;
		}
		else if(temp->data > minval && (temp->data < second_min_value || second_min_value == -1)) {
			second_min_value = temp->data;
		}
		find_min_util(temp->left, minval, second_min_value);
		find_min_util(temp->right, minval, second_min_value);
	}
	int findSecondMin(Node *temp) {
		if(!temp) return -1;
		int MinVal = temp->data;
		int secondMinValue = -1;
		find_min_util(temp, MinVal, secondMinValue);
		return secondMinValue;
	}
};
int main() {
	BinaryTree bt;
	Node *root = new Node(2);
	root->left = new Node(2);
	root->right = new Node(5);
	root->right->left = new Node(4);
	root->right->right = new Node(7);
	int element = bt.findSecondMin(root);
	if(element != -1) {
		cout<<"The second min element is : "<<element<<endl;
	}
	else {
		cout<<"No second min element"<<endl;
	}
	return 0;
}


