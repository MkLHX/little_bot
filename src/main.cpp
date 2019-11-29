#include <Arduino.h>
#include <SparkFun_TB6612.h>

// # Ultrasonic pin
#define trigPin A5
#define echoPin A4

long get_distance()
{
	long duration, dist;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	dist = (duration / 2) / 29.1;
	return dist;
}

void setup()
{
	// put your setup code here, to run once:
	Serial.begin(115200);

	// # Ultrasonic init
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void loop()
{
	// put your main code here, to run repeatedly:
	long distance = get_distance();

	Serial.println("distance is: " + String(distance));

	while(distance >= 140){
		// go forward
	}

	if(distance < 5){
		// go backward
	}

	delay(200);
}