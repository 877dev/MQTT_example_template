void MQTTcallback(char* topic, byte* payload, unsigned int length)
{
  // This gets called when a message arrives on one of the subscribed topics.
  // If you're sending messages and nothing happens then you probably forgot to subscribe to the topic in the MQTT_Connect function
  DEBUG_PRINTLN("MQTT arrived");
  DEBUG_PRINT("[");
  DEBUG_PRINT(topic);           //only print topic when debug is enabled, as it's the only topic subscribed to anyway.
  DEBUG_PRINTLN("]");

  //The below shows the received string in serial/Blynk terminal
  DEBUG_PRINT(" [");
  for (int i = 0; i < length; i++)
  {
    DEBUG_PRINT((char)payload[i]);
  }
  DEBUG_PRINTLN("]");

  // Convert the byte* payload array into a char array called trimmed_payload...
  char trimmed_payload[length + 1];                           // Extra character needed for the terminating nul character
  memset(trimmed_payload, 0, sizeof(trimmed_payload));        // Clear the contents
  memcpy(trimmed_payload, payload, length);                   // Copy the MQTT payload to trimmed_payload

  // This is my standard way of handling incoming M<QTT messages as strings
  // Still needed to allow thye if statement below to work...
  String msg_topic = String((char *)topic);
  String msg_payload = String((char *)payload);
  msg_payload.remove(length); // Trim any unwanted characters off the end of the string

  // We now have two string variables, 'msg_topic' and 'msg_payload' that we can use in 'if' statements below...

  // This processes a message that comes in on the .../keypad topic
  if (msg_topic == base_mqtt_topic + "/incomingTopic")
  {
    //send to some function:
    filter(trimmed_payload, length); // Pass the raw payload to the filter function
  }

  // Handle messages from other topics in here,
  // just like we did with the CMD topic above.
  // DON'T FORGET to subscribe to the topic in void MQTT_Connect()

} // End of void MQTTcallback
