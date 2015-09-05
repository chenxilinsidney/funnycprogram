#ifndef _OBSERVER_HPP_
#define _OBSERVER_HPP_
#include <iostream>
#include "display.hpp"
using namespace std;

class Observer
{
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};


class CurrentConditionDisplay : public Observer, public DisplayElement
{
public:
    CurrentConditionDisplay() {
        temp_ = 0.0;
        humidity_ = 0.0;
    }
    void update(float temp, float humidity, float pressure) {
        temp_ = temp;
        humidity_ = humidity;
    }
    void display() {
        cout << "Currenct Condition: " << endl;
        cout << "----- temperature: " << temp_ << "F degrees." << endl;
        cout << "-----    humidity: " << humidity_ << "\% humidity." << endl;
    }
private:
    float temp_;
    float humidity_;
};

#endif  // _OBSERVER_HPP_
