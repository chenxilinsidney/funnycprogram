#ifndef _INVOKER_HPP_
#define _INVOKER_HPP_
#include <iostream>
#include "reciever.hpp"
using namespace std;

class SimpleRemoteControl
{
    public:
        SimpleRemoteControl() {
            command_ = NULL;
        }
        void setCommand(Command* command) {
            command_ = command;
        }
        void buttonPressed() {
            if (command_ != NULL)
                command_->execute();
        }
    private:
        Command* command_;
};

#endif  // _INVOKER_HPP_
