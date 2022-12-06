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
		//std::cout<<n->data<<" ";//11 12 13 14
		n = n->next;
	}
    printf("\n");
}

struct Node* insert_begin(struct Node* head, int x)
{
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = x;
    ptr->next = head;
    return ptr;
}

struct Node* insert_between(struct Node* head, int x, int ind)
{
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = x;
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p = head;
    int i=0;
    while(i!=ind-1)
    {
        p = p->next;
        ++i;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;

}

struct Node* insert_end(struct Node* head, int x)
{
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = x;
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;

}

struct Node* insert_after(struct Node* head,int x, int key)
{
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = x;
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p = head;
    while(p->data != key)
    {
        p = p->next;
        if(p==NULL)
        {
            return head;
        }
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;

}
struct Node* insert_before(struct Node* head,int x, int key)
{
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = x;
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p = head;
    while(p->next->data != key)
    {
        p = p->next;
        if(p==NULL)
        {
            return head;
        }
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;

}

int main()
{
	struct Node* head = (struct Node*) malloc (sizeof(struct Node));
	struct Node* second = (struct Node*) malloc (sizeof(struct Node));
	struct Node* third = (struct Node*) malloc (sizeof(struct Node));
	struct Node* fourth = (struct Node*) malloc (sizeof(struct Node));
	
	head->data = 11;
	head->next = second;
	second->data = 12;
	second->next = third;
	third->data = 13;
	third->next = fourth;
	fourth->data = 14;
	fourth->next = NULL;
	
	traversePrint(head);

    head = insert_begin(head,22);
    traversePrint(head);

    head = insert_between(head,32,1);
    traversePrint(head);
    head = insert_between(head,56,2);
    traversePrint(head);

    head = insert_end(head,20);
    traversePrint(head);

    head = insert_after(head,100,11);
    traversePrint(head);

    head = insert_before(head,200,14);
    traversePrint(head);
	
	return 0;
}