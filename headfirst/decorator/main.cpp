#include <iostream>
#include <string>
#include "beverage.hpp"
using namespace std;

int main()
{
    Espresso espresso;
    HouseBlend houseBlend;
    Beverage* beverage = new Mocha(espresso);
    Beverage* beverage2 = new Mocha(*beverage);
    cout << beverage->getDescription() << endl;
    cout << "cost: " << beverage->cost() << endl;
    cout << beverage2->getDescription() << endl;
    cout << "cost: " << beverage2->cost() << endl;
    return 0;
}

