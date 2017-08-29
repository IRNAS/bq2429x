/**
 * This is an example demonstrating the use of the max1720x library
 * Print out the information to serial monitor at 115200 baud
 */

#include <Wire.h>
#include <bq2429x.h>

bq2429x charger;

void setup()
{
    Serial.begin(115200); // Initializes serial port
    // Waits for serial port to connect. Needed for Leonardo only
    while ( !Serial ) ;  
}

void loop()
{

  digit_debug();
  string_debug();
  
  delay(2000);
}

/*
 *  Function: void digit_debug()
 *  Description: it is serial printing all the values but in bits
 */
void digit_debug() {
  Serial.println("---------------------");
  Serial.print("VBus: ");
  Serial.println(charger.getVBus());

  Serial.print("Charge: ");
  Serial.println(charger.getCharge());

  Serial.print("DMP: ");
  Serial.println(charger.getDMP());

  Serial.print("PG: ");
  Serial.println(charger.getPG());

  Serial.print("THERM: ");
  Serial.println(charger.getTHERM());

  Serial.print("VSYS: ");
  Serial.println(charger.getVSYS());
  
  Serial.println("-  -  -  -  -  -  -  ");

  Serial.print("Charge fault: ");
  Serial.println(charger.getChgFault());

  Serial.print("Watchdog fault: ");
  Serial.println(charger.getWatchdogFault());

  Serial.print("OTG fault: ");
  Serial.println(charger.getOTGFault());

  Serial.print("BAT fault: ");
  Serial.println(charger.getBATFault());

  Serial.print("NTC1 fault: ");
  Serial.println(charger.getNTC1Fault());

  Serial.print("NTC0 fault: ");
  Serial.println(charger.getNTC0Fault());
}

/*
 *  Function: void string_debug()
 *  Description: it is writing all data to serial but in strings - more readble
 */
void string_debug() {
  Serial.println("---------------------");
  Serial.print("VBus: ");
  switch(charger.getVBus()) { 
    case 0: Serial.println("unknown");            break; 
    case 1: Serial.println("USB");                break; 
    case 2: Serial.println("non-standard USB");   break; 
    case 3: Serial.println("OTG");                break; 
  } 

  Serial.print("Charge: ");
  switch(charger.getCharge()) {
    case 0: Serial.println("Not charging");       break;
    case 1: Serial.println("Pre-charge");         break;
    case 2: Serial.println("Fast charging");      break;
    case 3: Serial.println("Charge termination"); break;
  }

  Serial.print("DMP: ");
  Serial.println(charger.getDMP() ? "Not DPM" : "VINDPM or IINDPM");

  Serial.print("PG: ");
  Serial.println(charger.getPG() ? "Power good" : "Not good power");

  Serial.print("THERM: ");
  Serial.println(charger.getTHERM() ? "In thermal regulation" : "Normal status");

  Serial.print("VSYS: ");
  Serial.println(charger.getVSYS() ? "BAT < VSYSMIN" : "BAT > VSYSMIN");
  
  Serial.println("-  -  -  -  -  -  -  ");

  Serial.print("Charge fault: ");
  switch(charger.getChgFault()) {
    case 0: Serial.println("none");               break;
    case 1: Serial.println("Input fault (OVP)");  break;
    case 2: Serial.println("Thermal shutdown");   break;
    case 3: Serial.println("Charge time exp.");   break;
  }

  Serial.print("Watchdog fault: ");
  Serial.println(charger.getWatchdogFault() ? "Watchdog timer expiration" : "Normal");

  Serial.print("OTG fault: ");
  Serial.println(charger.getOTGFault() ? "VBUS overloaded or VBUS OVP in boost mode" : "Normal");

  Serial.print("BAT fault: ");
  Serial.println(charger.getBATFault() ? "BatOVP" : "Normal");

  Serial.print("NTC1 fault: ");
  Serial.println(charger.getNTC1Fault());

  Serial.print("NTC0 fault: ");
  Serial.println(charger.getNTC0Fault());
}

