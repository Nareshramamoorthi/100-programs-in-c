#include <stdio.h>
int main ()
{
    int sum=0;
    int final=0;
    int ff=0;
    int arr[3][3],i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("Enter a[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<3;i++){
        sum=0;
        {
            for(j=0;j<3;j++){
                sum+=arr[i][j];
            }
            if(final<sum){
            final=sum;
            }
        }

    }
    printf("%d",final);

}
