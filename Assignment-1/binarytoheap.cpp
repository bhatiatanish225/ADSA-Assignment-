#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void InorderTraversal(Node* root, vector<int>& elements) {
    if (root == NULL) return;
    InorderTraversal(root->left, elements);
    elements.push_back(root->data);
    InorderTraversal(root->right, elements);
}

void BSTToMinHeap(Node* root, vector<int>& elements, int& index) {
    if (root == NULL) return;

    root->data = elements[index++];
    BSTToMinHeap(root->left, elements, index);
    BSTToMinHeap(root->right, elements, index);
}

void PrintLevelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);

    vector<int> elements;
    InorderTraversal(root, elements);

    int index = 0;
    BSTToMinHeap(root, elements, index);

    cout << "Level Order Traversal of Min-Heap: ";
    PrintLevelOrder(root);
    cout << endl;

    return 0;
}
