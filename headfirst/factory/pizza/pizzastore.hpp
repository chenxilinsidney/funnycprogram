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
            Pizza* pizza = createPizza(type);
            pizza->display();
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
            return pizza;
        }
        virtual Pizza* createPizza(string type) = 0;
        virtual ~PizzaStore() {}
};

class NYPizzaStore : public PizzaStore
{
    public:
        Pizza* createPizza(string type) {
            Pizza* pizza = NULL;
            if (type == "CheessePizza")
                pizza = new NYCheessePizza;
            else if (type == "PepperoniPizza")
                pizza = new NYPepperoniPizza;
            else if (type == "GreekPizza")
                pizza = new NYGreekPizza;
            return pizza;
        }
};

class ChicagoPizzaStore : public PizzaStore
{
    public:
        Pizza* createPizza(string type) {
            Pizza* pizza = NULL;
            if (type == "CheessePizza")
                pizza = new ChicagoCheessePizza;
            else if (type == "PepperoniPizza")
                pizza = new ChicagoPepperoniPizza;
            else if (type == "GreekPizza")
                pizza = new ChicagoGreekPizza;
            return pizza;
        }
};

#endif // _PIZZASTORE_HPP_
