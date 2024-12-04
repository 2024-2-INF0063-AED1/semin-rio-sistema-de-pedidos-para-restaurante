#ifndef ORDERS_H
#define ORDERS_H

#include "menu.h"
#include <time.h>

// Estrutura para os pedidos
typedef struct Order {
    int orderId;             // Número do pedido
    char customerName[50];   // Nome do cliente
    int tableNumber;         // Número da mesa
    int itemId;              // ID do item do cardápio
    int quantity;            // Quantidade do item
    char status[20];         // Status do pedido
    time_t timestamp;        // Momento em que o pedido foi feito
    struct Order* next;      // Ponteiro para o próximo pedido
} Order;

// Funções relacionadas aos pedidos
Order* createOrder(int orderId, const char* customerName, int tableNumber, int itemId, int quantity, const char* status);
void addOrder(Order** orders, MenuItem* menu);
Order* findOrderById(Order* orders, int orderId);
void updateOrderStatus(Order* orders, MenuItem* menu, float* cashRegister);
void displayOrders(Order* orders);
void freeOrders(Order** orders);
void saveOrdersToFile(Order* orders, const char* filename);
Order* loadOrdersFromFile(const char* filename);
void listPendingOrders(Order* orders);

#endif 
