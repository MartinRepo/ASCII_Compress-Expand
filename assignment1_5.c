#include <stdio.h>
#define MAX_LEN 100

int main(void){
    int c;
    int i = 0;
    char ch[MAX_LEN];

    while(scanf("%d", &c)==1){
        if(c==10){
            // check if it is 10 but not \n
            ch[i]='\n';
        } else if (c==32){
            // check if it is 32 but not space
            ch[i]=' ';
        } else if (c==9){
            // check if it is 9 but not \t
            ch[i]='\t';
        }else if (c ==' ' || c == '\t' || c == '\n') { 
            // check if it is separator
            continue;
        } else if (c == EOF){
            break;
        } else {
            ch[i] = c;
        }
        ++i;
    }

    // add \0 to the end, to avoid char array make character randomly.
    ch[i]='\0';
    printf("%s", ch); 
    return 0;
}