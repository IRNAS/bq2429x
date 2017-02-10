/**
 * Name: bq2429x
 * Author: Luka Mustafa - Institute IRNAS Race { info@irnas.eu }
 * Version: 1.0
 * Description: A library for interfacing the MAXIM MAX17201/MAX17205
 * 				Li+ fuel gauges.
 * Source: https://github.com/pAIgn10/LiFuelGauge
 * License: Copyright (c) 2017 Nick Lamprianidis 
 *          This library is licensed under the GPL license
 *          http://www.opensource.org/licenses/mit-license.php
 * Inspiration: The library is inspired by: https://github.com/pAIgn10/LiFuelGauge
 * Filename: bq2429x.h
 * File description: Definitions and methods for the bq2429x library
 */

#ifndef bq2429x
#define bq2429x_h

#include <Arduino.h>
#include <Wire.h>

// bq2429x register addresses
const int bq2429x_ADDR = 0x6b;
const int bq2429x_INPUT_CTRL_ADDR = 0x00; // Input Source Control Register REG00 [reset = 00110xxx, or 3x]
const int bq2429x_POWERON_CTRL_ADDR = 0x01; // Power-On Configuration Register REG01 [reset = 00011011, or 0x1B]
const int bq2429x_CHARGE_CUR_CTRL_ADDR = 0x02; // Charge Current Control Register REG02 [reset = 01100000, or 60]
const int bq2429x_PRECHARGE_CTRL_ADDR = 0x03; // Pre-Charge/Termination Current Control Register REG03 [reset = 00010001, or 0x11]
const int bq2429x_CHARGE_VOL_CTRL_ADDR = 0x04; // Charge Voltage Control Register REG04 [reset = 10110010, or 0xB2]
const int bq2429x_CHARGE_TERM_CTRL_ADDR = 0x05; // Charge Termination/Timer Control Register REG05 [reset = 10011010, or 0x9A]
const int bq2429x_BOOST_THERMAL_CTRL_ADDR = 0x06; // Boost Voltage/Thermal Regulation Control Register REG06 [reset = 01110011, or 0x73]
const int bq2429x_MISC_CTRL_ADDR = 0x07; // Misc Operation Control Register REG07 [reset = 01001011, or 4B]
const int bq2429x_STATUS_ADDR = 0x08; // System Status Register REG08
const int bq2429x_FAULT_ADDR = 0x09; // New Fault Register REG09
const int bq2429x_VENDOR_ADDR = 0x0A; // Vender / Part / Revision Status Register REG0A

// Class for interfacing the bq2429x
class bq2429x
{
public:
	bq2429x();
    uint8_t getStatus();
    uint8_t getFaults();
    void setChargeVoltage(double voltage);
    void setChargeCurrent(double current);
    void setInputCurrentLimit(double current);
    void setInputVoltageLimit(double voltage);
};

#endif  // bq2429x
