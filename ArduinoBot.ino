// *** Angulos dos servo motores ***
#define abre 90       // constante para abertura da "boca" do robo
#define fecha 180     // constante para fechamento da "boca" do robo
#define centro 90     // constante para centralizar a "cabeça" do robo
#define esquerda 45    // constante para posicionar a "cabeça" do robo a esquerda
#define direita 135   // constante para posicionar a "cabeça" do robo a direita

// *** Definição dos botões para controle da "cabeça" e "boca" do robo ***
#define tecla1 2      // constante para leitura do pino 2 (~ tecla1 ~ botao1)
#define tecla2 3      // constante para leitura do pino 3 (~ tecla2 ~ botao2)
#define tecla3 4      // constante para leitura do pino 4 (~ tecla3 ~ botao3)
#define tecla4 5      // constante para leitura do pino 5 (~ tecla4 ~ botao4)

// ** Variáveis ***
const int ledPin = 13;  // constante para guardar o pino do led
int button1State = 0;   // variável para guardar o status do pino 2 (tecla1)
int button2State = 0;   // variável para guardar o status do pino 3 (tecla2)
int button3State = 0;   // variável para guardar o status do pino 4 (tecla3)
int button4State = 0;   // variável para guardar o status do pino 5 (tecla4)

// *** Definições referentes aos servo motores ***
#include <Servo.h>    // carrega definições para biblioteca de uso de servo motores
Servo servoboca;      // servoboca   -> servo motor que será usado para abrir e fechar a "boca" do robo
Servo servocabeca;    // servocabeca -> servo motor que será usado para movimentar a "cabeça" do robo

// *** Definição de variáveis ***
boolean bocafechada = true;     // boolean usado para definir quando a boca do robo está fechada (true) ou aberta (false)
boolean cabecacentro = true;    // boolena usado para definir quando a cabeça está no centro (true) ou não (false)
boolean cabecaesq = false;      // boolena usado para definir quando a cabeça está a esquerda (true) ou não (false)
boolean cabecadir = false;      // boolena usado para definir quando a cabeça está a direita (true) ou não (false)

// *** Definição do status inicial do programa ***
void setup() {
  servoboca.attach(9);        // indica que o servo motor da boca do robo estará na porta 9 do arduino
  servocabeca.attach(10);     // indica que o servo motor da cabeça do robo estará na porta 10 do arduino
  servoboca.write(fecha);     // executa comando para fechar a boca do robo
  servocabeca.write(centro);  // executa comando para centralizar a cabeça do robo
  pinMode(ledPin, OUTPUT);    // declara ledPin como saida
}

// *** loop principal do Arduino ***
void loop() {
  button1State = digitalRead(tecla1); // faz a leitura do status da tecla1
  
  if(button1State == HIGH)  // Caso tecla1 seja pressionada, executa a movimentação da boca
    {
    digitalWrite(ledPin, HIGH);
    servocabeca.write(centro);
    delay(300);
    digitalWrite(ledPin, LOW);
    servoboca.write(abre);
    delay(500);
    digitalWrite(ledPin, HIGH);
    servoboca.write(fecha);
    delay(500);
    digitalWrite(ledPin, LOW);
    servoboca.write(abre);
    delay(500);
    digitalWrite(ledPin, HIGH);
    servoboca.write(fecha);
    delay(500);
    digitalWrite(ledPin, LOW);
    servoboca.write(abre);
    delay(500);
    digitalWrite(ledPin, HIGH);
    servoboca.write(fecha);
    delay(500);
    }

  button2State = digitalRead(tecla2);
  
  if(button2State == HIGH)
    {
    digitalWrite(ledPin, HIGH);
    servocabeca.write(centro);
    delay(300);
    digitalWrite(ledPin, LOW);
    servocabeca.write(direita);
    delay(500);
    digitalWrite(ledPin, HIGH);
    servocabeca.write(esquerda);
    delay(500);
    digitalWrite(ledPin, LOW);
    servocabeca.write(direita);
    delay(500);
    digitalWrite(ledPin, HIGH);
    servocabeca.write(esquerda);
    delay(500);
    digitalWrite(ledPin, LOW);
    servocabeca.write(direita);
    delay(500);
    digitalWrite(ledPin, HIGH);
    servocabeca.write(esquerda);
    delay(500);
    servocabeca.write(centro);
    }

  button3State = digitalRead(tecla3);
  
  if(button3State == HIGH)
    {
    digitalWrite(ledPin, HIGH);
    servocabeca.write(centro);
    delay(300);
    digitalWrite(ledPin, LOW);
    servocabeca.write(direita);
    delay(500);
    }

  button4State = digitalRead(tecla4);
  
  if(button4State == HIGH)
    {
    digitalWrite(ledPin, HIGH);
    servocabeca.write(centro);
    delay(300);
    digitalWrite(ledPin, LOW);
    servocabeca.write(esquerda);
    delay(500);
    }

}
