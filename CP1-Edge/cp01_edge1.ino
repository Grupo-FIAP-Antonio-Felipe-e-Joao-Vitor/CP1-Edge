#include <LiquidCrystal.h> //incluindo a biblioteca LiquidCrystal

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); //definindo a tela
int sensor = A0; //definindo o pino do sensor
int ledVerde = 13; //definindo o pino do led verde
int ledAmarelo = 9; //defininfo o pino do led amarelo
int ledVermelho = 8; //defininfo o pino do led vermelho
int buzzer = 7; //defininfo o pino do buzzer

int minOk = 30; //defininfo a porcentagem minima para ok
int maxOk = 50; //defininfo a porcentagem maxima para ok
int intervaloAlertaMin = minOk - 10; //definindo o intervalo minimo para estar em alerta
int intervaloAlertaMax = maxOk + 10; //definindo o intervalo maximo para estar em alerta


void exibirLogo() //criando a funcao para exibir o logo
{ // inicio da funcao
  lcd.begin(16,2); //inicializando a tela e especificando dimensoes      
  lcd.clear(); //limpando tela
  
  lcd.setCursor(0,0); //reposicionando cursor para (0, 0)        
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(15,0); //reposicionando cursor para (15, 0)
  lcd.print("-"); //ecrevendo "-" na tela
  delay(300); // espera 3 milisegundos
  
  lcd.setCursor(1,0); //reposicionando cursor para (1, 0)           
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(14,0); //reposicionando cursor para (14, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(300); //espera 3 milisegundos
  
  lcd.setCursor(2,0); //reposicionando cursor para (2, 0)          
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(13,0); //reposicionando cursor para (13, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(300); //espera 3 milisegundos 
  
  lcd.setCursor(3,0); //reposicionando cursor para (3, 0)                    
  lcd.print(" "); //escrevendo "-" na tela
  lcd.setCursor(12,0); //reposicionando cursor para (12, 0)          
  lcd.print(" "); //escrevendo "-" na tela
  delay(300); //espera 3 milisegundos
	
  lcd.setCursor(4, 0); //reposicionando cursor para (4, 0)
  lcd.print("Dev-Goat"); //escrevendo "Dev Goat" na tela
  delay(1000); //espera 1 segundo
  
  lcd.setCursor(3, 1); //reposicionando cursor para (3, 1)
  lcd.print("Bem-vindo!"); //escrevendo "Bem-vindo!" na tela
  delay(2000); //espera 2 segundos
} //fim da funcao

void exibirIluminacao () //criando a funcao para exbir a iluminacao
{ //inicio da funcao
  lcd.clear(); //limpando tela
  
  lcd.setCursor(0,0);  //reposicionando cursor para (0, 0)
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(15, 0);  //reposicionando cursor para (15, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(100); //espera 1 milisegundo
  
  lcd.setCursor(1,0); //reposicionando cursor para (1, 0)
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(14, 0); //reposicionando cursor para (14, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(100); //espera 1 milisegundo
  
  lcd.setCursor(2,0); //reposicionando cursor para (2, 0)
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(13, 0); //reposicionando cursor para (13, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(100); //espera 1 milisegundo
  
  lcd.setCursor(3,0); //reposicionando cursor para (3, 0)
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(12, 0); //reposicionando cursor para (12, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(100); //espera 1 milisegundo
  
  lcd.setCursor(4,0); //reposicionando cursor para (4, 0)
  lcd.print("-"); //escrevendo "-" na telaa
  lcd.setCursor(11, 0); //reposicionando cursor para (11, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(100); //espera 1 milisegundo
  
  lcd.setCursor(5,0); //reposicionando cursor para (5, 0)
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(10, 0); //reposicionando cursor para (10, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(100); //espera 1 milisegundo
  
  lcd.setCursor(6,0); //reposicionando cursor para (6, 0)
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(9, 0); //reposicionando cursor para (9, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(100); //espera 1 milisegundo
  
  lcd.setCursor(7,0); //reposicionando cursor para (7, 0)
  lcd.print("-"); //escrevendo "-" na tela
  lcd.setCursor(8, 0); //reposicionando cursor para (8, 0)
  lcd.print("-"); //escrevendo "-" na tela
  delay(100); //espera 1 milisegundo
  
  
  lcd.setCursor(0 ,1); //reposicionando cursor para (0, 1)
  lcd.print("Luz: "); //escrevendo "Luz: " na tela
} //fim da funcao

