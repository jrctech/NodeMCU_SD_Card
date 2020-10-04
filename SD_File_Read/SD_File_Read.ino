// Lee en el Monitor Serie el contenido de un archivo.

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
 
void setup()
{
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Iniciando SdCard...");
  if (!SD.begin(CS)) {
    Serial.println("Error al iniciar.");
    return;
  }
    Serial.println("SdCard iniciada.");

  File miarchivo = SD.open("leer.txt");
  if (miarchivo) {
    while (miarchivo.available()) {
      Serial.write(miarchivo.read());
      //delay(200);
    }
    miarchivo.close();
  }
  else {
    Serial.println("Error al abrir el archivo.");
  }
}

void loop() {
}
