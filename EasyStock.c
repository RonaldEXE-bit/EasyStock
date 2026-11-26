#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto estoque[MAX];
int total = 0;

void cadastrar() {
    printf("Nome do produto: ");
    scanf(" %[^\n]", estoque[total].nome);

    printf("Quantidade: ");
    scanf("%d", &estoque[total].quantidade);

    printf("Preco: ");
    scanf("%f", &estoque[total].preco);

    total++;

    printf("Produto cadastrado!\n");
}

void listar() {
    int i;

    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for(i = 0; i < total; i++) {
        printf("\nProduto: %s", estoque[i].nome);
        printf("\nQuantidade: %d", estoque[i].quantidade);
        printf("\nPreco: %.2f\n", estoque[i].preco);
    }
}

void consultar() {
    char nome[50];
    int i, achou = 0;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome);

    for(i = 0; i < total; i++) {
        if(strcmp(nome, estoque[i].nome) == 0) {
            printf("\nProduto: %s", estoque[i].nome);
            printf("\nQuantidade: %d", estoque[i].quantidade);
            printf("\nPreco: %.2f\n", estoque[i].preco);
            achou = 1;
        }
    }

    if(achou == 0) {
        printf("Produto nao encontrado.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n=== EasyStock ===\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produto\n");
        printf("3 - Consulta Produto\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar();
                break;

            case 2:
                listar();
                break;

            case 3:
                consultar();
                break;

            case 0:
                printf("EasyStock Fechado\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}