//www.tecnologiaeciencia-------------------------
// por Thiago Teixeira--------------------------
 
// Pinos do Sensor da esquerda
const int trigPin_es =2;
const int echoPin_es =3;
 
// Pinos do Sensor da direita
const int trigPin_di =8;
const int echoPin_di =13;
 
//Conexao 1 (IN1) do motor 1 (M1) = 1N1M1
int IN1M1=6;
//Conexao 2 (IN1) do motor 1 (M1) = 1N2M1
int IN2M1=5;
//Enable do motor 1 (para controlar a velocidade e direção)
int ENAM1=4;
 
//Conexao 1 (IN1) do motor 1 (M2) = 1N1M2
int IN1M2=11;
//Conexao 2 (IN2) do motor 2 (M1) = 1N1M1
int IN2M2=10;
//Enable do motor 2 (para controlar a velocidade e direção)
int ENAM2=9;
 
// variavel que armazenara
// a distancia do objeto visto do Sensor direito
int distancia_di =0;
// variavel que armazenara
// a distancia do objeto visto do Sensor esquerdo
int distancia_es =0;
 
void setup()
{
//Serial
  Serial.begin(9600);
 
//Seta os pinos do do Sensor da direita
//(trigger saida)
//(echo entrada)
   pinMode(trigPin_di, OUTPUT);
   pinMode(echoPin_di, INPUT);
 
//Seta os pinos do do Sensor da esquerda
//(trigger saida)
//(echo entrada)
   pinMode(trigPin_es, OUTPUT);
   pinMode(echoPin_es, INPUT);
 
//motor1
pinMode(IN1M1,OUTPUT);
   pinMode(IN2M1,OUTPUT);  
 
//motor2
  pinMode(IN1M2,OUTPUT);
   pinMode(IN2M2,OUTPUT);
 
}
 
void loop(){
 
//faz a leitura da distancia do objeto com o Sensor da direita
digitalWrite(trigPin_di, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin_di, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin_di, LOW);
 
        unsigned long duracao_di = pulseIn(echoPin_di, HIGH);
//captura a distacia do objeto lido do Sensor da direita
      distancia_di = duracao_di / 58;
 
//Imprime na Tela (para teste)
Serial.print("A Distancia em CM direita : ");
        Serial.println(distancia_di);
 
//faz a leitura da distancia do objeto com o Sensor da esquerda
  digitalWrite(trigPin_es, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin_es, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin_es, LOW);
       
        unsigned long duracao_es= pulseIn(echoPin_es, HIGH);
//captura a distacia do objeto lido do Sensor da esquerda
distancia_es = duracao_es / 58;
 
//Imprime na Tela (para teste)
  Serial.print("A Distancia em CM esquerda : ");
       Serial.println(distancia_es);
 
//Se a distancia lida pelos sensores for maior que 25
//a plataforma se desloca para a frente
      if((distancia_di >25) && (distancia_es > 25)){
 
//Velocidade dos motores
  analogWrite(ENAM2, 1000);
                 analogWrite(ENAM1, 1000);
 
//Rotação Frontal
digitalWrite(IN1M1,HIGH);
                 digitalWrite(IN2M1,LOW);
 
//Rotação Frontal
  digitalWrite(IN1M2,HIGH);
                 digitalWrite(IN2M2,LOW);
 
   Serial.println("frente");
               
//desliga os motores e recomeca o loop
  desligaMotor();
 
//Se a distancia lida pelos sensores for menor que 25
//a plataforma se desloca para esquerda em torno de si
  }else if((distancia_di <25) && (distancia_es < 25)){
             
//Velocidade dos motores
   analogWrite(ENAM2, 1000);
               analogWrite(ENAM1, 1000);
             
//Rotação Reversa motor 1
  digitalWrite(IN1M1,LOW);
               digitalWrite(IN2M1,HIGH);
 
//Rotação Frontal motor 2
  digitalWrite(IN1M2,HIGH);
               digitalWrite(IN2M2,LOW);
               
Serial.println("retorno");
                delay(100);
//desliga os motores e recomeca o loop
   desligaMotor();
           
 
//se o objeto lido estiver proximo ao Sensor da direita
//a plataforma desloca para esquerda em torno de si
      }else if((distancia_di <25) && (distancia_es > 25)){
           
//Velocidade dos motores
   analogWrite(ENAM2, 1000);
                 analogWrite(ENAM1, 1000);
 
//Rotação Reversa motor 1
digitalWrite(IN1M1,LOW);
                 digitalWrite(IN2M1,HIGH);
 
//Rotação Frontal motor 2
digitalWrite(IN1M2,HIGH);
                 digitalWrite(IN2M2,LOW);
 
   Serial.println("esquerda");
                  delay(200);
//desliga os motores e recomeca o loop
desligaMotor();
 
//se o objeto lido estiver proximo ao Sensor da esquerda
//a plataforma desloca para direita em torno de si
     }else if((distancia_es <25) && (distancia_di > 25)){
 
//Velocidade dos motores
       analogWrite(ENAM2, 1000);
                 analogWrite(ENAM1, 1000);
 
//Rotação Frontal motor 1
  digitalWrite(IN1M1,HIGH);
                 digitalWrite(IN2M1,LOW);
 
//Rotação Reversa motor 2
digitalWrite(IN1M2,LOW);
                 digitalWrite(IN2M2,HIGH);  
             
                  Serial.println("direita");  
                  delay(200);
               
//desliga os motores e recomeca o loop
   desligaMotor();
 
   }
 
}
 
//metodo que desliga os motores para recomecar
//novas leitura
void desligaMotor(){
 
delay(200);
 
//desliga os motores
  digitalWrite(IN2M1,LOW);
       digitalWrite(IN1M1,LOW);
       digitalWrite(IN2M2,LOW);
       digitalWrite(IN1M2,LOW);
       delay(10);
           
//zera os motores
analogWrite(ENAM2, 0);
       analogWrite(ENAM1, 0);
               
 
}
