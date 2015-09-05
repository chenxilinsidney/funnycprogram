#ifndef _SUBJECT_HPP_
#define _SUBJECT_HPP_
#include <iostream>
#include "observer.hpp"
#include <list>
using namespace std;

class Subject
{
public:
    virtual void registerObserver(Observer& o) = 0;
    virtual void removeObserver(Observer& o) = 0;
    virtual void notifyObserver() = 0;
    virtual ~Subject() {}
private:
};

class WeatherData : public Subject
{
public:
    WeatherData() {
        temp_ = 0.0;
        humidity_ = 0.0;
        pressure_ = 0.0;
    }
    void registerObserver(Observer& o) {
        // ignore repeat
        pObserver_.push_back(&o);
    }
    void removeObserver(Observer& o) {
        // ignore repeat
        for (list<Observer*>::iterator it = pObserver_.begin();
                it != pObserver_.end(); it++) {
            if (*it == &o) {
                // ignore repeat
                pObserver_.erase(it);
                return;
            }
        }
    }
    void notifyObserver() {
        for (list<Observer*>::iterator it = pObserver_.begin();
                it != pObserver_.end(); it++) {
            // ignore repeat
            (*it)->update(temp_, humidity_, pressure_);
        }
    }
    void setMeasurements(float temp, float humidity, float pressure) {
        temp_ = temp;
        humidity_ = humidity;
        pressure_ = pressure;
        notifyObserver();
    }
private:
    float temp_;
    float humidity_;
    float pressure_;
    list<Observer*> pObserver_;
};


#endif  // _SUBJECT_HPP_
