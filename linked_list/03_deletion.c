#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};


void traversePrint(struct Node* n)
{
	while(n!=NULL)
	{
        printf("%d ",n->data);
		//std::cout<<n->data<<" ";//11 12 13 14 15 16
		n = n->next;
	}
}

struct Node* delete_begin(struct Node* head)
{
    printf("\nDeleting first element\n");
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node* delete_index(struct Node* head,int index)//assuming index start from 0
{                                                       //does't work for first element
    printf("\nDeleting element at index %d\n",index);
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p=head;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        ++i;
    }
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr = p->next;
    p->next = ptr->next;
    free(ptr);
    return head;
}

struct Node* delete_end(struct Node* head)
{
    printf("\nDeleting element from end\n");
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p=head;
    while(p->next->next != NULL)
    {
        p = p->next;
    }
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr = p->next;
    p->next = NULL;
    free(ptr);
    return head;
}

struct Node* delete_value(struct Node* head,int value)
{
    printf("\nDeleting element of value: %d\n",value);
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p=head;
    while(p->next->data != value)
    {
        p = p->next;
        if(p->next == NULL)
            return head;
    }
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr = p->next;
    p->next = ptr->next;
    free(ptr);
    return head;
}
int main()
{
	struct Node* head = (struct Node*) malloc (sizeof(struct Node));
	struct Node* second = (struct Node*) malloc (sizeof(struct Node));
	struct Node* third = (struct Node*) malloc (sizeof(struct Node));
	struct Node* fourth = (struct Node*) malloc (sizeof(struct Node));
	struct Node* fifth = (struct Node*) malloc (sizeof(struct Node));
	struct Node* sixth = (struct Node*) malloc (sizeof(struct Node));

	
	head->data = 11;
	head->next = second;
	second->data = 12;
	second->next = third;
	third->data = 13;
	third->next = fourth;
	fourth->data = 14;
	fourth->next = fifth;
    fifth->data = 15;
    fifth->next = sixth;
    sixth->data = 16;
    sixth->next = NULL;
	
	traversePrint(head);

    head = delete_begin(head);
    traversePrint(head);

    head = delete_index(head,3);
    traversePrint(head);

    head = delete_end(head);
    traversePrint(head);

    head = delete_value(head,1);
    traversePrint(head);

    head = delete_value(head,13);
    traversePrint(head);
	
	return 0;
}