#include <stdio.h>
#include <stdlib.h>

#define M 8

void primeiraMatriz(int matriz[M][M]){
	int i, j;
	
	printf(" Primeira Matriz\n");
	
	for(i = 0; i < M; i++){
		printf("\n");
		for(j = 0; j < M; j++){
			printf(" %d ", matriz[M][M]);
		}
	}
	
}

void aleatoria(int matriz[M][M]){
	int i, j;
	
	printf("\n\n\n Matriz Aleatoria\n");
	
	for(i = 0; i < M; i++){
		printf("\n");
		for(j = 0; j < M; j++){
			matriz[M][M] = rand() % 2;
			printf(" %d ", matriz[M][M]);
		}
	}
}

main(){
	srand(time(NULL));
	int matriz[M][M] = {0};
	
	primeiraMatriz(matriz);
	aleatoria(matriz);
	
}
