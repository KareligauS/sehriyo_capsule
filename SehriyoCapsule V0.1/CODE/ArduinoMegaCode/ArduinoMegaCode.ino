#include<Servo.h>

#define CELL_BEGIN_PIN 4

Servo cell[3];

char buff[50] = {'\0'};

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  for(int i=0; i<3; i++){
    cell[i].attach(CELL_BEGIN_PIN+i);
  }
}
void loop() {
  if(Serial3.available()){
    String get = Serial3.readStringUntil('\n');
    //Теперь запрос имеет вид: GET /OS012
    //get[5] - 'O' - Open (вроде)
    //get[6] - включен (S) или выключен (U) safe режим. (обрабатывается только S случай)
    //get[7-9] - номера ячеек.
    
    if(get[5]=='O'){
      byte to_open = 0;
      byte index;
      for (int i = 0; i<3; i++){
        index = get[7+i]-'0';
        if(index>=0&&index<=2){
          bitWrite(to_open, index, true);
        }
      }
      
      cellMove(to_open, get[6]);
      Serial.println(get); 
    }
  }
}

void cellMove(byte command, char mode){
  static bool is_open = false; //Как это работает?
  for(int i = 0; i<3; i++){
    if(bitRead(command,i)){
      is_open?
        Serial.println(static_cast<String>("CLOSE: ")+static_cast<String>(i+1)):
      is_open?
        cell[i].write(0) : //Это действие никогда не совершится. Зачем оно здесь?
        (mode != "S")? cell[i].write(90);
    }
  }
  is_open = !is_open;
}
