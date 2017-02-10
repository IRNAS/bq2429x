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
    uint8_t status = charger.getStatus();
    Serial.print("Status: 0b");
    Serial.println(status,BIN);  // Gets charger status
    
    //Decode status:
    uint8_t vbus_status = status >> 6;
    Serial.print("Voltage input: ");
    switch (vbus_status) {
    case 0:
      Serial.print("unknown");
      break;
    case 1:
      Serial.print("USB");
      break;
    case 2:
      Serial.print("non-standard USB");
      break;
    case 3:
      Serial.print("OTG");
      break;
  }
  Serial.println("");
  
  uint8_t charge_status = (status&0b00110000) >> 4;
  Serial.print("Charging status: ");
    switch (charge_status) {
    case 0:
      Serial.print("not charging");
      break;
    case 1:
      Serial.print("pre-charge");
      break;
    case 2:
      Serial.print("fast charging");
      break;
    case 3:
      Serial.print("charge termination");
      break;
  }
  Serial.println("");
  
  Serial.print("DPM_STAT: ");
  Serial.print(bitRead(status, 3),HEX);
  Serial.print(" PG_STAT: ");
  Serial.print(bitRead(status, 2),HEX);
  Serial.print(" THERM_STAT: ");
  Serial.print(bitRead(status, 1),HEX);
  Serial.print(" VSYS_STAT: ");
  Serial.println(bitRead(status, 0),HEX);

  uint8_t faults = charger.getFaults();
    Serial.print("Faults: 0b");
    Serial.println(faults,BIN);  // Gets charger status
    
    //Decode status:
    uint8_t chg_fault = (faults&0b00110000) >> 4;
    Serial.print("Charging fault: ");
    switch (chg_fault) {
    case 0:
      Serial.print("none");
      break;
    case 1:
      Serial.print("Input fault (OVP)");
      break;
    case 2:
      Serial.print("Thermal shutdown");
      break;
    case 3:
      Serial.print("Charge time exp.");
      break;
  }
  Serial.println("");
    
  Serial.print("WATCHDOG_FAULT: ");
  Serial.print(bitRead(faults, 7),HEX);
  Serial.print(" OTG_FAULT: ");
  Serial.print(bitRead(faults, 6),HEX);
  Serial.print(" BAT_FAULT: ");
  Serial.print(bitRead(faults, 3),HEX);
  Serial.print(" NTC_FAULT_1: ");
  Serial.print(bitRead(faults, 1),HEX);
  Serial.print(" NTC_FAULT_0: ");
  Serial.println(bitRead(faults, 0),HEX);
  
  Serial.println("");
  Serial.println("");
  
  
  delay(2000);
}