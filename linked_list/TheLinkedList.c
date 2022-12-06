#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}node;

node* insert(node* head)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node ->next = NULL;
    printf("\tenter the value:");
    scanf("%d",&new_node->info);
    if(head == NULL)
    {
        head = new_node;
    }
    else{
        node* temp = head;
        while(temp->next!=NULL) //last element
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

void display(node* head)
{
    if(head == NULL)
    {
        printf("\nempty\n");
    }
    else
    {
        printf("\t");
        
        while(head!=NULL)
        {
            printf("%d,",head->info);
            head = head->next;
        }
    }
}
int main()
{
    node* head = NULL;
    int choice;
    while(1)
    {
        int choice;
        printf("Options:\n");

        // printf("1.insert at begin\n"); //done
        // printf("1.insert at index\n"); // done

        // printf("2.delete at end\n"); // done
        // printf("1.delete at begin\n");// done
        // printf("1.delete at index\n");// done
        
        // printf("1.delete by value\n");// linear search + linked list faltu apne aap karlena display ka loop lagana temp->next->info == value // value not found
        // doubly 
        // circular //yaham tak
        //____________
        // queue (vishwas) (ill try)

        printf("1.insert at end\n");//imp
        printf("2.display\n");//imp
        printf("3.exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head = insert(head);
                break;
            case 2:
                display(head);
                break;
            case 3: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}
