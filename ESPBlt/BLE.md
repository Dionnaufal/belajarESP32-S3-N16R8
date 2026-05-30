# BLE

Program ini adalah kontrol LED onboard **ESP32-S3** menggunakan **BLE (Bluetooth Low Energy)**.  
LED onboard pada board yang dipakai adalah **RGB NeoPixel** di **GPIO 48**, sehingga **tidak bisa** dikontrol dengan `digitalWrite()` biasa seperti LED standar.

## Fitur
- Kontrol LED onboard ESP32-S3 via BLE
- Mendukung beberapa warna
- Mudah dites menggunakan aplikasi **nRF Connect**
- Menampilkan log di **Serial Monitor**

## Hardware
- ESP32-S3 Dev Module
- LED onboard RGB / NeoPixel pada **GPIO 48**

## Library yang dibutuhkan
Install library berikut di Arduino IDE:
- `BLE` (dari core ESP32)
- `Adafruit NeoPixel`

## Kode Program
```cpp
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
```

## Cara Upload
1. Buka **Arduino IDE**
2. Pilih board: **ESP32S3 Dev Module**
3. Pilih port COM yang sesuai
4. Pastikan library sudah terpasang
5. Upload program ke board

## Cara Test di HP
Gunakan aplikasi **nRF Connect**:
1. Scan device BLE
2. Cari device dengan nama: **ESP32S3_BLE_LED**
3. Connect
4. Buka characteristic dengan UUID berikut:
   - Service UUID: `4fafc201-1fb5-459e-8fcc-c5c9c331914b`
   - Characteristic UUID: `beb5483e-36e1-4688-b7f5-ea07361b26a8`
5. Kirim perintah:
   - `1` = LED hijau
   - `2` = LED merah
   - `3` = LED biru
   - `0` = LED mati

## Output Serial Monitor
Contoh log:
```text
BLE aktif. Cari device: ESP32S3_BLE_LED
Perangkat BLE terhubung
Diterima: 1
LED HIJAU
Diterima: 0
LED OFF
```

## Catatan Penting
- ESP32-S3 **tidak mendukung Bluetooth Classic Serial** seperti `BluetoothSerial.h`
- Gunakan **BLE**
- LED onboard board ini adalah **NeoPixel RGB**, bukan LED biasa
- Karena itu, kontrol LED harus memakai **Adafruit_NeoPixel**
- Jika memakai LED eksternal, LED biasa masih bisa dikontrol dengan `digitalWrite()` pada pin seperti GPIO 2

## Troubleshooting

### 1. LED tidak menyala
- Pastikan board benar-benar memakai LED onboard RGB
- Pastikan pin LED adalah **GPIO 48**
- Pastikan library `Adafruit NeoPixel` sudah terinstall

### 2. Error `Adafruit_NeoPixel.h: No such file or directory`
Install library:
- **Adafruit NeoPixel**

### 3. Device BLE tidak muncul
- Pastikan board sudah menyala
- Buka Serial Monitor 115200
- Pastikan muncul pesan:
  `BLE aktif. Cari device: ESP32S3_BLE_LED`

### 4. Perintah terkirim tapi LED tidak berubah
- Pastikan Anda mengirim karakter `1`, `2`, `3`, atau `0`
- Pastikan menulis ke **characteristic UUID yang benar**

## Ringkasan
Project ini memakai **BLE** untuk mengontrol **LED RGB onboard ESP32-S3**.  
Karena LED onboard adalah **NeoPixel di GPIO 48**, kontrol tidak bisa menggunakan `digitalWrite()`, melainkan harus memakai library **Adafruit_NeoPixel**.
