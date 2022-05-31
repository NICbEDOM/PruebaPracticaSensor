#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int pinSensor = A0; //pin del sensor de temperatura
const int pinLed = 13; //pin del led para alerta de temperatura
int valorSensor = 0; //Valor en blanco para guardar variable
float temperatura = 0; //Valor en blanco para guardar variable

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT); //Declaracion del led de salida
  Serial.begin(9600); //Inicia la comunicacion serial
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorSensor = analogRead(pinSensor); //leemos el valor del sensor

  float milivolts = (valorSensor / 1023.0) * 5000; 
  //Convertimos el valor a milivolts, luego a centigrados, consideremos que 1 grado c = 10 milivoltios
  temperatura = milivolts/10;
  Serial.print(temperatura); //Impresion en pantalla y lcd
  Serial.println("Temperatura = ");
  lcd.print(temperatura);
  lcd.print(" oC");
  if(temperatura > 80){ //Temperatura maxima registrada en la tierra + 20 grados para evitar una alerta falsa. 
    //Tengamos en cuenta que en incendios forestales se registran de < 250.
    digitalWrite(pinLed, HIGH);
    lcd.print("        EMERGENCIA");
  } else {
    digitalWrite(pinLed, LOW);
  }
  delay(500);
  lcd.clear();
}
//C:\\Users\\ADMINI~1\\AppData\\Local\\Temp\\arduino_build_548017/Arduino_Temperatura_F_.ino.hex
