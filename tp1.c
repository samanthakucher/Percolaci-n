#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define P     16             // 1/2^P, P=16
#define Z     27000          // iteraciones
#define N     30             // lado de la red simulada


void llenar(int *red, int n, float prob);
void imprimir(int *red, int n);
int numeros(float P); // meter en llenar
int   actualizar(int *red,int *clase,int s,int frag);
void  etiqueta_falsa(int *red,int *clase,int s1,int s2);
void  corregir_etiqueta(int *red,int *clase,int n);
int   percola(int *red,int n);


int main(){
	int i, j, *red;
	float prob, denominador;
	n=N;
  z=Z;
	red = (int *)malloc(n*n*sizeof(int));

  for(i=0;i<z;i++)
    {
      prob=0.5;
      denominador=2.0;
 
      srand(time(NULL));

      for(j=0;j<P;j++) //no menos de 13 iteraciones (P>13)
        {
          llenar(red,n,prob);
      
          hoshen(red,n);
        
          denominador=2.0*denominador;

          if (percola(red,n)) 
             prob+=(-1.0/denominador); 
          else prob+=(1.0/denominador);
		//ir guardando en cada paso prob/N que percolan 
        }
    }

  free(red);
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
 
void llenar(int *red, int n, float prob){
	int i;
	for(i=0; i<n*n; i++) {
			red[i] = numeros(prob);
	}
}

void imprimir(int *red, int n){
	int i, j;
	for(i=0; i<n; i++){ 
		for(j=0; j<n; j++){ 
			printf("%i ", red[i*n+j]); //Si le pongo \t deja un espacio
		}
	printf("\n");
	}
}


