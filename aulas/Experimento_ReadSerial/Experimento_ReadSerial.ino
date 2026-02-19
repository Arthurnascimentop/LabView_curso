void setup() {
  Serial.begin(9600);

  // Inicializa gerador aleatório com ruído analógico
  randomSeed(analogRead(A0));
}

void loop() {

  // Gera valores aleatórios
  int temperature = random(20, 51);  // 20 até 50 °C
  int humidity    = random(30, 91);  // 30 até 90 %

  // Envia no formato desejado
  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  // Pequeno delay para não inundar a serial
  delay(1000);
}
