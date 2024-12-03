#ifndef REPORTS_H
#define REPORTS_H

#include "menu.h"
#include "orders.h"

// Funções de relatórios
void generateTopSellingItems(MenuItem* menu);
void generateSystemSummary(Order* orders, float cashRegister);

#endif 
