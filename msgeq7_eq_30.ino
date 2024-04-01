//ESSE É O PROGRAMA CERTO ATUALIZADO PRO EQUALIZADOR

int analogPin=0;
int strobePin=2;
int resetPin=3;
int ledred=11;
int ledblue=10;
int ledgreen=9;
int spectrumValue[7];
int spectrumValue2[7];
int filter=220;
int i, j;

#include <binary.h>

//MATRIX
#include <LedControl.h>
int DIN = 11;
int CS =  12;
int CLK = 13;
LedControl lc=LedControl(DIN,CLK,CS,4);

byte som1[8] = {0x3C,0x42,0xBD,0xA5,0xA5,0xBD,0x42,0x3C};
byte som2[8] = {0x3C,0x42,0x81,0x99,0x99,0x81,0x42,0x3C};
byte som3[8] = {0x3C,0x7E,0xFF,0xE7,0xE7,0xFF,0x7E,0x3C};
byte column1[9] = {B10000000, B11000000, B11100000, B11110000, B11111000, B11111100, B11111110, B11111111, B11111111};
byte column2[9] = {B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111, B11111111};


void setup(){
  
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);


  //MATRIX
  for(int i=0; i<4;i++){
    lc.shutdown(i,false);       //The MAX72XX is in power-saving mode on startup
    lc.setIntensity(i,3);      // Set the brightness to maximum value
    lc.clearDisplay(i);         // and clear the display
     }
  printSound(som1);

  
}

void loop(){

  //MSGEQ7
  digitalWrite(resetPin, HIGH);
  digitalWrite(resetPin, LOW);
  for (i=0;i<7;i++){
    delayMicroseconds(36);
    digitalWrite(strobePin, LOW);
    delayMicroseconds(18);
    //delay(30);
    spectrumValue[i]=analogRead(analogPin);
    spectrumValue[i]=constrain(spectrumValue[i], filter, 1023);
    spectrumValue[i]=map(spectrumValue[i], filter,1023,0,8);
    spectrumValue2[i] = spectrumValue[i];
    Serial.print(spectrumValue[i]);
    Serial.print(" ");
    delayMicroseconds(18);
    digitalWrite(strobePin, HIGH);
  }
  Serial.println();
  


  //SETLEDS DA MATRIX
  j=6;
  for(int i=0;i<7;i++){
    lc.setColumn(1, j, column1[spectrumValue[i]]);
    lc.setColumn(2, i+1, column1[spectrumValue[i]]);
    j--;
  }
  


  //CAIXA DO GRAVE
  if(spectrumValue[0]>6){
    printSound(som2);
    printSound(som3);
    delay(1);
    lc.clearDisplay(0);
    lc.clearDisplay(3);
    printSound(som1);
  }


}

void printSound(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {

    lc.setRow(0,i,character[i]);
    lc.setRow(3,i,character[i]);

  }
}
