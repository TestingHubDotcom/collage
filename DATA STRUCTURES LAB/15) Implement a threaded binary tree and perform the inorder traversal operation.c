// Threaded Binary Tree (Inorder Traversal)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
    int lthread, rthread;
} Node;

Node* insert(Node* root, int key) {
    Node *ptr = root, *par = NULL;
    while (ptr != NULL) {
        if (key == ptr->data) return root;
        par = ptr;
        if (key < ptr->data) {
            if (ptr->lthread == 0) ptr = ptr->left;
            else break;
        } else {
            if (ptr->rthread == 0) ptr = ptr->right;
            else break;
        }
    }
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = key;
    tmp->lthread = tmp->rthread = 1;
    if (par == NULL) {
        tmp->left = tmp->right = NULL;
        root = tmp;
    } else if (key < par->data) {
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = 0;
        par->left = tmp;
    } else {
        tmp->left = par;
        tmp->right = par->right;
        par->rthread = 0;
        par->right = tmp;
    }
    return root;
}

void inorder(Node* root) {
    Node* ptr = root;
    if (!ptr) return;
    while (ptr->lthread == 0) ptr = ptr->left;
    while (ptr) {
        printf("%d ", ptr->data);
        if (ptr->rthread) ptr = ptr->right;
        else {
            ptr = ptr->right;
            while (ptr && ptr->lthread == 0) ptr = ptr->left;
        }
    }
    printf("\n");
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
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
