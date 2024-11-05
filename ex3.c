#include <stdio.h>

#define QUAD 5

void add_matriz(int matriz[QUAD][QUAD]){
	int i, j;
	
	for(i = 0; i < 	QUAD; i++){
		for(j = 0; j < QUAD; j++){
			printf("%d X %d: ", i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
		}
	}
		
}

void soma(int matriz[QUAD][QUAD], int vetor[QUAD]){
	int i, j, soma;
	
	for(i = 0; i < QUAD; i++){
			soma = 0;
			for(j = 0; j < QUAD; j++){
				soma += matriz[i][j];
			}
			vetor[i] = soma;
			printf("\nA soma da linha %d eh: ", i+1);
			printf(" %d", vetor[i]);
		}
}

main(){
	int matriz[QUAD][QUAD], vetor[QUAD];
	
	add_matriz(matriz);
	soma(matriz, vetor);
		
}

