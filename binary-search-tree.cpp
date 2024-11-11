#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    int getData() const {
        return data;
    }

    void setData(int data) {
        Node::data = data;
    }

    Node* getLeft() const {
        return left;
    }

    void setLeft(Node* left) {
        Node::left = left;
    }

    Node* getRight() const {
        return right;
    }

    void setRight(Node* right) {
        Node::right = right;
    }

    Node(): data(0), left(nullptr), right(nullptr) {}
    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BST {
    Node* root;

public:
    BST(): root(nullptr) {}

    void insert(int value) {
        if (search(value))
            return;

        Node* n = new Node(value, nullptr, nullptr);
        if (root == nullptr) {
            root = n;
            return;
        }
        Node* p = root;

        while (true) {
            if (p->data < n->data) {
                if (p->right == nullptr) break;
                p = p->right;
            } else {
                if (p->left == nullptr) break;
                p = p->left;
            }
        }

        if (p->data > n->data)
            p->left = n;
        else
            p->right = n;
    }

    bool search(int value) {
        Node* p = root;

        while (p != nullptr) {
            if (p->data == value)
                return true;
            if (p->data > value)
                p = p->left;
            else
                p = p->right;
        }

        return false;
    }

    void remove(int value) {
        root = removeRec(root, value);
    }

private:
    Node* removeRec(Node* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = removeRec(node->left, value);
        } else if (value > node->data) {
            node->right = removeRec(node->right, value);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);

            // Copy the inorder successor's content to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = removeRec(node->right, temp->data);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        // Loop down to find the leftmost leaf
        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Initial BST:" << endl;
    bst.remove(20);
    bst.remove(30);
    bst.remove(50);

    return 0;
}
