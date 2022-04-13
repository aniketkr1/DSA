// implementation of queue using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front;
struct node *rear;

void enqueue()
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->link = NULL;
    if( rear == NULL )
    {
        rear = ptr;
        front = ptr;    // fornt in always pointing the first element
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    front = temp->link;
    free(temp);
    printf("One element is deleted\n");
}

void top_element()
{
    printf("\nTop element is %d\n", rear->data);
}

void print_queue()
{
    struct node *temp;
    temp = front;
    if( temp == NULL )
    {
        printf("Noting to print");
    }
    else
    {
        printf("\nQueue: - ");
        while( temp != NULL )
        {
            printf("%d  ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    
}


int main()
{
    int choice;
    do
    {
        printf("\n\tMain Menu");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Top Element");
        printf("\n4. Print Queue");
        printf("\n5. Exit");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();  break;
            case 2:
                dequeue();  break;
            case 3:
                top_element();  break;
            case 4:
                print_queue();  break;
            case 5:
                printf("--eixt--");
                exit(1);    break;
            default:
                printf("Wrong choice");
        }
    }
    while( choice != 0 );
}