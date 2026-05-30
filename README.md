# belajarESP32-S3-N16R8

Bismillahirrahmanirrahim, Assalamualaikum Warahmatullahi Wabarokatuh.
Hai semua, namaku Muhammad Dionnaufal Ar-Raafi'.
Repository ini adalah catatan perjalanan belajarku ngulik **ESP32-S3-N16R8**.  
Targetnya bukan cuma “nyoba nyala”, tapi benar-benar dipakai buat **belajar mikrokontroler**, **eksperimen sebanyak mungkin**, lalu didokumentasikan dengan rapi.

Aku beli board ini buat dipasang, dicoba, didokumentasikan, dilaporkan hasilnya, dibongkar lagi kalau perlu, lalu diulang sampai benar-benar paham.  
Intinya: **belajar lewat praktik, trial-error, dan dokumentasi**.

## Kenapa repo ini dibuat?

Aku pengen punya satu tempat untuk:
- nyimpen catatan belajar ESP32-S3-N16R8
- dokumentasi setup dan wiring
- nyatet error, solusi, dan hal-hal yang kepelajari
- bikin laporan kecil tiap eksperimen / project
- nyimpen hasil bongkar-pasang dan evaluasi setelah ngetes hardware atau kode
- jadi arsip perkembangan dari project sederhana sampai yang lebih serius

## Tujuan utama

Beberapa target dari repo ini:

- memahami dasar mikrokontroler lewat praktik langsung
- terbiasa upload program ke ESP32
- belajar pin, input/output, komunikasi serial, sensor, dan aktuator
- belajar debugging hardware dan software
- membangun kebiasaan dokumentasi teknis
- punya kumpulan project yang makin lama makin kompleks
- menjadikan setiap percobaan, termasuk yang gagal, tetap bernilai

---

## Pola belajar di repo ini

Kurang lebih alurnya akan seperti ini:

1. **Pasang**
   - install tools
   - conect board
   - cek board kebaca
   - upload program sederhana

2. **Uji coba**
   - tes fitur dasar
   - tes komponen
   - lihat apa yang jalan dan apa yang belum

3. **Dokumentasi**
   - catat tujuan percobaan
   - tulis wiring
   - simpan source code
   - screenshot / foto hasil kalau perlu
   - catat error dan solusi

4. **Laporan**
   - bikin rangkuman singkat:
     - apa yang dicoba
     - hasilnya bagaimana
     - kendalanya apa
     - next step apa

5. **Bongkar / evaluasi**
   - lepas rangkaian
   - cek lagi kesalahan wiring atau logika program
   - revisi
   - coba ulang dengan versi yang lebih baik

---

## Roadmap belajar

### Dasar banget
- [ ] board detection
- [ ] upload program pertama
- [ ] blink LED
- [ ] baca Serial Monitor
- [ ] paham pin dasar dan power

### Input / Output
- [ ] tombol
- [ ] LED
- [ ] buzzer
- [ ] relay
- [ ] PWM / fading LED

### Sensor & display
- [ ] sensor suhu / kelembapan
- [ ] sensor cahaya
- [ ] sensor gerak
- [ ] OLED / LCD
- [ ] pembacaan data sensor secara realtime

### Komunikasi & konektivitas
- [ ] Wi-Fi
- [ ] Bluetooth
- [ ] HTTP request
- [ ] kirim data ke web / API
- [ ] MQTT dasar

### Project menengah
- [ ] mini monitoring suhu ruangan
- [ ] smart lamp sederhana
- [ ] alarm sensor gerak
- [ ] web dashboard lokal
- [ ] data logger

### Project eksperimen
- [ ] bongkar project lama lalu improve
- [ ] bandingkan beberapa pendekatan coding
- [ ] optimasi wiring dan struktur code
- [ ] bikin versi dokumentasi yang lebih rapi
- [ ] bikin project yang benar-benar kepakai

---

## Format dokumentasi project

Biar konsisten, kemungkinan setiap folder project akan punya isi seperti ini:

```md
# Nama Project

## Tujuan
Menjelaskan project ini dibuat untuk apa.

## Komponen
- ESP32-S3-N16R8
- breadboard
- jumper
- sensor / modul terkait

## Wiring
Jelaskan koneksi pin yang dipakai.

## Kode
Simpan source code utama.

## Hasil
Apa yang berhasil dijalankan.

## Kendala
Error, bug, atau masalah wiring / library / upload.

## Solusi
Apa yang diubah sampai project jalan.

## Evaluasi
Kalau diulang, apa yang harus diperbaiki.

## Next Step
Langkah lanjutan setelah project ini selesai.
```

---

## Aturan main repo ini

Supaya repo ini tetap berguna, aku pengen pegang beberapa prinsip:

- **lebih baik project kecil tapi jalan**
- **error harus dicatat, jangan cuma dilupakan**
- **project gagal tetap masuk dokumentasi**
- **setiap eksperimen harus punya kesimpulan**
- **kode boleh sederhana, yang penting paham**
- **rapi pelan-pelan lebih baik daripada nunggu sempurna**

---

## Fokus belajar

Hal yang paling pengen aku dapetin dari repo ini:

- ngerti alur kerja mikrokontroler
- ngerti baca datasheet / referensi
- ngerti hubungan hardware dan software
- bisa troubleshooting sendiri
- punya portofolio project
- punya dokumentasi yang bisa dibaca lagi kapanpun dimanapun

---

## Catatan

Repo ini bukan repo yang isinya langsung project besar semua.  
Sebagian besar justru akan berisi:

- percobaan kecil
- catatan hasil tes
- dokumentasi wiring
- log error
- revisi project
- pembelajaran dari kegagalan

Dan emang itu tujuannya.

---

## TODO terdekat

- [ ] setup environment
- [ ] test koneksi board
- [ ] upload program blink pertama
- [ ] buat folder `docs/`
- [ ] buat folder `projects/`
- [ ] mulai laporan eksperimen pertama

---

## License

Masih bebas dipakai untuk dokumentasi belajar pribadi.  
Kalau nanti repo ini berkembang, bagian license bisa dirapikan lagi.
