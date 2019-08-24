

int main(){
	
} 


void afunda(int a[], int k, int N){
	int aux;
	k = 1;
	aux = a[k];
	a[k]=a[N];
	a[N]=aux;
	N--;
	
	return afunda(a,k,N);
}
