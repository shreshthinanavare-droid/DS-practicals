//binary search tree operations and traversal(store roll no, insertion, deletion,searching,treetraversal)
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int roll;
  struct Node *left;
  struct Node *right;
};

struct Node* createNode(int roll)
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a roll number
struct Node* insert(struct Node *root, int roll)
{
  if (root == NULL)
    return createNode(roll);

  if (roll < root->roll)
    root->left = insert(root->left, roll);

  else if (roll > root->roll)
    root->right = insert(root->right, roll);

  else
    printf("Roll number already exists!\n");

    return root;
}

// Search for a roll number
struct Node* search(struct Node *root, int roll)
{
  if (root == NULL || root->roll == roll)
    return root;

  if (roll < root->roll)
    return search(root->left, roll);

  return search(root->right, roll);
}

// Find minimum node
struct Node* findMin(struct Node *root)
{
  while (root != NULL && root->left != NULL)
    root = root->left;

  return root;
}

// Delete a roll number
struct Node* deleteNode(struct Node *root, int roll)
{
    if (root == NULL)
        return root;

    if (roll < root->roll)
        root->left = deleteNode(root->left, roll);
    else if (roll > root->roll)
        root->right = deleteNode(root->right, roll);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->roll = temp->roll;
        root->right = deleteNode(root->right, temp->roll);
    }

    return root;
}

// Inorder: Left, Root, Right
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->roll);
        inorder(root->right);
    }
}

// Preorder: Root, Left, Right
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->roll);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left, Right, Root
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->roll);
    }
}

// Free all allocated nodes
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, roll;

    do
    {
        printf("\n\n--- BST Student Record System ---");
        printf("\n1. Add Student");
        printf("\n2. Remove Student");
        printf("\n3. Search Student");
        printf("\n4. Inorder Traversal");
        printf("\n5. Preorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                root = insert(root, roll);
                break;

            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);

                if (search(root, roll) != NULL)
                {
                    root = deleteNode(root, roll);
                    printf("Student record deleted.\n");
                }
                else
                    printf("Student not found.\n");
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);

                if (search(root, roll) != NULL)
                    printf("Student found.\n");
                else
                    printf("Student not found.\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    freeTree(root);

    return 0;
}
