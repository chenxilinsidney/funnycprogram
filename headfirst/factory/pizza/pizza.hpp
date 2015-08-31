#ifndef _PIZZA_HPP_
#define _PIZZA_HPP_
#include <iostream>
using namespace std;
class Pizza
{
    public:
        virtual void display() = 0;
        virtual void prepare() {
            cout << "Pizza prepared" << endl;
        }
        virtual void bake() {
            cout << "Pizza bake" << endl;

        }
        virtual void cut() {
            cout << "Pizza cut" << endl;

        }
        virtual void box() {
            cout << "Pizza box" << endl;

        }
        virtual ~Pizza() {}
};

class CheessePizza : public Pizza
{
    public:
        void display() {
            cout << "This is a CheessePizza" << endl;
        }
};

class GreekPizza : public Pizza
{
    public:
        void display() {
            cout << "This is a GreekPizza" << endl;
        }
};

class PepperoniPizza : public Pizza
{
    public:
        void display() {
            cout << "This is a PepperoniPizza" << endl;
        }
};

class SimplePizzaFactory
{
    public:
        static Pizza* createPizza(string type) {
            Pizza* pizza = NULL;
            if (type == "CheessePizza")
                pizza = new CheessePizza;
            else if (type == "PepperoniPizza")
                pizza = new PepperoniPizza;
            else
                pizza = new GreekPizza;
            return pizza;
        }
};
#endif  // _PIZZA_HPP_
