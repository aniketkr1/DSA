// implementation on circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

// head is always pointing the last element
struct node *head;

// insertion at the beginning
void insert_front()
{
    struct node *temp, *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    if( head == NULL )
    {
        head = ptr;
        ptr->link = head;
    }
    else
    {
        ptr->link = head->link;
        head->link = ptr;
    }
}


// insertion at the end
void insert_last()
{
    struct node *temp, *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    if( head == NULL )
    {
        head = ptr;
        ptr->link = head;
    }
    else
    {
        ptr->link = head->link;
        head->link = ptr;
        head = ptr; 
    }
}

// insertion after a specific position
void insert_pos()
{
    struct node *ptr, *temp, *tempx;
    int pos, i = 0;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    temp = head->link;
    while( i < pos )
    {
        tempx = temp;
        temp = temp->link;
        i++;
    }
    tempx->link = ptr;
    ptr->link = temp;

}

// delete at the beginning
void delete_front()
{
    struct node *temp;
    temp = head->link;
    if( head == NULL )
    {
        printf("\nList is empty.");
    }
    else
    {
        head->link = temp->link;
        free(temp);
    }
    printf("NOde deleted\n");

}

// delete at the end
void delete_end()
{
    struct node *temp;
    temp = head->link;
    if( head == NULL )
    {
        printf("\nList is empty");
    }
    else
    {
        while( temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = head->link;
        head = temp;
    }
    printf("\nNode deleted");
}

// delete by position
void delete_pos()
{
    struct node *temp, *ptr;
    temp = head->link;
    int pos, i = 0;
    
    if( head == NULL )
    {
        printf("\nList is empty.\n");
    }
    else
    {
        printf("Enter position: ");
        scanf("%d", &pos);
        while( i < pos -1)
        {
            ptr = temp;
            temp = temp->link;
            i++;
        }
        
        ptr->link = temp->link;
        free(temp);
        printf("Node deleted");
        

    }
}

// search an element
void search()
{
    struct node *temp;
    temp = head->link;
    int item, count = 0;
    int flag = 0;
    printf("Enter a element to search: ");
    scanf("%d", &item);
    while( temp != head )
    {
        count = count + 1;
        if(temp->data == item)
        {
            printf("\n%d is found at %d postion", item, count);
            flag = 1;
        }
        temp = temp->link;
    }
    if(temp->data == item)
    {
        printf("\n%d is found at %d position", item , count+1);
        flag = 1;
    }
    if( flag == 0 )
    {
        printf("\nNot found");
    }
}

void print_list()
{
    struct node *ptr;
    if( head == NULL )
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nList: ");
        ptr = head->link;
        while(ptr != head)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->link;
        }
        printf("%d", ptr->data);
    }
    printf("\n");
}

int main()
{
    int choice;
    while ( choice != 0 ) 
    {
        printf("\n\t---:main menu:---\n");
        printf("1. Insert at the beginning");
        printf("\n2. Insert at the list");
        printf("\n3. Insert after a specific position");
        printf("\n4. Print list");
        printf("\n5. Delete at the beginning");
        printf("\n6. Delter at the end");
        printf("\n7. Delete by position");
        printf("\n8. search");
        printf("\n9. Exit\n");

        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_front();     break;
            case 2:
                insert_last();      break;
            case 3:
                insert_pos();       break;
            case 4:
                print_list();       break;
            case 5:
                delete_front();     break;
            case 6:
                delete_end();       break;
            case 7:
                delete_pos();       break;
            case 8:
                search();           break;
            case 9:
                printf("--eixt--");
                exit(0);            break;
            default:
                printf("Enter a valid choice..");
        }
    }

}