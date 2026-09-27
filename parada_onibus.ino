#define LED_VERMELHO D2
#define LED_AZUL D3
#define BUZZER D4
#define PORTA D5
#define BOTAO_PARADA D6

bool solicitacaoAtiva = false;
bool botaoAnterior = HIGH;
bool portaAnterior = HIGH;
bool buzzerAtivo = false;

unsigned long inicioBuzzer = 0;

void setup() {
  Serial.begin(115200);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(PORTA, INPUT_PULLUP);
  pinMode(BOTAO_PARADA, INPUT_PULLUP);

  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AZUL, HIGH);
  digitalWrite(BUZZER, LOW);

  Serial.println("Sistema iniciado");
  Serial.println("Aguardando solicitacao de parada");
}

void loop() {
  bool botaoAtual = digitalRead(BOTAO_PARADA);
  bool portaAtual = digitalRead(PORTA);

  if (botaoAtual == LOW && botaoAnterior == HIGH) {
    solicitacaoAtiva = true;

    buzzerAtivo = true;
    inicioBuzzer = millis();

    digitalWrite(BUZZER, HIGH);

    Serial.println("Parada solicitada");
  }

  if (buzzerAtivo && millis() - inicioBuzzer >= 3000) {
    buzzerAtivo = false;
    digitalWrite(BUZZER, LOW);

    Serial.println("Alerta sonoro finalizado");
  }

  if (portaAtual == LOW && portaAnterior == HIGH) {
    solicitacaoAtiva = false;

    buzzerAtivo = false;
    digitalWrite(BUZZER, LOW);

    Serial.println("Porta aberta - solicitacao atendida");
  }

  if (solicitacaoAtiva) {
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AZUL, LOW);
  } else {
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AZUL, HIGH);
  }

  botaoAnterior = botaoAtual;
  portaAnterior = portaAtual;

  delay(20);
}
