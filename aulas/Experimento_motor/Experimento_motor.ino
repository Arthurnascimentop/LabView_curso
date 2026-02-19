const int relePin = 5;
const bool releAtivoEmLow = false;

const byte bufferSize = 30;
char buffer[bufferSize];
byte indexBuffer = 0;

bool estadoMotor = false;

void setup() {
  Serial.begin(9600);
  pinMode(relePin, OUTPUT);
  desligarMotor();
}

void loop() {

  while (Serial.available()) {
    char c = Serial.read();

    // Ignora CR (caso venha \r\n)
    if (c == '\r') return;

    if (c == '\n') {
      buffer[indexBuffer] = '\0';

      // Só processa se tiver algo válido
      if (indexBuffer > 0) {
        processarComando(buffer);
      }

      indexBuffer = 0;  // Limpa buffer
    } 
    else {
      if (indexBuffer < bufferSize - 1) {
        buffer[indexBuffer++] = c;
      } 
      else {
        // Se estourar buffer, limpa tudo
        indexBuffer = 0;
      }
    }
  }
}

void processarComando(const char* cmd) {

  if (strcmp(cmd, "Motor: on") == 0) {
    ligarMotor();
  } 
  else if (strcmp(cmd, "Motor: off") == 0) {
    desligarMotor();
  }
  // Qualquer outra coisa é ignorada silenciosamente
}

void ligarMotor() {
  if (!estadoMotor) {
    estadoMotor = true;
    digitalWrite(relePin, releAtivoEmLow ? LOW : HIGH);
  }
}

void desligarMotor() {
  if (estadoMotor) {
    estadoMotor = false;
    digitalWrite(relePin, releAtivoEmLow ? HIGH : LOW);
  }
}
