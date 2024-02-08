//Stacks
#include<iostream>
using namespace std;
#define MAXSTACK 5
class ArrayStack{
	int a[MAXSTACK];
	int top;
	public:
	ArrayStack(){
		top = -1;
	}
	void isempty(){
		if(top == -1){
			cout<<"Stack Underflow"<<endl;
			return;
		}
	}
	void isfull(){
		if(top == MAXSTACK -1){
			cout<<"Stack Overflow"<<endl;
			return;
		}
	}
	void push(int value){
		isfull();
		top++;
		a[top] = value;
	}
	void pop(){
		isempty();
		top--;
	}
	void display() const{
		if(top == -1){
			cout<<"No elements found.\n";
			return;
		}
		cout<<"The elements of the stack are: ";
		for(int i=0; i<=top;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
};
int main(){
	ArrayStack s;
	int value, choice;
	cout<<"1. PUSH Operation\n2. POP Operation\n3. Display Elements\n4. Exit\n";
	while(1){
		cout<<"Enter your choice: ";
		cin>>choice;
		if(choice == 1){
			cout<<"Enter value: ";
			cin>>value;
		}
		switch(choice){
			case 1:
				s.push(value);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"Invalid Option\n";
		}
	}
	return 0;
}

