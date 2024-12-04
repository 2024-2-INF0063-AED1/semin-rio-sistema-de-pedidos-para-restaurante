#ifndef MENU_H
#define MENU_H


typedef struct MenuItem {
    int id;                  // Identificador único do item
    char name[50];           // Nome do item
    float price;             // Preço do item
    int salesCount;          // Número de vendas do item
    struct MenuItem* next;   // Ponteiro para o próximo item
} MenuItem;

// Funções relacionadas ao cardápio
MenuItem* createMenuItem(int id, const char* name, float price);
void addMenuItem(MenuItem** menu, int id, const char* name, float price);
void displayMenu(MenuItem* menu);
void removeMenuItem(MenuItem** menu, int itemId);
void freeMenu(MenuItem** menu);
void saveMenuToFile(MenuItem* menu, const char* filename);
MenuItem* loadMenuFromFile(const char* filename);
MenuItem* findMenuItemById(MenuItem* menu, int itemId);

#endif 
