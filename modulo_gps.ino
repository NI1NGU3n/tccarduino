#define GPS_RX 4
#define GPS_TX 3
//https://blog.eletrogate.com/gps-neo-6m-com-arduino-aprenda-usar/
//https://drive.google.com/file/d/0B4NjXBDncdL0QlVwcC1FcS0zQVk/view
#define GPS_Serial_Baud 9600
#include <SoftwareSerial.h>
// The serial connection to the GPS device
SoftwareSerial gpsSerial(GPS_RX, GPS_TX);

void setup()
{
  Serial.begin(115200); // Beginning the serial monitor at Baudrate 115200 and make sure you select same in serial monitor
  gpsSerial.begin(GPS_Serial_Baud);
}

void loop()
{
  //Mostra os dados crus do GPS
  while (gpsSerial.available() > 0)
  {
    Serial.write(gpsSerial.read());
  }
}
