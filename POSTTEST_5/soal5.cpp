#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

void preOrderTraversal(Node* root) {
    //1. Jika node saat ini adalah nullptr, langsung return
    if (root == nullptr) {
        return;
    }
    
    //2. Output data node saat ini
    cout << root->data << " ";
    
    //3. Transversal ke subtree kiri
    preOrderTraversal(root->left);
    
    //3. Transversal ke subtree kiri
    preOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); 
    cout << endl;
    return 0;
}