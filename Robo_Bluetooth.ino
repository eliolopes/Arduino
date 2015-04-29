//Contagem de milisegundos para os delays
unsigned long startMilis = 0;

//Conexao 1 (IN1) do motor 1 (M1) = 1N1M1
int IN1M1=5;
//Conexao 2 (IN1) do motor 1 (M1) = 1N2M1
int IN2M1=6;
//Enable do motor 1 (para controlar a velocidade e direção)
int ENAM1=4;

//Conexao 1 (IN1) do motor 1 (M2) = 1N1M2
int IN1M2=10;
//Conexao 2 (IN2) do motor 2 (M1) = 1N1M1
int IN2M2=11;
//Enable do motor 2 (para controlar a velocidade e direção)
int ENAM2=9;

void setup()
{
//Seta os Pinos dos Motores como Saida
 pinMode(IN1M1,OUTPUT);
 pinMode(IN2M1,OUTPUT);  
 
 pinMode(IN1M2,OUTPUT);
 pinMode(IN2M2,OUTPUT);  

  Serial.begin(9600);
}

void loop(){
//Captura o Caractere recebido na serial (bluetooth)
char c =Serial.read();

//1 =frente (chama o metodo mod e manda o inteiro que corresponde a direção)
 if(c == ’1′){
    mod(1);
 }
//2 =direita (fechada)
  if(c == ’2′){
    mod(2);
 }
//3 =esquerda (fechada)
if(c == ’3′){
    mod(3);
 }

//direita (aberta)
if(c == ’4′){
    mod(4);
 }

//esquerda (aberta)
  if(c == ’5′){
    mod(5);
 }
 
//para tras
  if(c == ’6′){
    mod(6);
 }
 
//parar
  if(c == ’0′){
    mod(0);
 }

//seta um valor diferente dos demais acima para parar o motor
  c =’ ‘;
//um pequeno delay para não parar os motores de imetiato
delay(25);

//para os motores
digitalWrite(IN2M1,LOW);
   digitalWrite(IN1M1,LOW);
   digitalWrite(IN2M2,LOW);
   digitalWrite(IN1M2,LOW);

}

//Metodo chamado dentro do loop
//que fará as ações nos motores
void mod(int x)
{

//instacia o contador
unsigned long currentMillis = millis();

// 0 =Parar
  if(x == 0)
     {

//Velocidade dos motores 0 para parar no pino ENA
  analogWrite(ENAM1, 0);
        analogWrite(ENAM2, 0);

//desliga todoas as portas para não haver rotacao
digitalWrite(IN1M1,LOW);
        digitalWrite(IN2M1,LOW);
 
        digitalWrite(IN1M2,LOW);
        digitalWrite(IN2M2,LOW);

//Irá para Frente
   }else if(x == 1)
  {
//Velocidade do Motor
       analogWrite(ENAM1, 1000);
        analogWrite(ENAM2, 1000);
        
//Direciona o Motor 1 para a Frente
     digitalWrite(IN1M1,LOW);
        digitalWrite(IN2M1,HIGH);
 
//Direciona o Motor 2 para a Frente
       digitalWrite(IN1M2,LOW);
       digitalWrite(IN2M2,HIGH);
  }

//3 =esquerda (fechada)
  else if(x == 3)
  {
//Apenas liga o motor da direita
//para virar para esquerda

//velocidade do motor
   analogWrite(ENAM1, 1000);

//rotacao do motor da direita para frente
     digitalWrite(IN1M1,LOW);
        digitalWrite(IN2M1,HIGH);

  }
//2 =direita (fechada)
  else if(x == 2)
  {
//Apenas liga o motor da esquerda
//para virar para direita

//velocidade do motor
   analogWrite(ENAM2, 1000);

//rotacao do motor da esquerda para frente
    digitalWrite(IN1M2,LOW);
     digitalWrite(IN2M2,HIGH);
  }
 
//5 =direta(aberta)
else if(x == 5)
  {
   
//liga ambos os motor da esquerda e direita
// porém o motor da esquerda ficara mais rapido
//para virar para direita

//velocidade dos motores
    analogWrite(ENAM1, 1000);
        analogWrite(ENAM2, 140);
        
//rotacao do motor da esquerda para frente
  digitalWrite(IN1M1,LOW);
        digitalWrite(IN2M1,HIGH);
 
//rotacao do motor da direita para frente
    digitalWrite(IN1M2,LOW);
       digitalWrite(IN2M2,HIGH);
     
 
  }
  else if(x == 4)
  {
  
//liga ambos os motor da esquerda e direita
// porém o motor da direita ficara mais rapido
//para virar para esquerda
        analogWrite(ENAM1, 140);
        analogWrite(ENAM2, 1000);
        
//rotacao do motor da esquerda para frente
      digitalWrite(IN1M1,LOW);
        digitalWrite(IN2M1,HIGH);
 
//rotacao do motor da direita para frente
       digitalWrite(IN1M2,LOW);
       digitalWrite(IN2M2,HIGH);
  }

//6 =re
  else if(x == 6)
  {
//Habilita ambos motores em velocidade maxima
analogWrite(ENAM1, 1000);
        analogWrite(ENAM2, 1000);

//rotacao do motor reversa da esquerda
       digitalWrite(IN1M1,HIGH);
        digitalWrite(IN2M1,LOW);
 
//rotacao do motor reversa da direita
     digitalWrite(IN1M2,HIGH);
       digitalWrite(IN2M2,LOW);
  }

//imprime o caracter enviado na serial (Para teste)
Serial.println(x);
}
- See more at: http://tecnologiaeciencia.com.br/projeto-de-robo-arduino-controlado-por-smartphone-ou-tablet-android/#sthash.K6iSbzIt.dpuf
