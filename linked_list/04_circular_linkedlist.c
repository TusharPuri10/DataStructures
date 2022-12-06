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
	
	return 0;
}