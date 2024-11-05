#include <stdio.h>

#define QUAD 10

void funcao(int matriz[QUAD][QUAD]);
void somar(int matriz[QUAD][QUAD]);

main(){
	int matriz[QUAD][QUAD] = {0};
	
	funcao(matriz);
	somar(matriz);
	
}

void funcao(int matriz[QUAD][QUAD]){
	int i, j;
	
	for(i = 0; i < QUAD; i++){
		for(j = 0; j < QUAD; j++){
			printf("Digite o valor da matriz %d %d: ", i, j);
			scanf("%d", &matriz[i][j]);
			
		}
	}
}

void somar(int matriz[QUAD][QUAD]){
	int i, j, cont = 0;
	
	for(i = 0; i < QUAD; i++){
		for(j = 0; j < QUAD; j++){
			if (i == j){
				cont+= matriz[i][j];
			}
		}
	}
	
	printf("\nO traco da matriz eh: %d",cont);
}
