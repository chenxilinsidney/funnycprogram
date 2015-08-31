#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_
#include <iostream>
#include "product.hpp"
using namespace std;

enum PRODUCTTYPE {SFJ, XSL, NAS};

class SoapFactory
{
public:
    static SoapBase* createSoap(PRODUCTTYPE type) {
        SoapBase* soapBase;
        switch (type) {
            case SFJ:
                soapBase = new SFJSoap;
                break;
            case XSL:
                soapBase = new XSLSoap;
                break;
            case NAS:
                soapBase = new NASSoap;
                break;
        }
        return soapBase;
    }
};
#endif  // _FACTORY_HPP_
