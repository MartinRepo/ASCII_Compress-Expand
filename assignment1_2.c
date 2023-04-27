#include <stdio.h>

int main(void){
    char ch;
    int letters = 0, digits = 0, spaces = 0, others = 0;
    while(scanf("%c", &ch)!=EOF){
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'){
            //if it is letter
            letters += 1;
        } else if (ch >= '0' && ch <= '9'){
            // if it is number
            digits += 1;
        } else if (ch == ' '){
            // if it is spaces
            spaces += 1;
        }else {
            others += 1;
        }
    }
    printf("%d %d %d %d", letters, digits, spaces, others);
    return 0;
}