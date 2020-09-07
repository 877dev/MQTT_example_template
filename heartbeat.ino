void heartbeat()  // function for heartbeat check and watchdog pat
{
  //publish freeram value first of all
  MQTTclient.publish((base_mqtt_topic + "/freeram").c_str(), String(ESP.getFreeHeap()).c_str(), true);

  //if mqtt message published successfully, pat the hardware watchdog / or flash built in led
  if (MQTTclient.publish((base_mqtt_topic + "/heartbeat").c_str(), String(WiFi.RSSI()).c_str(), true))
  {
    DEBUG_PRINTLN("Heartbeat sent");
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);    
  }
}
