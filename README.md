# Compactible level measurement and forewarning in Petrol Bunk using Telegram

## Introduction

Let us consider a town having at least 10 petrol filling stations and for sure there will be a zonal head or manager who monitors and manages the oil supply to this fuel stations.The petrol level in the container is measured by some classic methods and the measured data is known only to the petrol station dealer and communicated to the manager through normal phone call and Petrol is refilled.The actual problem is when the demand increases and fuel gets exhausted. There may also delay in refill due to some truck delay struck in Traffic or due to some improper communication.To overcome this and to introduce automation we came up with this product idea.

Our aim is to design a product which measures the level of petrol using sensor and communicate the measured quantity through interactive Telegram bot to know the dynamic change in the real time to the manager and make quick the process of refills.The objective of this model is to make a compact level measurement device to measure the Petrol in petrol bunks using ultrasonic sensor.The measured data is communicated through creating Interactive bot in Telegram. 

## Components :

- NodeMCU ( ESP8266 )
- Ultrasonic sensor ( HC - SR04 )
- Telegram App

## Connections :

- Vcc pin of Ultrasonic sensor to 3V3 pin
- Gnd pin of Ultrasonic sensor to Gnd pin of nodeMCU
- Echo pin to D3 pin of nodeMCU
- Trig pin to D4 pin of nodeMCU

## Sample Output

<img src="https://user-images.githubusercontent.com/64604283/97111427-b772e380-1704-11eb-8891-e1a2cea91d4e.jpeg" alt="Telegram Bot" width="400" height="600">


