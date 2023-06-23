//Pines
#define Pin_Lock 23
#define Pin_Wave_In 22
#define Pin_Fist 21
#define Pin_Fingers_Spread 19
#define Pin_Wave_Out 18
#define Pin_led 2

//Variables
String cad="";
String pose="", mode="";
int pos=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(30);

  pinMode(Pin_Lock, OUTPUT);
  pinMode(Pin_Wave_In, OUTPUT);
  pinMode(Pin_Fist, OUTPUT);
  pinMode(Pin_Fingers_Spread, OUTPUT);
  pinMode(Pin_Wave_Out, OUTPUT);
  pinMode(Pin_led, OUTPUT);

  for(int i=0;i<=5;i++)
  { 
  digitalWrite(Pin_Wave_In,!digitalRead(Pin_Wave_In));
  digitalWrite(Pin_Fist,!digitalRead(Pin_Fist));
  digitalWrite(Pin_Fingers_Spread,!digitalRead(Pin_Fingers_Spread));
  digitalWrite(Pin_Wave_Out,!digitalRead(Pin_Wave_Out));
  digitalWrite(Pin_led,!digitalRead(Pin_led));
  delay(300);
  }

  digitalWrite(Pin_Lock, 1);

}


void F_Rest_Pose(){
  digitalWrite(Pin_led, 0);
  digitalWrite(Pin_Wave_In, 0);
  digitalWrite(Pin_Fist, 0);
  digitalWrite(Pin_Fingers_Spread, 0);
  digitalWrite(Pin_Wave_Out, 0);
  digitalWrite(Pin_led, !digitalRead(Pin_led));
  delay(500);
}

void F_WaveIn_Pose(){
  digitalWrite(Pin_led, 0);
  digitalWrite(Pin_Wave_In, 0);
  digitalWrite(Pin_Fist, 0);
  digitalWrite(Pin_Fingers_Spread, 0);
  digitalWrite(Pin_Wave_Out, 0);
  digitalWrite(Pin_Wave_In, 1);
}

void F_Fist_Pose(){
  digitalWrite(Pin_led, 0);
  digitalWrite(Pin_Wave_In, 0);
  digitalWrite(Pin_Fist, 0);
  digitalWrite(Pin_Fingers_Spread, 0);
  digitalWrite(Pin_Wave_Out, 0);
  digitalWrite(Pin_Fist, 1);
}

void F_FingersSpread_Pose(){
  digitalWrite(Pin_led, 0);
  digitalWrite(Pin_Wave_In, 0);
  digitalWrite(Pin_Fist, 0);
  digitalWrite(Pin_Fingers_Spread, 0);
  digitalWrite(Pin_Wave_Out, 0);
  digitalWrite(Pin_Fingers_Spread, 1);
}

void F_WaveOut_Pose(){
  digitalWrite(Pin_led, 0);
  digitalWrite(Pin_Wave_In, 0);
  digitalWrite(Pin_Fist, 0);
  digitalWrite(Pin_Fingers_Spread, 0);
  digitalWrite(Pin_Wave_Out, 0);
  digitalWrite(Pin_Wave_Out, 1);
}

void loop() {
  // put your main code here, to run repeatedly:


  if(Serial.available()){
    cad = Serial.readString();
    //cad=mode+","+pose
    pos = cad.indexOf(',');
    mode = cad.substring(0,pos);
    pose = cad.substring(pos+1);
  
  }

  if(mode == "locked") 
  {
    digitalWrite(Pin_Lock,1);
    Serial.println("\nMyo locked");
  }

  else if(mode == "unlocked"){

    digitalWrite(Pin_Lock,0);

    Serial.println("\nMyo unlocked");
    Serial.println(pose);

    if (pose.equals("rest")) {
      F_Rest_Pose();
      Serial.println("rest");
    } 

    else if (pose.equals("waveIn")) {
      F_WaveIn_Pose();
      Serial.println("waveIn");
    } 

    else if (pose.equals("fist")) {
      F_Fist_Pose();
      Serial.println("fist");
    } 

    else if (pose.equals("fingersSpread")) {
      F_FingersSpread_Pose();
      Serial.println("fingersSpread");
    } 
    
    else if (pose.equals("waveOut")) {
      F_WaveOut_Pose();
      Serial.println("waveOut");
    } 
    
    else pose = "";

  }

}

