#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a key in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node with a given value from BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to free the memory allocated for the BST
void freeBST(struct Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n----- Menu -----\n");
    printf("a. Create a BST\n");
    printf("b. Traverse the BST (Inorder, Preorder, Postorder)\n");
    printf("c. Search the BST\n");
    printf("d. Delete from BST\n");
    printf("e. Exit\n");
}

int main() {
    struct Node* root = NULL;
    char choice;
    int key, value;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                // Create a BST
                printf("Enter the number of elements: ");
                int n;
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                break;

            case 'b':
                // Traverse the BST
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\nPreorder Traversal: ");
                preorderTraversal(root);
                printf("\nPostorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 'c':
                // Search the BST
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL)
                    printf("Key %d found in the BST.\n", key);
                else
                    printf("Key %d not found in the BST.\n", key);
                break;

            case 'd':
                // Delete from BST
                printf("Enter the element to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Element %d deleted from the BST.\n", value);
                break;

            case 'e':
                // Exit
                freeBST(root);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 'e');


}
