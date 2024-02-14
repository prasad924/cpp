#include <bits/stdc++.h>
using namespace std;
// Function to check if given queue element
// can be sorted into another queue using a
// stack.
bool checkSorted(int n, queue<int>& q)
{
stack<int> st;
int expected = 1;
int fnt;
// while given Queue is not empty.
while (!q.empty()) {
fnt = q.front();
q.pop();
// if front element isthe expected element
if (fnt == expected)
expected++;
else {
// ifstack is empty, push the element
if (st.empty()) {
st.push(fnt);
}
// iftop element is less than element which
// need to be pushed, then return false.
else if (!st.empty() && st.top() < fnt) {
return false;
}
// else push into the stack.
else
st.push(fnt);
}
// while expected element are coming from
// stack, pop them out.
while (!st.empty() && st.top() == expected) {
st.pop();
expected++;
}
}
// ifthe final expected element value is equal
// to initial Queue size and the stack is empty.
68
if (expected - 1 == n && st.empty())
return true;
return false;
}
// Driven Program
int main()
{
queue<int> q;
char ans;
int val;
do
{
cout<<"Enter value to be pushed:"<<endl;
cin>>val;
q.push(val);
cout<<"Do you want to add another element : press[y for yes and n for no]:";
cin>>ans;
} while(ans=='y');
int n = q.size();
(checkSorted(n, q) ? (cout << "Yes") :(cout << "No"));
return 0;
}
