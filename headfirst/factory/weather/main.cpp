#include <iostream>
#include "subject.hpp"
#include "observer.hpp"

int main()
{
    WeatherData weatherData;
    CurrentConditionDisplay(&weatherData);
    weatherData.setMeasurements(3,5,6);
    return 0;
}
