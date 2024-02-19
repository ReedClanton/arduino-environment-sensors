/** External Import(s) **/
#include <Adafruit_AHTX0.h>
#include <Arduino_SensorKit.h>

/** Define Macro(s) **/
/* Assign Pin(s) */
// NoOp
/* Configuration Value(s) */
#define LOOP_WAIT 1000
#define SERIAL_BAUD 115200
/* Default Value(s) */
// NoOp

/** Local Import(s) **/
// NoOp

/** Global Variable(s) **/
Adafruit_AHTX0 aht;


void setup() {
  // Serial setup.
  Serial.begin(SERIAL_BAUD);

  // Temperature & humidity setup.
  if (! aht.begin()) {
    Serial.println("#*# Could not find AHT? Check wiring...");
	while (1) delay(10);
  }
  Serial.println("#*# AHT10 or AHT20 found.");

  // Pressure, temperature, & altitude setup.
  if (! Pressure.begin()) {
    Serial.println("#*# Could not initialize pressure sensor...");
	while (1) delay(10);
  }
  Serial.println("#*# Pressure sensor initialized.");
}

void loop() {
  // Get sensor data from first sensor set.
  sensors_event_t ahtx0_humidity, ahtx0_temp;
  aht.getEvent(&ahtx0_humidity, &ahtx0_temp);
  // Get sensor data from second sensor set.
  float bmp280_temp = Pressure.readTemperature();
  // Error check temperature readings.
  String temp;
  if ((ahtx0_temp.temperature > bmp280_temp && ahtx0_temp.temperature > bmp280_temp * 1.1) || (ahtx0_temp.temperature < bmp280_temp && ahtx0_temp.temperature * 1.1 < bmp280_temp)) {
    temp = String("ERR");
  } else {
    // Take the average.
    temp = String((bmp280_temp + ahtx0_temp.temperature) / 2);
  }
  // Publish sensor data.
  Serial.println(temp + " C");
  Serial.println(String(ahtx0_humidity.relative_humidity) + " % rH");
  Serial.println(String(Pressure.readPressure()) + " Pa");
  Serial.println(String(Pressure.readAltitude()) + " m");

  delay(LOOP_WAIT);
}

