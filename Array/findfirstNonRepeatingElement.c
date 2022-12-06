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
        int count=0;
        for(int j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
                ++count;
        }
        if(count == 1)
        {
            printf("%d is first non repeating element",arr[i]);
            goto end;
        }
    }
    printf("Non repeating element does not exist\n");
    end:{}
    return 0;
}