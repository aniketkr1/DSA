// implementation on circular queue
#include<stdio.h>

int front = -1;
int rear = -1;

void Enqueu(int queue[], int size, int item)
{
    if( (front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("\nOverflown");
        return;
    }
    if( front == - 1 )
    {
        front = 0; 
        rear = 0;
    }
    else
    {
        if( rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
    }
    queue[rear] = item;
}

void Dequeu( int queue[], int size)
{
    if( front == -1  )
    {
        printf("\nUnderflown");
        return;
    }
    printf("\nElement deleted from queue is: %d", queue[front]);
    if( front == rear )
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if(front == size - 1 )
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }
}

void Display(int queue[],int size)
{
    int front_x = front;
    int rear_x = rear;
    if( front_x == -1 )
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue elements are:  ");
    if( front_x <= rear_x )
    {
        while(front_x <= rear_x )
        {
            printf("%d  ", queue[front_x]);
            front_x++;
        }
    }
    else
    {
        while(front_x <= size -1 )
        {
            printf("%d  ", queue[front_x]);
            front_x++;
        }
        front_x = 0;
        while( front_x <= rear_x )
        {
            printf("%d  ",queue[front_x]);
            front_x++;
        }
    }
}

int main()
{
    int size, choice, item;
    printf("Enter the size of queue: ");
    scanf("%d",&size);
    int queue[size];
    do
    {
        printf("\n\t---:MENU:---\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter a choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter a element to insert: ");
                scanf("%d", &item);
                Enqueu(queue,size,item);    break;
            case 2:
                Dequeu(queue,size);         break;
            case 3:
                Display(queue,size);        break;
            case 4:
                printf("\n--exit--\n");
                break;
            default:
                printf("\nWrong chioice");
            
        }
    }
    while( choice != 4);
}