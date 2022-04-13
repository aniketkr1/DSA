//operation in binary search tree
#include<stdio.h>
#include<stdlib.h>

struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
};

struct BSTnode *CreateNode(int data)
{
    struct BSTnode *NewNode = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;

    return NewNode;
}

struct BSTnode *find_min(struct BSTnode *root)
{
    struct BSTnode *temp = root;
    while( temp && temp->left != NULL )
    {
        temp = temp->left;
    }
    return temp;
}

struct BSTnode *search(struct BSTnode *root, int data)
{
    struct BSTnode *temp = root;
    while( temp->data != data )
    {
        
        if( temp->data > data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
        if( temp == NULL )
        {
            return NULL;
        }
    }
    return temp;
}

// insertion in binary tree
struct BSTnode *insert(struct BSTnode *root, int data)
{
    if( root == NULL )
    {
        return CreateNode(data);    // used everytime
    }
    if( data < root->data )
    {
        root->left = insert(root->left, data);
    }
    else
    if( data > root->data )
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct BSTnode *delete(struct BSTnode *root, int data)
{
    if( root == NULL )
    {
        return root;
    }
    else if( data < root->data )
    {
        root->left = delete(root->left, data);
    }
    else if( data > root->data )
    {
        root->right = delete(root->right, data);
    }
    else    // I found you, Get ready to be deleted
    {
        // Case 1: No child
        if( root->left == NULL && root->right == NULL )
        {
            free(root);
            root = NULL;
            //return root;
        }
        // Case 2: One child
        else if( root->left == NULL)
        {
            struct BSTnode *temp = root;
            root = root->right;
            free(temp);
            //return root;
        }
        else if( root->right == NULL )
        {
            struct BSTnode *temp = root;
            root = root->left;
            free(temp);
            //return root;
        }
        // Case 3: 2 children
        else
        {
            struct BSTnode *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;

}

void preorder(struct BSTnode *root)
{
    if( root != NULL )
    {
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct BSTnode *root)
{
    if( root != NULL )
    {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

void postorder(struct BSTnode *root)
{
    if( root != NULL )
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}

int main()
{
    int choice, n, item;
    struct BSTnode *root = NULL;
    struct BSTnode *res;
    while(choice != 0)
    {
        printf("\t\n--:MENU:--");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Preorder Traversal");
        printf("\n5. Inorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\npress 0 for eixt");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
           case 1:
                printf("Enter value of n: ");
                scanf("%d", &n);
                for( int i = 0; i < n; i++ )
                {
                    printf("Enter data: ");
                    scanf("%d", &item);
                    root = insert(root, item);
                }
                break;

            case 2:
                printf("Enter a element to search: ");
                scanf("%d", &item);
                res = search(root, item);
                if( res == NULL )
                {
                    printf("Not found");
                }
                else
                {
                    printf("Element found");
                }
                break;
            case 3:
                printf("Enter a elemet to delete: ");
                scanf("%d", &item);
                res = delete(root, item);
                if( res == root )
                {
                    printf("Element deleted");
                }
                else
                {
                    printf("not found");
                }
                break;
            case 4:
                printf("Preorder Traversal:- ");
                preorder(root);
                break;
            case 5:
                printf("Inorder Traversal:- ");
                inorder(root);
                break;
            case 6:
                printf("Postorder Traversal:- ");
                postorder(root);
                break;

        }
    }
}