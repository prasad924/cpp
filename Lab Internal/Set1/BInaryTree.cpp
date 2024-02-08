//Binary tree using arrays
#include<iostream>
using namespace std;
class BinaryTree {
	int *tree, size;
	public:
		BinaryTree(int maxsize) {
			size = maxsize;
			tree = new int[size];
			for(int i = 0; i<size; ++i){
				tree[i] = -1;
			}
		}
		void insert(int value) {
			insertRecursive(value, 0);
		}
		void display() {
			cout<<"The elements of the binary tree are : ";
			for(int i = 0; i<size; ++i) {
				if(tree[i] != -1) {
					cout<<tree[i]<<" ";
				}
				else {
					cout<<"-";
				}
			}
			cout<<endl;
		}
		private:
			void insertRecursive(int value, int index) {
				if(index < size) {
					if(tree[index] == -1) {
						tree[index] = value;
					}
					else {
						if(value < tree[index]) {
							insertRecursive(value, 2*index+1);
						}
						else {
							insertRecursive(value, 2*index+2);
						}
					}
				}
			}
};
int main() {
	BinaryTree bt(15);
	int elements[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
	int numElements = sizeof(elements)/sizeof(elements[0]);
	for(int i = 0; i < numElements; ++i) {
		bt.insert(elements[i]);
	}
	bt.display();
	return 0;
}

