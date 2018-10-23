bool reading = false;
String headY = "";
String headCY = "";
String headZ = "";
String headCZ = "";
String mess[2] ="";
void setup() {
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  delay(100);
  analogWrite(7, 50);
  // Open Serial1 communications and wait for port to open:
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial1.println("Goodnight moon!");
  
}
int i = 0;
char data;
void loop() { // run over and over
  mess[0]="";
  mess[1]="";
  while (Serial1.available()) {
    data = char(int(Serial1.read()));
    if (data == '>') {  i = 0;reading = false;}
    if (reading == true){
      if (data == ':'){i = 1;}
      mess[i] += data;
      }
    if (data == '<') {  reading = true;}
    //Serial.print(mess[1]);
    delay(1);
  }
  if (digitalRead(22) == 0){
   headCY = "left";
   Serial.print("warn YLeft");
   Serial1.print("<stop:YLeft>");
    }else
  if (digitalRead(23) == 0){
   headCY = "right";
   Serial.print("warn YRight");
   Serial1.print("<stop:YRight>");
    } else {headCY="";}
  
  if (digitalRead(24) == 0){
   headCZ = "left";
   Serial.print("warn ZLeft");
   Serial1.print("<stop:ZLeft>");
    }
  
  if (digitalRead(25) == 0){
   headCZ = "right";
   Serial.print("warn ZRight");
   Serial1.print("<stop:ZRight>");
    }
  
  
  if (digitalRead(26) == 0){
   Serial.print("warn Left arm block");
   Serial1.print("<stop:LAUp>");
    }
  
  if (digitalRead(27) == 0){
   Serial.print("warn Left arm block");
   Serial1.print("<stop::ADown>");
    }
  
  if (digitalRead(25) == 0){
   Serial.print("warn Right arm block");
   Serial1.print("<stop:RAUp>");
    }
  
  if (digitalRead(29) == 0){
   Serial.print("warn Right arm block");
   Serial1.print("<stop:RADown>");
    }
if (mess[0] == "turn1"){
    if (mess[1] == ":0"){
      headY  = "right";
          Serial.print("right");
      analogWrite(11, 0);
      digitalWrite(10, 8);
      } 
     if (mess[1] == ":1"){
      headY  = "left";
          Serial.print("left");
      analogWrite(11, 0);
      digitalWrite(10, 0);
      }
    }
  if (mess[0] == "turn2"){
    if (mess[1] == ":1"){
      headZ  = "left";
          Serial.print("Zleft");
      analogWrite(9, 0);
      digitalWrite(8, 8);
      }
     if (mess[1] == ":0"){
      headZ  = "right";
          Serial.print("ZRIGHT");
      analogWrite(9, 0);
      digitalWrite(8, 0);
      }
    }
  if (headCY != headY){
    if (mess[0] == "speed1"){
    if (mess[1] != 0){
      analogWrite(11, 8);
      } else {
         analogWrite(11, 0);
         
      }
      }
  } else {
      analogWrite(11, 0);
  }
  if (headCZ != headZ){
  if (mess[0] == "speed2"){
    if (mess[1] != 0){
      analogWrite(9, 8);
      } else {
      analogWrite(9, 0);
      }
    }
  } else {
      analogWrite(9, 0);
  }

  
  if (mess[0] == "stop1"){
      analogWrite(11, 0);
    }
  if (mess[0] == "stop2"){
      analogWrite(9, 0);
    }
   
}

