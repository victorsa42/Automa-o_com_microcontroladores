//Analog Input
 
#define ANALOG_PIN_0 36
#define ANALOG_PIN_1 23

int analog_value = 0;

int ThermistorPin;
    double adcMax, Vs;

    double R1 = 10000.0;   // voltage divider resistor value
    double Beta = 3950.0;  // Beta value
    double To = 298.15;    // Temperature in Kelvin for 25 degree Celsius
    double Ro = 10000.0;   // Resistance of Thermistor at 25 degree Celsius

void setup()
 
{
 
Serial.begin(115200); 
delay(1000); // give me time to bring up serial monitor
 
Serial.println(""); 
Serial.println("ESP32 Temperature"); 
Serial.println(""); 


pinMode(LED_BUILTIN, OUTPUT);

ThermistorPin = A0;
adcMax = 4095;   // ADC resolution 10-bit (0-1023)
Vs = 3.3;          // supply voltage

}
 
void loop()
 
{
analog_value = analogRead(ANALOG_PIN_0)/51;
Serial.println(analog_value);
//delay(500);


double Vout, Rt = 0;
double T, Tc, Tf = 0;
Vout = analogRead(ANALOG_PIN_1) * Vs/adcMax;
Rt = R1 * Vout / (Vs - Vout);
T = 1/(1/To + log(Rt/Ro)/Beta);  // Temperature in Kelvin
Tc = T - 273.15;                 // Celsius
Tf = Tc * 9 / 5 + 32;            // Fahrenheit
Serial.print("Temp: ==> ");
Serial.println(Tc);

if (Tc < analog_value) {
  digitalWrite(LED_BUILTIN, HIGH);
 } else {
  digitalWrite(LED_BUILTIN, LOW);
 }

delay(2000); 
}



