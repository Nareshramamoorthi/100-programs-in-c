// Online C compiler to run C program online
#include <stdio.h>

int main() {
  int a,b,sum;
  scanf("%d",&a);
  b=a;
  int temp =a%100;
  int temp1=a/100;
  int ftemp= temp+temp1;
  temp=0;
  temp1=0;
  temp =a%10;
  temp1=a/10;
 int f1temp= temp+temp1;
  temp=0;
  temp1=0;
  while(a>0){
      temp=a%10;
      sum=sum+temp;
      a=a/10;
  }
  a=b;
  int ff=a+ftemp+f1temp+sum;
  printf("%d\n",ff);
    return 0;
}
