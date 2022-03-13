#include<Servo.h>

#define CELL_BEGIN_PIN 4

Servo cell[3];

char buff[50] = {'\0'};

bool block = 0;
byte is_open;

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  for(int i=0; i<3; i++){
    cell[i].attach(CELL_BEGIN_PIN+i);
    cell[i].write(90);
    is_open = 0;
  }
}
void loop() {
  if(Serial3.available()){
    String get = Serial3.readStringUntil('\n');
    //Теперь запрос имеет вид: GET /O012
    //get[5] - Режим (O - Open, С - Close)
    //get[6-8] - номера ячеек.
    if(get[5]=='O' && block==0){
      byte to_open = 0;
      byte index;
      for (int i = 0; i<3; i++){
        index = get[6+i*2]-'0';
        if(index>=0&&index<=2){
          bitWrite(to_open, index, true);
        }
      }
      Serial.println(to_open,BIN);
      cellMove(to_open);
    }
    else if(get[5]=='C'){
      block=!block;
      block==true? Serial.println("BLOCKMODE Activated"):Serial.println("BLOCKMODE Deactivated");
    }

    if (block){
      for(int i = 0; i<3; i++){
        cell[i].write(90);
        is_open = 0;
      }
    }
    
    Serial.println(get);    
  }
}
void cellMove(byte command){
  for(int i = 0; i<3; i++){
    if(bitRead(command,i)){
      bitRead(is_open, i)?
        Serial.println(static_cast<String>("CLOSE: ")+static_cast<String>(i+1)):
        Serial.println(static_cast<String>("OPEN: ")+static_cast<String>(i+1));
      bitRead(is_open, i)?
        cell[i].write(90): 
        cell[i].write(0);
      bitRead(is_open, i)?
        bitWrite(is_open, i, false): bitWrite(is_open, i, true);
    }
    
  }
}
