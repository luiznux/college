#include <iostream>
 
using namespace std;
 
int main()
{
    int vet[] = {1, 2, 3, 4, 5, 7}, soma = 0;
    float media;
    for (int i = 0; i < 6; i++) {
        soma = soma + vet[i];
    }
    media = soma / 6.0;
    cout << "Soma: " << soma << endl;
    cout << "Media: " << media;
    return 0;
}
