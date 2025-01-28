#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct BinaryTree {
    public:
    BinaryTree* left;
    BinaryTree* right;
    int data;

    BinaryTree(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTree* Insert(BinaryTree* node, int data) {
    if (node == NULL) {
        return new BinaryTree(data);
    }

    if (data < node->data) {
        node->left = Insert(node->left, data);
    } else if (data > node->data) {
        node->right = Insert(node->right, data);
    }

    return node;
}

BinaryTree* FindMin(BinaryTree* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

BinaryTree* Delete(BinaryTree* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = Delete(root->left, key);
    } else if (key > root->data) {
        root->right = Delete(root->right, key);
    } else {
        if (root->left == NULL) {
            BinaryTree* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BinaryTree* temp = root->left;
            delete root;
            return temp;
        }

        BinaryTree* temp = FindMin(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }

    return root;
}

void Inorder(BinaryTree* root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Preorder(BinaryTree* root) {
    if (root != NULL) {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(BinaryTree* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

int MaxDepth(BinaryTree* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(MaxDepth(root->left), MaxDepth(root->right));
}

int MinDepth(BinaryTree* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    if (root->left == NULL) {
        return 1 + MinDepth(root->right);
    }
    if (root->right == NULL) {
        return 1 + MinDepth(root->left);
    }
    return 1 + min(MinDepth(root->left), MinDepth(root->right));
}

int main() {
    BinaryTree* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 7);

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;

    cout << "Maximum Depth: " << MaxDepth(root) << endl;
    cout << "Minimum Depth: " << MinDepth(root) << endl;

    root = Delete(root, 7);
    cout << "After Deleting 7, Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    return 0;
}
