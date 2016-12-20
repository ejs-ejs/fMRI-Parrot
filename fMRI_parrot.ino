/*
  fMRI Parrot simulates NNL Syncro Box from NordicNeuroLab, used to interface the MR scanner and the patient
  The primary purpose is off-site testing fMRI paradigmas

  Supported functionality:
   send sync signal when starting every slice;
   send sync signal when starting every volume;
   send response from the patient, using 4 hardware buttons;
   programable aquisition time RT
   programable number of slices
   programable number of volumes

  The configuration is applied via RS-232 interface
  Current state is visible on the OLED display
*/

//#define EEPROM_INIT 1

//waht kind of OLED display we have?
#define HAVE_OLED_U8G 1
//#define HAVE_OLED_U8G8 0

// use JPRC SSD1306 OLED library?
//#define HAVE_OLED_JPRC 0


char __VERSION[] = "0.1c"; // version

//
//  buttons

#define K_TRIGGER 9
#define K1 4
#define K2 5
#define K3 6
#define K4 8

// pjrc debouncer
#include <Bounce2.h>
#define T_DEBOUNCE 10

Bounce debouncTrig = Bounce();
Bounce debouncK1 = Bounce();
Bounce debouncK2 = Bounce();
Bounce debouncK3 = Bounce();
Bounce debouncK4 = Bounce();


// command inteface
#include <SerialCommand.h>
SerialCommand sCmd;     // The SerialCommand object

//#define EEPROM_INIT
#include <EEPROM.h>


#include "fMRI_parrot.h"
Device cDevice;
Parrot cParrot; // create instances




#ifdef HAVE_OLED_U8G
// connect to i2c display
//#include <U8GLibExt.h>
 
#include <U8glib.h>
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);  // Fast I2C / TWI
#endif


#ifdef HAVE_OLED_U8G8
#include <U8x8lib.h>
U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

#endif


#ifdef HAVE_OLED_JPRC

#define SSD1306_128_64

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SH1106_I2C_ADDRESS   0x3C

Adafruit_SSD1306 display(-1); // use SH1106 via I2C / TWI, without RESET

#endif





// define run variables
byte _Start = 0;
byte _RunMode = 0; // idle

unsigned long cTime;
unsigned long tSlice;
unsigned long timeTick;
unsigned long timeDelta = 0;

unsigned int cSlice = 0;
unsigned int cVolume = 1;
unsigned int cPrescan = 0;


/* CONTROLL COMMANDS
    start paradigma
*/
void CMD_paradigma_start() {
  _Start = 1;
}

/* CONTROLL COMMANDS
    stop paradigma
*/
void CMD_paradigma_stop() {
  _Start = 0;
}

void CMD_paradigma_reset() {
  cVolume = 1;
  cSlice = 1;
}


/* CONTROLL COMMANDS
    unrecognized command
*/
void CMD_any() {
  Serial.println(F("This is fMRI Parrot"));
  Serial.print(F("\t version "));
  Serial.println(__VERSION);
  Serial.println(F("Press \"?\" for help"));
}
//===================================================================



void loop() {

  // key processing
  check_buttons();

  // read serial port
  sCmd.readSerial();


  if (_Start) {

    // enter pre-scan mode

    if (cPrescan < cParrot.NumPrescans) {
      if (_RunMode == 0 ) {
        _RunMode = 1; // prescanning for T1 stabilication
      }
      if ( cVolume > 0 ) {
        cVolume = 0; 
      }

      tSlice = cParrot.TR / cParrot.NumSlices; // tSlice is slice aquisition time. Change on volume boundary

      if (cParrot.TickPerPrescan) {
        Serial.print(cParrot.keySyncPrescan);
      }


      if (cSlice < cParrot.NumSlices) {
        slice_volume();
      } else {
        cSlice = 0;
        cPrescan++; // increase current Volume
      }

    } else {

      // reset volume count, start scanning
      //        cVolume = 0;
      _RunMode = 2; // scanning


      if (cVolume <= cParrot.NumVolumes) {

       tSlice = cParrot.TR / cParrot.NumSlices; // tSlice is slice aquisition time. Change on volume boundary
        
        //          cSlice = 0;
        if (cVolume == 0) {
          cVolume = 1;
          if (cParrot.TickPerVolume) {
          Serial.print(cParrot.keySyncVolume);
           }
        
        if (cParrot.DEBUG) {
        Serial.print(F("DEBUG: cSlice="));
        Serial.print(cSlice, DEC);
        Serial.print(F("\t cVolume="));
        Serial.print(cVolume, DEC);
        Serial.print(F("\t tSlice="));
        Serial.println(tSlice, DEC);
      }
          }
        
        if (cSlice < cParrot.NumSlices) {
          slice_volume();
        } else {
           if (cParrot.TickPerVolume) {
          Serial.print(cParrot.keySyncVolume);
           }
          cSlice = 0;
          cVolume++; // increase current Volume
          if (cParrot.DEBUG) {
        Serial.print(F("DEBUG: cSlice="));
        Serial.print(cSlice, DEC);
        Serial.print(F("\t cVolume="));
        Serial.print(cVolume, DEC);
        Serial.print(F("\t tSlice="));
        Serial.println(tSlice, DEC);
      }
        }

      } else {
        _Start = 0;
        _RunMode = 0;
        cVolume = 1;
        cPrescan = 0;
      }
    }
  } // running

#ifdef HAVE_OLED_U8G
  // draw the screen
  u8g.firstPage();
  do {
    draw_oled(cVolume, cSlice);
  }
  while ( u8g.nextPage() );

#endif

}

