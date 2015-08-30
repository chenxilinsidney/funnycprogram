#include <iostream>
#include "duck.hpp"
using namespace std;

int main()
{
    FlyBehavior *flyBehavior = new FlyNoWay();
    QuackBehavior *quackBehavior = new Quack();
    MallardDuck* mallardDuck = new MallardDuck(*flyBehavior, *quackBehavior);
    Duck* duck = mallardDuck;
    duck->performfly();
    duck->display();
    duck->performQuack();
    return 0;
}
