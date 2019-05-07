unsigned int motorOut1 = 3;
unsigned int motorOut2 = 2;
unsigned int pwm = 9;
unsigned int sensorPin = A5;
unsigned int val = 0;
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 1000;


unsigned char receivedChar;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensorPin,INPUT);
pinMode(motorOut1,OUTPUT);
pinMode(motorOut2,OUTPUT);
pinMode(pwm,OUTPUT);
startMillis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
currentMillis = millis();  
 if (currentMillis - startMillis >= period)
  {
    val = analogRead(sensorPin);
     if (val >650)
     {
      Serial.println(val);}
     else{
      Serial.println(val);} 
      startMillis = currentMillis; 
  }
recInfo();
runMotor();
}
void recInfo(){
  if(Serial.available()>0)
  {
    receivedChar = Serial.read();
  }
}

void runMotor(){
  if (receivedChar == '1'){
    analogWrite(pwm,75);
    digitalWrite(motorOut1, HIGH);
    digitalWrite(motorOut2, LOW);
    delay(2000);
  }
  else if(receivedChar == '8')
  {
    analogWrite(pwm,0);}
  else{
    analogWrite(pwm,255);
    digitalWrite(motorOut1, HIGH);
    digitalWrite(motorOut2, LOW);
    delay(2000);
  }
}
