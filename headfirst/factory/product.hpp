#ifndef _PRODUCT_HPP_
#define _PRODUCT_HPP_
#include <iostream>
using namespace std;

class SoapBase
{
public:
    virtual ~SoapBase() {}
    virtual void show() = 0;
};

class SFJSoap : public SoapBase
{
public:
    void show() {
        cout << "SFJ Soap!" << endl;
    }
};

class XSLSoap : public SoapBase
{
public:
    void show() {
        cout << "XSL Soap!" << endl;
    }
};

class NASSoap : public SoapBase
{
public:
    void show() {
        cout << "NAS Soap!" << endl;
    }
};
#endif  // _PRODUCT_HPP_
