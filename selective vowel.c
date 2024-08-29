#include <stdio.h>
#include <string.h>

int main() {
    char string[20];
    int a,count=0;
    scanf("%s",string);
    scanf("%d",&a);
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U' ||
            string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u') {
                count++;
                if(count<=a){
                   printf("%c ", string[i]);
                }
        }
    }
    return 0;
}
