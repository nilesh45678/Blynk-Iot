//create by nilesh45678

//Replace with your blynk cred
#define BLYNK_TEMPLATE_ID           "Replace"
#define BLYNK_TEMPLATE_NAME         "Replace"
#define BLYNK_AUTH_TOKEN            "Replace"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Replace with your wifi ssid and Password...
char ssid[] = "Replace";
char pass[] = "Replace";

#define DHTPIN 2          // connect to D4 pin
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  //Check your virtual pins 
  Blynk.virtualWrite(V1, h);   
  Blynk.virtualWrite(V0, t);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();

  //This function is to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
