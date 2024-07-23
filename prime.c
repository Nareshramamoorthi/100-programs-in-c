#include <stdio.h>

int main()
{
 int n,flag=0,i;
 printf("Enter the no : ");
 scanf("%d",&n);
 if(n==0||n==1){
     flag=0;
 }
for(i=2;i<=n/2;i++){
    if(n%i==0){
        flag=1;
        break;
    }
}
if(flag==0){
    printf("the give no is  prime");
}
else{
    printf("it not  prime");
}

    return 0;
}
