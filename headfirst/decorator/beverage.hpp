#ifndef _BEVERAGE_HPP_
#define _BEVERAGE_HPP_
#include <iostream>
#include <string>
using namespace std;

class Beverage
{
public:
    Beverage() {
        decription = "Unknown Beverage";
    }
    virtual string getDescription() {
        return decription;
    }
    virtual double cost() = 0;
    string decription;
private:
};

class Espresso : public Beverage
{
public:
    Espresso() {
        decription = "Espresso";
    }
    double cost() {
        return 9.9;
    }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend() {
        decription = "House Blend Coffee";
    }
    double cost() {
        return 0.89;
    }
};

class CondimentDecorator : public Beverage
{
};

class Mocha : public Beverage
{
public:
    Mocha(Beverage& beverage) {
        pbeverage_ = &beverage;
    }
    string getDescription() {
        return "Mocha" + pbeverage_->getDescription();
    }
    double cost() {
        return 0.20 + pbeverage_->cost();
    }
private:
    Beverage* pbeverage_;
};


#endif  // _BEVERAGE_HPP_

