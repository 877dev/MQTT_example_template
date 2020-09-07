void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  // Add support for OTA***************************************
  ArduinoOTA.onError([](ota_error_t error) {
    ESP.restart();
  });
  ArduinoOTA.setHostname(client_id);
  // No authentication by default
  ArduinoOTA.setPassword(ota_pass);  //password defined in secret credentials file (also see 1Password)
  ArduinoOTA.begin();  /* setup the OTA server */
  // **********************************************************

}
