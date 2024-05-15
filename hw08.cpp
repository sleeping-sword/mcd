#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right; 
}; 
Node* insertNode(Node* node, int data) { 
    if (node == NULL) {
        Node* temp = new Node();
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    return node;
}



void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;
    map<int, int> library;
    string command;
    int bookID;

    while (true) {
        cin >> command;
        if (command == "end") break;

        if (command == "insert") {
            cin >> bookID;
            if (library[bookID]) {
                cout << bookID << " already exists in the library.\n";
            } else {
                library[bookID] = 1;
                root = insertNode(root, bookID);
            }
        } else if (command == "check") {
            cin >> bookID;
            if (library[bookID]) {
                cout << bookID << " exists in the library.\n";
            } else {
                cout << bookID << " does not exist in the library.\n";
            }
        } else if (command == "show") {
            cout << "Preorder: ";
            preorder(root);
            cout << "\nInorder: ";
            inorder(root);
            cout << "\nPostorder: ";
            postorder(root);
            cout << "\n";
        }
    }

    //cout << "\nFinal tree state:\n";
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\n";

    return 0;
}