#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to insert a value into the binary tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // If the value is less than the current node, insert into the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If the value is greater than or equal to the current node, insert into the right subtree
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform inorder traversal and print values
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    // Open the file for reading
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Exit with an error code
    }

    // Read the first integer from the file to determine the array size
    int arraySize;
    fscanf(file, "%d", &arraySize);

    // Create a binary tree and read values into it
    struct TreeNode* root = NULL;
    for (int i = 0; i < arraySize; ++i) {
        int value;
        fscanf(file, "%d", &value);
        root = insert(root, value);
    }

    fclose(file);

    // Print values in inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory for the binary tree (not implemented in this simple example)
    
    return 0; 
}
