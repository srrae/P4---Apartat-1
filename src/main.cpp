#include <Arduino.h>

const int led = 4;
SemaphoreHandle_t sem;

void tOn(void *p);
void tOff(void *p);

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);

  Serial.println("--- SISTEMA INICIAT: COMPROVANT LED PIN 4 ---");
  digitalWrite(led, HIGH); delay(500);
  digitalWrite(led, LOW); delay(500);
  Serial.println("--- COMPROVACIÓ OK: INICIANT TASQUES ---");

  sem = xSemaphoreCreateBinary();
  xSemaphoreGive(sem);

  xTaskCreate(tOn, "ON", 2048, NULL, 1, NULL);
  xTaskCreate(tOff, "OFF", 2048, NULL, 1, NULL);
}

void loop() {}

void tOn(void *p) {
  for (;;) {
    if (xSemaphoreTake(sem, portMAX_DELAY) == pdTRUE) {
      digitalWrite(led, HIGH);
      Serial.println("LED: ON");
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      xSemaphoreGive(sem);
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
  }
}

void tOff(void *p) {
  for (;;) {
    if (xSemaphoreTake(sem, portMAX_DELAY) == pdTRUE) {
      digitalWrite(led, LOW);
      Serial.println("LED: OFF");
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      xSemaphoreGive(sem);
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
  }
}