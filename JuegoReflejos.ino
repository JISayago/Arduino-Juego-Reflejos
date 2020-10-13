#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool juego_seleccionado = false;
bool a_tiempo = false;
bool tiempo_seleccionado = false;

unsigned long el_tiempo;
unsigned long tiempo_prendido;
unsigned long tiempo_push;

long tiempo_menos_nivel = 100;
long tiempo_base = 3000;
long tiempo_diferencia = 0;
long opcion_tiempo = 0;

long tiempos[]={1000,1200,1400,1600,1800,2000,2200,2400,2600,2800,3000};

double mejor = 9999.00;
double opcion_tiempo_decimal;                         
double tiempo_mejor_decimal;

int menuOpcion[] = {1,2,3};
int opcion = 0;//opcion seleccionada en menu()

int i = 0;//iteraciones en menu()
int i2 = 0;//iteracion muestra lcd nivel 2
int i3 = 0;//iteraciones menuTiempos()
int i4 = 0;//iteracion muestra lcd nivel 3
int nivel = 1;

int ledD = 6;
int ledC = 7;
int ledI = 13;

int cmC = 0;
int cmD = 0;
int cmI = 0;

int contador_aciertos = 0;
int contador_fallos = 0;

int leds[] = {ledD,ledC,ledI};
int ledRandom = 0;

//+++++++++++++++++++++++++++++++++++++INICIO++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++JUEGO_ENTRENAMIENTO_UNO++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void juego_uno_entrenamiento(long opcion_tiempo){// inicio funcion juego 1

     contador_aciertos = 0;
     contador_fallos = 0;

     tiempo_base = opcion_tiempo;
   
     while(contador_fallos<51)
     {
         tiempo_prendido = millis();     
         
         lcd.clear();
         lcd.setCursor(0, 0);
         lcd.print("Aciertos: ");
         lcd.print(contador_aciertos);
         lcd.setCursor(0, 1);
         lcd.print("Fallos: ");
         lcd.print(contador_fallos); 
    
         ledRandom = leds[random(0,3)];
         digitalWrite(ledRandom,HIGH);
         el_tiempo = millis();
       
       /////////////////////////////////////////////////      
        if(digitalRead(ledC)==HIGH)
        { // inicio led HIGH  
          
          while(millis() - el_tiempo <= tiempo_base)
          {//inicio while tiempo
             cmC = 0.01723 * readUltrasonicDistance(9,9);
              if(cmC <= 40)
              { 
                a_tiempo = true;
                
                tiempo_push=millis();
                
                digitalWrite(ledRandom,LOW);
                
                el_tiempo = -tiempo_base;//para salir del while
      
              }
              else 
              {
               a_tiempo = false;
              }
          }//end while tiempo
        
          if(a_tiempo){

             contador_aciertos++;
            
             tiempo_diferencia = tiempo_push - tiempo_prendido;        
          }
          else
          {
            contador_fallos++;
            tiempo_diferencia = 9999;
          }
          
           delay(150);
           digitalWrite(ledRandom,LOW);
             if(tiempo_diferencia < mejor)
               {//inicio if tiempoDiferencia ... tiempoMejor 
                mejor = tiempo_diferencia;
                 
                 tiempo_mejor_decimal = mejor/1000;
                 
               }//end if tiempoDiferencia ... tiempoMejor 

    
           }//end if led HIGH 
           
           
      
       ////////////////////////////////////////////
       
        if(digitalRead(ledD)==HIGH)
        { // inicio led HIGH  
          
          while(millis() - el_tiempo <= tiempo_base)
          {//inicio while tiempo
             cmD = 0.01723 * readUltrasonicDistance(8,8);
              if(cmD <= 40){     
                       
                a_tiempo = true;
                
                tiempo_push=millis();
                
                digitalWrite(ledRandom,LOW);
                
                el_tiempo = -tiempo_base;//para salir del while
      
              }
              else {
      
               a_tiempo = false;
                
              }
          }//end while tiempo
        
          if(a_tiempo){
            
             contador_aciertos++;
            
             tiempo_diferencia = tiempo_push - tiempo_prendido;
        
          }
          else{
             contador_fallos++;
            tiempo_diferencia = 9999;
          }
          
           delay(150);
           digitalWrite(ledRandom,LOW);
           if(tiempo_diferencia < mejor)
           {//inicio if tiempoDiferencia ... tiempoMejor 
               mejor = tiempo_diferencia;
             
                 tiempo_mejor_decimal = mejor/1000;
                
            }//end if tiempoDiferencia ... tiempoMejor 

    
           }//end if led HIGH 
           
                 
       //////////////////////////////////////////////
         if(digitalRead(ledI)==HIGH)
        { // inicio led HIGH  
          
          while(millis() - el_tiempo <= tiempo_base)
          {//inicio while tiempo
             cmI = 0.01723 * readUltrasonicDistance(10,10);
              if(cmI <= 40){     
                       
                a_tiempo = true;
                
                tiempo_push=millis();
                
                digitalWrite(ledRandom,LOW);
                
                el_tiempo = -tiempo_base;//para salir del while
      
              }
              else {
      
               a_tiempo = false;
                
              }
          }//end while tiempo
        
          if(a_tiempo){
            
             contador_aciertos++;
            
             tiempo_diferencia = tiempo_push - tiempo_prendido;
        
          }
          else{
             contador_fallos++;
            tiempo_diferencia = 9999;
          }
          
           delay(150);
           digitalWrite(ledRandom,LOW);
             if(tiempo_diferencia < mejor)
           {//inicio if tiempoDiferencia ... tiempoMejor 
                mejor = tiempo_diferencia;
                 
                 tiempo_mejor_decimal = mejor/1000;
                 
            }//end if tiempoDiferencia ... tiempoMejor 

    
           }//end if led HIGH 
           
           
       //////////////////////////////////////////////      
       
        delay(50);
        digitalWrite(ledRandom,LOW);
     
       
         if(digitalRead(A5) == HIGH && digitalRead(A4) == HIGH){
          contador_fallos = 51;
        }
 
      }//end while de fallos
  
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Mejor Reaccion: ");
     lcd.setCursor(0,1);
     lcd.print(tiempo_mejor_decimal); 
     lcd.print(" segundos");
     delay(2000);
   
}//end funcion juego 1
//+++++++++++++++++++++++++++++++++++++FINAL++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++JUEGO_ENTRENAMIENTO_UNO++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


