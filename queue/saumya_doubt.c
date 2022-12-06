#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int info;
   struct node* next;
}node;
 
node* insert(node* rear){
    printf("entered the function:\n");
    node* new_node=(node*)malloc(sizeof(node));
    printf("enter the value: ");
    scanf("%d",&new_node->info);
    new_node->next=NULL;
    if(rear==NULL){
        rear=new_node;
    }
    else{
        
       rear->next=new_node;
        rear=new_node;
    }
    return rear;

}
void largestel(node* head){
int largest=head->info;
while(head!=NULL){
    if(largest< (head->info)){
        largest=head->info;
    }
    head=head->next;
}
printf("largest element is :%d\n",largest);
}

int main(){
    node * head=NULL;
    node* rear=NULL;
    int ch;
    int flag=0;
    while(1){
        printf("press 1 for insert \n 2 for largest element\n");
        printf("\nenter choice: ");
        scanf("%d",&ch);//mistake 1 was here "%d " space nhi aata
        switch(ch)
        {
            case 1:
                rear=insert(rear);
                if(flag==0){
                    head=rear;

                }
                flag++;
                break;
            case 2:
                largestel(head);
                break;
            case 3:
                exit(0);
            default:
                printf("wrong input\n");

        }
    }

    return 0;
}