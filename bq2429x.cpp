/**
 * Name: bq2429x
 * Author: Luka Mustafa - Institute IRNAS Race { info@irnas.eu }
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

// Initializes variables and the Wire library
bq2429x::bq2429x() { 
    Wire.begin(); 
}


uint8_t bq2429x::getStatus()
{
	Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_STATUS_ADDR);
	Wire.endTransmission(false);
	Wire.requestFrom(bq2429x_ADDR, (int)1,HIGH); //send stop
    return Wire.read();
}  

uint8_t bq2429x::getFaults()
{
	Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_FAULT_ADDR);
	Wire.endTransmission(false);
	Wire.requestFrom(bq2429x_ADDR, (int)1,HIGH); //send stop
    return Wire.read();
}  
   
   
void bq2429x::setChargeVoltage(double voltage)
{
	Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_CHARGE_VOL_CTRL_ADDR);
	Wire.endTransmission(false);
	Wire.requestFrom(bq2429x_ADDR, (int)1,HIGH);
    
    uint8_t current_value = Wire.read();
    uint8_t new_value = current_value;
    
    Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_CHARGE_VOL_CTRL_ADDR);
    Wire.write(new_value);
    Wire.endTransmission(false);
    return;
}

void bq2429x::setChargeCurrent(double current)
{
	Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_CHARGE_CUR_CTRL_ADDR);
	Wire.endTransmission(false);
	Wire.requestFrom(bq2429x_ADDR, (int)1,HIGH);
    
    uint8_t current_value = Wire.read();
    uint8_t new_value = current_value;
    
    Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_CHARGE_CUR_CTRL_ADDR);
    Wire.write(new_value);
    Wire.endTransmission(false);
    return;
}

void bq2429x::setInputCurrentLimit(double current)
{
	Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_INPUT_CTRL_ADDR);
	Wire.endTransmission(false);
	Wire.requestFrom(bq2429x_ADDR, (int)1,HIGH);
    
    uint8_t current_value = Wire.read();
    uint8_t new_value = current_value;
    
    Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_INPUT_CTRL_ADDR);
    Wire.write(new_value);
    Wire.endTransmission(false);
    return;
}

void bq2429x::setInputVoltageLimit(double voltage)
{
	Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_INPUT_CTRL_ADDR);
	Wire.endTransmission(false);
	Wire.requestFrom(bq2429x_ADDR, (int)1,HIGH);
    
    uint8_t current_value = Wire.read();
    uint8_t new_value = current_value;
    
    Wire.beginTransmission(bq2429x_ADDR);
	Wire.write(bq2429x_INPUT_CTRL_ADDR);
    Wire.write(new_value);
    Wire.endTransmission(false);
    return;
}