//+++++++++++++++++++++++++++++++++++++INICIO++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++JUEGO_NIVELES_DOS++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
   
void juego_dos_niveles(){//inicio funcion juego 2
  
      contador_aciertos = 0;
      contador_fallos = 0;  
  
      tiempo_menos_nivel = 100;
      tiempo_base = 3000;  
     
      nivel = 1;
  
      while(contador_fallos<2){ //inicio while fallos
           tiempo_prendido = millis();
   
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("Aciertos: ");
           lcd.print(contador_aciertos);
           lcd.setCursor(0, 1);
           lcd.print("Fallos: ");
           lcd.print(contador_fallos);  
    
           ledRandom = leds[random(0,3)];
           digitalWrite(ledRandom,HIGH);
           el_tiempo = millis();
 
  
   /////////////////////////////////////////////////      
           if(digitalRead(ledC)==HIGH){ // inicio led HIGH             
              
               while(millis() - el_tiempo <= tiempo_base) {//inicio while tiempo             
                  cmC = 0.01723 * readUltrasonicDistance(9,9);
                   if(cmC <= 40){     
                       
                       a_tiempo = true;
                
                       tiempo_push=millis();
                
                       digitalWrite(ledRandom,LOW);
                
                       el_tiempo = -tiempo_base;//para salir del while
                         
                   }
                   else {
      
                      a_tiempo = false;
                
                   }
                }//end while tiempo
        
              if(a_tiempo){
            
                 contador_aciertos++;
            
                 tiempo_diferencia = tiempo_push - tiempo_prendido;
                
                 tiempo_base = tiempo_base - tiempo_menos_nivel;
        
              }
              else{
                 contador_fallos++;
                 tiempo_diferencia = 9999;
              }
          
           delay(150);
           digitalWrite(ledRandom,LOW);

            if(tiempo_diferencia < mejor){//inicio if tiempoDiferencia ... tiempoMejor 
                            
                 mejor = tiempo_diferencia;               
                            
                 tiempo_mejor_decimal = mejor/1000;
                
            }//end if tiempoDiferencia ... tiempoMejor       

    
           }//end if led HIGH 
           
           
       
       ////////////////////////////////////////////
       
        if(digitalRead(ledD)==HIGH){ // inicio led HIGH  
               
          while(millis() - el_tiempo <= tiempo_base)  {//inicio while tiempo
             cmD = 0.01723 * readUltrasonicDistance(8,8);
              if(cmD <= 40){     
                       
                a_tiempo = true;
                
                tiempo_push=millis();
                
                digitalWrite(ledRandom,LOW);
                
                el_tiempo = -tiempo_base;//para salir del while
      
              }
              else {
      
               a_tiempo = false;
                
              }
          }//end while tiempo
        
          if(a_tiempo){
            
             contador_aciertos++;
            
             tiempo_diferencia = tiempo_push - tiempo_prendido;
            
             tiempo_base = tiempo_base - tiempo_menos_nivel;
        
          }
          else{
             contador_fallos++;
             tiempo_diferencia = 9999;
          }
          
           delay(150);
           digitalWrite(ledRandom,LOW);
            if(tiempo_diferencia < mejor)
           {//inicio if tiempoDiferencia ... tiempoMejor 
                
                 mejor = tiempo_diferencia;
             
                 tiempo_mejor_decimal = mejor/1000;
                 
                
            }//end if tiempoDiferencia ... tiempoMejor 
    
           }//end if led HIGH 
           
          


       
       //////////////////////////////////////////////
         if(digitalRead(ledI)==HIGH)
        { // inicio led HIGH  
          
          while(millis() - el_tiempo <= tiempo_base)
          {//inicio while tiempo
             cmI = 0.01723 * readUltrasonicDistance(10,10);
              if(cmI <= 40){     
                       
                a_tiempo = true;
                
                tiempo_push=millis();
                
                digitalWrite(ledRandom,LOW);
                
                el_tiempo = -tiempo_base;//para salir del while
      
              }
              else {
      
               a_tiempo = false;
                
              }
          }//end while tiempo
        
          if(a_tiempo){
            
             contador_aciertos++;
            
             tiempo_diferencia = tiempo_push - tiempo_prendido;
            
             tiempo_base = tiempo_base - tiempo_menos_nivel;
        
          }
          else{
             contador_fallos++;
            tiempo_diferencia = 9999;
          }
          
           delay(150);
           digitalWrite(ledRandom,LOW);

               if(tiempo_diferencia < mejor)
           {//inicio if tiempoDiferencia ... tiempoMejor 
                
                 mejor = tiempo_diferencia;  
                 
                 tiempo_mejor_decimal = mejor/1000;
                 
                
            }//end if tiempoDiferencia ... tiempoMejor 
    
           }//end if led HIGH 
           
         
       

       //////////////////////////////////////////////      
       
        delay(50);
        digitalWrite(ledRandom,LOW);
        
          if(digitalRead(A5) == HIGH && digitalRead(A4) == HIGH){
       contador_fallos = 5;
       }
        Serial.println(tiempo_base);
 
           if(tiempo_base == 300){
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("Felicidades");
           lcd.setCursor(0,1);
           lcd.print("llego al nivel maximo:");
           lcd.print(nivel); 
           delay(2500);
           }
        
            nivel++;
   
  }  //end while de fallos  
  
          while(i2<5){
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("Mejor Reaccion: ");
           lcd.setCursor(0,1);
           lcd.print(tiempo_mejor_decimal); 
           lcd.print(" segundos");
           delay(750);
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("Nivel Alcanzado: ");
           lcd.setCursor(0,1);
           lcd.print(nivel-3); 
           delay(750);
            i2++;           
        }
  
}//fin funcion juego 2

