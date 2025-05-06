

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int findHeight(Node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

void mirrorTree(Node* root) {
    if (root == nullptr)
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    swap(root->left, root->right);
}

bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of nodes to insert initially: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    // Insert new node
    cout << "\nEnter a value to insert: ";
    cin >> val;
    root = insert(root, val);
    cout << "Inorder Traversal after insertion: ";
    inorder(root);
    cout << endl;

    // Height
    cout << "Height of the tree: " << findHeight(root) << endl;

    // Minimum value
    cout << "Minimum value in tree: " << findMin(root) << endl;

    // Mirror tree
    cout << "\nMirroring the tree...\n";
    mirrorTree(root);
    cout << "Inorder Traversal after mirroring: ";
    inorder(root);
    cout << endl;

    // Search
    cout << "\nEnter value to search: ";
    cin >> val;
    if (search(root, val))
        cout << "Value " << val << " found in the tree." << endl;
    else
        cout << "Value " << val << " not found in the tree." << endl;

    return 0;
}
