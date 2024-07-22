#include <stdio.h>

int main() {
   int row,star;
   for(row=1;row<=10;row++){
       for(star=1;star<=row;star){
           printf("*");
       }
   }

    return 0;
}
