//Analog Input 
#define ANALOG_PIN_0 36
float analog_value = 0;
float angulo = 0;
 
// PMW SERVO
#define SERVO_PIN 5
int freq = 50;
int channel = 0;
int resolution = 8;
int dutyCycle = 21;
 
void setup()
{
 
Serial.begin(115200);
 
delay(1000); // give me time to bring up serial monitor
 
Serial.println("ESP32 Servo Control");
 
ledcSetup(channel, freq, resolution);
 
ledcAttachPin(SERVO_PIN, channel);
 
ledcWrite(channel, dutyCycle);
 
}
 
void loop() 
{
 
analog_value = analogRead(ANALOG_PIN_0);
 
Serial.print(analog_value);
 
Serial.print(" Angulo ==> ");

angulo = analog_value*180/4095;
 
Serial.println(angulo);
 
dutyCycle = map(analog_value, 0, 4095, 5, 32);
 
ledcWrite(channel, dutyCycle);
 
delay(5000);
 
}
