
#include <assert.h>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

// Define a type alias for the message handler
using MessageHandler = function<void(const string&)>;

// Centralized print function
void printMessage(const string& message) {
  cout << message << endl;
}

bool isTemperatureOk(float temperature, MessageHandler handler) {
  if (temperature < 0 || temperature > 45) {
    handler("Temperature out of range!");
    return false;
  }
  return true;
}

bool isSocOk(float soc, MessageHandler handler) {
  if (soc < 20 || soc > 80) {
    handler("State of Charge out of range!");
    return false;
  }
  return true;
}

bool isChargeRateOk(float chargeRate, MessageHandler handler) {
  if (chargeRate > 0.8) {
    handler("Charge Rate out of range!");
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate, MessageHandler handler) {
  return isTemperatureOk(temperature, handler) &&
         isSocOk(soc, handler) &&
         isChargeRateOk(chargeRate, handler);
}

int main() {
  // You can replace printMessage with a lambda or another handler if needed
  assert(batteryIsOk(25, 70, 0.7, printMessage) == true);
  assert(batteryIsOk(50, 85, 0, printMessage) == false);
}
