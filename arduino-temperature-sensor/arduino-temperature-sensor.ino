/** External Import(s) **/
#include "Arduino_SensorKit.h"

/** Define Macro(s) **/
/* Assign Pin(s) */
// NoOp
/* Set What Hardware is Used */
#define USE_OLED true
#define USE_SERIAL true
#define USE_PRESSURE_SENSOR true
#define USE_TEMPERATURE_SENSOR false // TODO: Figure out why it doesn't work.
/* Configuration Value(s) */
#define LOOP_WAIT 0
/* Default Value(s) */
// NoOp

/** Custom Import(s) **/
#include "output.h"
#include "math.h"

/** Global Variable(s) **/
// NoOp


void setup() {
  /* Output Setup */
  outputSetup(USE_OLED, USE_SERIAL);

  /* Input Setup */
  // NoOp

  /* Sensor Setup */
  if (USE_PRESSURE_SENSOR) { Pressure.begin(); }
  if (USE_TEMPERATURE_SENSOR) { Environment.begin(); }
}

void loop() {
  /* Pressure Sensor */
  if (USE_PRESSURE_SENSOR) {
    outputAdd("Temp:       ", String(CelsiusToFahrenheit(Pressure.readTemperature())), " F");
    outputAdd("Pres:   ", String(Pressure.readPressure()), " Pa");
    outputAdd("Alt:   ", String(Pressure.readAltitude()), " m");
  }

  /* Temperature Sensor */
  if (USE_TEMPERATURE_SENSOR) {
    outputAdd("Temp:    ", String(Environment.readTemperature()), " C");
    outputAdd("Humidity: ", String(Environment.readHumidity()), " %");
  }

  outputPublish();
  
  delay(LOOP_WAIT);
}

