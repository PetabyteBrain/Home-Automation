/*
 * Keychain Storage Module for the Home Automation project
 * (Client version)
 * https://github.com/PetabyteBrain/Home-Automation
 * 
 */
#include <MultiStepper.h>
#include <AccelStepper.h>
#include "BLEDevice.h"

#define LED_PIN 2  // GPIO2 pin connected to LED (Built-in & external) {Shows direction at which Motor was turned}
#define LED_PIN2 4  // GPIO4 pin connected to LED (external) {Shows Bluetooth Connection status: Connected/disconnected}
#define BUTTON_PIN 18 // GPIO18 pin connected to button
#define BUTTON_PIN2 17 // GPIO17 pin connected to button
AccelStepper stepper1(1, 19, 21); // (Typeof driver: with 2 pins, STEP, DIR)

// The remote service we wish to connect to.
static BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
// The characteristic of the remote service we are interested in.
static BLEUUID charUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic *pRemoteCharacteristic;
static BLEAdvertisedDevice *myDevice;
static String value = "";  // Global variable to store characteristic value
static String LastCharacteristicPressed = "";
bool motorOnState = false;
bool switchNextState = false;

static void notifyCallback(BLERemoteCharacteristic *pBLERemoteCharacteristic, uint8_t *pData, size_t length, bool isNotify) {
  Serial.print("Notify callback for characteristic ");
  Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
  Serial.print(" of data length ");
  Serial.println(length);
  Serial.print("data: ");
  Serial.write(pData, length);
  Serial.println();
  
  value = String((char*)pData);  // Update value from notification
}

class MyClientCallback : public BLEClientCallbacks {
  void onConnect(BLEClient *pclient) {}

  void onDisconnect(BLEClient *pclient) {
    connected = false;
    digitalWrite(LED_PIN2, LOW);
    Serial.println("onDisconnect");
  }
};

bool connectToServer() {
  Serial.print("Forming a connection to ");
  Serial.println(myDevice->getAddress().toString().c_str());

  BLEClient *pClient = BLEDevice::createClient();
  Serial.println(" - Created client");

  pClient->setClientCallbacks(new MyClientCallback());

  // Connect to the remote BLE Server.
  pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
  Serial.println(" - Connected to server");
  pClient->setMTU(517);  // set client to request maximum MTU from server (default is 23 otherwise)

  // Obtain a reference to the service we are after in the remote BLE server.
  BLERemoteService *pRemoteService = pClient->getService(serviceUUID);
  if (pRemoteService == nullptr) {
    Serial.print("Failed to find our service UUID: ");
    Serial.println(serviceUUID.toString().c_str());
    pClient->disconnect();
    return false;
  }
  Serial.println(" - Found our service");

  // Obtain a reference to the characteristic in the service of the remote BLE server.
  pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
  if (pRemoteCharacteristic == nullptr) {
    Serial.print("Failed to find our characteristic UUID: ");
    Serial.println(charUUID.toString().c_str());
    pClient->disconnect();
    return false;
  }
  Serial.println(" - Found our characteristic");

  // Read the initial value of the characteristic.
  if (pRemoteCharacteristic->canRead()) {
    value = pRemoteCharacteristic->readValue();
    Serial.print("The initial characteristic value was: ");
    Serial.println(value.c_str());
  }

  if (pRemoteCharacteristic->canNotify()) {
    pRemoteCharacteristic->registerForNotify(notifyCallback);
  }

  connected = true;
  return true;
}

/**
 * Scan for BLE servers and find the first one that advertises the service we are looking for.
 */
class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks {
  /**
   * Called for each advertising BLE server.
   */
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    Serial.print("BLE Advertised Device found: ");
    Serial.println(advertisedDevice.toString().c_str());

    // We have found a device, let us now see if it contains the service we are looking for.
    if (advertisedDevice.haveServiceUUID() && advertisedDevice.isAdvertisingService(serviceUUID)) {

      BLEDevice::getScan()->stop();
      myDevice = new BLEAdvertisedDevice(advertisedDevice);
      doConnect = true;
      doScan = false;  // Stop scanning since we found the device

    }  // Found our server
  }  // onResult
};  // MyAdvertisedDeviceCallbacks

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  stepper1.setMaxSpeed(1000); // Set maximum speed value for the stepper
  stepper1.setAcceleration(500); // Set acceleration value for the stepper
  stepper1.setCurrentPosition(200); // Set the current position to 200 steps
  Serial.println("Starting Arduino BLE Client application...");
  BLEDevice::init("");

  // Retrieve a Scanner and set the callback we want to use to be informed when we
  // have detected a new device.  Specify that we want active scanning and start the
  // scan to run for 5 seconds.
  BLEScan *pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(1349);
  pBLEScan->setWindow(449);
  pBLEScan->setActiveScan(true);
  pBLEScan->start(5, false);
}  // End of setup.

// This is the Arduino main loop function.
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  int buttonState2 = digitalRead(BUTTON_PIN2);

  if (buttonState == LOW) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW)
    }

  // If the flag "doConnect" is true then we have scanned for and found the desired
  // BLE Server with which we wish to connect.  Now we connect to it.  Once we are
  // connected we set the connected flag to be true.
  if (doConnect) {
    if (connectToServer()) {
      Serial.println("We are now connected to the BLE Server.");
      digitalWrite(LED_PIN2, HIGH);
    } else {
      Serial.println("We have failed to connect to the server; there is nothing more we will do.");
      digitalWrite(LED_PIN2, LOW);
    }
    doConnect = false;
  }

  // If we are connected to a peer BLE Server, print the value of the characteristic.
  if (value.c_str() != LastCharacteristicPressed){
    if (connected) {
      digitalWrite(LED_PIN2, HIGH);
      Serial.print("Current characteristic value: ");
      Serial.println(value.c_str());
      switchNextState = true;
      
    } else if (doScan) {
      digitalWrite(LED_PIN2, LOW);
      BLEDevice::getScan()->start(0);  // Start scanning after disconnect
    }
    LastCharacteristicPressed = value.c_str();
  }
  // Automated Task (can be changed to anything) 
  // {Turns an extension cable off or on depending on the value given}
  if(connected){
    if(switchNextState){
      //Turns extension cable Off by turnin the Motor in the corresponding direction
      if(!motorOnState){

        stepper1.moveTo(0); // Set desired move: 800 steps (in quater-step resolution that's one rotation)
        stepper1.runToPosition(); // Moves the motor to target position w/ acceleration/ deceleration and it blocks until is in position

        digitalWrite(LED_PIN, LOW);
        motorOnState = true;
      }
      //Turns extension cable On by turnin the Motor in the corresponding direction
      else if(motorOnState){

        stepper1.moveTo(400); // Set desired move: 800 steps (in quater-step resolution that's one rotation)
        stepper1.runToPosition(); // Moves the motor to target position w/ acceleration/ deceleration and it blocks until is in position
        
        digitalWrite(LED_PIN, HIGH);
        motorOnState = false;
      }
    }
    switchNextState = false;
  }
  
  delay(1000);  // Delay a second between loops.
}  // End of loop
