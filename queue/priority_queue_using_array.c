// Priority Queue is an abstract data type that is similar to a queue,
//  and every element has some priority value associated with it.
//   The priority of the elements in a priority queue determines the order
//    in which elements are served (i.e., the order in which they are removed).
//  If in any case the elements have same priority, they are served as per their ordering in the queue.

// 1) Ascending Order Priority Queue
// 4,6,8,9,10. Here, 4 is the smallest number, therefore, it will get the highest priority in a priority queue

// 2) Descending order Priority Queue 
// 4,6,8,9,10. Here, 10 is the largest number, therefore, it will get the highest priority in a priority queue

#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct node
{
    int val;
    int pri;
}node;
int insert(node a[],int front,int rear)
{
    if(rear == max-1)
        printf("Overflow\n");
    else{
        // ++rear;
        // printf("Enter the value: ");
        // scanf("%d",&a[rear]);
        if(rear==-1)
        {
            ++rear;
            printf("Enter the value: ");
            scanf("%d",&a[rear].val);
            printf("Enter the priority: ");
            scanf("%d",&a[rear].pri);
        }
        else
        {
            ++rear;
            printf("Enter the value: ");
            scanf("%d",&a[rear].val);
            printf("Enter the priority: ");
            scanf("%d",&a[rear].pri);
            int j = rear-1;
            while(j>=0 && a[j].pri > a[rear].pri)
		    {
                a[j+1].pri=a[j].pri;
                a[j+1].val=a[j].val;
                j--;
		    }
		    a[j+1].val=a[rear].val;
        }

    }
    return rear;
}

int delete(node a[],int front,int rear)
{
    if(front == -1)
        printf("Queue is empty\n");
    else{
        printf("deleted element is %d\n",a[front]);
        ++front;
    }
    return front;
}

void display(node a[], int front, int rear)
{
    if(front == -1)
        printf("Queue is empty\n");
    else{
        for(int i=front;i<=rear;i++)
            printf("%d,",a[i]);
        printf("\n");
    }
}
int main()
{
    int front = -1, rear = -1;
    int choice,flag=0;
    node a[max];
    while(1)
    {
        printf("Options:\n");
        printf("1.insert\n");//imp
        printf("2.delete\n");//imp
        printf("3.display\n");//imp
        printf("4.exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        printf("\n");

        switch(choice)
        {
            case 1:
                rear = insert(a,front,rear);
                if(flag==0)
                    ++front;
                flag=1;
                break;
            case 2:
                front = delete(a,front,rear);
                if(front==-1)
                {
                    rear=-1;
                    flag=0;
                }
                break;
            case 3:
                display(a,front,rear);
                break;
            case 4: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}