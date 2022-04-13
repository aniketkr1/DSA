// implementation of dubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prv;
    struct node *nxt;
};

struct node *head;

// insert at the end
void insert_end()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    if( head == NULL )
    {
        ptr->prv = NULL;
        ptr->nxt = NULL;
        head = ptr;
    }
    else
    {
        temp = head;
        while( temp->nxt != NULL )
        {
            temp = temp->nxt;
        }
        temp->nxt = ptr;
        ptr->prv = temp;
        ptr->nxt = NULL;
    }
}

void print_list()
{
    struct node *ptr;
    printf("\nprinting values...\n");
    ptr = head;
    while( ptr != NULL )
    {
        printf("%d  ", ptr->data);
        ptr = ptr->nxt;
    }
}

int main()
{
    insert_end();
    insert_end();
    insert_end();
    insert_end();
    print_list();
}