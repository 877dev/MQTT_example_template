void setup()
{
  Serial.begin(115200);    // This is the native baud rate of most NodeMCUs, using this baud rate you will be able to see MCU and Debug messages in the serial monitor

  setup_wifi(); //connect to wifi and start OTA server

  //MQTT setup and connect
  MQTTclient.setServer(mqtt_server_ip, mqtt_port); //setup MQTT broker information as defined earlier
  MQTTclient.setCallback(MQTTcallback);            // set callback details - this function is called automatically whenever a message arrives on a subscribed topic (a bit like BLYNK_WRITE)
  MQTT_Connect();                                  //Connect to MQTT broker, publish Status/MAC/count, and subscribe to keypad topic


  //Optional print free memory 
  DEBUG_PRINTLN(mqtt_client_id); //MQTT changed to "client_id)
  DEBUG_PRINTLN("Free RAM: ");
  DEBUG_PRINT(ESP.getFreeHeap());
  DEBUG_PRINTLN(" bytes");
  DEBUG_PRINTLN("Publish topic is:" +base_mqtt_topic +"/incomingTopic");

  //Optional watchdog function
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, HIGH);  // turn off the LED

}
