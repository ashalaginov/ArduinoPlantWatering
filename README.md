## ArduinoPlantWatering 
Simple Plant Watering on Arduino Mini, Li-ion battery, 3-6v water pump and moisture sensor

## Description
This is a simple Arduino Plant Watering stations that checks soil moisture level and runs water once in a while. Because of LowPower library usage, the station can run 1-2 months autonomously, however, water bucket should be sufficiently big. Connect int moisture sensor output pi to A0, moisture sensor VCC to 9 and VCC of water pump motor to 5th pin. During setup(), water will be running for 30 seconds for the putpose of test. Further, loop() checks soil moisture level every 3 days and waters the plant for 30 seconds if sensor value is more than 800 (out of 1024), meaning the soil is dry. Arduino will be going into power down state for 8 s with ADC and BOD module disabled, therefore, making the whole setup very much power-efficient. 

## Requirements
- Arduino IDE 1.8.12
- Arduino Mini 1.21
- Soild Moisture Sensors
- Water pump 3-6v
- Li-ion battery 3.7v
