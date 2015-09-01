#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_
#include <iostream>
using namespace std;
class Singleton
{
    public:
        static Singleton* getInstance() {
            if (uniqueInstance == NULL)
                uniqueInstance = new Singleton;
            return uniqueInstance;
        }
        virtual void display() {
            cout << "Singleton " << uniqueInstance << endl;
        }
    private:
        Singleton() {}
        static Singleton* uniqueInstance;
};

Singleton* Singleton::uniqueInstance = new Singleton;

#endif  // _SINGLETON_HPP_
