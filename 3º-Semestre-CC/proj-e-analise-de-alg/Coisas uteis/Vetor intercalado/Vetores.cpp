#include<stdio.h>
int main(){
	int vetor1[5]={2,3,12,90,312};
	int vetor2[7]={5,5,5,8,10,10,10};
	int vetor3[13];
	int a = 0;//5
	int b = 0;//7
	int i;
	for(i=0;i<13;i++){
		if (vetor1[a]<=vetor2[b]){
		
			vetor3[i]=vetor1[a];
			a++;
		}
		else {
		vetor3[i]=vetor2[b];
		b++;
		}
		if(b>8){
			vetor3[i]=vetor1[a];
			a++;
		}
		printf("%d",vetor3[i],";");
	}
	
	return 0;
		
}
