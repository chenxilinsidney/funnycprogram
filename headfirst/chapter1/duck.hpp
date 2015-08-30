#include <iostream>
using namespace std;

class Duck
{
public:
    virtual void quack() {
        cout << "I can quack" << endl;
    }
    virtual void swim() {
        cout << "I can swim" << endl;
    }
    virtual void display() = 0;
    virtual void fly() {
        cout << "I can fly" << endl;
    }
};

class MallardDuck : public Duck
{
public:
    void display() {
        cout << "I am green" << endl;
    }
};

class RedheadDuck : public Duck
{
public:
    void display() {
        cout << "I am red" << endl;
    }
    void fly() {
    }
};

class RubberDuck : public Duck
{
public:
    void display() {
        cout << "I am rubber" << endl;
    }
    void quack() {
        cout << "I can not quack:zizi" << endl;
    }
};

