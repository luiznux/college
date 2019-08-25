#include <stdio.h>

int fatorial(int n){

    if( n == 0 || n ==1){
        return 1;
    }
    else if(n < 2){
       return 1;
    }
    else{
        return n * fatorial(n-1);
    }
}

// o x é o f(x) e o n é ate onde vc quer que calcule a somatoria
float euler_de_x(int x, int n){
    
    float f;
    
    int cont = 0;

    for(int i = 0; i <= n; i++){
        cont++;
        f+= x**i / fatorial(i);
    }

    return f;
}

int main(){

    return 0;
}
