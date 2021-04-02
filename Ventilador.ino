/*
   Ventilador.ino

   Prueba del ventilador.
   la salida es el pin 9.
   Dependiendo del valor que lea en el pin A0
   La salida esta conectada a una resistencia de 1K, a la base del trnasistor.
   

*/

const int analogPin = A0; // Entrada señal analogica
int percent = 0;
int pwm = 0;
const int pwmPin = 9;
int pot = 0; // almacena la lectura analógica raw del potenciometro

void setup() {
  Serial.begin(115200);
  pinMode(pwmPin, OUTPUT);

}

void loop() {
  pot = analogRead(analogPin); // lectura analógica raw (0-1023)
  percent = map(pot, 0, 1023, 90,108); // convertir a porcentaje (0-100)

 // percent=100;
  pwm = percent * 2.55;
Serial.print("Porcentaje: ");
  Serial.println(percent);
  Serial.print("PWM: ");
  Serial.println(pwm);

  analogWrite(pwmPin, pwm);
  delay(1000);
}
