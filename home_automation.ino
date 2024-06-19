#define BLYNK_TEMPLATE_ID "TMPL6Fu65WhD"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define relay1 D0

#define BLYNK_AUTH_TOKEN "UCCl3wmr_gSTIVkXVObI5pRNPFF9_C9z"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "realme C17";
char pass[] = "12345678";

BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  Serial.print("Value received from Blynk: ");
  Serial.println(value1);
  if (value1 == 1) {
    Serial.println("Turning relay ON");
    digitalWrite(relay1, HIGH);
  } else {
    Serial.println("Turning relay OFF");
    digitalWrite(relay1, LOW); 
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);

  digitalWrite(relay1, LOW);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  Serial.println("Setup complete");
}

void loop() {
  Blynk.run();
}