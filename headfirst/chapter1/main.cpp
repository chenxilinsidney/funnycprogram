#include <iostream>
#include "duck.hpp"
using namespace std;

int main()
{
    Duck* duck;
    MallardDuck mallardDuck;
    duck = &mallardDuck;
    duck->quack();
    duck->display();
    duck->fly();
    RedheadDuck redheadDuck;
    duck = &redheadDuck;
    duck->quack();
    duck->display();
    duck->fly();
    RubberDuck rubberDuck;
    duck = &rubberDuck;
    duck->quack();
    duck->display();
    duck->fly();
    return 0;
}
