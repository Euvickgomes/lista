#include <stdio.h>
#include <ctype.h>

#define NUM 9
#define CONT 4

void cadeias(char vetor[NUM],  int cont[CONT], int i, int j){

	for(j = 0; j < CONT; j++){
		printf("\n");
	for(i = 0; i < NUM; i++){
		printf("DNA %d: ", j+1);
		printf("Coloque a base do DNA -  Adenina (A), Citosina (C), Guanina (G) e Timina (T):  ");
		scanf(" %c", &vetor[i]);
		
		vetor[i] = toupper(vetor[i]);
		
		if ((vetor[i] == 'A') || (vetor[i] == 'C') || (vetor[i] == 'G') || (vetor[i] == 'T')){
			
			if(vetor[i] == 'A'){
				cont[j]++;
			}
		} else 
			printf("\nA base esta errada!");

	}		
	}
}

void quatroVezes(int j, int cont[CONT]){

	printf("\n");
	for(j = 0; j < CONT; j++){
		if (cont[j] > 4){
			printf("a Adenina aparece mais de 4 vezes no DNA %d\n", j+1);
		}
	}
	
}

main(){
	char vetor[NUM];
	int i, j, cont[CONT] = {0};
	
	cadeias(vetor, cont, i, j);
	quatroVezes(j, cont);

}
