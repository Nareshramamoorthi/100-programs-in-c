
#include <stdio.h>

int main() {
    int a;
    printf("enter the  no u want to print multiple times:");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        printf("%d is in the loop so it print multiple times \n",a);
    }

    return 0;
}
