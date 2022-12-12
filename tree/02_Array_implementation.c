#include<stdio.h>
#define max 10
int main()
{
    int tree[max];
    for(int i=0;i<max;i++)
        scanf("%d",&tree[i]);

    for(int i=0;i<max;i++)
    {
        printf("current node is %d\n",tree[i]);
        if(i<1)
            printf("\tNo root node\n");
        else
            printf("\tRoot node is %d\n",tree[(i-1)/2]);
        if((2*i)+1 < max)
            printf("\tleft node is %d\n",tree[(2*i)+1]);
        else
            printf("\t No left node.\n");
        if((2*i)+2 < max)
            printf("\tright node is %d\n",tree[(2*i)+2]);
        else
            printf("\t No right node.\n");
    }
    return 0;
}