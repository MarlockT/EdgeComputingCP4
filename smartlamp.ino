/******************************************************
 * Projeto: Smart Lamp - Monitoramento Global de Vinherias
 * Check Point 4 - Turma 1ESPK
 * 
 * Autores:
 * - Nuno Coutinho Henrique RM562438
 * - Yasmin Amorim Affonso RM563645
 *
 * Descrição:
 * Leitura de temperatura e umidade (DHT22) e luminosidade (LDR),
 * enviando os dados para o ThingSpeak usando ESP32 no simulador Wokwi.
 ******************************************************/
//Bibliotecas utilizadas
#include <WiFi.h>
#include "DHT.h"
#include <HTTPClient.h>

//Conexões feitas
#define DHTPIN 15
#define DHTTYPE DHT22
#define LDRPIN 34

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* server = "http://api.thingspeak.com/update";
String apiKey = "JOHBBPMVFV6ST75L";

DHT dht(DHTPIN, DHTTYPE);

//Conectando no Wifi
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado!");
  dht.begin();
}

//Checando temperatura cada 15 segundos
void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int lum = analogRead(LDRPIN);

  if (!isnan(temp) && !isnan(hum)) {
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      String url = server;
      url += "?api_key=" + apiKey;
      url += "&field1=" + String(temp);
      url += "&field2=" + String(hum);
      url += "&field3=" + String(lum);

      http.begin(url);
      int httpCode = http.GET();
      if (httpCode > 0) {
        Serial.print("Temperatura: ");
        Serial.print(temp);
        Serial.println(" °C");

        Serial.print("Umidade: ");
        Serial.print(hum);
        Serial.println(" %");

        Serial.print("Luminosidade: ");
        Serial.println(lum);
        Serial.println("---------------------");

        Serial.println("Dados enviados ao ThingSpeak!");
      } else {
        Serial.println("Falha no envio.");
      }
      http.end();
    }
  }
  delay(20000); // respeitar limite do ThingSpeak (15s+)
}
