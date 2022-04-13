// c program to perform deletion, insertion and traversal(iterative) in a binary search tree
#include<stdio.h>
#include<stdlib.h>

// struct of node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// for creating node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

// for insertion of nodes
struct node *insert(struct node *root, int data)
{
    
    struct node *ptr = root;
    struct node *temp = NULL;
    if(root == NULL)
    {
        return createNode(data);
    }
    while(ptr != NULL)
    {
        temp = ptr;
        if(data < ptr->data)
        {
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    if(data < temp->data)
    {
        temp->left = createNode(data);
    }
    else{
        temp->right = createNode(data);
    }

    return root;
    
}

// for deletion of nodes
struct node *delete(struct node *root, int target)
{
    struct node *ptr = NULL, *temp;
    temp = root;
    while(temp->data != target)
    {
        ptr = temp; // ptr is pointing to parent node
        if(temp->data < target)
        {
            temp = temp->right;
        } 
        else if(target < temp->data){
            temp = temp->left;
        }
    }

    
    // deletion start here
    // zero child(leaf node)
    if(temp->left == NULL && temp->right == NULL)
    {
        // ptr is pointing to parent node
        if(ptr->left == temp)
        {
            ptr->left = NULL;
        }
        else
        {
            ptr->right = NULL;
        }
        free(temp);
        return root;
    }

    // one child
    if(temp->left == NULL )
    {
        // when there is only two elements
        if(ptr == NULL)
        {
            root = temp->right;
            free(temp);
            return root;
        }

        // element to be deleted have only right child
        // if the parent left child is the element to be deleted then parent left child become
        // the right child of the node to be delated
        if(ptr->right == temp)
        {
            ptr->right = temp->right;
        }
        else 
        {
            ptr->left = temp->right;
        }
        free(temp);
        return root;
    }
    if(temp->right == NULL)
    {
        // when there is only two elements
        if(ptr == NULL)
        {
            root = temp->left;
            free(temp);
            return root;
        }
        
        // element to be delted have only left child
        // if the parent right child is the element to be delated then parent left child 
        // become the left child of the node to be deleted
        if(ptr->right == temp)
        {
            ptr->right = temp->left;
        }
        else{
            ptr->left = temp->left;
        }
        free(temp);
        return root;
    }
    
    // two child
    if(temp->left != NULL && temp->right != NULL)
    {
        // find minimum in right subtree
        struct node *min = temp->right;
        struct node *parent = temp;
        while(min->left != NULL)
        {
            parent = min;
            min = min->left;
        }

        // copying data from min node to the node to be delated
        temp->data = min->data;

        // min is the leaf node
        if(min->left == NULL && min->right == NULL)
        {
            if(parent->left == min)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
            free(min);
            return root;
        }

        // min have 1 child
        if(min->right == NULL)
        {
            // min have only left child
            if(parent->right == min)
            {
                parent->right = min->left;
            }
            else{
                parent->left = min->left;
            }
            free(min);
            return root;
        }

        // min have 1 child
        if(min->left == NULL )
        {
            
            // min have only right child
            if(parent->right == min)
            {
                parent->right = min->right;
            }
            else 
            {
                parent->left = min->right;
            }
            free(min);
            return root;
        }
        
        
    }
}

// inorder traversal of bst
void Inorder(struct node *root)
{
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        printf("%d  ", root->data);
        Inorder(root->right);
    }
}

// main function
int main()
{
    struct node *root = NULL;
    int size;
    printf("How many elements you want to insert: ");
    scanf("%d", &size);
    for(int i = 0; i<size; i++)
    {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("\nInorder travesal:- ");
    Inorder(root);

    int target;
    printf("\nEnter a element to delete:");
    scanf("%d", &target);
    root = delete(root, target);
    printf("\nInorder trersal:- ");
    Inorder(root);
}