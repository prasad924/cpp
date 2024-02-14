#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool canSortQueue(queue<int>& inputQueue, queue<int>& targetQueue) {
    stack<int> tempStack;

    while (!inputQueue.empty()) {
        int current = inputQueue.front();
        inputQueue.pop();

        if (current == targetQueue.front()) {
            targetQueue.pop();
        } else {
            if (tempStack.empty()) {
                tempStack.push(current);
            } else {
                while (!tempStack.empty() && tempStack.top() < current) {
                    targetQueue.push(tempStack.top());
                    tempStack.pop();
                }
                tempStack.push(current);
            }
        }
    }

    while (!tempStack.empty() && tempStack.top() == targetQueue.front()) {
        tempStack.pop();
        targetQueue.pop();
    }

    return tempStack.empty() && targetQueue.empty();
}

int main() {
    queue<int> inputQueue, targetQueue;

    // Populate the queues with data
    inputQueue.push(3);
    inputQueue.push(2);
    inputQueue.push(1);
    inputQueue.push(4);

    targetQueue.push(1);
    targetQueue.push(2);
    targetQueue.push(3);
    targetQueue.push(4);

    if (canSortQueue(inputQueue, targetQueue)) {
        cout << "The input queue can be sorted into the target queue using a stack.\n";
    } else {
        cout << "The input queue cannot be sorted into the target queue using a stack.\n";
    }

    return 0;
}

