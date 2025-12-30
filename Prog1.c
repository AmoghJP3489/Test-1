//Test1 BST creation and inorder traversal
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(struct node *root, struct node *newnode);
struct node *create();
struct node *deleteNode(struct node *root, int value);
struct node *find_min(struct node *root);
void inorder(struct node *ptr);

int main()
{
    int ch, value;

    while (1)
    {
        printf("\nEnter a choice:\n");
        printf("1 - Create\n");
        printf("2 - Delete\n");
        printf("3 - Inorder\n");
        printf("4 - Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                root = create();
                break;

            case 2: 
                if (root == NULL)
                {
                    printf("Tree is already empty\n");
                    break;
                }

                printf("Enter the element to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);

                if (root == NULL)
                    printf("Tree is empty after deletion\n");

                break;

            case 3:
                printf("---- INORDER ----\n");
                inorder(root);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

struct node *create()
{
    int ch;
    do {
        int value;
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->left = NULL;
        newnode->right = NULL;

        printf("Enter the value: ");
        scanf("%d", &value);
        newnode->data = value;

        if (root == NULL)
            root = newnode;
        else
            insert(root, newnode);

        printf("1 to continue, 2 to exit: ");
        scanf("%d", &ch);

    } while (ch == 1);

    return root;
}

void insert(struct node *root, struct node *newnode)
{
    if (newnode->data < root->data)
    {
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    }
    else if (newnode->data > root->data)
    {
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}

struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

struct node *find_min(struct node *root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}
