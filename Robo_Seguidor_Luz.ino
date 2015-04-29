/*
—————————————————————–
Projeto Robo Seguidor de Luz com LDR
Criado por Thiago Teixeira
—————————————————————–
*/

//pino analogico do LDR da Direita
int pinLDRDir = A0;
//variavel que receberá o valor do LDR da Direita
float LDRDir = 0;  
//pino analogico do LDR da Esquerda
int pinLDREsq = A5;
//variavel que receberá o valor do LDR da Esquerda
float LDREsq = 0;
//variavel que receberá o valor da distancia encontrada pelo
//Sensor Ultrassônico
int valorUS = 0;

//Pino do Sensor Ultrassônico
// que envia o sinal sonoro
int PINO_Gatilho =9;

//Pino do Sensor Ultrassônico
// que recebe o sinal sonoro emitido
int PINO_ECO  =8;

//pino de controle do motor da direita
int motor_di =12;

//pino de controle motor da esquerda
int motor_es =13;

void setup() {
//seta o pino de controle dos motores como saida
  pinMode(motor_di, OUTPUT);
  pinMode(motor_es, OUTPUT);

//Serial
  Serial.begin(9600);

//Seta o Estado padrão para o Sensor Ultrassonico
   pinMode(PINO_Gatilho, OUTPUT);
   pinMode(PINO_ECO, INPUT);
}

void loop(){
//chama o metodo que executa a leituira
//da distancia do objeto em relação ao Ultrassonico
  leituraSensorUltrassonico();

//faz a leitura da portas analogica do LDR
LDRDir = analogRead(pinLDRDir);
  LDREsq = analogRead(pinLDREsq);

//Printa os valores na tela (debug)
  Serial.print(“direita  “);
  Serial.println(LDRDir);
  Serial.print(“esquerda  “);
  Serial.println(LDREsq);

//Se o valor do sensor da esquersa for 80% direita
// O carrinho vira pra esquerda (aciona o motor da direita)
  if( LDREsq*0.80 >= LDRDir){
    digitalWrite(motor_es ,HIGH);
    digitalWrite(motor_di,LOW);
  }
//Senão o valor do sensor da direita for 80% esquerda
// O carrinho vira pra esquerda (aciona o motor da esquerda)
  else if( LDRDir*0.80 >= LDREsq){
    digitalWrite(motor_di,HIGH);
    digitalWrite(motor_es,LOW);
  }
//senão a distancia do Ultrassonico for maior que 25 cm
//o carrinho ira para frente
  else if(valorUS > 25){
    
    digitalWrite(motor_di,HIGH);
    digitalWrite(motor_es,HIGH);
  }
//o estado é mantido por 90 ms até fazer nova leitura
  delay(90);
//desliga os motores e mantem por 20 ms
  digitalWrite(motor_di,LOW);
  digitalWrite(motor_es,LOW);
  delay(20);

}
//metodo de leitura do sensor ultrassonico
void   leituraSensorUltrassonico(){
   
        //faz a leitura da distancia do objeto com o Sensor
        digitalWrite(PINO_Gatilho, LOW);
        delayMicroseconds(2);
        digitalWrite(PINO_Gatilho, HIGH);
        delayMicroseconds(10);
        digitalWrite(PINO_Gatilho, LOW);
        
        unsigned long valor = pulseIn(PINO_ECO, HIGH);
        //captura a distacia do objeto lido do Sensor
        valorUS = valor/58;
        Serial.println(valorUS);
}
- See more at: http://tecnologiaeciencia.com.br/robo-arduino-seguidor-de-luz/#sthash.rHiR8Q5J.dpuf
