#ifndef _API_H__
#define _API_H__
#include <iostream>
using namespace std;

class OutdoorLight
{
    public:
        void on() {
            cout << "OutdoorLight is on " << endl;
        }
        void off() {
            cout << "OutdoorLight is off " << endl;
        }
};

class Light
{
    public:
        void on() {
            cout << "Light is on " << endl;
        }
        void off() {
            cout << "Light is off " << endl;
        }
};
#endif  // _API_H__

