#include <stdio.h>
#define BOI 3

struct data
    {
        int mes;
        int ano;
    };
struct gado
{
    int codigo;
    float leite, alim;
    struct data nasc;
    char abate;
};

void menu(struct gado boi[BOI]){
    int opcao, saida = 1, gado_abate = 0, contador = 0;
    float leiteTotal = 0, comida = 0, leiteAbate = 0, aliAbate = 0; 

    do{
        printf("\n            MENU:\n");
        printf("1 - Cadastrar gado\n");
        printf("2 - Lista de gado para abate\n");
        printf("3 - Leite total produzido na semana\n");
        printf("4 - Alimento total consumido na semana\n");
        printf("5 - Leite que vai ser consumido apos abate\n");
        printf("6 - Alimento que vai ser consumido apos abate\n");
        printf("7 - Qntd de gados que vao para abate\n");
        printf("8 - sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:{
            printf("\n       Cadastro de gado:\n");
            printf("Codigo:  ");
            scanf("%d", &boi[contador].codigo);
            printf("\nLeite produzido por semana:  ");
            scanf("%f", &boi[contador].leite);
            leiteTotal += boi[contador].leite;
            printf("\nAlimento consumido por semana:  ");
            scanf("%f", &boi[contador].alim);
            comida += boi[contador].alim;
            printf("\nEm qual mes o gado nasceu?  ");
            do{
                scanf("%d", &boi[contador].nasc.mes);
                if(boi[contador].nasc.mes < 1 || boi[contador].nasc.mes > 12){
                    printf("\nMes invalido, digite novamente: ");
                }
            } while (boi[contador].nasc.mes < 1 || boi[contador].nasc.mes > 12);
            printf("\nEm qual ano o gado nasceu?  ");
            scanf("%d", &boi[contador].nasc.ano);

            contador++;
            
            printf("\n\nDigite [1] para voltar para o menu.\nDigite [0] para sair.\n");
            scanf("%d", &saida);

        } break;
        
        case 2:{
        for(int i = 0; i < contador; i++){
            if((2024 - boi[i].nasc.ano > 5) || (boi[i].leite < 40) || ((boi[i].leite >= 50 || boi[i].leite <= 70) && (boi[i].alim > 50))){
                boi[i].abate = 's';
                gado_abate++;
                aliAbate += boi[i].alim;
                leiteAbate += boi[i].leite;
            } else{
                boi[i].abate = 'n';
            }
            printf("\nboi %d - codigo: %d - abate: %c", i+1, boi[i].codigo, boi[i].abate);
        }
        printf("\n\nDigite [1] para voltar para o menu.\nDigite [0] para sair.\n");
        scanf("%d", &saida);

        } break;

        case 3:{  
        printf("\nA quantidade total de leite produzida por semana na fazenda eh: %2f", leiteTotal);

        printf("\n\nDigite [1] para voltar para o menu.\nDigite [0] para sair.\n");
        scanf("%d", &saida);
        } break;

        case 4:{
            printf("\nA quantidade total de alimento consumido por semana na fazenda eh: %2f", comida);

            printf("\n\nDigite [1] para voltar para o menu.\nDigite [0] para sair.\n");
            scanf("%d", &saida);
        } break;

        case 5:{
            printf("\nA quantidade total de leite que vai ser produzido por semana na fazenda, após o abate eh: %2f", (leiteTotal - leiteAbate));

            printf("\n\nDigite [1] para voltar para o menu.\nDigite [0] para sair.\n");
            scanf("%d", &saida);
        } break;

        case 6:{
            printf("\nA quantidade total de alimento que vai ser consumido por semana na fazenda, após o abate eh: %2f", (comida - aliAbate));

            printf("\n\nDigite [1] para voltar para o menu.\nDigite [0] para sair.\n");
            scanf("%d", &saida);
        } break;

        case 7:{
            printf("\nA quantidade de gados que vao para abate eh: %d", gado_abate);

            printf("\n\nDigite [1] para voltar para o menu.\nDigite [0] para sair.\n");
            scanf("%d", &saida);
        } break;

        case 8:{
            printf("\nVoce saiu!");
            saida = 0;
        } break;
        default:{
            printf("\nEssa opcao nao existe!");
        }
            break;
        }

    } while(saida == 1);
}

int main(){
    
    struct gado boi[BOI] = {0};

    menu(boi);

    return 0;
}