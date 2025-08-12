// AVL Tree Implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
    int height;
} Node;

int max(int a, int b) { return (a > b) ? a : b; }
int height(Node* n) { return n ? n->height : 0; }
Node* create(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->left = n->right = NULL; n->height = 1;
    return n;
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }
Node* insert(Node* node, int key) {
    if (!node) return create(key);
    if (key < node->data) node->left = insert(node->left, key);
    else if (key > node->data) node->right = insert(node->right, key);
    else return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->data) return rightRotate(node);
    if (balance < -1 && key > node->right->data) return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
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
