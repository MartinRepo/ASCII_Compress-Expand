#include <stdio.h>
#define MAX_LEN 100

int main(void){
    int num1[MAX_LEN]={0}, num2[MAX_LEN]={0}, sum[MAX_LEN];
    char input;
    int len1=0, len2=0, carry=0;

    //stroe number into array
    while(scanf("%c", &input)==1){
        if(input=='\n' || input=='\t' || input==' '){
            break;
        }
        num1[len1++] = input - '0';
    }

    while(scanf("%c", &input)!=EOF){
        if(input=='\n' || input=='\t' || input==' '){
            break;
        }
        num2[len2++] = input - '0';
    }


    //reverse two arrays
    int temp;
    for (int i = 0; i < len1 / 2; ++i) {
        temp = num1[i];
        num1[i] = num1[len1 - i - 1];
        num1[len1 - i - 1] = temp;
    }

    for (int i = 0; i < len2 / 2; ++i) {
        temp = num2[i];
        num2[i] = num2[len2 - i - 1];
        num2[len2 - i - 1] = temp;
    }
    
    //compute the sum of two number
    int i;
    for (i = 0; i < len1 || i < len2 || carry > 0; ++i) {
        int n1, n2;
        //check if overflow, if yes->0
        if(i<len1){
            n1=num1[i];
        } else {
            n1=0;
        }
        if(i<len2){
            n2=num2[i];
        } else {
            n2=0;
        }
        //calculate sum on each digit
        int numberSum = n1 + n2 + carry;
        //assign unit digit to sum
        sum[i] = numberSum % 10; 
        //assign remainder to carry
        carry = numberSum / 10; 
    }

    // output the sum
    for (int j = i - 1; j >= 0; --j) {
        printf("%d", sum[j]);
    }

    return 0;
}

