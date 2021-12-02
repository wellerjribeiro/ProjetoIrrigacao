#include <Servo.h> // biblioteca servo

Servo myservo; 
int m=0;
int n=0;
int pos = 0; 
void setup()
 {
  // coloque seu código de configuração aqui, para executar uma vez:
pinMode(A0, INPUT_PULLUP);           // Sensor de umidade do solo 1 PIN A0
pinMode(A1, INPUT_PULLUP);           // Sensor de umidade do solo 1 PIN A1
pinMode(8,OUTPUT);                             // Módulo de Relé PIN D8
Serial.begin(9600);                                  //  Taxa de Buart do Sensor
myservo.attach(9);                                   //  Servo PIN D9

digitalWrite(8, HIGH);                           // Relé normalmente alto para condição DESLIGADA
}

void loop() 
{

  // coloque seu código principal aqui, para executar repetidamente:

int m= analogRead(A0);                         // Sensor de umidade do solo 1 PIN A0
int n= analogRead(A1);                           // Sensor de umidade do solo 1 PIN A1
Serial.println(m);
delay(10);
Serial.println(n);
delay(200);
if (m>=980)
{
 myservo.write(90);              // diga ao servo para ir para a posição na variável 'pos'
        
  digitalWrite(8, LOW);       // Retransmissão ON
  delay(1000);
  }

else if(m<=970) 
{
 digitalWrite(8, HIGH);      // Retransmissão ON
 }

 if (n>=980)
{

  myservo.write(0);              // diga ao servo para ir para a posição na variável 'pos'
        
  digitalWrite(8, LOW);       // Retransmissão ON
  delay(1000);
  
  }

else if(n<=970)
{

  digitalWrite(8, HIGH);    // Retransmissão OFF
  }
  
else
{
  digitalWrite(8, HIGH);   // Retransmissão OFF
  }
}
