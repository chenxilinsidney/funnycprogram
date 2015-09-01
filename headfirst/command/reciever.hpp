#ifndef _RECIEVER_HPP_
#define _RECIEVER_HPP_
#include <iostream>
#include "api.hpp"
using namespace std;
class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class OutdoorLightOnCommand : public Command
{
    OutdoorLight outdoorLight_;
public:
    OutdoorLightOnCommand(OutdoorLight& outdoorLight) :
        outdoorLight_(outdoorLight) {}
    void execute() {
        outdoorLight_.on();
    }
    void undo() {
        outdoorLight_.off();
    }
};

class LightOnCommand : public Command
{
    Light light_;
public:
    LightOnCommand(Light& light) :
        light_(light) {}
    void execute() {
        light_.on();
    }
    void undo() {
        light_.off();
    }
};
#endif  // _RECIEVER_HPP_
