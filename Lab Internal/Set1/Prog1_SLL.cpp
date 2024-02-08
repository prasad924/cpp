#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *link;
	Node(int d){
		data = d;
		link = NULL;
	}
};
class SingleLinkedList{
	public:
		Node *head = NULL;
		void insert_at_beginning(int data){
			Node *temp = head;
			Node *new_node = new Node(data);
			new_node->link = temp;
			head = new_node;
		}
		void insert_at_end(int data){
			Node *temp = head;
			if(head == NULL){
				Node *new_node = new Node(data);
				head = new_node;
			}
			else{
				while(temp->link != NULL) temp = temp->link;
				Node *new_node = new Node(data);
				temp->link = new_node;
			}
		}
		void insert_at_position(int position, int data){
			if(position < 1){
				cout<<"Invalid Posiition"<<endl;
				return;
			}
			else{
				Node *temp = head;
				if(head == NULL){
					cout<<"There are lesser elements"<<endl;
					return;
				}
				else{
					for(int i=0;i<position-1;i++){
						if(temp->link == NULL){
							cout<<"There are lesser elements"<<endl;
							return;
						}
						temp = temp->link;
					}
					Node *new_node = new Node(data);
					new_node->link = temp->link;
					temp->link = new_node;
				}
			}
		}
		void delete_element(int element){
			Node *temp = head,*prev = NULL;
			while(temp != NULL && temp->data != element){
				prev = temp;
				temp = temp->link;
			}
			if(temp == NULL) cout<<"Element not found."<<endl;
			else{
				if(head->data == element) head = temp->link;
				else prev->link = temp->link;
				delete temp;
				cout<<"Node deleted"<<endl;
			}
		}
		void length() const{
			int length = 0;
			if(head == NULL) cout<<"Length of the list ...0"<<endl;
			else{
				Node *temp = head;
				while(temp != NULL){
					length++;
					temp = temp->link;
				}
				cout<<"Length of the list ..."<<length<<endl;
			}
		}
		void display() const{
			Node *temp = head;
			if(temp == NULL) cout<<"There are no elements in the Linked List."<<endl;
			else{
				cout<<"Elements in the list are ...";
				while(temp != NULL)
				{
					cout<<temp->data<<"->";
					temp = temp->link;
				}
				cout<<
				endl;
			}
		}
};
int main(){
	SingleLinkedList s;
	int choice,data,position;
	cout<<"1. Create\n2. Display\n3. Prepend\n4. InsertStposition\n5. Delete\n6. Length\n7. Exit\n";
	while(1){
		cout<<"Enter option...";
		cin>>choice;
		if(choice == 1 or choice == 3 or choice == 4){
			cout<<"Enter a value ...";
			cin>>data;
		}
		switch(choice)
		{
			case 1:
				s.insert_at_end(data);
				break;
			case 2:
				s.display();
				break;
			case 3:
				s.insert_at_beginning(data);
				break;
			case 4:
				cout<<"Enter the position ...";
				cin>>position;
				s.insert_at_position(position, data);
				break;
			case 5:
				cout<<"Enter a element to delete ...";
				cin>>data;
				s.delete_element(data);
				break;
			case 6:
				s.length();
				break;
			case 7:
				exit(0);
			default:
				cout<<"Invalid Option"<<endl;
		}
	}
	return 0;
}
