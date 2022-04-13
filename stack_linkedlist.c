// implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node *head;

struct node 
{
    int data;
    int link;
};

struct node *top;

// push an item to the list
void push()
{

    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->link = NULL;
    if( head == NULL )
    {
        head = ptr;
        top = ptr;
    }
    else
    {
        temp = head;
        while( temp->link != NULL )
        {
            temp = temp->link;
        }
        temp->link = ptr;
        top = ptr;
    }
}

void pop()
{
    struct node *ptr, *temp;
    if( head == NULL )
    {
        printf("Nothing to pop");
    }
    else
    {
       if( head->link == NULL )     // deleting when there is only one element in the list
       {
           head = NULL;
           printf("\n%d is popped", head->data);
           free(head);
           
       }
       else
       {
           ptr = head;
           while( ptr->link != NULL )
           {
               temp = ptr;
               ptr = ptr->link;
           }
           temp->link = NULL;
           printf("\n%d is popped", ptr->data);
           free(ptr);
           
       }
    }
}

// printing the stack
void print_stack()
{
    struct node *ptx;
    ptx = head;
    if( ptx == NULL )
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("\nElements are: ");
        while( ptx != NULL )
        {
            printf("%d  ", ptx->data);
            ptx = ptx->link;
        }
    }
}

// size of list
void size()
{
    int count = 0;
    struct node *cnt;
    cnt = head;
    while( cnt != NULL )
    {
        count = count + 1;
        cnt = cnt->link;
    }
    printf("\nsize of stack = %d", count);
}

// print top element
void print_top()
{
    printf("\nTop element = %d", top->data);
}

int main()
{
    int choice;
    while( choice != 0 )
    {
        printf("\n\t---:Main Menu:---\n");
        printf("\n1. Push");
        printf("\n2. pop");
        printf("\n3. Top Element");
        printf("\n4. size");
        printf("\n5. Display stack");
        printf("\n6. Exit");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        switch( choice )
        {
            case 1:
                push(); break;
            case 2:
                pop();  break;
            case 3:
                print_top();    break;
            case 4:
                size(); break;
            case 5:
                print_stack();  break;
            case 6:
                printf("\n--exit--");
                exit(0);
            default:
                printf("\nEnter a correct choice");
            
        }
    }


}