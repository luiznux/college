#include <stdio.h>

int haste(int n, int p[]){

    if (n == 0) return 0;

    int i, max = -1;

    for (i = 1; i <= n; i++){

        int temp = p[i] + haste(n-i, p);
        if (temp >max) max = temp;
    }

    return max;
}
