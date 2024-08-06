/*
 * Keychain Storage Module for the Home Automation project
 * (Server version)
 * https://github.com/PetabyteBrain/Home-Automation
 * 
 */
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define BUTTON_PIN 21 // GPIO21 pin connected to button
#define LED_PIN 2  // GPIO2 pin connected to LED (Built-in & external) {Recognizes if Button is pressed}

BLECharacteristic *pCharacteristic;
int lastButtonState = HIGH;  // Assume button is released initially

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Starting BLE work!");

  BLEDevice::init("Button BLE Server");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE |
                      BLECharacteristic::PROPERTY_NOTIFY
                    );

  pCharacteristic->setValue("Button Released");
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // Functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined!");
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      digitalWrite(LED_PIN, HIGH);
      pCharacteristic->setValue("Button Pressed");
      pCharacteristic->notify();
    } else {
      digitalWrite(LED_PIN, LOW);
      pCharacteristic->setValue("Button Released");
      pCharacteristic->notify();
    }
    lastButtonState = buttonState;  // Update last button state
  }

  delay(100);
}
