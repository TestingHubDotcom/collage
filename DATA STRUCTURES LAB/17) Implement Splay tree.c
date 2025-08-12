// Splay Tree Implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
Node* splay(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) {
        if (!root->left) return root;
        if (key < root->left->data) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->data) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right) root->left = leftRotate(root->left);
        }
        return (root->left) ? rightRotate(root) : root;
    } else {
        if (!root->right) return root;
        if (key > root->right->data) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->data) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left) root->right = rightRotate(root->right);
        }
        return (root->right) ? leftRotate(root) : root;
    }
}
Node* insert(Node* root, int key) {
    if (!root) {
        root = (Node*)malloc(sizeof(Node));
        root->data = key; root->left = root->right = NULL;
        return root;
    }
    root = splay(root, key);
    if (root->data == key) return root;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    if (key < root->data) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }
    return newNode;
}
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    Node* root = NULL;
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
