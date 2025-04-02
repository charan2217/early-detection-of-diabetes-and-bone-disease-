#include <Wire.h>
#include <LCD_I2C.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "ESP_Wahaj.h"
Adafruit_MPU6050 mpu;
int cou=0;
float flt=0;
float flt1=0;
float flag=0;
float flag1=0;
int prev;
int flex=0;
int piezo=1024;
int pwm;
#include <SimpleDHT.h>
int pinDHT11 = D0;
#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;
SimpleDHT11 dht11(pinDHT11);
float bpm,spo2;
String stat="";
float te,hu;
// always include thingspeak header file after other header files and custom macros
char ssid[] = "Project";   // your network SSID (name) 
char pass[] = "12345678";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
float d;
  String y="";
  int xt=0;
LCD_I2C lcd(0x27); // Initialize the LCD with I2C address 0x27
#include <Wire.h>

const int irReceiverPin = A0;       // Analog pin connected to IR receiver

void setup() {
  Serial.begin(9600);
  start("Project","12345678");
  adc.begin();
    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();                // Turn on the backlight
  pinMode(A0, INPUT);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MULTIPLE DISEASES");
  lcd.setCursor(0, 1);
  lcd.print("MONITORING");
  delay(3000);
  Serial.println("");
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
}

void loop() {

 
     if (CheckNewReq()==1)
 {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PLACE YOUR LEG");
  delay(3000);
  lcd.clear();
  for(int ki=0;ki<100;ki++)
  {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  flt=a.acceleration.x;
  flt1=a.acceleration.y;
  if((flt>flag+0.5)||(flt<flag-0.5)||(flt1>flag1+0.5)||(flt1<flag1-0.5))
  {
    cou++;
  }
  flag=flt;
  flag1=flt1;
  flex=adc.readADC(0);
  prev=adc.readADC(1);
  Serial.println(prev);
  if(piezo>prev)
  {
    piezo=prev;
    }
    
  delay(100);
  }
//float pressureValue = measurepressure();
 // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
Serial.print("Sample OK: ");
Serial.print((int)temperature); Serial.print(" *C, "); 
Serial.print((int)humidity); Serial.println(" H");
te=temperature;
hu=humidity;
lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.print(te);
   lcd.setCursor(0, 1);
   lcd.print("HUM:");
  lcd.print(hu);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PRESSURE:");
  lcd.print(piezo);
  lcd.setCursor(0, 1);
  lcd.print("ANGLE:");
  lcd.print(cou);
  lcd.print(" F:");
  lcd.print(flex);
  delay(1000);
String myString = String(piezo)+String(",")+String(te)+String(",")+String(hu)+String(",")+String(cou)+String(",")+String(flex);
    returnThisStr(myString);
    delay(1000);
String path = getPath();
      path.remove(0,1);
       pwm = path.toInt();
       cou=0;
  }

  

}
