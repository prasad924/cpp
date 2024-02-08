//Queue
#include<iostream>
using namespace std;
#define MAXQUEUE 5
class ArrayQueue{
	int arr[MAXQUEUE];
	int front,rear;
	public:
		ArrayQueue(){
			front=rear=-1;
		}
		void enqueue(int value){
			if(((rear+1)%MAXQUEUE)==front){
				cout<<"Queue is full.\n";
				return;
			}
			if(front ==-1){
				front = 0;
			}
			rear = (rear+1)%MAXQUEUE;
			arr[rear] = value;
		}
		void dequeue(){
			if(front == -1){
				cout<<"Queue is empty.\n";
				return;
			}
			if(front == rear){
				cout<<"The deleting element is..."<<arr[front]<<endl;
				front = rear = -1;
			}
			else{
				cout<<"The deleting element is..."<<arr[front]<<endl;
				front = (front+1)%MAXQUEUE;
			}
		}
		void display(){
			if(front == -1){
				cout<<"Queue is empty.\n";
				return;
			}
			cout<<"The elements of Queue are...";
			for (int i = front; ; i = (i + 1) % MAXQUEUE) {
        		cout << arr[i] << "->";
        		if (i == rear) break;
			}
			cout<<endl;
		}
};
int main(){
	int choice, data;
	ArrayQueue a;
	cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
	while(1){
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter data: ";
				cin>>data;
				a.enqueue(data);
				break;
			case 2:
				a.dequeue();
				break;
			case 3:
				a.display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"Invalid choice\n";
		}
	}
}
