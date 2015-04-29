//do
const int c = 261;
//re
const int d = 294;
//mi
const int e = 329;
//fa
const int f = 349;
//so
const int g = 391;
//so sustenido
const int gS = 415;
//la
const int a = 440;
//la sustenido
const int aS = 455;
//si
const int b = 466;
//do maior
const int cH = 523;
//do maior sustenido
const int cSH = 554;
//re maior
const int dH = 587;
//re maior sustenido
const int dSH = 622;
//mi maior sustenido
const int eH = 659;
//fa maior
const int fH = 698;
//fa maior sustenido
const int fSH = 740;
//so maior
const int gH = 784;
//so maior sustenido
const int gSH = 830;
//la maior
const int aH = 880;

const int buzzerPin = 3;

void setup()
{
//Setup pin modes
  pinMode(buzzerPin, OUTPUT);

}
 
void loop()
{

//toca a primeira parte
  parte1();

//toca a segunda parte
  parte2();
 
  variacao();

}

//metodo que toca a cancao
//primeiro parametro nota
//segundo duracao
void beep(int nota, int duracao)
{
//toca a nota no pino 3
  tone(buzzerPin, nota, duracao);
 

   delay(duracao);

//Para o tom no pino do alto falante
  noTone(buzzerPin);
 
  delay(50);

}

//parte 1 da musica
void parte1()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
}

//segunda parte
void parte2()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
}

//variacao
void variacao(){
//Variacao 1
beep(f, 250);  
  beep(gS, 500);  
  beep(f, 350);  
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);  
  beep(cH, 125);
  beep(eH, 650);
 
  delay(500);

//repete a segunda parte
  parte2();

//segunda variacao da musica
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);  
 
  delay(650);
}
- See more at: http://tecnologiaeciencia.com.br/arduino-marcha-imperial-star-wars/#sthash.ekJsNIet.dpuf
