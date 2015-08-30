#include <iostream>
using namespace std;

class FlyBehavior
{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly() {
        cout << "I am flying" << endl;
    }
};

class FlyRocketPowered : public FlyBehavior
{
public:
    void fly() {
        cout << "I am flying with rocket" << endl;
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly() {
        cout << "I can not fly" << endl;
    }
};

class QuackBehavior
{
public:
    virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
    void quack() {
        cout << "Quack" << endl; 
    }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() {
        cout << "Silent" << endl; 
    }
};

class Squeak : public QuackBehavior
{
public:
    void quack() {
        cout << "Squeak" << endl; 
    }
};

class Duck
{
public:
    Duck(FlyBehavior& flyBehavior, QuackBehavior& quackBehavior) {
        this->pflyBehavior = &flyBehavior;
        this->pquackBehavior = &quackBehavior;
    }
    void setFlyBehavior(FlyBehavior& flyBehavior) {
        this->pflyBehavior = &flyBehavior;
    }
    void setQuackBehavior(QuackBehavior& quackBehavior) {
        this->pquackBehavior = &quackBehavior;
    }
    void performfly() {
        if (pflyBehavior != NULL)
            pflyBehavior->fly();
    }
    void performQuack() {
        if (pquackBehavior != NULL)
        pquackBehavior->quack();
    }
    virtual void display() = 0;
    void swim() {
        cout << "I can swim" << endl;
    }
private:
    FlyBehavior* pflyBehavior;
    QuackBehavior* pquackBehavior;
};

class MallardDuck : public Duck
{
public:
    MallardDuck(FlyBehavior& flyBehavior, QuackBehavior& quackBehavior) :
    Duck(flyBehavior, quackBehavior){}
    void display() {
        cout << "I am green" << endl;
    }
};

class RedheadDuck : public Duck
{
public:
    RedheadDuck(FlyBehavior& flyBehavior, QuackBehavior& quackBehavior) :
    Duck(flyBehavior, quackBehavior){}
    void display() {
        cout << "I am red" << endl;
    }
};

class RubberDuck : public Duck
{
public:
    RubberDuck(FlyBehavior& flyBehavior, QuackBehavior& quackBehavior) :
    Duck(flyBehavior, quackBehavior){}
    void display() {
        cout << "I am rubber" << endl;
    }
};

