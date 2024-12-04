#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// Cria um novo item do cardápio
MenuItem* createMenuItem(int id, const char* name, float price) {
    MenuItem* newItem = (MenuItem*)malloc(sizeof(MenuItem));
    if (!newItem) {
        printf("Erro ao alocar memoria para o item do cardapio!\n");
        exit(1);
    }
    newItem->id = id;
    strcpy(newItem->name, name);
    newItem->price = price;
    newItem->salesCount = 0; // Inicia o contador de vendas
    newItem->next = NULL;
    return newItem;
}

// Adiciona um item ao cardápio
void addMenuItem(MenuItem** menu, int id, const char* name, float price) {
    // Verifica se o ID já existe
    if (findMenuItemById(*menu, id) != NULL) {
        printf("Erro: Já existe um item com o ID %d.\n", id);
        return;
    }
    MenuItem* newItem = createMenuItem(id, name, price);
    newItem->next = *menu;
    *menu = newItem;
    printf("Item '%s' adicionado ao cardapio com sucesso!\n", name);
}

// Exibe os itens do cardápio
void displayMenu(MenuItem* menu) {
    printf("\n=== Cardapio ===\n");
    if (!menu) {
        printf("O cardapio esta vazio.\n");
        return;
    }
    while (menu) {
        printf("ID: %d | Nome: %s | Preco: R$%.2f | Vendas: %d\n", menu->id, menu->name, menu->price, menu->salesCount);
        menu = menu->next;
    }
}

// Remove um item do cardápio
void removeMenuItem(MenuItem** menu, int itemId) {
    if (*menu == NULL) {
        printf("O cardapio esta vazio. Nenhum item para remover.\n");
        return;
    }

    MenuItem* current = *menu;
    MenuItem* previous = NULL;

    while (current != NULL && current->id != itemId) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Item com ID %d nao encontrado no cardapio.\n", itemId);
        return;
    }

    if (previous == NULL) {
        // O item a ser removido é o primeiro da lista
        *menu = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Item com ID %d removido do cardapio com sucesso.\n", itemId);
}

// Libera a memória alocada para o cardápio
void freeMenu(MenuItem** menu) {
    MenuItem* current = *menu;
    while (current) {
        MenuItem* temp = current;
        current = current->next;
        free(temp);
    }
    *menu = NULL;
}

// Salva o cardápio em um arquivo
void saveMenuToFile(MenuItem* menu, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s' para escrita!\n", filename);
        return;
    }
    while (menu) {
        fprintf(file, "%d;%s;%.2f;%d\n", menu->id, menu->name, menu->price, menu->salesCount);
        menu = menu->next;
    }
    fclose(file);
}

// Carrega o cardápio de um arquivo
MenuItem* loadMenuFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Arquivo '%s' nao encontrado. Criando cardapio vazio.\n", filename);
        return NULL;
    }
    MenuItem* menu = NULL;
    int id, salesCount;
    char name[50];
    float price;
    while (fscanf(file, "%d;%49[^;];%f;%d\n", &id, name, &price, &salesCount) == 4) {
        MenuItem* item = createMenuItem(id, name, price);
        item->salesCount = salesCount;
        item->next = menu;
        menu = item;
    }
    fclose(file);
    return menu;
}

// Encontra um item do cardápio pelo ID
MenuItem* findMenuItemById(MenuItem* menu, int itemId) {
    while (menu) {
        if (menu->id == itemId) {
            return menu;
        }
        menu = menu->next;
    }
    return NULL; // Item não encontrado
}
