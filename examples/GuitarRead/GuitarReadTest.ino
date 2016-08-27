#include <WiiChuckGuitar.h>
WiiChuckGuitar guitar;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
guitar.begin();

}


void loop() {
guitar.poll();
Serial.print(guitar.AnalogX);
Serial.println(guitar.AnalogY);
Serial.print(guitar.TouchBar);
Serial.println(guitar.WhammyBar);
Serial.print(guitar.Plus);
Serial.println(guitar.Minus);
Serial.print(guitar.Down);
Serial.println(guitar.Up);
Serial.print(guitar.Green);
Serial.print(guitar.Red);
Serial.print(guitar.Yellow);
Serial.print(guitar.Blue);
Serial.println(guitar.Orange);
Serial.println("-------");
delay(1000);





  
}

