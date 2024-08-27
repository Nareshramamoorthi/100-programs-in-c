#include <stdio.h>
int main ()
{   int a,sum=0;
    int arr[a];
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    if(sum%a==0){
        printf("no num need to add");
    }
    else{
        int mod=sum%a;
        int final =a-mod;
        printf("the num should add is : %d",final);
    }

}
