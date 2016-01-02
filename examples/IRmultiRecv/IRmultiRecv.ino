#include <IRremote.h>

// To support more than 5 receivers, remember to change the define
// IR_PARAMS_MAX in IRremoteInt.h as well.
#define RECEIVERS 5

IRrecv *irrecvs[RECEIVERS];

decode_results results;

void setup()
{
  Serial.begin(9600);

  irrecvs[0] = new IRrecv(2); // Receiver #0: pin 2
  irrecvs[1] = new IRrecv(3); // Receiver #1: pin 3
  irrecvs[2] = new IRrecv(4); // Receiver #2: pin 4
  irrecvs[3] = new IRrecv(5); // Receiver #3: pin 5
  irrecvs[4] = new IRrecv(6); // Receiver #4: pin 6

  for (int i = 0; i < RECEIVERS; i++)
    irrecvs[i]->enableIRIn();
}

void loop() {
  for (int i = 0; i < NUMBER_IRRECV; i++)
  {
    if (irrecvs[i]->decode(&results))
    {
      Serial.print("Receiver #");
      Serial.print(i);
      Serial.print(":");
      Serial.println(results.value, HEX);
      irrecvs[i]->resume();
    }
  }
}
