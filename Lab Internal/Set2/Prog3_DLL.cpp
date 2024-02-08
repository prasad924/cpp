//Double Linked List
#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *prev;
	Node *link;
	Node(int d){
		data = d;
		prev = NULL;
		link = NULL;
	}
};
class DoubleLinkedList{
	public:
	Node *head,*tail = NULL;
	void insert_at_beginning(int data){
		Node *new_node = new Node(data);
		if(head == NULL){
			head = tail = new_node;
		}
		else{
			head->prev = new_node;
			new_node->link = head;
			head = new_node;
		}
		cout<<"Node inserted.\n\n";
	}
	
	void insert_at_end(int data){
		Node *new_node = new Node(data);
		if(head == NULL){
			head = tail = new_node;
		}
		else{
			tail->link = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
		cout<<"Node inserted.\n\n";
	}
	void insert_after_element(int data){
		int element;
		cout<<"Enter element to insert a node after it:";
		cin>>element;
	    Node *new_node = new Node(data);
	    if(head == NULL){
	        cout<<"List is empty.\n\n";
	    }
	    else{
	        Node *temp = head;
	        while(temp != NULL && temp->data != element){
	            temp = temp->link;
	        }
	        if(temp == NULL){
	            cout<<element<<" Not found in the list.\n\n";
	        }
	        else{
	            new_node->link = temp->link;
	            new_node->prev = temp;
	            if(temp->link != NULL){
	                temp->link->prev = new_node;
	            }
	            temp->link = new_node;
	            cout<<"Node inserted after "<<element<<".\n\n";
        	}
    	}
	}
	void delete_element(int element){
	    if(head == NULL){
	        cout<<"List is empty.\n\n";
	    }
	    else{
	        Node *temp = head;
	        while(temp != NULL && temp->data != element){
	            temp = temp->link;
	        }
	        if(temp == NULL){
	            cout<<element<<" Not found in the list.\n\n";
	        }
	        else{
	            if(temp == head){
	                head = head->link;
	                if(head != NULL)
	                    head->prev = NULL;
	            }
	            else if(temp == tail){
	                tail = tail->prev;
	                if(tail != NULL)
	                    tail->link = NULL;
	            }
	            else{
	                temp->prev->link = temp->link;
	                temp->link->prev = temp->prev;
	            }
	            delete temp;
	            cout<<"Node with data "<<element<<" deleted.\n\n";
	        }
	    }
	}

	void display(){
		if(head == NULL){
			cout<<"There are no elements.\n";
		}
		else{
			Node *temp = head;
			cout<<"Elements in the list are: ";
			while(temp != NULL){
				cout<<temp->data<<"->";
				temp = temp->link;
			}
			cout<<"\n";
		}
	}
	void reverse(){
		if(head == NULL){
			cout<<"There are no elements.\n\n";
		}
		else{
			Node *temp = tail;
			cout<<"Elements of list in reverse order are: ";
			while(temp != NULL){
				cout<<temp->data<<"->";
				temp = temp->prev;
			}
		}
		cout<<"\n\n";
	}
};
int main(){
	int data,choice;
	DoubleLinkedList d;
	cout<<"1. create\n2. Insert at beginning\n3. Insert after element\n4. Delete @NodeOfElement\n5. Display\n6. Display in reverse\n7. Exit\n";
	while(1){
		
		cout<<"Enter your choice: ";
		cin>>choice;
		if(choice <5){
			cout<<"Enter value...";
			cin>>data;
		}
		switch(choice){
			case 1:
				d.insert_at_end(data);
				break;
			case 2:
				d.insert_at_beginning(data);
				break;
			case 3:
				d.insert_after_element(data);
				break;
			case 4:
				d.delete_element(data);
				break;
			case 5:
				d.display();
				break;
			case 6:
				d.reverse();
				break;
			case 7:
				exit(0);
				break;
			default:
				cout<<"Invalid\n";
		}
	}
}
