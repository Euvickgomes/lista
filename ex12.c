#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTATOS 100

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int DDD;
    char numero[15];
} Telefone;

typedef struct {
    char rua[50];
    int numero;
    char complemento[30];
    char bairro[30];
    char cep[15];
    char cidade[30];
    char estado[30];
    char pais[30];
} Endereco;

typedef struct {
    char nome[50];
    char email[50];
    Endereco endereco;
    Telefone telefone;
    Data aniversario;
    char observacoes[100];
} Contato;

Contato agenda[MAX_CONTATOS];
int totalContatos = 0;

void inserirContato();
void buscaPorNome();
void buscaPorMesAniversario();
void buscaPorDiaMesAniversario();
void removeContato();
void imprimeAgenda(int opcao);
void ordenarAgenda();

int main() {
    int opcao;
    do {
        printf("\nMenu da Agenda\n");
        printf("1. Buscar por primeiro nome\n");
        printf("2. Buscar por mes de aniversario\n");
        printf("3. Buscar por dia e mes de aniversario\n");
        printf("4. Inserir pessoa\n");
        printf("5. Retirar pessoa\n");
        printf("6. Imprimir agenda\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                buscaPorNome();
                break;
            case 2:
                buscaPorMesAniversario();
                break;
            case 3:
                buscaPorDiaMesAniversario();
                break;
            case 4:
                inserirContato();
                ordenarAgenda();
                break;
            case 5:
                removeContato();
                break;
            case 6:
                printf("1. Imprimir nome, telefone e e-mail\n");
                printf("2. Imprimir todos os dados\n");
                int opcaoImprimir;
                scanf("%d", &opcaoImprimir);
                imprimeAgenda(opcaoImprimir);
                break;
            case 7:
                printf("Saindo da agenda.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    return 0;
}

void inserirContato() {
    if (totalContatos >= MAX_CONTATOS) {
        printf("Agenda cheia!\n");
        return;
    }

    Contato novoContato;

    printf("Nome: ");
    fgets(novoContato.nome, 50, stdin);
    novoContato.nome[strcspn(novoContato.nome, "\n")] = '\0'; 

    printf("E-mail: ");
    fgets(novoContato.email, 50, stdin);
    novoContato.email[strcspn(novoContato.email, "\n")] = '\0';

    printf("Endereco - Rua: ");
    fgets(novoContato.endereco.rua, 50, stdin);
    novoContato.endereco.rua[strcspn(novoContato.endereco.rua, "\n")] = '\0';

    printf("Endereco - Numero: ");
    scanf("%d", &novoContato.endereco.numero);
    getchar();

    printf("Endereco - Complemento: ");
    fgets(novoContato.endereco.complemento, 30, stdin);
    novoContato.endereco.complemento[strcspn(novoContato.endereco.complemento, "\n")] = '\0';

    printf("Endereco - Bairro: ");
    fgets(novoContato.endereco.bairro, 30, stdin);
    novoContato.endereco.bairro[strcspn(novoContato.endereco.bairro, "\n")] = '\0';

    printf("Endereco - CEP: ");
    fgets(novoContato.endereco.cep, 15, stdin);
    novoContato.endereco.cep[strcspn(novoContato.endereco.cep, "\n")] = '\0';

    printf("Endereco - Cidade: ");
    fgets(novoContato.endereco.cidade, 30, stdin);
    novoContato.endereco.cidade[strcspn(novoContato.endereco.cidade, "\n")] = '\0';

    printf("Endereco - Estado: ");
    fgets(novoContato.endereco.estado, 30, stdin);
    novoContato.endereco.estado[strcspn(novoContato.endereco.estado, "\n")] = '\0';

    printf("Endereco - Pais: ");
    fgets(novoContato.endereco.pais, 30, stdin);
    novoContato.endereco.pais[strcspn(novoContato.endereco.pais, "\n")] = '\0';

    printf("Telefone - DDD: ");
    scanf("%d", &novoContato.telefone.DDD);
    getchar();

    printf("Telefone - Numero: ");
    fgets(novoContato.telefone.numero, 15, stdin);
    novoContato.telefone.numero[strcspn(novoContato.telefone.numero, "\n")] = '\0';

    printf("Data de Aniversario (dia mes ano): ");
    scanf("%d %d %d", &novoContato.aniversario.dia, &novoContato.aniversario.mes, &novoContato.aniversario.ano);
    getchar();

    printf("Observacoes: ");
    fgets(novoContato.observacoes, 100, stdin);
    novoContato.observacoes[strcspn(novoContato.observacoes, "\n")] = '\0';

    agenda[totalContatos] = novoContato;
    totalContatos++;
    printf("Contato inserido com sucesso!\n");
}

void buscaPorNome() {
    char nome[50];
    int encontrado = 0;

    printf("Digite o primeiro nome para busca: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < totalContatos; i++) {
        if (strstr(agenda[i].nome, nome) != NULL) {
            printf("Nome: %s, Telefone: (%d) %s, E-mail: %s\n", agenda[i].nome, agenda[i].telefone.DDD, agenda[i].telefone.numero, agenda[i].email);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("Contato nao encontrado.\n");
}

void buscaPorMesAniversario() {
    int mes;
    int encontrado = 0;

    printf("Digite o mes para busca: ");
    scanf("%d", &mes);
    getchar();

    for (int i = 0; i < totalContatos; i++) {
        if (agenda[i].aniversario.mes == mes) {
            printf("Nome: %s, Telefone: (%d) %s, E-mail: %s\n", agenda[i].nome, agenda[i].telefone.DDD, agenda[i].telefone.numero, agenda[i].email);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("Nenhum contato encontrado para este mes.\n");
}

void buscaPorDiaMesAniversario() {
    int dia, mes;
    int encontrado = 0;

    printf("Digite o dia e mes para busca: ");
    scanf("%d %d", &dia, &mes);
    getchar();

    for (int i = 0; i < totalContatos; i++) {
        if (agenda[i].aniversario.dia == dia && agenda[i].aniversario.mes == mes) {
            printf("Nome: %s, Telefone: (%d) %s, E-mail: %s\n", agenda[i].nome, agenda[i].telefone.DDD, agenda[i].telefone.numero, agenda[i].email);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("Nenhum contato encontrado para esta data.\n");
}

void removeContato() {
    char nome[50];
    int encontrado = 0;

    printf("Digite o nome da pessoa a ser removida: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            encontrado = 1;
            for (int j = i; j < totalContatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            totalContatos--;
            printf("Contato removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) printf("Contato nao encontrado.\n");
}

void imprimeAgenda(int opcao) {
    for (int i = 0; i < totalContatos; i++) {
        if (opcao == 1) {
            printf("Nome: %s, Telefone: (%d) %s, E-mail: %s\n", agenda[i].nome, agenda[i].telefone.DDD, agenda[i].telefone.numero, agenda[i].email);
        } else if (opcao == 2) {
            printf("Nome: %s\nE-mail: %s\nTelefone: (%d) %s\nRua: %s, %d\nComplemento: %s\nBairro: %s\nCEP: %s\nCidade: %s\nEstado: %s\nPais: %s\nAniversario: %02d/%02d/%d\nObservacoes: %s\n\n",
                   agenda[i].nome, agenda[i].email, agenda[i].telefone.DDD, agenda[i].telefone.numero,
                   agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.complemento,
                   agenda[i].endereco.bairro, agenda[i].endereco.cep, agenda[i].endereco.cidade,
                   agenda[i].endereco.estado, agenda[i].endereco.pais,
                   agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano,
                   agenda[i].observacoes);
        }
    }
}

void ordenarAgenda() {
    Contato temp;
    for (int i = 0; i < totalContatos - 1; i++) {
        for (int j = i + 1; j < totalContatos; j++) {
            if (strcmp(agenda[i].nome, agenda[j].nome) > 0) {
                temp = agenda[i];
                agenda[i] = agenda[j];
                agenda[j] = temp;
            }
        }
    }
}