void setup() //funcao setup
{ //inicio da funcao
  pinMode(sensor, INPUT); //definindo o pin mode do sensor como input
  pinMode(ledVerde, OUTPUT); //definindo o pin mode do ledVerde como output
  pinMode(ledAmarelo, OUTPUT); //definindo o pin mode do ledAmarelo como output
  pinMode(ledVermelho, OUTPUT); //definindo o pin mode do ledVermelho como output
  pinMode(buzzer, OUTPUT); //definindo o pin mode do buzzer como output
  
  exibirLogo(); //chamando a funcao exibirLogo
  exibirIluminacao(); //chamando a funcao exibirIluminacao
} //fim da funcao

void loop() //funcao loop
{ //inicio da funcao
  float leitura = analogRead(sensor); //criando uma variavel do tipo float que recebe os valor do sensor
  int leituraPorcentagem = map(leitura, 344, 1017, 100, 0); //remapeando os valores da variavel leitura para um novo intervalo entre 0 e 100

  if (leituraPorcentagem >= minOk & leituraPorcentagem <= maxOk)  { //se leituraPorcentagem estiver dentro do intervalo ok
    digitalWrite(ledVerde, HIGH); //acende led verde
    digitalWrite(ledAmarelo, LOW); //apaga led amarelo
    digitalWrite(ledVermelho, LOW); //apaga led veermelho
    digitalWrite(buzzer, LOW); //para o alarme
  }
  else {
    if ((leituraPorcentagem >= intervaloAlertaMin & leituraPorcentagem < minOk) | leituraPorcentagem <= intervaloAlertaMax & leituraPorcentagem  > maxOk) { //se leituraPorcentagem estiver dentro do intervalo de alerta
      digitalWrite(ledVerde, LOW); //apaga led verde
      digitalWrite(ledAmarelo, HIGH); //acende led amarelo
      digitalWrite(ledVermelho, LOW); //apaga led vermelho
      for (int i = 0; i <= 4; i++){ //loop for, repete 5 vezes
          digitalWrite(buzzer, HIGH); //toca alarme
          delay(100); //espera 1 milisegindos
          digitalWrite(buzzer, LOW); //para o alarme
        }
    }
    else {
      if (leituraPorcentagem < intervaloAlertaMin | leituraPorcentagem  > intervaloAlertaMax){ //se leituraPorcentagem estiver dentro do intervalo critico
       	digitalWrite(ledVerde, LOW); //apaga led verde
        digitalWrite(ledAmarelo, LOW); //apaga led amarelo
        digitalWrite(ledVermelho, HIGH); //acende led vermelho
        digitalWrite(buzzer, HIGH); //toca alarme
      }
      else { //se leituraPorcentagem não estiver dentro de nenhum intervalo
      	digitalWrite(ledVerde, LOW); //apaga led verde
        digitalWrite(ledAmarelo, LOW); //apaga led amarelo
        digitalWrite(ledVermelho, LOW); //apaga led vermelho
        digitalWrite(buzzer, LOW); //para o alarme
      }
    }
  }
  
  
  
  lcd.setCursor(5, 1); //reposicionando cursor para (5, 1)
  lcd.print(leituraPorcentagem); //escrevendo o valor da variavel leituraPorcentagem na tela
  lcd.print("%"); //escrevendo "%" na tela
  delay(1000); //espera 1 segundo
} //fim da funcao


