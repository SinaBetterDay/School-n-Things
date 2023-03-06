#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    void insert(char val) {
        Node* newNode = new Node(val);

        if (root == NULL) {
            root = newNode;
            return;
        }

        Node* temp = root;
        Node* parent = NULL;

        while (temp != NULL) {
            parent = temp;

            if (val < temp->data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        if (val < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void inorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BST tree;

    tree.insert('D');
    tree.insert('B');
    tree.insert('F');
    tree.insert('A');
    tree.insert('C');
    tree.insert('E');
    tree.insert('G');

    cout << "The Tree: D B F A C E G\n";
    
    
    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorderTraversal(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorderTraversal(tree.root);
    cout << endl;

    return 0;
}
