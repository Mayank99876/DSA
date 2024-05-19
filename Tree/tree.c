// deletion function error
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *left, *right;
} Node;
int insert(Node **, int);
Node *getNode(int);
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);
void deletion(Node **, int);
void casea(Node **, Node **, Node *);
void caseb(Node **, Node **, Node *);

int main()
{
    Node *root = NULL;
    int ch, item;

    do
    {
        printf("\t\t\tMAIN MENU\n");
        printf("\t\t\t1.Insert\n");
        printf("\t\t\t2.Preorder Traverse\n");
        printf("\t\t\t3.Inorder Traverse\n");
        printf("\t\t\t4.Postorder Traverse\n");
        printf("\t\t\t5.Delete item\n");
        printf("\t\t\t6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to insert: ");
            scanf("%d", &item);
            insert(&root, item);
            break;
        case 2:
            printf("Preorder Traverse: ");
            preorder(root);
            break;
        case 3:
            printf("\nInorder Traverse: ");
            inorder(root);
            break;
        case 4:
            printf("\nPostorder Traverse: ");
            postorder(root);
            break;
        case 5:
            printf("\nEnter item to delete: ");
            scanf("%d", &item);
            deletion(root, item);
            break;
        case 6:
            break;
        }

    } while (ch != 6);
    return 0;
}

Node *getNode(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->info = item;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t", root->info);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    printf("%d\t", root->info);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d\t", root->info);
}

int insert(Node **p_root, int item)
{
    Node *save = NULL;
    Node *ptr = *p_root;
    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            printf("Duplicate item can't be copy...");
            break;
        }
        else if (item > ptr->info)
        {
            save = ptr;
            ptr = ptr->right;
        }
        else
        {
            save = ptr;
            ptr = ptr->left;
        }
    }

    Node *newnode = getNode(item);

    if (save == NULL)
    {
        *p_root = newnode;
    }
    else
    {
        if (item < save->info)
        {
            save->left = newnode;
        }
        else
            save->right = newnode;
    }
}

void deletion(Node **p_root, int item)
{
    Node *save = NULL, *ptr = *p_root;
    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            break;
        }
        else if (item > ptr->info)
        {
            save = ptr;
            ptr = ptr->right;
        }
        else
        {
            save = ptr;
            ptr = ptr->left;
        }
    }
    if (ptr == NULL)
    {
        printf("Item not found\n");
        return;
    }
    if (ptr->left != NULL && ptr->right != NULL)
        caseb(p_root, &save, ptr);
    else
        casea(p_root, &save, ptr);
    free(ptr);
}

void casea(Node **p_root, Node **save, Node *ptr)
{
    Node *child;
    if (ptr->left == NULL && ptr->right == NULL)
        child = NULL;
    else if (ptr->left != NULL)
        child = ptr->left;
    else
        child = ptr->right;
    if (ptr == *p_root)
        *p_root = child;
    else if (ptr == (*save)->right)
        (*save)->right = child;
    else
        (*save)->left = child;
}

void caseb(Node **p_root, Node **save, Node *ptr)
{
    Node *suc = ptr->right, *parsuc = ptr;
    if (suc->left != NULL)
    {
        while (suc->left != NULL)
        {
            parsuc = suc;
            suc = suc->left;
        }
        casea(p_root, &parsuc, suc);
        suc->left = ptr->left;
        suc->right = ptr->right;
    }
    else
    {
        casea(p_root, &parsuc, suc);
        suc->left = ptr->left;
    }

    if (ptr == *p_root)
        *p_root = suc;
    else if (ptr == (*save)->right)
        (*save)->right = suc;
    else
        (*save)->left = suc;
}