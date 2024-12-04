#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orders.h"
#include "reports.h"

// Funções para carregar e salvar o valor do caixa
float loadCashRegisterFromFile(const char* filename);
void saveCashRegisterToFile(float cashRegister, const char* filename);

// Exibe o menu principal
void showMenu() {
    printf("\n=== Sistema de Pedidos para Restaurante ===\n");
    printf("1. Gerenciar cardapio\n");
    printf("2. Gerenciar pedidos\n");
    printf("3. Gerar relatorios\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

// Gerencia o cardápio
void menuManagement(MenuItem** menu) {
    int option, id;
    char name[50];
    float price;

    do {
        printf("\n=== Gerenciar cardapio ===\n");
        printf("1. Adicionar item\n");
        printf("2. Exibir cardapio\n");
        printf("3. Remover item\n");
        printf("4. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        getchar(); // Consome o '\n' residual

        switch (option) {
            case 1:
                displayMenu(*menu); // Mostra o cardápio atual
                printf("Digite o ID do item: ");
                scanf("%d", &id);
                getchar(); // Consome o '\n' residual

                printf("Digite o nome do item: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove o '\n' do final

                printf("Digite o preco do item: ");
                scanf("%f", &price);
                getchar(); // Consome o '\n' residual

                addMenuItem(menu, id, name, price);
                break;
            case 2:
                displayMenu(*menu);
                break;
            case 3:
                displayMenu(*menu); // Exibe o cardápio antes de remover
                printf("Digite o ID do item a ser removido: ");
                scanf("%d", &id);
                getchar(); // Consome o '\n' residual
                removeMenuItem(menu, id);
                break;
            case 4:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (option != 4);
}

// Gerencia os pedidos
void orderManagement(Order** orders, MenuItem* menu, float* cashRegister) {
    int option;

    do {
        printf("\n=== Gerenciar pedidos ===\n");
        printf("1. Adicionar pedido\n");
        printf("2. Atualizar status de pedido\n");
        printf("3. Exibir pedidos\n");
        printf("4. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        getchar(); // Consome o '\n' residual

        switch (option) {
            case 1:
                displayMenu(menu); // Mostra o cardápio antes de adicionar um pedido
                addOrder(orders, menu);
                break;
            case 2:
                updateOrderStatus(*orders, menu, cashRegister);
                break;
            case 3:
                displayOrders(*orders);
                break;
            case 4:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (option != 4);
}

// Gera os relatórios
void generateReports(MenuItem* menu, Order* orders, float cashRegister) {
    int option;

    do {
        printf("\n=== Relatorios ===\n");
        printf("1. Itens mais vendidos\n");
        printf("2. Pedidos pendentes\n");
        printf("3. Resumo geral\n");
        printf("4. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        getchar(); // Consome o '\n' residual

        switch (option) {
            case 1:
                generateTopSellingItems(menu);
                break;
            case 2:
                listPendingOrders(orders);
                break;
            case 3:
                generateSystemSummary(orders, cashRegister);
                break;
            case 4:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (option != 4);
}

// Carrega o valor do caixa de um arquivo
float loadCashRegisterFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    float cash = 0.0;
    if (file) {
        fscanf(file, "%f", &cash);
        fclose(file);
    } else {
        printf("Arquivo de caixa '%s' nao encontrado. Iniciando caixa em R$0.00.\n", filename);
    }
    return cash;
}

// Salva o valor do caixa em um arquivo
void saveCashRegisterToFile(float cashRegister, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao salvar o caixa no arquivo '%s'.\n", filename);
        return;
    }
    fprintf(file, "%.2f\n", cashRegister);
    fclose(file);
}

// Função principal
int main() {
    MenuItem* menu = loadMenuFromFile("menu.txt");
    Order* orders = loadOrdersFromFile("orders.txt");
    float cashRegister = loadCashRegisterFromFile("cash.txt");
    int option;

    do {
        showMenu();
        scanf("%d", &option);
        getchar(); // Consome o '\n' residual

        switch (option) {
            case 1:
                menuManagement(&menu);
                break;
            case 2:
                orderManagement(&orders, menu, &cashRegister);
                break;
            case 3:
                generateReports(menu, orders, cashRegister);
                break;
            case 4:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (option != 4);

    // Salva os dados antes de sair
    saveMenuToFile(menu, "menu.txt");
    saveOrdersToFile(orders, "orders.txt");
    saveCashRegisterToFile(cashRegister, "cash.txt");

    // Libera a memória alocada
    freeMenu(&menu);
    freeOrders(&orders);

    return 0;
}
