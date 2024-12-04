#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "orders.h"
#include "menu.h"

// Cria um novo pedido
Order* createOrder(int orderId, const char* customerName, int tableNumber, int itemId, int quantity, const char* status) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    if (!newOrder) {
        printf("Erro ao alocar memoria para o pedido!\n");
        exit(1);
    }
    newOrder->orderId = orderId;
    strcpy(newOrder->customerName, customerName);
    newOrder->tableNumber = tableNumber;
    newOrder->itemId = itemId;
    newOrder->quantity = quantity;
    strcpy(newOrder->status, status);
    newOrder->timestamp = time(NULL); // Marca o momento do pedido
    newOrder->next = NULL;
    return newOrder;
}

// Adiciona um pedido
void addOrder(Order** orders, MenuItem* menu) {
    int orderId, itemId, quantity, tableNumber;
    char customerName[50], status[20] = "Pendente";
    char inputBuffer[100];
    char* endPtr;

    // Solicita o ID do pedido, garantindo que não seja duplicado
    while (1) {
        printf("Digite o ID do pedido: ");
        scanf("%d", &orderId);
        getchar(); // Consome o '\n' residual

        if (findOrderById(*orders, orderId) != NULL) {
            printf("Erro: Ja existe um pedido com o ID %d. Selecione outro.\n", orderId);
        } else {
            break; // ID é único
        }
    }

    printf("Digite o nome do cliente: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = '\0'; // Remove o '\n' do final

    // Solicita o número da mesa com validação
    while (1) {
        printf("Digite o numero da mesa: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // Remove o '\n' do final

        tableNumber = (int)strtol(inputBuffer, &endPtr, 10);
        if (*endPtr == '\0' && inputBuffer[0] != '\0') {
            break; // Entrada válida
        } else {
            printf("Erro: Numero da mesa invalido. Por favor, digite um numero inteiro.\n");
        }
    }

    printf("Digite o ID do item do cardapio: ");
    scanf("%d", &itemId);
    getchar(); // Consome o '\n' residual

    MenuItem* item = findMenuItemById(menu, itemId);
    if (!item) {
        printf("Erro: Item com ID %d não encontrado no cardapio.\n", itemId);
        return;
    }

    printf("Digite a quantidade do item: ");
    scanf("%d", &quantity);
    getchar(); // Consome o '\n' residual

    if (quantity <= 0) {
        printf("Quantidade invalida. O pedido não foi adicionado.\n");
        return;
    }

    Order* newOrder = createOrder(orderId, customerName, tableNumber, itemId, quantity, status);
    newOrder->next = *orders;
    *orders = newOrder;

    printf("Pedido %d adicionado com sucesso para o cliente '%s' na mesa %d.\n", orderId, customerName, tableNumber);
}

// Encontra um pedido pelo ID
Order* findOrderById(Order* orders, int orderId) {
    while (orders) {
        if (orders->orderId == orderId) {
            return orders;
        }
        orders = orders->next;
    }
    return NULL; // Pedido não encontrado
}

// Lista pedidos pendentes
void listPendingOrders(Order* orders) {
    if (!orders) {
        printf("Nenhum pedido disponível.\n");
        return;
    }

    printf("\n=== Pedidos Pendentes ===\n");
    int hasPending = 0;
    Order* current = orders;
    time_t now = time(NULL);

    while (current) {
        if (strcmp(current->status, "Pendente") == 0) {
            double seconds = difftime(now, current->timestamp);
            int minutes = (int)(seconds / 60);
            int hours = minutes / 60;
            minutes = minutes % 60;
            seconds = (int)seconds % 60;

            printf("Pedido ID: %d | Cliente: %s | Mesa: %d | Item ID: %d | Quantidade: %d | Tempo Decorrido: %02dh:%02dm:%02ds\n",
                   current->orderId, current->customerName, current->tableNumber, current->itemId, current->quantity,
                   hours, minutes, (int)seconds);
            hasPending = 1;
        }
        current = current->next;
    }
    if (!hasPending) {
        printf("Não há pedidos pendentes.\n");
    }
}

// Atualiza o status de um pedido
void updateOrderStatus(Order* orders, MenuItem* menu, float* cashRegister) {
    int orderId, option;

    listPendingOrders(orders); // Exibe os pedidos pendentes

    printf("Digite o ID do pedido que deseja atualizar: ");
    scanf("%d", &orderId);
    getchar(); // Consome o '\n' residual

    Order* order = findOrderById(orders, orderId);
    if (!order) {
        printf("Erro: Pedido com ID %d não encontrado.\n", orderId);
        return;
    }

    printf("Digite 1 para marcar como 'Concluido' ou 2 para sair: ");
    scanf("%d", &option);
    getchar(); // Consome o '\n' residual

    if (option == 1) {
        strcpy(order->status, "Concluido");
        MenuItem* item = findMenuItemById(menu, order->itemId);
        if (item) {
            item->salesCount += order->quantity;            // Atualiza a contagem de vendas do item
            float totalPrice = item->price * order->quantity; // Calcula o valor total do pedido
            *cashRegister += totalPrice;                    // Adiciona o total ao caixa
            printf("Pedido %d atualizado para 'Concluido'.\n", orderId);
            printf("Valor de R$%.2f adicionado ao caixa.\n", totalPrice);
        } else {
            printf("Erro: Item do pedido nao encontrado no cardapio.\n");
        }
    } else {
        printf("Nenhuma alteracao foi feita.\n");
    }
}

// Exibe todos os pedidos
void displayOrders(Order* orders) {
    printf("\n=== Pedidos ===\n");
    if (!orders) {
        printf("Nenhum pedido registrado.\n");
        return;
    }
    time_t now = time(NULL);
    while (orders) {
        double seconds = difftime(now, orders->timestamp);
        int minutes = (int)(seconds / 60);
        int hours = minutes / 60;
        minutes = minutes % 60;
        seconds = (int)seconds % 60;

        printf("Pedido ID: %d | Cliente: %s | Mesa: %d | Item ID: %d | Quantidade: %d | Status: %s | Tempo Decorrido: %02dh:%02dm:%02ds\n",
               orders->orderId, orders->customerName, orders->tableNumber, orders->itemId, orders->quantity, orders->status,
               hours, minutes, (int)seconds);
        orders = orders->next;
    }
}

// Libera a memória alocada para os pedidos
void freeOrders(Order** orders) {
    Order* current = *orders;
    while (current) {
        Order* temp = current;
        current = current->next;
        free(temp);
    }
    *orders = NULL;
}

// Salva os pedidos em um arquivo
void saveOrdersToFile(Order* orders, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo '%s' para escrita!\n", filename);
        return;
    }
    while (orders) {
        fprintf(file, "%d;%s;%d;%d;%d;%s;%ld\n", orders->orderId, orders->customerName, orders->tableNumber, orders->itemId,
                orders->quantity, orders->status, orders->timestamp);
        orders = orders->next;
    }
    fclose(file);
}

// Carrega os pedidos de um arquivo
Order* loadOrdersFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Arquivo '%s' nao encontrado. Criando lista de pedidos vazia.\n", filename);
        return NULL;
    }
    Order* orders = NULL;
    int orderId, itemId, quantity, tableNumber;
    char customerName[50], status[20];
    time_t timestamp;
    while (fscanf(file, "%d;%49[^;];%d;%d;%d;%19[^;];%ld\n", &orderId, customerName, &tableNumber, &itemId, &quantity, status, &timestamp) == 7) {
        Order* newOrder = createOrder(orderId, customerName, tableNumber, itemId, quantity, status);
        newOrder->timestamp = timestamp; // Restaura o timestamp
        newOrder->next = orders;
        orders = newOrder;
    }
    fclose(file);
    return orders;
}