//+++++++++++++++++++++++++++++++++++++FINAL++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++JUEGO_NIVELES_DOS++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//



//+++++++++++++++++++++++++++++++++++++INICIO++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++JUEGO_ERRORES_TRES+++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


void juego_errores_tres(long opcion_tiempo){// inicio funcion juego 3

     contador_aciertos = 0;
     contador_fallos = 0;
     tiempo_base = opcion_tiempo;
     tiempo_menos_nivel = 100;
     nivel = 1;
     
   
     while(contador_fallos<3){

        tiempo_prendido = millis();     
         
         lcd.clear();
         lcd.setCursor(0, 0);
         lcd.print("Aciertos: ");
         lcd.print(contador_aciertos);
         lcd.setCursor(0, 1);
         lcd.print("Fallos: ");
         lcd.print(contador_fallos); 
    
         ledRandom = leds[random(0,3)];
         digitalWrite(ledRandom,HIGH);
         el_tiempo = millis();
       
       /////////////////////////////////////////////////      
        if(digitalRead(ledC)==HIGH)
        { // inicio led HIGH  
          
          while(millis() - el_tiempo <= tiempo_base)
          {//inicio while tiempo
             cmC = 0.01723 * readUltrasonicDistance(9,9);
              if(cmC <= 40){     
                       
                a_tiempo = true;
                
                tiempo_push=millis();
                
                digitalWrite(ledRandom,LOW);
                
                el_tiempo = -tiempo_base;//para salir del while
      
              }
              else {
      
               a_tiempo = false;
                
              }
          }//end while tiempo
        
          if(a_tiempo){
            
             contador_aciertos++;
            
             tiempo_diferencia = tiempo_push - tiempo_prendido;
            
             tiempo_base = tiempo_base - tiempo_menos_nivel;
        
          }
          else{
             contador_fallos++;
            tiempo_diferencia = 9999;
          }
          
           delay(150);
           digitalWrite(ledRandom,LOW);
           if(tiempo_diferencia < mejor)
           {//inicio if tiempoDiferencia ... tiempoMejor 
                
                 mejor = tiempo_diferencia;               
                            
                 tiempo_mejor_decimal = mejor/1000;
                 
                
            }//end if tiempoDiferencia ... tiempoMejor 
    
           }//end if led HIGH 
           
            
       
       ////////////////////////////////////////////
       
        if(digitalRead(ledD)==HIGH)
        { // inicio led HIGH  
          
          while(millis() - el_tiempo <= tiempo_base)
          {//inicio while tiempo
             cmD = 0.01723 * readUltrasonicDistance(8,8);
              if(cmD <= 40){     
                       
                a_tiempo = true;
                
                tiempo_push=millis();
                
                digitalWrite(ledRandom,LOW);
                
                el_tiempo = -tiempo_base;//para salir del while
      
              }
              else {
      
               a_tiempo = false;
                
              }
          }//end while tiempo
        
          if(a_tiempo){
            
             contador_aciertos++;
            
             tiempo_diferencia = tiempo_push - tiempo_prendido;
            
             tiempo_base = tiempo_base - tiempo_menos_nivel;
        
          }
          else{
             contador_fallos++;
            tiempo_diferencia = 9999;
          }
          
           delay(150);
           digitalWrite(ledRandom,LOW);
           if(tiempo_diferencia < mejor)
           {//inicio if tiempoDiferencia ... tiempoMejor 
                
                 mejor = tiempo_diferencia;
             
                 tiempo_mejor_decimal = mejor/1000;
                 
                
            }//end if tiempoDiferencia ... tiempoMejor 
    
           }//end if led HIGH 
           
           


       
       //////////////////////////////////////////////
         if(digitalRead(ledI)==HIGH)
        { // inicio led HIGH  
          
          while(millis() - el_tiempo <= tiempo_base)
          {//inicio while tiempo
             cmI = 0.01723 * readUltrasonicDistance(10,10);
              if(cmI <= 40){     
                       
                a_tiempo = true;
                
                tiempo_push=millis();
                
                digitalWrite(ledRandom,LOW);
                
                el_tiempo = -tiempo_base;//para salir del while
      
              }
              else {
      
               a_tiempo = false;
                
              }
          }//end while tiempo
        
          if(a_tiempo){
            
             contador_aciertos++;
            
             tiempo_diferencia = tiempo_push - tiempo_prendido;
            
             tiempo_base = tiempo_base - tiempo_menos_nivel;
        
          }
          else{
             contador_fallos++;
            tiempo_diferencia = 9999;
          }
          
           delay(150);
           digitalWrite(ledRandom,LOW);
             if(tiempo_diferencia < mejor)
           {//inicio if tiempoDiferencia ... tiempoMejor 
                
                 mejor = tiempo_diferencia;  
                 
                 tiempo_mejor_decimal = mejor/1000;
                 
                
            }//end if tiempoDiferencia ... tiempoMejor 
    
           }//end if led HIGH 

           

       //////////////////////////////////////////////      
       
        delay(50);
        digitalWrite(ledRandom,LOW);
           if(digitalRead(A5) == HIGH && digitalRead(A4) == HIGH){
       contador_fallos = 5;
       }
       
         nivel++;

   }      //end while de fallos
   
       while(i4<5){
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("Mejor Reaccion: ");
           lcd.setCursor(0,1);
           lcd.print(tiempo_mejor_decimal); 
           lcd.print(" segundos");
           delay(750);
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("Nivel Alcanzado: ");
           lcd.setCursor(0,1);
           lcd.print(nivel-3); 
           delay(750);
            i4++;           
        }
   
}//end funcion juego 3


