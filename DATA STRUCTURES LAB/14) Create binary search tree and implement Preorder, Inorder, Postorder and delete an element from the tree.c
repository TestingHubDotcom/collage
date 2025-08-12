#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* create(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (!root) return create(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left) current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                inorder(root); printf("\n");
                break;
            case 4:
                preorder(root); printf("\n");
                break;
            case 5:
                postorder(root); printf("\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
