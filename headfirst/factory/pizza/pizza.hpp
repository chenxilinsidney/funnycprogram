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

class NYCheessePizza : public CheessePizza
{
    public:
        void display() {
            cout << "This is a NYCheessePizza" << endl;
            CheessePizza::display();
        }
};

class NYGreekPizza : public GreekPizza
{
    public:
        void display() {
            cout << "This is a NYGreekPizza" << endl;
            GreekPizza::display();
        }
};

class NYPepperoniPizza : public PepperoniPizza
{
    public:
        void display() {
            cout << "This is a NYPepperoniPizza" << endl;
            PepperoniPizza::display();
        }
};

class ChicagoCheessePizza : public CheessePizza
{
    public:
        void display() {
            cout << "This is a ChicagoCheessePizza" << endl;
            CheessePizza::display();
        }
};

class ChicagoGreekPizza : public GreekPizza
{
    public:
        void display() {
            cout << "This is a ChicagoGreekPizza" << endl;
            GreekPizza::display();
        }
};

class ChicagoPepperoniPizza : public PepperoniPizza
{
    public:
        void display() {
            cout << "This is a ChicagoPepperoniPizza" << endl;
            PepperoniPizza::display();
        }
};
#endif  // _PIZZA_HPP_