//+++++++++++++++++++++++++++++++++++++FINAL++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++JUEGO_ERRORES_TRES+++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//




//+++++++++++++++++++++++++++++++++++++++INICIO++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++FUNCIONES++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int menu(bool juego_seleccionado)
{ 
 
  if(!juego_seleccionado){ 
    
  delay(800);
  while(digitalRead(A4) == LOW){//A4 boton izquierdo--Seleccionador
   
    if(digitalRead(A5)== HIGH){//A5 boton derecho--Navegador
       opcion = menuOpcion[i];
       juego_seleccionado = true;
       tiempo_seleccionado = false;
       i++;
       if(i>=3){
          i = 0;
       }
    }
    
    lcd.begin(16, 2);
    lcd.print("Opcion de juego: ");
    lcd.setCursor(0,1);
    if(opcion == 0){
    lcd.print("No Seleccionado");
    }
    else{
    lcd.print(opcion);
    }
      delay(150);
  }
  return opcion;
  
  }
 
}

long menuTiempos(bool tiempo_seleccionado)
{ 
  
 
  delay(1500);
  if(!tiempo_seleccionado){
    
  while(digitalRead(A4) == LOW){//A4--Boton Izquierda--Seleccionador
   
    if(digitalRead(A5)== HIGH){//A5--Boton Derecha--Navegador
       opcion_tiempo = tiempos[i3];
       opcion_tiempo_decimal = opcion_tiempo;
       opcion_tiempo_decimal = opcion_tiempo_decimal/1000;
      randomSeed(analogRead(A0));//para generar un random segun documentacion tiene que leer un anolog input vacio para inicializarse
       tiempo_seleccionado = true;
       i3++;
       if(i3>=11){
          i3 = 0;
       }
    }
    
    lcd.begin(16, 2);
    lcd.println("Delay del Parpa-");
    lcd.setCursor(0,1);
    lcd.print("deo ");
    lcd.print(opcion_tiempo_decimal);
     lcd.print(" seg.");
    
      delay(150);
  }
  return opcion_tiempo;
  
  }
     
}

