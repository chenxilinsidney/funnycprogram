#include <iostream>
#include "reciever.hpp"
#include "invoker.hpp"
using namespace std;

int main()
{
    Light lightA;
    LightOnCommand lightOnCommand(lightA);
    OutdoorLight outdoorLight;
    OutdoorLightOnCommand outdoorLightOnCommand(outdoorLight);
    SimpleRemoteControl simpleRemoteControl;
    simpleRemoteControl.setCommand(&lightOnCommand);
    simpleRemoteControl.buttonPressed();
    simpleRemoteControl.setCommand(&outdoorLightOnCommand);
    simpleRemoteControl.buttonPressed();
    return 0;
}
