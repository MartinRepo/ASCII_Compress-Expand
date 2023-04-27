#include <stdio.h>
int main(void){
    double PI = 3.14;
    int r1, r2;
    float circum, area;
    float sumOfArea=0, sumOfCircum=0;
    //input r1 and r2
    scanf("%d%d", &r1, &r2);
    //check if r1<=r2
    if(r1>r2){
        return 0;
    }
    while(r1<=r2){
        circum = 2*PI*r1;
        area = PI*r1*r1;
        r1 += 1;
        sumOfArea += area;
        sumOfCircum += circum;
    }
    printf("%.3f\n", sumOfArea);
    printf("%.3f\n", sumOfCircum);
    return 0;
}