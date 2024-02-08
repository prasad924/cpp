#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* root, int key) {
        if (root == NULL) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }

        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* deleteRec(Node* root, int key) {
        if (root == NULL) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->key) {
            root->right = deleteRec(root->right, key);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRec(root->right, temp->key);
        }

        return root;
    }

    bool searchRec(Node* root, int key) {
        if (root == NULL) {
            return false;
        }

        if (key == root->key) {
            return true;
        } else if (key < root->key) {
            return searchRec(root->left, key);
        } else {
            return searchRec(root->right, key);
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteNode(int key) {
        root = deleteRec(root, key);
    }

    bool search(int key) {
        return searchRec(root, key);
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Original BST: ";
    cout << "Search 20: " << (bst.search(20) ? "Found" : "Not Found") << endl;

    cout << "Deleting 20...\n";
    bst.deleteNode(20);

    cout << "BST after deletion: ";
    cout << "Search 20: " << (bst.search(20) ? "Found" : "Not Found") << endl;

    return 0;
}

