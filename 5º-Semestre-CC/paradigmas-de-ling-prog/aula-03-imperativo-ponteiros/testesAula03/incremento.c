#include <stdio.h>

void f (int *x, int*y)
{
  *x = *x + 1;
  *y = *y + 1;
}
int main(void){
    int a=10, b=20;
    f(&a,&b);
    printf("a=%d b=%d\n",a,b);
    f(&a,&a);
    printf("a=%d b=%d\n",a,b);

    int *p, *q;
}
