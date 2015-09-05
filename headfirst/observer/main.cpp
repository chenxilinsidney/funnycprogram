#include <iostream>
#include "observer.hpp"
#include "subject.hpp"
using namespace std;

int main()
{
    CurrentConditionDisplay currentConditionDisplay;
    WeatherData weatherData;
    weatherData.registerObserver(currentConditionDisplay);
    weatherData.setMeasurements(3.0, 4.0, 5.0);
    currentConditionDisplay.display();
    weatherData.setMeasurements(5.0, 4.0, 5.0);
    currentConditionDisplay.display();
    weatherData.removeObserver(currentConditionDisplay);
    weatherData.setMeasurements(5.0, 5.0, 5.0);
    currentConditionDisplay.display();
    weatherData.registerObserver(currentConditionDisplay);
    weatherData.setMeasurements(5.0, 5.0, 5.0);
    currentConditionDisplay.display();
    return 0;
}
