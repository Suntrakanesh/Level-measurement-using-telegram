# Compactible level measurement and forewarning in Petrol Bunk using Telegram

## Introduction

Let us consider a town having at least 10 petrol filling stations and for sure there will be a zonal head or manager who monitors and manages the oil supply to this fuel stations.The petrol level in the container is measured by some classic methods and the measured data is known only to the petrol station dealer and communicated to the manager through normal phone call and Petrol is refilled.The actual problem is when the demand increases and fuel gets exhausted. There may also delay in refill due to some truck delay struck in Traffic or due to some improper communication.To overcome this and to introduce automation we came up with this product idea.

Our aim is to design a product which measures the level of petrol using sensor and communicate the measured quantity through interactive Telegram bot to know the dynamic change in the real time to the manager and make quick the process of refills. 

## Components :

- NodeMCU ( ESP8266 )
- Ultrasonic sensor ( HC - SR04 )
- Telegram App

## Connections :

- Vcc pin of Ultrasonic sensor to 3V3 pin
- Gnd pin of Ultrasonic sensor to Gnd pin of nodeMCU
- Echo pin to D3 pin of nodeMCU
- Trig pin to D4 pin of nodeMCU

## Working :

Here Ultrasonic sensor is used to measure the level of the petrol in particular petrol bunk. Ultrasonic sensor is widely used contactless distance measurement device. It is fixed at the top of the storage tank. It will send an ultrasonic wave which in turn hit on the surface of petrol and bounce back to sensor. The speed of the ultrasonic wave is constant, and time taken by wave to bounce back is directly proportional to distance. By this methodology, the level of the fuel is measured. Here, one needs to note that the distance measured is the air-gap of fuel tank , not a actual level of the fuel. In order to measure the level of the fuel , the mesured value should be subracted from entire depth of storage tank. For that , I have included this statement `distance= 122-distance` in arduino sketch. Here, I have assumed that the entire depth of tank is 122 cm. We need to change this value based on requirement. And, unique feature of our project is , user can get the update of any petrol bunk at any instant. This if statement `if (msg.text.equalsIgnoreCase("Bunk 1 Update me"))` is responsible for it. Whenever the user needs to get the update of level of petrol bunk, he/she needs to chat in the telegram bot as " Bunk 1 Update me ". This message is received by the nodeMCU and execute the above mentioned if statement. Then, the sensor will detect the level of the petrol , and send back the reply in telegram bot. Here, we need to name the petrol bunk. For instance, I have named it as Bunk 1. Likewise, if we chat as " Bunk 2 Update me ", then Bunk 2 will send the reply. In addition to that, whenever the level of petrol is below the certain value , the nodeMCU will send an automatic alert message to bot along with the name of the petrol bunk.  This statement`if (distance<=8)` can do it. Here , I have assumed the threshold value to be 8 cm. We can change it accordingly.

## Visit this website to create the telegram bot : <a href="https://core.telegram.org/bots" target="_blank">
  <img align="center" alt="Creating the telegram bot" width="80px" src="https://user-images.githubusercontent.com/64604283/97112738-f2c4e080-170b-11eb-99cb-6d6250e2798b.png" />
</a><br/>


## Sample Output

<img src="https://user-images.githubusercontent.com/64604283/97111427-b772e380-1704-11eb-8891-e1a2cea91d4e.jpeg" alt="Telegram Bot" width="400" height="600">

## License

MIT © [Suntrakanesh](https://github.com/Suntrakanesh/Level-measurement-using-telegram/blob/main/LICENSE)


