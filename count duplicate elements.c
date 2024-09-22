#include<stdio.h>
#include <stdlib.h>

int main()
{
    int arr[1000],i,j,n,count=0;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count=count+1;
                break;
            }
        }
    }
    printf("%d",count);

}
