int sensor_pin = A0;
int red_led = 4;
int yel_led = 3;
int green_led = 2;
int buzzer = 5;
int output_value;

void setup() {

  pinMode(red_led, OUTPUT);
  pinMode(yel_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
   Serial.begin(9600);

   Serial.println("Reading From the Sensor ...");

   delay(2000);

   }

void loop() {
  output_value = analogRead(sensor_pin);

  if(output_value > 200){
      digitalWrite(green_led, HIGH);
      digitalWrite(yel_led, LOW);
      digitalWrite(red_led, LOW);
      noTone(buzzer);
  }
  if(output_value < 200 && output_value > 100){
      digitalWrite(yel_led, HIGH);
      digitalWrite(green_led, LOW);
      digitalWrite(red_led, LOW);
      noTone(buzzer);
  }
  if(output_value < 100 && output_value >= 0){
      digitalWrite(red_led, HIGH);
      digitalWrite(yel_led, LOW);
      digitalWrite(green_led, LOW);
      tone(buzzer, 5000); // Send 1KHz sound signal...
  }

  Serial.print("Mositure : ");

  Serial.println(output_value);

  //Serial.println("%");
  delay(1000);
}
