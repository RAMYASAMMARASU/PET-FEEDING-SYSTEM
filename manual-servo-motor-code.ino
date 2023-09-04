#define BLYNK_TEMPLATE_ID "TMPL3mnE3_HeV"
#define BLYNK_TEMPLATE_NAME "IOT PET FEEDER"
#define BLYNK_AUTH_TOKEN "41GMiGUimvlb6CVLY-2nzrcE1wrdgwAW"

#include <Servo.h>
#include <BlynkSimpleEsp8266.h>  // Use the appropriate library for your board

char auth[] = "41GMiGUimvlb6CVLY-2nzrcE1wrdgwAW";


Servo servo;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "ramya", "9014953612");



  servo.attach(4); // Use the appropriate pin for the servo
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0) // Virtual Pin 0 is the inbuilt push button in the Blynk app
{
  int buttonState = param.asInt();
  
  if (buttonState == LOW) {
    // Turn on the servo motor
    servo.write(90); // Set the servo angle to 90 degrees
    // delay(1000);
  } else {
    // Turn off the servo motor
    servo.write(0);  // Set the servo angle to 0 degrees
    delay(1000);
  }
}

