#include <iostream>
using namespace std;
#include "pizza.hpp"
#include "pizzastore.hpp"

int main()
{
    PizzaStore pizzastore;
    Pizza* pizza = pizzastore.orderPizza("PepperoniPizza");
    delete pizza;
    return 0;
}
