# ESP8266-DHT11 Bağlantısı


ESP8266 Kurulumu (Arduino IDE):

1. Arduino IDE'yi açın.
2. Arayüzün üst kısmındaki "Dosya" menüsünden "Tercihler" seçeneğine tıklayın.
3. Açılan pencerede, "İlave Kart Yöneticileri URL'leri" kutusuna aşağıdaki URL'yi yapıştırın:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
4. "OK" düğmesine tıklayın ve pencereyi kapatın.
5. Ardından, "Araçlar" menüsünden "Kart" seçeneğine gelin.
6. "Kart Yöneticisi"ni seçin.
7. Arama kutusuna "esp8266" yazın.
8. "esp8266" paketini seçin ve "Yükle" düğmesine tıklayın.
9. İşlem tamamlandığında, "Kapat" düğmesine tıklayarak Kart Yöneticisi penceresini kapatın.


ESP8266-01 modülünün bağlantısı:

1. Öncelikle, ESP8266-01 modülünü hazırlayın. Bu modül, GPIO0, GPIO2, CH_PD (Chip Power Down) ve RST (Reset) gibi sınırlı sayıda pinlere sahiptir.

2. Güç bağlantısını yapın:
   - ESP8266-01 modülünün VCC (besleme) pini 3.3V bir güç kaynağına bağlanmalıdır. Bu pin, 5V ile beslendiğinde zarar görebilir, bu nedenle 3.3V kullanmanız önemlidir.
   - Toprak bağlantısı için ESP8266-01 modülünün GND pini toprağa bağlanmalıdır. Bu, ESP8266 ve diğer bileşenler arasında ortak bir toprak referansı sağlar.

3. Seri haberleşme bağlantısını yapın:
   - ESP8266-01 modülünün RX (Receive) pini, USB-TTL dönüştürücünün TX (Transmit) pinine bağlanmalıdır.
   - ESP8266-01 modülünün TX (Transmit) pini, USB-TTL dönüştürücünün RX (Receive) pinine bağlanmalıdır.

4. Programlama modu için GPIO0 ve GPIO2 pinlerini ayarlayın:
   - Programlama moduna geçmek için, ESP8266-01 modülünün GPIO0 pini GND'ye bağlanmalıdır.
   - GPIO2 pini açık (HIGH) konumunda bırakılmalıdır.

5. CH_PD (Chip Power Down) pini bağlantısını yapın:
   - ESP8266-01 modülünün CH_PD pini, 3.3V güç kaynağına bağlanmalıdır. Bu pin, ESP8266'nın çalışması için gerekli olan güç beslemesini sağlar.

6. Reset bağlantısını yapın:
   - ESP8266-01 modülünün RST (Reset) pini, bir düğme veya başka bir mekanizma ile toprağa bağlanarak modülün sıfırlanmasını sağlar.

7. Bağlantıları doğru bir şekilde yaptığınızdan emin olun. Bağlantılarınızı kontol edin ve gevşek veya yanlış bağlantıları düzeltin.


DHT11 Bağlantısı:

1. Öncelikle, DHT11 sensörünü hazırlayın. Bu sensör, toprak, güç ve veri pinlerine sahiptir.

2. Sensörün VCC (besleme) pini 3.3V bir güç kaynağına bağlanmalıdır. Bu pin, 5V ile beslendiğinde sensör zarar görebilir, bu nedenle 3.3V kullanmanız önemlidir.

3. Sensörün GND (toprak) pini toprağa bağlanmalıdır. Bu, sensör ve diğer bileşenler arasında ortak bir toprak referansı sağlar.

4. Sensörün sinyal (veri) pini, ESP8266 veya Arduino gibi mikrodenetleyicinin bir dijital giriş pinine bağlanmalıdır. Bu pin, sensörden gelen veriyi alacak ve işleyecektir.

5. Veri pini, bir 10K direnç ile VCC (besleme) pini arasına bağlanmalıdır. Bu pull-up direnci, veri hattının istikrarını sağlar.

6. Bağlantıları doğru bir şekilde yaptığınızdan emin olun. Bağlantıları kontrol edin ve gevşek veya yanlış bağlantıları düzeltin.



Bu adımları takip ederek ESP8266 kartınızı Arduino IDE üzerinde kurabilir ve DHT11 sensörünü bağlayabilirsiniz. Kod, ESP8266 kartını Wi-Fi ağına bağlar ve DHT11 sensöründen sıcaklık ve nem ölçümlerini alır.





# ESP8266-DHT11 Connections

ESP8266 Setup (Arduino IDE):

1. Open the Arduino IDE.
2. Click on the "File" menu at the top of the interface and select "Preferences".
3. In the opened window, paste the following URL into the "Additional Board Managers URLs" box:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
4. Click "OK" and close the window.
5. Next, go to the "Tools" menu and select "Board".
6. Choose "Board Manager".
7. Type "esp8266" in the search box.
8. Select the "esp8266" package and click "Install".
9. Once the installation is complete, click "Close" to close the Board Manager window.


ESP8266-01 Module Connection:

1. First, prepare the ESP8266-01 module. This module has limited pins such as GPIO0, GPIO2, CH_PD (Chip Power Down), and RST (Reset).

2. Make the power connections:
   - Connect the VCC (power) pin of the ESP8266-01 module to a 3.3V power source. It is important to use 3.3V as supplying it with 5V can damage the module.
   - Connect the GND (ground) pin of the ESP8266-01 module to the ground. This provides a common ground reference between the ESP8266 and other components.

3. Make the serial communication connections:
   - Connect the RX (Receive) pin of the ESP8266-01 module to the TX (Transmit) pin of the USB-TTL converter.
   - Connect the TX (Transmit) pin of the ESP8266-01 module to the RX (Receive) pin of the USB-TTL converter.

4. Set GPIO0 and GPIO2 pins for programming mode:
   - To enter programming mode, connect the GPIO0 pin of the ESP8266-01 module to GND.
   - Keep the GPIO2 pin in an open (HIGH) position.

5. Make the CH_PD (Chip Power Down) pin connection:
   - Connect the CH_PD pin of the ESP8266-01 module to a 3.3V power source. This pin provides the power required for the ESP8266 to function.

6. Make the reset connection:
   - Connect the RST (Reset) pin of the ESP8266-01 module to ground using a button or another mechanism to reset the module.

7. Ensure that you have made the connections correctly. Check the connections and fix any loose or incorrect connections.


DHT11 Connection:

1. First, prepare the DHT11 sensor. This sensor has pins for ground, power, and data.

2. The VCC (power) pin of the sensor should be connected to a 3.3V power source. It is important to use 3.3V as supplying it with 5V can damage the sensor.

3. The GND (ground) pin of the sensor should be connected to the ground. This provides a common ground reference between the sensor and other components.

4. The data pin of the sensor should be connected to a digital input pin of the microcontroller, such as ESP8266 or Arduino. This pin will receive and process the data from the sensor.

5. The data pin should be pulled up to the VCC pin using a 10K resistor. This pull-up resistor ensures the stability of the data line.

6. Make sure you have made the connections correctly. Check the connections and fix any loose or incorrect connections.

By following these steps, you can set up your ESP8266 board in the Arduino IDE and connect the DHT11 sensor.
