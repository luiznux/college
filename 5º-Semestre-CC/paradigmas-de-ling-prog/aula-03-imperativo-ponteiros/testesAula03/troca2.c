#include <stdio.h>

void troca( int x, int y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int a=10, b=20;
    troca(&a,&b);
    printf("a=%d b=%d\n",a,b);
    return 0;
}
