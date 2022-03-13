#include<Servo.h>

#define CELL_BEGIN_PIN 4

Servo cell[3];

char buff[50] = {'\0'};

bool block = 0;

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  for(int i=0; i<3; i++){
    cell[i].attach(CELL_BEGIN_PIN+i);
    cell[i].write(0);
  }
}
void loop() {
  if(Serial3.available()){
    String get = Serial3.readStringUntil('\n');
    if(get[5]=='O' && block==0){
      byte to_open = 0;
      byte index;
      index = get[6]-'0';
      if(index>=0&&index<=2){
        bitWrite(to_open, index, true);
      }
      index = get[8]-'0';
      if(index>=0&&index<=2){
        bitWrite(to_open, index, true);
      }
      index = get[10]-'0';
      if(index>=0&&index<=2){
        bitWrite(to_open, index, true);
      }
      Serial.println(to_open,BIN);
      cellMove(to_open);
    }
    else if(get[5]=='C'){
      block=!block;
      block==true?Serial.println("BLOCK ALL"):Serial.println("UNBLOCK ALL");
      cell[0].write(90);
      cell[1].write(90);
      cell[2].write(90);
    }
    Serial.println(get);    
  }
}
void cellMove(byte command){
  bool is_open = command;
  for(int i = 0; i<3; i++){
    if(bitRead(command,i)){
      is_open?
        Serial.println(static_cast<String>("CLOSE: ")+static_cast<String>(i+1)):
        Serial.println(static_cast<String>("OPEN: ")+static_cast<String>(i+1));
      is_open?
        cell[i].write(0): 
        cell[i].write(90);
    }
  }
}
