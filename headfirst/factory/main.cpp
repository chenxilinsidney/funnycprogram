#include <iostream>
#include "product.hpp"
#include "factory.hpp"
using namespace std;

int main()
{
    // SoapFactory soapFactory;
    SoapBase* soapBase1 = SoapFactory::createSoap(XSL);
    soapBase1->show();
    SoapBase* soapBase2 = SoapFactory::createSoap(SFJ);
    soapBase2->show();
    SoapBase* soapBase3 = SoapFactory::createSoap(NAS);
    soapBase3->show();
    delete soapBase1;
    delete soapBase2;
    delete soapBase3;
    return 0;
}
