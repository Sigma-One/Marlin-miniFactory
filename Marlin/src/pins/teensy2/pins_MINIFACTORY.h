/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 *  Variant mF3.1
 *  Date    14 NOV 2023
 *  Author  Sinewave
 *
 *  Modified for miniFactory pins
 */

/**
 *  There are two Arduino IDE extensions that are compatible with this board
 *  and with the mainstream Marlin software.
 *
 *  Teensyduino - https://www.pjrc.com/teensy/teensyduino.html
 *    Select Teensy++ 2.0 in Arduino IDE from the 'Tools > Board' menu
 *
 *    Installation instructions are at the above URL.  Don't bother loading the
 *    libraries - they are not used with the Marlin software.
 *
 *  Printrboard - https://github.com/scwimbush/Printrboard-HID-Arduino-IDE-Support
 *
 *    Installation:
 *
 *       1. Go to the above URL, click on the "Clone or Download" button and then
 *          click on "Download ZIP" button.
 *       2. Unzip the file, find the "printrboard" directory and then copy it to the
 *          hardware directory in Arduino.  The Arduino hardware directory will probably
 *          be located in a path similar to this: C:\Program Files (x86)\Arduino\hardware.
 *       3. Restart Arduino.
 *       4. Select "Printrboard" from the 'Tools > Board' menu.
 *
 *  Teensyduino is the most popular option. Printrboard is used if your board doesn't have
 *  the Teensyduino bootloader on it.
 */

/**
 *  To burn the bootloader that comes with Printrboard:
 *
 *   1. Connect your programmer to the board.
 *   2. In the Arduino IDE select "Printrboard" and then select the programmer.
 *   3. In the Arduino IDE click on "burn bootloader". Don't worry about the "verify failed at 1F000" error message.
 *   4. The programmer is no longer needed. Remove it.
 */

// Pins extracted from a miniFactory 2 Marlin 1 configuration

#include "env_validate.h"

// https://reprap.org/wiki/Teensy_Breadboard
#define BOARD_INFO_NAME "miniFactory 3"

//
// Steppers & Endstops
//
#define X_STEP_PIN                            34
#define X_DIR_PIN                             35
#define X_ENABLE_PIN                          31
#define X_STOP_PIN                            18

#define Y_STEP_PIN                            14
#define Y_DIR_PIN                             13
#define Y_ENABLE_PIN                          17
#define Y_STOP_PIN                            19

#define Z_STEP_PIN                            10
#define Z_DIR_PIN                             9
#define Z_ENABLE_PIN                          12
#define Z_STOP_PIN                            47

#define E0_STEP_PIN                            7
#define E0_DIR_PIN                             8
#define E0_ENABLE_PIN                          4

#define E1_STEP_PIN                           25
#define E1_DIR_PIN                            24
#define E1_ENABLE_PIN                         37

//
// Temperature Sensors
//
#define TEMP_0_PIN                             1  // Analog
#define TEMP_1_PIN                             2  // Analog
#define TEMP_BED_PIN                           3  // Analog

//
// Heaters / Fans
//
#define HEATER_0_PIN                          16
#define HEATER_1_PIN                          15
#define HEATER_BED_PIN                        28
#ifndef FAN0_PIN
  #define FAN0_PIN                            30
#endif

//
// Misc. Functions
//
#define SDSS                                  20
#define LED_PIN                               -1
#define PS_ON_PIN                             -1

#ifndef CASE_LIGHT_PIN
  #define CASE_LIGHT_PIN                      -1
#endif

//#define DIGIPOTSS_PIN       27
#define X_MS1_PIN           32
#define X_MS2_PIN           33
#define Y_MS1_PIN           32
#define Y_MS2_PIN           33
// Z_MS1 doesn't exist to my knowledge on the miniFactory 3 mainboard
// Marlin 2 however expects it to be there to allow setting microsteps
// So these are just the same pin now, it works I suppose
// Note that M350/351 will report Z as 11, but in reality only MS2 is enabled
// Thus Z steps should be double X and Y
#define Z_MS1_PIN           11
#define Z_MS2_PIN           11
#define E0_MS1_PIN          5
#define E0_MS2_PIN          6
#define E1_MS1_PIN          36
#define E1_MS2_PIN          26

//#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
//  #define SCK_PIN          21
//  #define MISO_PIN         22
//  #define MOSI_PIN         23
//#endif

//#define DIGIPOT_CHANNELS {3,1,0,2,4}

//
// LCD / Controller
//
#if IS_ULTIPANEL
  #define LCD_PINS_RS                          8  // E0
  #define LCD_PINS_EN                          9  // E1
  #define LCD_PINS_D4                         10  // C0
  #define LCD_PINS_D5                         11  // C1
  #define LCD_PINS_D6                         12  // C2
  #define LCD_PINS_D7                         13  // C3
  #define BTN_EN1                             38  // F0
  #define BTN_EN2                             39  // F1
  #define BTN_ENC                             40  // F2
#endif

//
// M3/M4/M5 - Spindle/Laser Control
//
#if HAS_CUTTER
  #define SPINDLE_LASER_PWM_PIN                0  // D0 PWM0B   MUST BE HARDWARE PWM
  #define SPINDLE_LASER_ENA_PIN                5  // D5  Pin should have a pullup!
  #define SPINDLE_DIR_PIN                      7  // D7
#endif
