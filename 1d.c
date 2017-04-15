
// CÓDIGO PARA REALIZAR EL PUNTO 1d)

/*


*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define P     16             // 1/2^P, P=16
#define Z     27000          // iteraciones    27000
#define N     6         // lado de la red simulada
#define PASO 0.05   // paso de probabilidad

void llenar(int *red, int n, float prob);
void imprimir(int *red, int n);
int hoshen(int *red,int n);
int   actualizar(int *red,int *clase,int s,int frag);
void  etiqueta_falsa(int *red,int *clase,int s1,int s2);
void  corregir_etiqueta(int *red,int *clase,int n);
void imprimir_clase(int *clase, int frag);
void imprimir_aux(int *aux, int n);
int percola(int *red, int n);
void calcula_ns(int *red, int* clase, int n, int frag);

int main(){
	int i, j, *red, *red_ini, n, z, cond; // semilla;
	float prob, Fp, percola_cont, paso;
	n=N;
  	z=Z;
   paso = 0.01;
	red = (int *)malloc(n*n*sizeof(int));
  	red_ini = (int *)malloc(n*n*sizeof(int)); 
//	FILE *f1; 
//	f1 = fopen("Fp_128.txt", "a");
   cond = 0;
 	prob=0.5;

//	for(j=0; j<100; j++){

//   	for(i=0;i<z;i++)
//    	{
  	  		srand(time(NULL)); // Para cada realización hay que cambiar la semilla. 
	  		llenar(red,n,prob);
  	  		hoshen(red,n);     


//   	}
	 
//		 prob = prob+paso;
//	}
	  printf("\n \n");
	  imprimir(red, n);
//	  fclose(f1);
//	  free(f1);	
	  free(red);
	  	 	
	  return 0;
}

void llenar(int *red, int n, float prob){
	int i;
	float res;
	for(i=0; i<n*n; i++) {
		red[i] = 0;
		res = (float)rand()/(float)RAND_MAX;
		if(res<prob){
			red[i] = 1;
		}
	}
//Pongo una matriz a eleccion, que deberia percolar
/*	for(i=n; i<2*n; i++) {
		red[i]=1; 
	}*/
	
}

void imprimir(int *red, int n){
	int i, j;
	for(i=0; i<n; i++){ 
		for(j=0; j<n; j++){ 
			printf("%i  ", red[i*n+j]); //Si le pongo \t deja un espacio
		}
	printf("\n");
	}
}

int   actualizar(int *red,int *clase,int s,int frag){

	while(clase[s]<0) s = -clase[s];

	if(!s){
		*red = frag;
		clase[frag] = frag;
		return frag+1;
	}
	else if(s){
		*red = s;
		return frag;
	}
}

int hoshen(int *red,int n){
  /*
    Esta funcion implementa en algoritmo de Hoshen-Kopelman.
    Recibe el puntero que apunta a la red y asigna etiquetas 
    a cada fragmento de red. 
  */
  int i,j,k,s1,s2,frag;
  int *clase;

  frag=0;
  
  clase=(int *)malloc(n*n*sizeof(int)); //vector de etiquetas

  for(k=0;k<n*n;k++) *(clase+k)=frag; //esto es: clase[k]=frag
  
  // primer elemento de la red

  s1=0; 
  frag=2; //1era etiqueta
  if (*red) frag=actualizar(red,clase,s1,frag);
  
  // primera fila de la red

  for(i=1;i<n;i++) //si el anterior es 1 y este tambien, van juntos
    {
      if (*(red+i)) //if red[i]=1 
         {
           s1=*(red+i-1);  //s1 es el anterior al que miramos
           frag=actualizar(red+i,clase,s1,frag);
         }
    }
  

  // el resto de las filas 

  for(i=n;i<n*n;i=i+n) //si el de arriba es 1 y este tambien, van juntos
    {

      // primer elemento de cada fila
      if (*(red+i)) 
         {
           s1=*(red+i-1); //el de arriba
           frag=actualizar(red+i,clase,s1,frag);
         }
      if (*(red+i)) 
         {
           s1=*(red+i-n); //el de arriba
           frag=actualizar(red+i,clase,s1,frag);
         }

      for(j=1;j<n;j++){
				if (*(red+i+j))
	  		{
	    			s1=*(red+i+j-1); 
            s2=*(red+i+j-n);

	    	if (s1*s2>0)
	      {
					etiqueta_falsa(red+i+j,clase,s1,s2);
	     	}
	    	else 
	      { if (s1!=0) frag=actualizar(red+i+j,clase,s1,frag);
	        else       frag=actualizar(red+i+j,clase,s2,frag);
	      }
	  		}
   		}

    }
//  printf("\n \n");

  corregir_etiqueta(red,clase,n);
//  imprimir_clase(clase, frag);   calcula_ns(red, clase, n, frag)
  calcula_ns(red, clase, n, frag);
	
  free(clase);

  return 0;
}


void calcula_ns(int *red, int* clase, int n, int frag){   // Calcula la cantidad de clusters (ns) de tamaño "s"

	int cont, i, j, k, s,l, *size_aux, *tipo_cluster, *ns, *size;
	s = 0; k = 0;	
   size_aux=(int *)malloc(2*frag*sizeof(int)); 
   tipo_cluster=(int *)malloc(2*frag*sizeof(int)); 
   size=(int *)malloc(2*frag*sizeof(int)); 
   ns=(int *)malloc(2*frag*sizeof(int)); 

	for(j=0; j<frag; j++){
		for(i=0; i<n*n; i++){
			
			if(clase[j]>0 && red[i]>0 && red[i] == clase[j])
				s++;  // calcula el tamaño de ese cluster.
			else if (clase[j]<0) continue;
		}
	 if(clase[j]>0 && s>0){
		size_aux[k] = s; 
		tipo_cluster[k] = clase[j];
		printf("%d   %d  \n",size_aux[k],tipo_cluster[k]);
		k++; s = 0;
	 } 
	}

   printf("\n \n ");
	printf("Cantidad de fragmentos        Tamaño \n");
	l = 0;
	for(i=0; i<k; i++){
      cont = 1;
		for(j=i+1; j<k;j++){
			if(size_aux[i]==size_aux[j] && size_aux[j]>0){
				cont++;
				size_aux[j]=0;
			}
		}


		if(size_aux[i]>0){     
			ns[l] = cont;   //  Número de clústers
			size[l] = size_aux[i];  // Tamaño "s"
		   printf("                   %d             %d  \n",ns[l],size[l]);		
			l++;				
		}
	}


	free(size_aux); free(tipo_cluster);
	free(size); free(ns);
}

void etiqueta_falsa(int *red, int *clase, int s1, int s2){  // pone etiquetas falsas en vector auxiliar "clase"

		while(clase[s1]<0) s1 = -clase[s1];
		while(clase[s2]<0) s2 = -clase[s2];	
		if(s2 > s1){
			 clase[s2] = -s1;	
			 *red = s1;		
		}
		else if (s2 < s1){
			 clase[s1] = -s2;	
			 *red = s2;	
		}
		else {
			*red=s1;	
		}	
}

void corregir_etiqueta(int *red, int *clase, int n){  // corrije etiquetas en la red.

	int i,s;
	for(i=0;i<n*n;i++){
		s = red[i]; 
		while(clase[s]<0) s = -clase[s];
		red[i] = s;
	
	}
}

void imprimir_clase(int *clase, int frag){
	int k;
	for(k=0;k<frag;k++){
		printf("%d ",*(clase+k));
	}
	printf("\n ");
}


