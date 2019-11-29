#include <Arduino.h>
#include <SparkFun_TB6612.h>

// # Ultrasonic Sensor
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

// # Motor
#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 9

const int offsetA = 1;
const int offsetB = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void go_forward(int speed = 150)
{
	forward(motor1, motor2, speed);
}

void go_backward(int speed = -150)
{
	back(motor1, motor2, speed);
}

void go_left(int speed = 150)
{
	left(motor1, motor2, speed);
}

void go_right(int speed = 150)
{
	right(motor1, motor2, speed);
}

void break_all()
{
	brake(motor1, motor2);
}

int randomized()
{
	return rand() % 100;
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

	// go forward
	while (get_distance() >= 140)
	{
		Serial.println("everything is ok!, i'm walking");
		go_forward();
		delay(250);
	}

	// go backward
	if (get_distance() < 5)
	{
		Serial.println("uuuuaaaaahhhhhhh there is a monster! runaway!!!!");
		// randomize the direction to runaway
		if (randomized() % 2 == 0)
		{
			Serial.println("turn to the left and go back run!!!!");
			go_left();
			go_backward();
			// delayed the backward
			delay(1500);
		}
		else
		{
			Serial.println("turn to the right and go back run!!!!");
			go_right();
			go_backward();
			// delayed the backward
			delay(1500);
		}
	}
}