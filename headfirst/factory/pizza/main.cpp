#include <iostream>
using namespace std;
#include "pizza.hpp"
#include "pizzastore.hpp"

int main()
{
    PizzaStore* pizzastore = new ChicagoPizzaStore;
    Pizza* pizza = pizzastore->orderPizza("PepperoniPizza");
    delete pizza;
    delete pizzastore;
    pizzastore = new NYPizzaStore;
    pizza = pizzastore->orderPizza("PepperoniPizza");
    delete pizza;
    delete pizzastore;
    return 0;
}
