//Circular Single Linked List
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
class CircularLinkedList{
	public:
		Node *last = NULL;
		void insert_at_beginning(int data){
			Node *new_node = new Node(data);
			if(last == NULL){
				last = new_node;
				last->link = last;
			}
			else{
				new_node->link = last->link;
				last->link = new_node;
			}
			cout<<"Successfully Node Inserted"<<endl<<endl;
		}
		void insert_at_end(int data){
			Node *new_node = new Node(data);
			if(last == NULL){
				last = new_node;
				last->link = last;
			}
			else{
				new_node->link = last->link;
				last->link = new_node;
				last = new_node;
			}
			cout<<"Successfully Node Inserted"<<endl<<endl;
		}
		void insert_at_position(int data){
			int position;
			cout<<"Enter the location where the node is to be inserted: ";
			cin>>position;
			if(position == 1 or last == NULL){
				insert_at_beginning(data);
			}
			else{
				Node *temp = last->link;
				for(int i=1;i<position;i++){
					if(temp->link == last){
						cout<<"There are lesser elements in the Linked List."<<endl;
						cout<<"Your data will be inserted at the end of the list."<<endl<<endl;
						insert_at_end(data);
						return;
					}
					temp = temp->link;
				}
				Node *new_node = new Node(data);
				new_node->link = temp->link;
				temp->link = new_node;
				cout<<"Successfully Node Inserted."<<endl<<endl;
			}
		}
		void delete_at_beginning(){
			if(last == NULL){
				cout<<"Error No elements found.\n\n";
			}
			else if(last->link == last){
				Node *temp = last;
				last = NULL;
				delete temp;
				cout<<"Successfully Node deleted.\n\n";
			}
			else{
				Node *temp = last->link;
				last->link = temp->link;
				delete temp;
				cout<<"Successfully Node deleted.\n\n";
			}
		}
		void delete_at_end(){
			if(last == NULL or last->link == last){
				delete_at_beginning();
			}
			else{
				Node *temp = last->link, *todelete = last;
				while(temp->link != last){
					temp = temp->link;
				}
				temp->link = last->link;
				last = temp;
				delete todelete,temp;
				cout<<"Successfully Node deleted.\n\n";
			}
		}
		void delete_element(){
			int element;
			cout<<"Enter element to be deleted: ";
			cin>>element;
			if(last == NULL){
				cout<<"Error List is empty."<<endl<<endl;
				return;
			}
			else{
				Node *temp = last->link;
				if(temp->data == element){
					delete_at_beginning();
					return;
				}
				else{
					while(temp->link->data != element){
						temp = temp->link;
					}
					Node *prev = temp;
					temp = temp->link;
					prev->link = temp->link;
					delete temp;
				}
				cout<<"Successfully Element deleted."<<endl<<endl;
			}
		}
		void display() const{
			if(last == NULL){
				cout<<"There are no elements lin the list."<<endl<<endl;
			}
			else{
				Node *temp = last->link;
				cout<<"Elements of the linked list are: ";
				do{
					cout<<temp->data<<"->";
					temp = temp->link;
				}
				while(temp != last->link);
				cout<<endl<<endl;
			}
		}
		void count()const{
			int count = 1;
			if(last == NULL){
				cout<<"There are Zero elements."<<endl<<endl;
			}
			else{
				Node *temp = last->link;
				while(temp->link != last->link){
					count++;
					temp = temp->link;
				}
				cout<<"There are "<<count<<" elements in the list."<<endl<<endl;
			}
		}
};
int main()
{
	CircularLinkedList c;
	int choice,data;
	while(1)
	{
		cout<<"---------------Circular Single Linked List operations---------------"<<endl;
		cout<<"1. Insert a node at the beginning of the Linked List."<<endl;
		cout<<"2. Insert a node at the end of the Linked List."<<endl;
		cout<<"3. Insert a node at specified position of the Linked List."<<endl;
		cout<<"4. Delete a node from the beginning of Linked List."<<endl;
		cout<<"5. Delete a node from the end of Linked List."<<endl;
		cout<<"6. Delete a node of the specified element in Linked List."<<endl;
		cout<<"7. length of Linked List."<<endl;
		cout<<"8. Display the elements of Linked List."<<endl;
		cout<<"9. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cout<<endl;
		if(choice<4){
			cout<<"Enter data for Node: ";
			cin>>data;
		}
		switch(choice)
		{
			case 1:
				cout<<"-----Node Insertion at the beginning-----"<<endl;
				c.insert_at_beginning(data);
				break;
			case 2:
				cout<<"-----Node Insertion at the end-----"<<endl;
				c.insert_at_end(data);
				break;
			case 3:
				cout<<"-----Node Insertion at a specific position-----"<<endl;
				c.insert_at_position(data);
				break;
			case 4:
				c.delete_at_beginning();
				break;
			case 5:
				c.delete_at_end();
				break;
			case 6:
				c.delete_element();
				break;
			case 7:
				c.count();
				break;
			case 8:
				c.display();
				break;
			case 9:
				exit(0);
			default:
				cout<<"Invalid Option";
		}
	}
	return 0;
}

