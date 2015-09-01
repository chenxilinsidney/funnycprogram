#include <iostream>
#include "singleton.hpp"
using namespace std;

int main()
{
    Singleton::getInstance()->display();
    Singleton::getInstance()->display();
    return 0;
}
