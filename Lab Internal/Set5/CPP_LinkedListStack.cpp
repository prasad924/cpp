//Stacks using linked list
#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *link;
};
class LinkedListStack{
	public:
		Node *top = NULL;
		void push(int val){
			Node *new_node = new Node();
			new_node->data = val;
			new_node->link = top;
			top = new_node;
		} 
		void pop(){
			if(top == NULL){
				cout<<"Stack Underflow\n";
			}
			else{
				int popped_element = top->data;
				top = top->link;
				cout<<"The Popped Element is... "<<popped_element;
				cout<<endl;
			}
			
		}
		void peek(){
			if(top == NULL){
				cout<<"No elements found\n";
			}
			else{
				int top_element = top->data;
				cout<<"The Element found in top is... "<<top_element<<endl;
			}
		}
		void display(){
			if(top == NULL){
				cout<<"There are no elements in the stack\n";
			}
			else{
				Node *temp = top;
				cout<<"The elements of the stack are... ";
				while(temp != NULL){
					cout<<temp->data<<"->";
					temp = temp->link;
				}
				cout<<endl;
			}
			
		}
};
int main(){
	LinkedListStack s;
	int choice, value;
	cout<<"1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
	while(1){
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter data: ";
				cin>>value;
				s.push(value);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.peek();
				break;
			case 4:
				s.display();
				break;
			case 5:
				exit(0);
			default:
				cout<<"Invalid Option\n";
		}
	}
	return 0;
}

