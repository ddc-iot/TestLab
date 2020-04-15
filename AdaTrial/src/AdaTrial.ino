/*
 * Project AdaTrial
 * Description: Trial Script for using Adafruit.io
 * Author: Brian Rashap
 * Date: 15-APR-2020
 */

#include <Adafruit_MQTT.h>

// This #include statement was automatically added by the Particle IDE. 
#include "Adafruit_MQTT/Adafruit_MQTT.h" 
#include "Adafruit_MQTT/Adafruit_MQTT_SPARK.h" 
#include "Adafruit_MQTT/Adafruit_MQTT.h" 


/************************* Adafruit.io Setup *********************************/ 
#define AIO_SERVER      "io.adafruit.com" 
#define AIO_SERVERPORT  1883                   // use 8883 for SSL 
#define AIO_USERNAME  "<username>"
#define AIO_KEY       "<key>>"


/************ Global State (you don't need to change this!) ***   ***************/ 
TCPClient TheClient; 

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details. 
Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY); 


/****************************** Feeds ***************************************/ 
// Setup a feed called <object> for publishing. 
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname> 

Adafruit_MQTT_Publish <object1> = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/<feedname1>");
Adafruit_MQTT_Publish <object2> = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/<feedname2>");

/************************ Normal Declarations ******************************/
int feed1;
int feed2;

// setup() runs once, when the device is first turned on.
void setup() {
  

}


void loop() {
  feed1 = random(1,100);
  feed2 = random(1,1000);

 if(mqtt.Update()){
  <object1>.publish(feed1); 
  <object2>.publish(feed2);
 } 
 delay(30000);
}