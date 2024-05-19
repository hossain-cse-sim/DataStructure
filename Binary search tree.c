#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root,int data)
{
    if (root==NULL)
    {
        return create(data);
    }
    if (data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if (data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

struct node *minValueNode(struct node *node)
{
    struct node *current=node;
    while (current && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}

struct node *deletenode(struct node *root,int data)
{
    if (root==NULL)
    {
        return root;
    }
    if (data<root->data)
    {
        root->left=deletenode(root->left, data);
    }
    else if (data>root->data)
    {
        root->right = deletenode(root->right, data);
    }
    else
        {
        if (root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
    else if (root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("BST Inorder:\n");
    inorder(root);
    printf("\n");
    root = deletenode(root, 20);
    printf("BST Inorder after deleting 20:\n");
    inorder(root);
    printf("\n");
    root = deletenode(root, 30);
    printf("BST Inorder after deleting 30:\n");
    inorder(root);
    printf("\n");
    root = deletenode(root, 50);
    printf("BST Inorder after deleting 50:\n");
    inorder(root);
    printf("\n");
    printf("BST Preorder:\n");
    preorder(root);
    printf("\n");
    printf("BST Postorder:\n");
    postorder(root);
    printf("\n");
    return 0;
}
