/**
 * Name: bq2429x
 * Author: Luka Mustafa - Institute IRNAS Race { info@irnas.eu } & Silard Gal
 * Version: 1.0
 * Description: A library for interfacing the MAXIM MAX17201/MAX17205
 * 				Li+ fuel gauges.
 * Source: https://github.com/pAIgn10/bq2429x
 * License: Copyright (c) 2017 Nick Lamprianidis 
 *          This library is licensed under the GPL license
 *          http://www.opensource.org/licenses/mit-license.php
 * Inspiration: The library is inspired by: https://github.com/pAIgn10/bq2429x
 * Filename: bq2429x.cpp
 * File description: Definitions and methods for the bq2429x library
 */

#include "bq2429x.h"

uint8_t current_status_register;      // store the status
uint8_t current_fault_register;       // store the fault

// Initializes variables and the Wire library
bq2429x::bq2429x() { 
    Wire.begin();                     // begin the i2c module
}

/*
 *  Function:     uint8_t bq2429x::getStatus()
 *  Description:  connects to the status register and reads out the data
 */
uint8_t bq2429x::getStatus()
{
	Wire.beginTransmission(bq2429x_ADDR);                     // begin i2c transmission
	Wire.write(bq2429x_STATUS_ADDR);                          // go to the status register
	Wire.endTransmission(false);                              // don't end transmission
	Wire.requestFrom(bq2429x_ADDR, (int)1,HIGH);              // request 1 byte from the register
  current_status_register = Wire.read();                    // write the data into the status register
}  

/*
 *  Function:     const char* bq2429x::getVBus()
 *  Description:  shifts around the data and gets the vbus data from the status register
 */
uint8_t bq2429x::getVBus()
{
  getStatus();                                              // read the register
  
  return current_status_register >> 6;                      // shift to the bit vbus and return it

}

/*
 *  Function:     const char* bq2429x::getCharge()  
 *  Description:  shifts around the data and gets the charge from the status register
 */
uint8_t bq2429x::getCharge()                                          
{
  getStatus();                                                            // get the register status

  return (current_status_register&0b00110000) >> 4;                       // go to that bit and return it
  
}
/* Function: uint8_t bq2429x::getDMP()      Description: gets the DMP from the status register */
uint8_t bq2429x::getDMP()   { getStatus(); return bitRead(current_status_register, 3); }    
  
/* Function: uint8_t bq2429x::getPG()       Description: gets the PG from the status register */
uint8_t bq2429x::getPG()    { getStatus(); return bitRead(current_status_register, 2); }      

/* Function: uint8_t bq2429x::getTHERM()    Description: gets the THERM from the status register */
uint8_t bq2429x::getTHERM() { getStatus(); return bitRead(current_status_register, 1); }    
  
/* Function: uint8_t bq2429x::getVSYS()     Description: gets the VSYS from the status register */
uint8_t bq2429x::getVSYS()  { getStatus(); return bitRead(current_status_register, 0); }      

/*
 *  Function:     uint8_t bq2429x::getFaults()
 *  Description:  connect to the device and gets the fault register 
 */
uint8_t bq2429x::getFaults()
{
	Wire.beginTransmission(bq2429x_ADDR);             // start i2c transmission           
	Wire.write(bq2429x_FAULT_ADDR);                   // go to the fault register
	Wire.endTransmission(false);                      // dont end the transmission
	Wire.requestFrom(bq2429x_ADDR, (int)1,HIGH);      // get the byte
  current_fault_register = Wire.read();             // write data to the fault register
}  

/*
 *  Function:     uint8_t bq2429x::getChgFault()
 *  Description:  gets the fault register and return the chg_fault status
 */
uint8_t bq2429x::getChgFault()
{
  getFaults();                                                        // get fault byte
  
  return (current_fault_register & 0b00110000) >> 4;                  // go to the chg fault bit  and return it

}

/* Function: uint8_t bq2429x::getWatchdogFault()    Description: gets the watchdog fault and return it  */
uint8_t bq2429x::getWatchdogFault() { getFaults(); return bitRead(current_fault_register, 7); } 

/* Function: uint8_t bq2429x::getOTGFault()         Description: get otg fault and return it            */
uint8_t bq2429x::getOTGFault()      { getFaults(); return bitRead(current_fault_register, 6); }

/* Function: uint8_t bq2429x::getBATFault()         Description: get bat fault and return it            */
uint8_t bq2429x::getBATFault()      { getFaults(); return bitRead(current_fault_register, 3); }     

/* Function: bq2429x::getNTC1Fault()                Description: get ntc1 fault and return it           */
uint8_t bq2429x::getNTC1Fault()     { getFaults(); return bitRead(current_fault_register, 1); }

/* Function: uint8_t bq2429x::getNTC0Fault()        Description: get ntc0 fault and return it           */
uint8_t bq2429x::getNTC0Fault()     { getFaults(); return bitRead(current_fault_register, 0); }

