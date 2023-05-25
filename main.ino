#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>


// DHT sensör tipine bağlı olarak aşağıdaki satırlardan birini yorum satırı olmaktan çıkarın!
#define DHTTYPE DHT11   // DHT 11


/*SSID ve Parolanızı buraya girin*/
const char* ssid = "wifiproject";  // SSID bilgisini buraya girin
const char* password = "wifitest";  // Parolayı buraya girin

ESP8266WebServer server(80);

// DHT Sensörü
uint8_t DHTPin = 2; // DHT sensörünün bağlı olduğu pin (GPIO_15 olarak tanımlanmıştır)

               
// DHT sensörünü başlat
DHT dht(DHTPin, DHTTYPE);                

float Temperature;
float Humidity;

// Wi-Fi ağına bağlanmak için fonksiyon
void connectToWiFi(const char* ssid, const char* password) {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Wi-Fi ağına bağlanılıyor: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Wi-Fi bağlantısı başarılı!");
  Serial.print("IP adresi: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  connectToWiFi("wifiproject", "wifitest");

  // Kök dizine yapılan istekleri işlemek için fonksiyon atanır
  server.on("/", handle_OnConnect);
  
  // Tanımlanmayan yol istekleri için 404 hata yanıtı gönderilir
  server.onNotFound(handle_NotFound);

  // HTTP sunucusunu başlat
  server.begin();
  
  Serial.println("HTTP sunucusu başlatıldı");
}

void loop() {
  // Gelen istekleri işle
  server.handleClient();
}

// Kök dizine yapılan istekleri işleyen fonksiyon
void handle_OnConnect() {
  // DHT sensöründen sıcaklık ve nem değerlerini oku
  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();
  
  // Sıcaklık ve nem değerlerini HTML yanıtı olarak gönder
  server.send(200, "text/html", SendHTML(Temperature, Humidity)); 
}

// Tanımlanmayan yol isteklerini işleyen fonksiyon
void handle_NotFound() {
  server.send(404, "text/plain", "Bulunamadı");
}

// Sıcaklık ve nem değerlerini HTML formatında oluşturup döndüren fonksiyon
//ptr html belgesini geçici olarak saklar String değişkenidir
String SendHTML(float Temperaturestat, float Humiditystat) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>Tests</title>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";
  ptr += "<h1>Sıcaklık ve Nem Proje Uygulaması</h1>\n";
  ptr += "<p><span class=\"temperature-icon\"></span>Sıcaklık: ";
  ptr += (int)Temperaturestat;
  ptr += "&deg;C</p>";
  ptr += "<p>Nem: ";
  ptr += (int)Humiditystat;
  ptr += "%</p>";
  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
