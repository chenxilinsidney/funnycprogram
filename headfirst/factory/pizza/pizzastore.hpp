#ifndef _PIZZASTORE_HPP_
#define _PIZZASTORE_HPP_
#include <iostream>
#include <string>
#include "pizza.hpp"
using namespace std;
class PizzaStore
{
    public:
        Pizza* orderPizza(string type) {
            Pizza* pizza = SimplePizzaFactory::createPizza(type);
            pizza->display();
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
            return pizza;
        }
};

#endif // _PIZZASTORE_HPP_
