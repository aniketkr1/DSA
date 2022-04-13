// c program to perform all operation on a linked list
#include<stdio.h>
#include<stdlib.h>

// global variable
struct node *head;

// node
struct node
{
    int data;
    struct node *link;
};

// adding elements at the end
void add_at_end()
{
    struct node *temp, *ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(head == NULL )
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while( ptr->link != NULL )
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}
// adding element at the beginning
void add_at_beg()
{
    struct node *temp, *ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &temp->data);
    if( head == NULL )
    {
        head = temp;
    }
    else
    {
        temp->link = head;
        head = temp;
    }
}
// adding element by position
void add_by_pos()
{
    struct node *ptr, *temp, *ptrx;
    int pos;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter position to where you want to insert: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &temp->data);
    ptr = head;
    for( int i = 0; i <pos-1; i++ )
    {
        ptrx = ptr;
        ptr = ptr->link;
    }
    temp->link = ptr;
    ptrx->link = temp;
}
// deleting element at end
void delete_at_end()
{
    struct node *ptr, *temp;
    if( head == NULL )
    {
        printf("Nothing to delete");
    }
    else
    {
       if( head->link == NULL )     // deleting when there is only one element in the list
       {
           head = NULL;
           free(head);
           printf("\nonly node of the list deleted");
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
           free(ptr);
           printf("\nNode deleted");
       }

        
    }
}

// deleting element at beginning
void delete_at_beg()
{
    struct node *ptr;
    
    if( head == NULL )
    {
        printf("\nNothing to delete");
    }
    else
    {
        ptr = head->link;
        head = ptr;
    }
    printf("\nDeleted from beginning");

}

// deleting element by pos
void delete_by_pos()
{
    int pos, i = 0;
    struct node *ptr, *temp;
    printf("Enter position to delete an element: ");
    scanf("%d", &pos);
    ptr = head;
    while( i < pos-1 )
    {
        temp = ptr;
        ptr = ptr->link;
        i++;
    }
    temp->link = ptr->link;
    free(ptr);
    printf("\nnode deleted");

}

// search for a element and get its position
void search()
{
    struct node *ptr;
    int item, count = 0;
    int flag = 0;
    printf("Enter a element to search: ");
    scanf("%d", &item);
    ptr = head;
    while( ptr != NULL )
    {
        count = count + 1;
        if( ptr->data == item )
        {
            flag = 1;
            printf("\n%d is found at position %d", item, count);
        }
        ptr = ptr->link;
    }
    if( flag == 0 )
    {
        printf("Element not found");    
    }
}

// size of linked list
void size()
{
    int count = 0;
    struct node *ptr;
    if( head == NULL )
    {
        printf("Empty");
    }
    else
    {
        ptr = head;
        while( ptr != NULL )
        {
            count = count + 1;
            ptr = ptr->link;
        }

    }
    printf("Total no of element = %d", count);

}

// printing the list
void print_list()
{
    struct node *ptx;
    ptx = head;
    if( ptx == NULL )
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("Elements are: ");
        while( ptx != NULL )
        {
            printf("%d  ", ptx->data);
            ptx = ptx->link;
        }
    }
    
}

int main()
{
    int choice;
    while( choice != 0)
    {
        printf("\n\n\t--: main menU:-- ");
        printf("\nChoose an option..");
        printf("\n1. Add element at last");
        printf("\n2. Print list");
        printf("\n3. Add element at beginning");
        printf("\n4. Add element by position");
        printf("\n5. search");
        printf("\n6. Delete at end");
        printf("\n7. Delete at beginning");
        printf("\n8. Delete by postion");
        printf("\n9. size");
        printf("\n10. Exit");
        
        printf("\nEnter your choice?");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                add_at_end();   break;
            case 2:
                print_list();   break;
            case 3:
                add_at_beg();   break;
            case 4:
                add_by_pos();    break;
            case 5:
                search();   break;
            case 6:
                delete_at_end();    break;
            case 7:
                delete_at_beg();    break;
            case 8:
                delete_by_pos();    break;
            case 9:
                size();     break;
            case 10:
                printf("--eixt--");
                exit(0);
                break;
            default:
                printf("\nEnter a valid choice");
        }
    }
}