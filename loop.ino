void loop ()
{
  // Add support for OTA***************************************
  ArduinoOTA.handle();
  // **********************************************************

  //MQTT processing
  if (!MQTTclient.connected())     // Note that MQTTclient.connected() will still return 'true' until the MQTT keepalive timeout has expired (around 35 seconds for my setup)
  {
    MQTT_Connect();
    //any other code which runs regardless of mqtt connection here
  }

  MQTTclient.loop();  //call this frequently

  //Manage heartbeat function timing
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis;
    heartbeat();
  }


  //any other code which only runs when mqtt connected here:

}
