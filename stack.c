#include<stdio.h>
int top = -1 ;
void push(int arr[])
{
    int a;
    printf("\nEnter a element to push: ");
    scanf("%d", &a);
    if( top == 9 )
    {
       printf("\nStack is full. Overflow condition\n");
    }
    else
    {
        top = top + 1 ;
        arr[top] = a ;
    }
}

void pop(int arr[])
{
    
    if( top == -1 )
    {
        print("\nStack is empty. Underflow condition\n");
    }
    else
    {
        top = top - 1 ;
        printf( "\nOne element is removed from the stack\n");
        
    }
}

void topElement(int arr[])
{
    printf( "\nThe top element is : %d", arr[top]);
}

void print(int arr[])
{
    printf("\nStack elements are : ");
    for(int i=0; i<=top; i++ )
    {
       printf("%d  ", arr[i] );
    }
}

void size()
{
  printf("\nThe size of the stack is :  %d",  top + 1 );
}

int main()
{
    int arr[10], x ;
    do
    {
        printf("\n\n");
        printf ("\n1. PUSH\n");
        printf ("2. POP\n");
        printf ("3. TOP ELEMENT\n");
        printf ("4. DISPLAY STACK\n");
        printf ("5. SIZE\n");
        printf ("6. EXIT\n");
        printf ("Enter a choice: ");
        scanf("%d",&x);

        switch (x)
        {
        case 1 :
            push(arr); break;
        case 2 :
            pop(arr); break;
        case 3 :
            topElement(arr); break;
        case 4 :
            print(arr); break;
        case 5 :
            size(); break;
        case 6 :
            printf ("----:exit:----");
            exit(1); break;
        }
    } while (  x != 0 );
    
}