#include <DHT.h>
#include <ArduinoJson.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define LED_WARNING 3    // LED naranja (50-75°C)
#define LED_CRITICAL 4   // LED rojo (>100°C)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(LED_WARNING, OUTPUT);
  pinMode(LED_CRITICAL, OUTPUT);

  // Prueba de encendido de LEDs al iniciar
  Serial.println("Inicializando sistema...");
  digitalWrite(LED_WARNING, HIGH);
  digitalWrite(LED_CRITICAL, HIGH);
  delay(1000); // Encendidos por 1 segundo
  digitalWrite(LED_WARNING, LOW);
  digitalWrite(LED_CRITICAL, LOW);
  Serial.println("Prueba de LEDs completada.");

  // Apagar LED 13 (LED "L")
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  delay(2000);
  
  float temp = dht.readTemperature();
  
  if (isnan(temp)) {
    Serial.println("{\"error\":\"Failed to read sensor\"}");
    return;
  }
  
  // Control de LEDs según temperatura
  if (temp > 100) {
    digitalWrite(LED_CRITICAL, HIGH);
    digitalWrite(LED_WARNING, HIGH);
  } 
  else if (temp >= 50 && temp <= 75) {
    digitalWrite(LED_WARNING, HIGH);
    digitalWrite(LED_CRITICAL, LOW);
  } 
  else {
    digitalWrite(LED_WARNING, LOW);
    digitalWrite(LED_CRITICAL, LOW);
  }
  
  // Enviar datos como JSON
  StaticJsonDocument<200> doc;
  doc["temperature"] = temp;
  doc["humidity"] = dht.readHumidity();
  doc["unit"] = "C";
  doc["status"] = (temp > 100) ? "CRITICAL" : (temp >= 50) ? "WARNING" : "NORMAL";
  
  serializeJson(doc, Serial);
  Serial.println();
}
