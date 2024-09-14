#include <stdio.h>
#include <string.h>

#define MAX_ITENS 3
#define NOME_MAX 50

char carrinho[MAX_ITENS][NOME_MAX];
int totalItens = 0;

// Verifica se o carrinho está cheio
int carrinhoCheio() {
    return totalItens >= MAX_ITENS;
}

// Adicionando um item ao carrinho
void adicionarItem(const char *nome) {
    if (carrinhoCheio()) {
        printf("----------------\n");
        printf(" CARRINHO CHEIO!\n");
        printf("----------------\n");

        return;
    }
    
    // Ver se já está no carrinho
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(carrinho[i], nome) == 0) {
            printf("-------------------------------\n");
            printf(" Item '%s' já está no carrinho.\n", nome);
            printf("-------------------------------\n");

            return;
        }
    }
    
    // Adicionar item no carrinho
    strcpy(carrinho[totalItens], nome);
    totalItens++;
    printf("Item '%s' adicionado ao carrinho.\n", nome);
}

// Para remover um item
void removerItem(const char *nome) {
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(carrinho[i], nome) == 0) {
            // Remove o item e desloca os itens subsequentes
            for (int j = i; j < totalItens - 1; j++) {
                strcpy(carrinho[j], carrinho[j + 1]);
            }
            totalItens--;
            printf("--------------------------------\n");
            printf(" Item '%s' removido do carrinho.\n", nome);
            printf("--------------------------------\n");

            return;
        }
    }
    printf("Item '%s' não encontrado no carrinho.\n", nome);
}

// Procurando um item no carrinho
void buscarItem(const char *nome) {
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(carrinho[i], nome) == 0) {
            printf("Item '%s' encontrado no carrinho.\n", nome);
            return;
        }
    }
    printf("Item '%s' não encontrado no carrinho.\n", nome);
}

// Listando os itens do carrinho 
void listarItens() {
    if (totalItens == 0) {
        printf("O carrinho está vazio.\n");
        return;
    }
    printf("Itens no carrinho:\n");
    for (int i = 0; i < totalItens; i++) {
        printf("%d. %s\n", i + 1, carrinho[i]);
    }
}

int main() {
    int opcao;
    char nome[NOME_MAX];

    do {
        printf("\n--- Menu do Carrinho de Compras ---\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Buscar item\n");
        printf("4. Listar itens\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("Digite o nome do item: ");
                fgets(nome, NOME_MAX, stdin);
                nome[strcspn(nome, "\n")] = 0; // Essa linha é para ajeitar a formatação da saída
                adicionarItem(nome);
                break;
            case 2:
                printf("Digite o nome do item a ser removido: ");
                fgets(nome, NOME_MAX, stdin);
                nome[strcspn(nome, "\n")] = 0;  
                removerItem(nome);
                break;
            case 3:
                printf("Digite o nome do item a ser buscado: ");
                fgets(nome, NOME_MAX, stdin);
                nome[strcspn(nome, "\n")] = 0;  
                buscarItem(nome);
                break;
            case 4:
                listarItens();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
