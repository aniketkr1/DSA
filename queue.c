#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 50
int front = -1;
int rear = -1;
int queue[MAXSIZE];

void peek()
{
    printf("\nFront element: %d", queue[front]);
}

bool is_full()
{
    if ( rear == MAXSIZE - 1)
    {
        return true;
    }
    else
    {   
        return false;
    }
}

bool is_empty()
{
    if( front < 0 || front > rear )
    {
        return true;
    }
    else
    {   
        return false;
    }
}

void Enqueue()      // adding element to the queue
{
    int add;
    if( is_full()==true)
    {
        printf("\nOverflow condition\n");
    }
    else
    {
        if( front == - 1)
        {
            front = 0;
        }
        printf("\nEnter the element to insert to queue: ");
        scanf("%d", &add);
        rear = rear + 1;
        queue[rear] = add;
    }
} 

void dequeue()      // deleting element from queue
{
    if(is_empty()==true)
    {
        printf("\nUnderflow Condition\n");
    }
    else
    {
        printf("\nElement deleted from queue is : %d", queue[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if( front == - 1 )
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements stored in queue is:  ");
        for( i = front ; i <= rear; i++ )
        {
            printf("%d  ", queue[i]);
        }
    }

}

int main()
{
    int choice;
    do 
    {
        printf("\n\n");
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Top element\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                Enqueue();  break;
            case 2:
                dequeue();  break;
            case 3:
                peek();  break;
            case 4:
                display();  break;
            case 5:
                printf("---exit---");
                exit(1);    break;
        
        }
       
    }
    while( choice != 0 );
}