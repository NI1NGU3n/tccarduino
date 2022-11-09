//Biblioteca para utilização de funções para protocolo I2C
#include <Wire.h>

// ARDUINO UNO 2 - PLACA MASTER

//I2C > 8BITS > 7BITS DE DADOS +
// 1BIT que define se a transmissão é escrita (0) ou leitura (1)
// ***MESTRE lê ou escreve no barramento

//Analog port 4 (A4) = SDA (serial data)
//Analog port 5 (A5) = SCL (serial clock)

// START CONDITION >

// início da transmissão I2C > borda de descida de SDA A4(0) +
// nível alto SCL A5(1)
// Temos que definir o endereço do escravo > 
// endereço_slave = 1 (0000001)
// 7 bits de endereço para o escravo
// como 2^7 = 128 podemos endereçar 128 escravos
// até 2^10 = 1024 escravos
// SDA envia o endereço em binário (0000001) que é lido através 
// das bordas de subida de SCL (clock) iniciando do bit + signif. 
// Após o envio do endereço, é selecionado o sentido da 
// transmissão (escrita ou leitura)
// Após o envio dos 8 bits (1Byte) >
// o slave deve dar um ACK (SDA = 0) > reconhecimento do mestre
// Mestre aguarda o envio do byte e se após ele SDA = 0 >
// Slave está pronto para a comunicação, caso SDA = 1 >
// Não existe o endereço/endereço errado, mestre considera NAK
// Após o ACK > envio do Byte de dados (MSB)
// Então ACK. **Para cada byte é necessário um ACK**

// STOP CONDITION > SDA (HIGH) SCL (HIGH)

//ENDEREÇO DO DISPOSITIVO ESCRAVO
const int endereco_escravo = 10;

//PINO DO BOTÃO
const int botao = 7;

//DADOS ENVIADOS PELO MESTRE AO ESCRAVO NESSA COMUNICAÇÃO
const char botao_pressionado = 'h';
const char botao_liberado = 'l';
//ESTADO DO BOTÃO

int estado_atual_botao = 0;
bool pressionado = false;


void setup()
{
  //INICIALIZANDO BARRAMENTO COMO MESTRE (sem argumento) 
  Wire.begin();
  
  //BAUD RATE PARA MOSTRAGEM NO MONITOR
  Serial.begin(9600);

  //DECLARA BOTÃO COMO ENTRADA PULL UP
  pinMode(botao,INPUT_PULLUP);

}

void loop()
{
  //LEITURA ESTADO DO BOTÃO
  estado_atual_botao = digitalRead(botao);
  
  //BOTÃO DESLIGADO INICIALMENTE E É PRESSIONADO
  if((estado_atual_botao == LOW) && (!pressionado))
  {
  	//INICIA A COMUNICAÇÃO ENVIANDO O ENDEREÇO DO ESCRAVO
      Wire.beginTransmission(endereco_escravo);
    
    //MOSTRA NO MONITOR A TRANSMISSÃO
	  Serial.println("Escravo:");
	  Serial.println(endereco_escravo);
    
    //ENVIO DOS DADOS > MESTRE ESCREVE NO BARRAMENTO
    //NESSE CASO > 'h'
      Wire.write(botao_pressionado);
    
    //MOSTRA NO MONITOR
	  Serial.println("Botao Pressionado:");
	  Serial.println(botao_pressionado);
    
	//ENCERRANDO A TRANSMISSÃO
      Wire.endTransmission();
    
	//ATUALIZAÇÃO DO ESTADO DO BOTÃO PARA A PRÒXIMA VERIFICAÇÃO
      pressionado = true;
    
    //MOSTRA NO MONITOR
	  Serial.println("Pressionado:");
	  Serial.println(pressionado);
  }
  //BOTAO NÃO ESTÁ MAIS PRESSIONADO
  else if((estado_atual_botao == HIGH) && pressionado)
  {
  
  //INICIA A COMUNICAÇÃO NOVAMENTE ENVIANDO O ENDEREÇO DO ESCRAVO
      Wire.beginTransmission(endereco_escravo);
    
    //MOSTRA NO MONITOR A TRANSMISSÃO
	  Serial.println("Escravo:");
	  Serial.println(endereco_escravo);
    
    //ENVIO DOS DADOS > MESTRE ESCREVE NO BARRAMENTO
    //NESSE CASO > 'l'
      Wire.write(botao_liberado);
    
    //MOSTRA NO MONITOR
	  Serial.println("Botao Liberado:");
	  Serial.println(botao_liberado);
    
	//ENCERRANDO A TRANSMISSÃO
      Wire.endTransmission();
    
	//ATUALIZAÇÃO DO ESTADO DO BOTÃO PARA A PRÒXIMA VERIFICAÇÃO
      pressionado = false;
    
    //MOSTRA NO MONITOR
	  Serial.println("Pressionado:");
	  Serial.println(pressionado);
  }

   delay(50); 
}