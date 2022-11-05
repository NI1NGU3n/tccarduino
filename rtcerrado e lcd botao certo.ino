//Programa : Relogio com modulo RTC DS1307
//Autor : FILIPEFLOP
 #define btn 6
//Carrega a biblioteca do RTC DS1307
#include <DS1307.h>
 #include <LiquidCrystal.h>
//código 2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Modulo RTC DS1307 ligado as portas A4 e A5 do Arduino 
DS1307 rtc(A4, A5);
 
void setup()
{
  pinMode(btn, INPUT);
    lcd.begin(16, 2);
  //Aciona o relogio
  rtc.halt(false);
   
  //As linhas abaixo setam a data e hora do modulo
  //e podem ser comentada apos a primeira utilizacao
  rtc.setDOW(FRIDAY);      //Define o dia da semana
  rtc.setTime(20, 37, 0);     //Define o horario
  rtc.setDate(6, 6, 2014);   //Define o dia, mes e ano
   
  //Definicoes do pino SQW/Out
  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);
   
  Serial.begin(9600);
}

void loop(){
  while (digitalRead(btn) == HIGH) {
      Serial.println("to vivo");
     
    }
  //Mostra as informações no Serial Monitor
  Serial.print("Hora : ");
  Serial.print(rtc.getTimeStr());
  Serial.print(" ");
  Serial.print("Data : ");
  Serial.print(rtc.getDateStr(FORMAT_SHORT));
  Serial.print(" ");
  Serial.println(rtc.getDOWStr(FORMAT_SHORT));
   
  //Aguarda 1 segundo e repete o processo
  
  delay (1000);
    lcd.setCursor(0, 1);
    lcd.println(rtc.getDOWStr(FORMAT_SHORT));
    lcd.setCursor(0, 0);
 lcd.println(rtc.getTimeStr());
}