int distance; // Define pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Define pins for LED and buzzer
const int ledPin = 7;
const int buzzerPin = 13;

// Variables for duration and distance
long duration;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pin modes for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set pin modes for LED and buzzer
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Clear the Trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the Echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If the distance is less than 50 cm, turn on LED and buzzer
  if (distance > 0 && distance < 50) {
    digitalWrite(ledPin, HIGH);    // Turn on LED
    tone(buzzerPin, 1000);         // Turn on buzzer at 1000 Hz
  } else {
    digitalWrite(ledPin, LOW);     // Turn off LED
    noTone(buzzerPin);             // Turn off buzzer
  }

  delay(500);  // Wait for half a second before the next measurement
}
