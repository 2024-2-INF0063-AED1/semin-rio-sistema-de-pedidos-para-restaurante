#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reports.h"
#include "orders.h"

// Gera relatório de itens mais vendidos
void generateTopSellingItems(MenuItem* menu) {
    if (!menu) {
        printf("Cardapio não disponível.\n");
        return;
    }

    // Cria uma cópia da lista do cardápio para ordenação
    MenuItem* sortedMenu = NULL;
    MenuItem* current = menu;

    // Copia a lista para sortedMenu
    while (current) {
        MenuItem* newItem = createMenuItem(current->id, current->name, current->price);
        newItem->salesCount = current->salesCount;
        newItem->next = sortedMenu;
        sortedMenu = newItem;
        current = current->next;
    }

    // Ordena sortedMenu por salesCount (Bubble Sort)
    int swapped;
    do {
        swapped = 0;
        MenuItem* ptr = sortedMenu;
        while (ptr && ptr->next) {
            if (ptr->salesCount < ptr->next->salesCount) {
                // Troca os dados
                int tempId = ptr->id;
                char tempName[50];
                strcpy(tempName, ptr->name);
                float tempPrice = ptr->price;
                int tempSalesCount = ptr->salesCount;

                ptr->id = ptr->next->id;
                strcpy(ptr->name, ptr->next->name);
                ptr->price = ptr->next->price;
                ptr->salesCount = ptr->next->salesCount;

                ptr->next->id = tempId;
                strcpy(ptr->next->name, tempName);
                ptr->next->price = tempPrice;
                ptr->next->salesCount = tempSalesCount;

                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);

    // Exibe os itens ordenados
    printf("\n=== Itens Mais Vendidos ===\n");
    current = sortedMenu;
    while (current) {
        printf("ID: %d | Nome: %s | Vendas: %d\n", current->id, current->name, current->salesCount);
        current = current->next;
    }

    // Libera a memória da lista copiada
    freeMenu(&sortedMenu);
}

// Gera um resumo geral do sistema
void generateSystemSummary(Order* orders, float cashRegister) {
    int totalOrders = 0, completedOrders = 0, pendingOrders = 0;
    Order* current = orders;

    while (current) {
        totalOrders++;
        if (strcmp(current->status, "Concluido") == 0) {
            completedOrders++;
        } else if (strcmp(current->status, "Pendente") == 0) {
            pendingOrders++;
        }
        current = current->next;
    }

    printf("\n=== Resumo Geral ===\n");
    printf("Total de Pedidos: %d\n", totalOrders);
    printf("Pedidos Concluidos: %d\n", completedOrders);
    printf("Pedidos Pendentes: %d\n", pendingOrders);
    printf("Total em Caixa: R$%.2f\n", cashRegister);
}
