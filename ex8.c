#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void mostrarMatriz(int matriz[TAM][TAM]){
	
	int i, j;
	printf("\n  ");
		for (j = 0; j < 10; j++){
    		printf("%3d", j);
		}
		printf("\n");
		
	for(i = 0; i < 10; i++){
	    printf("%2d", i);
    	for (j = 0; j < 10; j++){
    		printf("%3d", matriz[i][j]);
		}
		printf("\n");
	}
	
}

void andar(int matriz[TAM][TAM]){
	int i = 0, j = 0, vencedor = 0, x = 0, y = 0;
	
	while(vencedor == 0){	
	printf("Digite a posicao que vc deseja ir (linha, coluna):\n");
	printf("Posicao atual: %d %d\n", i, j);
	
	do {
        scanf("%d %d", &i, &j);
        if((i < 0 || i > 9) || (j < 0 || j > 9)){
            printf("Posicao invalida! Tente novamente:\n");
            }
        } while((i < 0 || i > 9) || (j < 0 || j > 9));
	
	if (matriz[i][j] == -1){
		printf("Voce bateu num obstaculo!");
		vencedor = 1;
	} else if(matriz[i][j] == 9){
		mostrarMatriz(matriz);
		printf("Parabens!! Voce ganhou");
		vencedor = 1;
	}else{
		matriz[x][y] = 0;
		x = i;
		y = j;
	matriz[x][y] = 1;
	system("cls");
	mostrarMatriz(matriz);		
	}
	
	}
}



int main(){
	int matriz[TAM][TAM]  = {
        { 0,  0, -1,  0,  0,  0, -1,  0,  0,  0},
        { 0, -1,  0,  0, -1,  0,  0,  0, -1,  0},
        { 0,  0,  0, -1,  0,  0, -1,  0,  0,  0},
        { 0, -1,  0,  0,  0, -1,  0,  0, -1,  0},
        { 0,  0, -1,  0,  0,  0,  0, -1,  0,  0},
        { 0,  0,  0,  0, -1,  0,  0,  0,  0, -1},
        { 0, -1,  0,  0,  0, -1,  0,  0,  0,  0},
        { 0,  0,  0, -1,  0,  0,  0, -1,  0,  0},
        { 0,  0, -1,  0,  0,  0, -1,  0,  0,  0},
        { 0,  0,  0,  0, -1,  0,  0,  0,  0,  9}
    };
	matriz[0][0] = 1;

    mostrarMatriz(matriz);
    andar(matriz);
    
    
	return 0;
    
}
