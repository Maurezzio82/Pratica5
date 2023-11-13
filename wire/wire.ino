#include <Wire.h>						//Inclui a biblioteca de comunicação I2C

const int PotPin = A0;						//Pino para leitura do sinal 
int Tensao = 0;							//Valor de 0 a 1023 em que a tensão é armazenada (10bits)
int addr = 0x42;						//Endereço I2C de comunicação
float TensaoF64 = 0.0;						//Variável Float para mostrar o valor em volts já convertido no terminal 


void setup() {
  // put your setup code here, to run once:
  
  Wire.begin(addr);						//Estabelece o início do protocolo de comunicação I2C
  Serial.begin(9600);						//Estabelece o início do protocolo de comunicação Serial (por USB com a IDE)
  Wire.onRequest(requestEvent); 				//Quando há requisição de dados por parte da Rasp Pi, a função "requestEvent" é chamada no Arduino
  
}

void loop() {
  delay(100);							//delay para intervalar o passamento de dados (evita ocorrência de Remote I/O Error)
}

void requestEvent() {						//Função chamada quando há requisição de dados

  Tensao = analogRead(PotPin);  				//Leitura do valor analógico no pino PotPin = A0
  Serial.print("Valor enviado: ");				//formatação
  Serial.println(Tensao);					//Print do valor lido (de 0 a 1023)
  Serial.print("Valor de tensão: ");				//formatação
  
  TensaoF64 = 5.0*Tensao;					//Conversão do valor inteiro
  TensaoF64 = TensaoF64/1024;					//para um Float

  Serial.println(TensaoF64);					//Print do valor lido em Volts
  

  Wire.write(highByte(Tensao));					//Envio do byte mais significativo (apenas os dois últimos carregam informação, 
  								//haja visto que A variável Tensao vem de uma leitura com resolução de 10 bits)
  Wire.write(lowByte(Tensao));					//Envio do byte menos significativo
}





























































//Estandarte desfraldado
//Preto e branco é sua cor
//Ponte Preta vai pro campo
//Pra mostrar o seu valor

//Ponte Preta inflamante
//Ponte Preta emoção
//Ponte Preta gigante
//Raça de campeão

//Seu estádio é o Majestoso
//Seu nome é uma glória
//Ponte Preta sempre sempre
//Na derrota e na vitória

//És a nossa Ponte Preta
//Orgulho de nossa terra
//Ponte Preta de paz
//onte Preta de guerra
//Ponte Preta de paz
//Ponte Preta de guerra

//Estandarte desfraldado
//Preto e branco é sua cor
//Ponte Preta vai pro campo
//Pra mostrar o seu valor

//Ponte Preta inflamante
//Ponte Preta emoção
//Ponte Preta gigante
//Raça de campeão

//Seu estádio é o Majestoso
//Seu nome é uma glória
//Ponte Preta sempre sempre
//Na derrota e na vitória

//És a nossa Ponte Preta
//Orgulho de nossa terra
//Ponte Preta de paz
//Ponte Preta de guerra
//Ponte Preta de paz
//Ponte Preta de guerra