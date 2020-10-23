#include "CTBot.h"
CTBot myBot;

String ssid = "<ssid>";     // REPLACE mySSID WITH YOUR WIFI SSID
String pass = "<password>"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "<token>";   // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN
uint8_t led = 2;            // the onboard ESP8266 LED.    
                            // If you have a NodeMCU you can use the BUILTIN_LED pin
                            // (replace 2 with BUILTIN_LED)  
const int trigP = 2;  //D4 Or GPIO-2 of nodemcu
const int echoP = 0;  //D3 Or GPIO-0 of nodemcu

long duration;
int distance;
float per_dis;
String distance_1;


void setup() {
  // initialize the Serial
  Serial.begin(9600);
  Serial.println("Starting TelegramBot...");
  
  pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoP, INPUT);   // Sets the echoPin as an Input

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");

  // set the pin connected to the LED to act as output pin
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH); // turn off the led (inverted logic!)

}

void loop() {
  
       digitalWrite(trigP, LOW);   // Makes trigPin low
       delayMicroseconds(2);       // 2 micro second delay 

       digitalWrite(trigP, HIGH);  // tigPin high
       delayMicroseconds(10);      // trigPin high for 10 micro seconds
       digitalWrite(trigP, LOW);   // trigPin low

       duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
       distance= duration*0.034/2;        //Calculating actual/real distance
       distance= 122-distance;
  // a variable to store telegram message data
       TBMessage msg;
       Serial.print("\nNew data \n");
       Serial.println(distance);
	
       if (distance<=8) {        // if the received message is "LIGHT OFF"...
                                    
             myBot.sendMessage(msg.sender.id, "Alert : Petrol Bunk 1 needs to refilled"); // notify the sender
    
            }
            
	per_dis=((float)distance/122)*100;
        distance_1=String(per_dis);

  // if there is an incoming message...
  if (myBot.getNewMessage(msg)) {
    

    if (msg.text.equalsIgnoreCase("Bunk 1 Update me")) {              
                                    
      myBot.sendMessage(msg.sender.id,distance_1);  // notify the sender
    }
    
  }
  // wait 500 milliseconds
  delay(500);
}
