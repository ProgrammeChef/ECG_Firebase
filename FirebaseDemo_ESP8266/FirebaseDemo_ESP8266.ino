
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "heart-rate-monitor-2020.firebaseio.com"
#define FIREBASE_AUTH "cJejQOohtesma5CySjSMX5O2yB7Bi5VbZMnBzzvh"
//#define WIFI_SSID "Friends"
//#define WIFI_PASSWORD "zewail@mao"

#define WIFI_SSID "mimokh"
#define WIFI_PASSWORD "@!l!@Nz2016"


void setup() {
  Serial.begin(9600);


  
  pinMode(D1, INPUT); // Setup for leads off detection LO +
  pinMode(D2, INPUT); // Setup for leads off detection LO -


  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int val;
String message="";

void loop() {
  for (int i =0; i<512;i++)
  {
/*
    if((digitalRead(D1) == 1)||(digitalRead(D2) == 1))
    {
     message+=String('!')+String(',');
    }
    else
    {*/
    // send the value of analog input 0:
    val=analogRead(A0);
    Serial.println(val);
    message+=String(val)+String(',');
  //  }
   delay(4);
   }
  
  Firebase.pushString("message", message);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  message="";
  
}
