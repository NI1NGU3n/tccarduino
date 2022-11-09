//Biblioteca para utilização de funções I2C
#include <Wire.h>

// ARDUINO UNO 2 - PLACA ESCRAVO

//DEFINE PINO LED
int LED = 13;

void setup()
{
  
  //DEFINE LED COMO SAÍDA
  	pinMode(LED,OUTPUT);
  
  //ESTADO PADRÃO DO LED > DESLIGADO
  	digitalWrite(LED,LOW);
  
  //INICIALIZAÇÃO DO BARRAMENTO COM O ESCRAVO
  //NESSE CASO, HÁ ARGUMENTO QUE É O PRÓPRIO END. DO ESCRAVO
  	Wire.begin(10);
  
  //FUNÇÃO QUE INDICA UMA FUNÇÃO QUE TRABALHA A MENSAGEM DO MESTRE
  	Wire.onReceive(RecebeMsg);

}

void loop()
{
	//NESSE CASO, ESCRAVO APENAS RECEBE A INFORMAÇÃO DO MESTRE
}

void RecebeMsg(int howMany)
{
  //FUNÇÃO QUE INDICA QUANDO O BARRAMENTO ESTÁ DISPONÍVEL
  while(Wire.available())
  	{
    	//LEITURA DO DADO RECEBIDO
    	char c = Wire.read();
    	
    	//SE BOTÃO PRESSIONADO RECEBE H
       	if( c == 'h' )
        {
      		digitalWrite(LED,HIGH); //ACIONA LED
          Serial.println(c);
    	} 
    	//SE BOTÃO LIBERADO RECEBE L
   	 	else if( c == 'l' )
    	{
      		digitalWrite(LED,LOW); //DESLIGA LED
  	  	}
    }
}