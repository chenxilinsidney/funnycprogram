#include <iostream>
#include <list>
#include "observer.hpp"
#ifndef _SUBJECT_HPP_
#define _SUBJECT_HPP_
using namespace std;

class SubjectInterface
{
    public:
        virtual void registerObserver(ObserverInterface* o) = 0;
        virtual void removeObserver(ObserverInterface* o) = 0;
        virtual void notifyObserver() = 0;
};

class WeatherData : public SubjectInterface
{
    public:
        WeatherData() :
            temperature(0.0),
            humidity(0.0),
            pressure(0.0)
            {}
        void registerObserver(ObserverInterface* o) {
            // prevent repeat
            if (!observers.empty()) {
                for (list<ObserverInterface*>::iterator it = observers.begin();
                        it != observers.end(); it++) {
                    if (*it == o) {
                        return;
                    }
                }
            }
            // register
            observers.push_back(o);
        }
        void removeObserver(ObserverInterface* o) {
            // remove
            if (!observers.empty()) {
                for (list<ObserverInterface*>::iterator it = observers.begin();
                        it != observers.end(); it++) {
                    if (*it == o) {
                        observers.erase(it);
                        return;
                    }
                }
            }
        }
        void notifyObserver() {
            // notify
            if (!observers.empty()) {
                for (list<ObserverInterface*>::iterator it = observers.begin();
                        it != observers.end(); it++) {
                    (*it)->update(temperature, humidity, pressure);
                }
            }
        }
        void measurementsChanged() {
            notifyObserver();
        }
        void setMeasurements(float temperature, float humidity, float pressure) {
            this->temperature = temperature;
            this->humidity = humidity;
            this->pressure = pressure;
            measurementsChanged();
        }
    private:
        float temperature;
        float humidity;
        float pressure;
        list<ObserverInterface*> observers;
};

#endif  // _SUBJECT_HPP_
