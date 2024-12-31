/*
 * Ejemplo de secuencia de parpado de un led.
 * 
 * Sobre si 0 o 1. Dado que en programación el primer número es el 0, el paso cero será
 * el primer paso, no os confundais con la numeración, contar 0, 1, 2, 3...
 */
const int numPasos = 3;



int paso;
unsigned long tiempos[numPasos] = { 10000, 20000, 30000 }; // El array lo crearemos con tantos pasos como haya.
unsigned long t; // Esta será nuestra variable de tiempo.

// La función que hará en el primer paso.
void paso0() {
  digitalWrite(2, HIGH);
  Serial.println("proceso1");
}
// La función que hará en el primer paso.
void paso1() {
  digitalWrite(2, LOW);
  Serial.println("proceso2");
}

void paso2() {
  digitalWrite(2, HIGH);
  Serial.println("proceso3");
}

 void setup() {
   Serial.begin(9600);
   pinMode(2, OUTPUT); // Led de la placa.
   // Iniciamos la secuencia.
   paso=0;
   paso0();
 }

 void loop() {
   // Comprobamos si el temporizador actual ha sobrepasado el tiempo del paso actual.
   if ( millis() - t > tiempos[paso] ) {
     t = millis(); // Guardamos el tiempo.
     paso++; // Incrementamos el paso.
     if ( paso==numPasos ) paso = 0; // Cambiamos al primer paso.
     switch ( paso ) {
       case 0: paso0(); break;
       case 1: paso1(); break;
       case 2: paso2(); break;
       default: break;
     }
   }
 }