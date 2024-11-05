#include <stdio.h>
#include <ctype.h>

#define NUM 9
#define CONT 4


void cadeias(char vetor[NUM],  int cont[CONT], int i, int j){
	
	char usuario;
	
	printf("Qual base vc quer saber se aparece mais de tais vezes?  ");
	scanf(" %c", &usuario);
	
	usuario = toupper(usuario);

	for(j = 0; j < CONT; j++){
		printf("\n");
	for(i = 0; i < NUM; i++){
		printf("DNA %d: ", j+1);
		printf("Coloque a base do DNA -  Adenina (A), Citosina (C), Guanina (G) e Timina (T):  ");
		scanf(" %c", &vetor[i]);
		
		vetor[i] = toupper(vetor[i]);
		
		if ((vetor[i] == 'A') || (vetor[i] == 'C') || (vetor[i] == 'G') || (vetor[i] == 'T')){
			
			if(vetor[i] == usuario){
				cont[j]++;
			}
		} else 
			printf("\nA base esta errada!");

	}		
	}
}

void quatroVezes(int j, int cont[CONT]){
	int n;
	
	printf("\nvc quer saber se a base aparece mais de n vezes? digite o valor de n: ");
	scanf("%d", &n);
	printf("\n");
	for(j = 0; j < CONT; j++){
		if (cont[j] > n){
			printf("a base aparece mais de %d vezes no DNA %d\n", n, (j+1));
		}
	}
	
}

main(){
	char vetor[NUM];
	int i, j, cont[CONT] = {0};
	
	cadeias(vetor, cont, i, j);
	quatroVezes(j, cont);

}
