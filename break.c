#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    for(int i=0;i<a;i++){
    if(a>=5){
        break;
    }
    printf("%d",a);
    }
    return 0;
}

