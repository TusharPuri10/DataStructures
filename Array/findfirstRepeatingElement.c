#include<stdio.h>
#define max 100
int main()
{
    int arr[max];
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(arr[i]==arr[j] && i!=j)
            {
                printf("%d is first repeating element",arr[i]);
                goto end;
            }
        }
    }
    printf(" repeating element does not exist\n");
    end:{}
    return 0;
}