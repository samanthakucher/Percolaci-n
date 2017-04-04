#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenar(int *red, int m, int n, float prob);
void imprimir(int *red, int m, int n);
int numeros(float P);

int main(){
	int *red;
	int m, n;
	float prob;
	m = 10;
	n = 9;
	prob = 0.7;
	srand(time(NULL));
	red = malloc(m*n*sizeof(int));
	llenar(red, m, n, prob);
	imprimir(red, m, n);
	return 0;
}

int numeros(float P){
	int n;
	n = 0;
	float res = (float)rand()/(float)RAND_MAX;
	if(res<P){
		n=1;
	}
	return n;
}
 
void llenar(int *red, int m, int n, float prob){
	int i;
	for(i=0; i<m*n; i++) {
			red[i] = numeros(prob);
	}
}

void imprimir(int *red, int m, int n){
	int i, j;
	for(i=0; i<m; i++){ 
		for(j=0; j<n; j++){ 
			printf("%i ", red[i*n+j]); //Si le pongo \t deja un espacio
		}
	printf("\n");
	}
}


