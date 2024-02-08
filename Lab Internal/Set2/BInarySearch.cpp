//Binary Search
#include<iostream>
using namespace std;
int sort(int arr[]) {
	for(int j = 1; j<9; j++) {
		int key = arr[j];
		int i = j-1;
		while(i>0 && arr[i]>key) {
			arr[i+1] = arr[i];
			i = i-1;
		}
		arr[i+1] = key;
	}
}
int BinarySearch(int arr[], int target) {
	int first = 0, middle, last = 8;
	while(last >= first) {
		middle = (first + last)/2;
		if(target < arr[middle]) {
			last = middle - 1;
		}
		else if(target > arr[middle]) {
			first = middle + 1;
		}
		else if(target == arr[middle]) {
			cout<<"Element found at location..."<<middle;
			return 0;
		}
		else {
			cout<<"Element Not found"<<endl;
			return -1;
		}
	}
}
int main() {
	int elements[9] = {23, 3, 5, 45, 6, 78, 11, 13, 1}, target;
	cout<<"Enter element to delete...";
	cin>>target;
	sort(elements);
	BinarySearch(elements, target);
}

