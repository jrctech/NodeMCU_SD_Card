// Escribe en el Monitor Serie y se guarda
// en una archivo de la SdCard.

//  SD Card Pinout:
/*          ____________________
 *         /   ._._._._._._._._.|
 *        / ._.                 |
 *        |  9  1 2 3 4 5 6 7 8 |
 *        |                     |
 *        |                     |
 *        |                     |
 *        |                     |
 *        |                     |
 *        |                     |
 *        -----------------------
 */

//SD Card pin     Microcontroller pin       NodeMCU pin
//     1              SPI CS                    D8
//     2              SPI MOSI                  D7
//     3              Ground                    G
//     4              VCC (3.3V in)             3V
//     5              SPI SCLK                  D5
//     6              Ground (shared with 3)    G
//     7              SPI MISO                  D6
//     8                 (NC)
//     9                 (NC)


#include <SD.h>
const int CS = D8; // Para el NodeMcu
// const int CS = 4; // Para el Arduino y Wemos
File miarchivo;

void setup() {
Serial.begin(115200);

  Serial.println("Iniciando SdCard...");
  if (!SD.begin(CS)) {
    Serial.println("Error al iniciar.");
    return;
  }
    Serial.println("SdCard iniciada.");
}

char rx_byte = 0;
String rx_str = "";

void loop() {
miarchivo = SD.open("escribir.txt", FILE_WRITE); // Abre el archivo.

if (Serial.available() > 0) { // ¿Hay algún caracter en el Monitor Serie?
    rx_byte = Serial.read(); // Toma el caracter.
    rx_str += rx_byte; // Va uniendo los caracteres escritos.
    
    if (rx_byte == '\n') {
          if (miarchivo) { 
            Serial.print("Escribe en la SdCard: ");
            Serial.print(rx_str);
            miarchivo.print(rx_str);
                      }
    rx_str = ""; 
}
}
miarchivo.close(); // Cierra el archivo.
}
