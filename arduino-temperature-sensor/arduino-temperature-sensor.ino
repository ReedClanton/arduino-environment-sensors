/** External Import(s) **/
#include "Arduino_SensorKit.h"

/** Define Macro(s) **/
/* Assign Pin(s) */
// NoOp
/* Set What Hardware is Used */
#define USE_OLED true
#define USE_SERIAL true
#define USE_PRESSURE_SENSOR true
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
}

void loop() {
  /* Pressure Sensor */
  if (USE_PRESSURE_SENSOR) {
    outputAdd("Temp:       ", String(CelsiusToFahrenheit(Pressure.readTemperature())), " F");
    outputAdd("Pres:   ", String(Pressure.readPressure()), " Pa");
    outputAdd("Alt:   ", String(Pressure.readAltitude()), " m");
  }

  outputPublish();
  
  delay(LOOP_WAIT);
}

