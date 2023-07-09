#include <IRremote.h>              // Incluye la biblioteca IRremote para recibir señales infrarrojas

#define Tecla_1 0xF30CFF00         // Definición del código de la tecla 1 del control remoto
#define Tecla_2 0xE718FF00         // Definición del código de la tecla 2 del control remoto

int IR = 11;                       // Pin utilizado para recibir la señal infrarroja
int LED = 13;                      // Pin utilizado para controlar el LED

void setup() {
  Serial.begin(9600);              // Inicializa la comunicación serial a una velocidad de 9600 baudios
  IrReceiver.begin(IR, DISABLE_LED_FEEDBACK);   // Inicializa el receptor infrarrojo en el pin especificado y desactiva la retroalimentación del LED
  pinMode(LED, OUTPUT);            // Configura el pin del LED como salida
} 

void loop() {
  if (IrReceiver.decode()) {       // Si se ha recibido una señal infrarroja
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);   // Imprime el código de la señal infrarroja recibida en hexadecimal
    
    if (IrReceiver.decodedIRData.decodedRawData == Tecla_1)   // Comprueba si el código recibido coincide con el de la tecla 1
      digitalWrite(LED, HIGH);    // Enciende el LED
    
    if (IrReceiver.decodedIRData.decodedRawData == Tecla_2)   // Comprueba si el código recibido coincide con el de la tecla 2
      digitalWrite(LED, LOW);     // Apaga el LED
    
    IrReceiver.resume();           // Prepara el receptor para recibir la próxima señal infrarroja
  }
  delay(100);                      // Pequeña pausa antes de repetir el ciclo
}
