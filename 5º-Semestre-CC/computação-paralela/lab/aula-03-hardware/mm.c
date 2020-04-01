#include <stdio.h>

#define MAX 1000

int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX] = {0};

int main() {
  int i, j, k;
  for(i=0;i<MAX;i++) {
    for(j=0;j<MAX;j++) {
      A[i][j] = B[i][j] = i*MAX+j;
    }
  }

  for(i=0;i<MAX;i++) {
      for(k=0;k<MAX;k++) {
    for(j=0;j<MAX;j++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  if(MAX<=3) {
    for(i=0;i<MAX;i++) {
      for(j=0;j<MAX;j++) {
        printf("%d ",C[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("%d\n",C[0][0]);
  }
}
