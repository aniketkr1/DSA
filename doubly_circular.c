// implementation on doubly ciucular linked list
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *prv;
    struct node *nxt;
};

struct node *head;

void insert_front()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    if( head == NULL )
    {
        ptr->prv = ptr;
        ptr->nxt = ptr;
        head = ptr;
    }
    else
    {
        struct node *temp;
        temp = head;
        while( temp->nxt != head)
        {
            temp = temp->nxt;
        }
        temp->nxt = ptr;
        ptr->prv = temp;
        head->prv = ptr;
        ptr->nxt = head;
        head = ptr;
    }
    printf("Node inserted\n"); 
}

void insert_end()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    if( head == NULL )
    {
        ptr->nxt = head;
        ptr->prv = head;
    }
    else
    {
        struct node *temp;
        temp = head->prv;
        ptr->prv = temp;
        temp->nxt = ptr;
        ptr->nxt = head;
        head->prv = ptr;
    }
    printf("Node inserted\n");
}

void printlist()
{
    struct node *ptr;
    ptr = head;
    printf("\nList:-  ");
    if( head == NULL )
    {
        printf("\nNothing to print");
    }
    else
    {
        while( ptr->nxt != head )
        {
            printf("%d  ", ptr->data);
            ptr = ptr->nxt;
        }
        printf("%d", ptr->data);
    }
}

int main()
{
    int choice;
    while( choice != 0 )
    {
        printf("\n1. Insert at front");
        printf("\n2. Insert at end");
        printf("\n3. Display list");
        printf("\n4. Exit");
        printf("\nEnter a choide: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            insert_front(); break;
            case 2:
            insert_end();   break;
            case 3:
            printlist();    break;
            case 4:
            printf("exit");
            exit(1);
        }
    }
}