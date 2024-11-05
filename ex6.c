#include <stdio.h>

#define V 3
#define T 3

void pegar(int vetorLinha[V], int vetorColuna[T]){
	int i, j;
	
	for(i= 0; i < V; i++){
		printf("V: ");
		scanf("%d", &vetorLinha[i]);
	}
	
	for(j = 0; j < T; j++){
		printf("T: ");
		scanf("%d", &vetorColuna[j]);
	}
	
}

void calcular(int vetorLinha[V], int vetorColuna[T], int matriz[V][T]){
	int i, j;
	
	for(i = 0; i < V; i++){
		for(j = 0; j < T; j++){
			matriz[i][j] = vetorLinha[i] * vetorColuna[j];
			printf("%d X %d = %d\n", vetorLinha[i], vetorColuna[j], matriz[i][j]);
		}
	}
	
}

int main(){
	
	int vetorLinha[V], vetorColuna[T], i, j, matriz[V][T];
	
	pegar(vetorLinha, vetorColuna);
	calcular(vetorLinha, vetorColuna, matriz);
	
	return 0;

}
