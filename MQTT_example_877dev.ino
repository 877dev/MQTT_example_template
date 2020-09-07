//Debugging
#define DEBUG //  <--------------Enable disable debug serial prints - comment out this line only
#ifdef  DEBUG
#define DEBUG_PRINT(x)      Serial.print (x)
#define DEBUG_PRINTLN(x)    Serial.println (x)
#define DEBUG_PRINTLNHEX(x) Serial.println (x, HEX)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINTLNHEX(x)
#endif


//Libraries
#include <PubSubClient.h>       // https://github.com/knolleary/pubsubclient
#include <ESP8266mDNS.h>        //for OTA updates
#include <WiFiUdp.h>            //for OTA updates
#include <ArduinoOTA.h>         //for OTA updates
#include <ESP8266WiFi.h>        //connection to WiFi, better for WiFi reconnects

#include "Secret_credentials.h" //***********Add your credentials here***********

//Wifi
char ssid[] = mySSID;             //Enter your WIFI Name
char pass[] = myPASSWORD;         //Enter your WIFI Password
char ota_pass[] = myOTApassword;  //Enter your Arduino OTA password here

//MQTT stuff******************************************************************************************************************************************************************
// MQTT Server Setting variables...
IPAddress mqtt_server_ip          myMqttIP;                      // Change to the IP Address for your MQTT Server...
const int mqtt_port =             myMqttPort;                    // Port for the MQTT Server...
const char *mqtt_username =       myMqttUser;                    // Change to your MQTT Server username...
const char *mqtt_password =       myMqttPassword;                // Change to your MQTT Server password...
String mqtt_client_id =           "Wemos_001_test";              // Used for unique MQTT Client ID
String base_mqtt_topic =          "test/wemos_001";              // Start of the MQTT Topic name used by this device
int mqtt_connect_count;                                          // Count of how may times we've connected to the MQTT server since booting (should always be 1 or more)
//
WiFiClient My_WiFi_Client;
PubSubClient MQTTclient(My_WiFi_Client);
//******************************************************************************************************************************************************************************


char *client_id = "Wemos_001_test"; // Used for OTA hostname - see if can combine with mqtt_client_id

//Setup variables for heartbeat
int interval = 5000;
unsigned long previousMillis = 0;
