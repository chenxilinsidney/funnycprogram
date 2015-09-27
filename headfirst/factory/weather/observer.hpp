#include <iostream>
#include "subject.hpp"
#ifndef _OBSERVER_HPP_
#define _OBSERVER_HPP_
using namespace std;
class ObserverInterface
{
    public:
        virtual void update(float temp, float humidity, float pressure) = 0;
};

class DisplayInterface
{
    public:
        virtual void display() = 0;
};

class CurrentConditionDisplay : public ObserverInterface,
    public DisplayInterface
{
    private:
        float temp;
        float humidity;
        WeatherData* subject;
    public:
        CurrentConditionDisplay(WeatherData *subject) {
            this->subject = subject;
            subject->registerObserver(this);
        }
        void update(float temp, float humidity, float pressure) {
            this->temp = temp;
            temp->humidity = humidity;
            display();
        }
        void display() {
            cout << "Current Conditions: " << temp << "F degrees and "
                << humidity << "%d humidity" << endl;
        }
};

class StaticsDisplay : public ObserverInterface,
    public DisplayInterface
{
    private:
        float temp;
        float humidity;
        WeatherData* subject;
    public:
        StaticsDisplay(WeatherData *subject) {
            this->subject = subject;
            subject->registerObserver(this);
        }
        void update(float temp, float humidity, float pressure) {}
        void display() {}
};

class ForecastDisplay : public ObserverInterface,
    public DisplayInterface
{
    private:
        float temp;
        float humidity;
        WeatherData* subject;
    public:
        StaticsDisplay(WeatherData *subject) {
            this->subject = subject;
            subject->registerObserver(this);
        }
        void update(float temp, float humidity, float pressure) {}
        void display() {}
};
#endif  // _OBSERVER_HPP_
