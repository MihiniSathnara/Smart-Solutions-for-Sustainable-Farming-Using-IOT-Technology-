#define PUMP_RELAY_PIN    7 // Arduino pin that connects to pump relay
#define MOISTURE_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor
#define PHOTORESISTOR_PIN A1 // Arduino pin that connects to AOUT pin of Photoresistor
#define LAMP_RELAY_PIN    4 // Arduino pin that connects to lamp relay
#define DHT22_PIN A4 // Arduino pin that connects to AOUT pin of temperature sensor
#define FAN_RELAY_PIN    2 // Arduino pin that connects to fan relay

#define MOISTURE_THRESHOLD 437 // CHANGE YOUR THRESHOLD HERE
#define LIGHT_THRESHOLD 339 // CHANGE YOUR THRESHOLD HERE
#define TEMPERATURE_THRESHOLD 179 //CHANGE YOUR THESHOLD HERE

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_RELAY_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(LAMP_RELAY_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(FAN_RELAY_PIN, OUTPUT); // set arduino pin to output mode
}

void loop() {
  int soilMoisture_analogValue = analogRead(MOISTURE_PIN); // read the analog value from soil moisture sensor
  int photoresistor_analogValue = analogRead(PHOTORESISTOR_PIN); // read the analog value from photoresistor
  int temperature_analogValue = analogRead(DHT22_PIN); // read the analog value from temperature sensor

  if (soilMoisture_analogValue > MOISTURE_THRESHOLD) {
    Serial.print("The soil is DRY => turn pump ON");
    digitalWrite(PUMP_RELAY_PIN, HIGH);
  } else {
    Serial.print("The soil is WET => turn pump OFF");
    digitalWrite(PUMP_RELAY_PIN, LOW);
  }

  Serial.print(" (");
  Serial.print(soilMoisture_analogValue);
  Serial.println(")");
  
  if (photoresistor_analogValue < LIGHT_THRESHOLD) {
    Serial.print("The light is LOW => turn lamp ON");
    digitalWrite(LAMP_RELAY_PIN, HIGH); 
  } else {
    Serial.print("The light is HIGH => turn lamp OFF");
    digitalWrite(LAMP_RELAY_PIN, LOW);
  }

  Serial.print(" (");
  Serial.print(photoresistor_analogValue);
  Serial.println(")");
  
   if (temperature_analogValue > TEMPERATURE_THRESHOLD) {
    Serial.print("The air is WARM => turn fan ON");
    digitalWrite(FAN_RELAY_PIN, HIGH);
  } else {
    Serial.print("The air is COLD => turn fan OFF");
    digitalWrite(FAN_RELAY_PIN, LOW);
  }

  Serial.print(" (");
  Serial.print(temperature_analogValue);
  Serial.println(")");
  
  

  delay(2000);
}