void comienzo(int juego){
  lcd.clear();
  lcd.print("Seleccionado: ");
  lcd.setCursor(0, 1);
  lcd.print(String("Juego ") + String(juego));
 
  delay(1000);
  if(juego != 2){
   menuTiempos(tiempo_seleccionado);  
   }
    delay(500);
  
  
  lcd.clear();
 
  lcd.setCursor(0, 1);
  for(int n = 3; n > 0; n--){
  delay(900);
  lcd.clear();
  lcd.print("Comenzando en: ");
  lcd.print(n);      
    }
  
  delay(250);
  lcd.clear();
  delay(1250);
}

  //para los ultrasonidos
  long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
  //para los ultrasonidos
  


//+++++++++++++++++++++++++++++++++++++++++FIN+++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++FUNCIONES++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//



void setup() {
  
  pinMode(ledD,OUTPUT);
  pinMode(ledI,OUTPUT);
  pinMode(ledC,OUTPUT);
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  
  el_tiempo = millis();//el tiempo desde el inicio de la aplicacion 
  lcd.begin(16, 2);
  lcd.print("---Just React---");
  lcd.setCursor(0,1);
  lcd.print("----------------");
  delay(1000);
  randomSeed(analogRead(A0));//para generar un random segun documentacion tiene que leer un anolog input vacio para inicializarse
   
  Serial.begin(9600); 

}


void loop() {

  menu(juego_seleccionado);
  
  if(opcion == 1){
    comienzo(opcion);
    juego_uno_entrenamiento(opcion_tiempo);  
  }  
  
  if(opcion == 2){
    comienzo(opcion);
    juego_dos_niveles();
    
  }
  if(opcion == 3){
    comienzo(opcion);
    juego_errores_tres(opcion_tiempo);
    
  }
  
}