#include <iostream>
#include <stack>

using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> inbox;
    stack<int> outbox;

public:
    void enqueue(int element) {
        inbox.push(element);
    }

    int dequeue() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }

        if (outbox.empty()) {
            cerr << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }

        int frontElement = outbox.top();
        outbox.pop();
        return frontElement;
    }
};

int main() {
    QueueUsingTwoStacks myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Dequeue: " << myQueue.dequeue() << "\n";
    cout << "Dequeue: " << myQueue.dequeue() << "\n";
    cout << "Dequeue: " << myQueue.dequeue() << "\n";
    cout << "Dequeue: " << myQueue.dequeue() << "\n";

    return 0;
}

