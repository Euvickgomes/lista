#include <stdio.h>

#define N 10

void funcao(int V[N], int A[N], int B[N], int i, int j, int k, int contNulos){

	for(i = 0; i < N; i++){
	printf("digite os numeros do vetor V: ");
	scanf("%d", &V[i]);
		
		if (V[i] == 0){
			contNulos++;
		} else if (V[i] > 0){
			A[j] = V[i];
			j++;
		} else {
			B[k] = V[i];
			k++;
		}
	}
	
	printf("Qtd de Numeros Nulos: ");
	printf("%d", contNulos);
}

void imprimirRespostas(int V[N], int A[N], int B[N], int i, int j, int k){

	printf("\n");
	printf("Numeros do Vetor V:");
	for(i = 0; i < N; i++){
		printf(" %d", V[i]);
	}
	printf("\n");
	printf("Numeros do Vetor A:");
	for(j = 0; j < N; j++){
		printf(" %d", A[j]);
	}
	printf("\n");
	printf("Numeros do Vetor B:");
	for(k = 0; k < N; k++){
		printf(" %d", B[k]);
	}
	
}

main(){
	int V[N], A[N] = {0}, B[N] = {0}, i, j = 0, k = 0, contNulos = 0;

	funcao(V, A, B, i, j, k, contNulos);
	imprimirRespostas(V, A, B, i, j, k);
	
}
