#include <stdio.h>
#include <stdlib.h>

#define COL 7
#define LIN 5

void mostrarMatriz(int matriz[LIN][COL]){
    int i, j;

    printf("\n  ");
	for (j = 0; j < COL; j++){
    	printf("%3d", j);
	}
	printf("\n");
    
    for(i = 0; i < LIN; i++){
        printf("%2d", i);
    	for (j = 0; j < COL; j++){
    		printf("%3d", matriz[i][j]);
		}
		printf("\n");
    }

}

void andar(int matriz[LIN][COL]){
    int i = 0, j = 0, x = 4, y = 0, bateu = 0;

    while(bateu == 0){
    printf("Digite a posicao que vc deseja ir (linha, coluna):\n");
	printf("Posicao atual: %d %d\n", x, y);

    do{
        scanf("%d %d", &i, &j);
        if((i < 0 || i > LIN) || (j < 0 || j > COL)){
            printf("Posicao invalida! Tente novamente: \n");
        }
        } while ((i < 0 || i > LIN) || (j < 0 || j > COL));
    

    if(matriz[i][j] == -1){
		printf("Voce bateu num obstaculo!");
        bateu = -1;
    } else if(matriz[i][j] == 2){
        printf("Voce chegou!!");
        bateu = 1;
    } else{
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
    int matriz[LIN][COL] = {0};
    
    matriz[4][0] = 1;
    matriz[3][0] = -1;
    matriz[0][2] = -1;
    matriz[2][2] = -1;
    matriz[4][4] = -1;
    matriz[1][5] = -1;
    matriz[2][5] = -1;
    matriz[0][6] = 2;

    mostrarMatriz(matriz);
    andar(matriz);

    return 0;
}