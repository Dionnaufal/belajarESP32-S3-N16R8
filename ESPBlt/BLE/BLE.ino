#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 48
#define NUMPIXELS 1

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;

void setLedColor(uint8_t r, uint8_t g, uint8_t b) {
  pixels.setPixelColor(0, pixels.Color(r, g, b));
  pixels.show();
}

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    Serial.println("Perangkat BLE terhubung");
  }

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    Serial.println("Perangkat BLE terputus");
    BLEDevice::startAdvertising();
    Serial.println("Iklan BLE dimulai lagi");
  }
};

class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String value = pCharacteristic->getValue();

    if (value.length() > 0) {
      char command = value[0];
      Serial.print("Diterima: ");
      Serial.println(command);

      switch (command) {
        case '1':
          setLedColor(0, 50, 0);   // Hijau
          Serial.println("LED HIJAU");
          break;

        case '2':
          setLedColor(50, 0, 0);   // Merah
          Serial.println("LED MERAH");
          break;

        case '3':
          setLedColor(0, 0, 50);   // Biru
          Serial.println("LED BIRU");
          break;

        case '0':
          pixels.clear();
          pixels.show();
          Serial.println("LED OFF");
          break;

        default:
          Serial.println("Perintah tidak dikenal");
      }
    }
  }
};

void setup() {
  Serial.begin(115200);

  pixels.begin();
  pixels.setBrightness(50);
  pixels.clear();
  pixels.show();

  // Tes awal
  setLedColor(50, 0, 0); delay(400); // merah
  setLedColor(0, 50, 0); delay(400); // hijau
  setLedColor(0, 0, 50); delay(400); // biru
  pixels.clear();
  pixels.show();

  BLEDevice::init("ESP32S3_BLE_LED");

  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ |
    BLECharacteristic::PROPERTY_WRITE |
    BLECharacteristic::PROPERTY_NOTIFY
  );

  pCharacteristic->setCallbacks(new MyCallbacks());
  pCharacteristic->setValue("0");
  pCharacteristic->addDescriptor(new BLE2902());

  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->start();

  Serial.println("BLE aktif. Cari device: ESP32S3_BLE_LED");
  Serial.println("Kirim 1=Hijau, 2=Merah, 3=Biru, 0=Mati");
}

void loop() {
}