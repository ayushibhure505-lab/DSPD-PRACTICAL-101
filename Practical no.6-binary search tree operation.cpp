#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

void search(struct Node* root, int key) {
    if (root == NULL)
        printf("NULL (Not Found)\n");
    else if (root->data == key)
        printf("Found!\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else {
            printf("Cannot delete non-leaf node!\n");
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int ch, val;
    while (1) {
        printf("\n1.Search  2.Insert  3.Delete Leaf  4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &val);
                search(root, val);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &val);
                root = deleteLeaf(root, val);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
