//Test 2 TBT and inorder traversal
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int lthread;
    int rthread;
};

struct node *root = NULL;

struct node *createNode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->lthread = 1;
    new->rthread = 1;
    return new;
}

void insert(int data)
{
    struct node *ptr = root;
    struct node *parent = NULL;

    while (ptr != NULL)
    {
        if (data == ptr->data)
            return;

        parent = ptr;

        if (data < ptr->data)
        {
            if (ptr->lthread == 0)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == 0)
                ptr = ptr->right;
            else
                break;
        }
    }

    struct node *new = createNode(data);

    if (parent == NULL)
    {
        root = new;
    }
    else if (data < parent->data)
    {
        new->left = parent->left;
        new->right = parent;
        parent->lthread = 0;
        parent->left = new;
    }
    else
    {
        new->right = parent->right;
        new->left = parent;
        parent->rthread = 0;
        parent->right = new;
    }
}

struct node *leftMost(struct node *ptr)
{
    while (ptr != NULL && ptr->lthread == 0)
        ptr = ptr->left;
    return ptr;
}

void inorder()
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }

    struct node *ptr = leftMost(root);

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);

        if (ptr->rthread == 1)
            ptr = ptr->right;
        else
            ptr = leftMost(ptr->right);
    }
}

int main()
{
    int ch, val;

    while (1)
    {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                inorder();
                printf("\n");
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid input\n");
                break;
        }
    }
}
