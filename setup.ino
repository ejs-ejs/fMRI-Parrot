void setup() {

 int eeAddress = 0;

#ifdef EEPROM_INIT 
unsigned short nProfiles = 6;

Parrot theParrots[nProfiles];

  theParrots[0].DEBUG = 0;
  strcpy(theParrots[0].Name,"NNL Sync"); // profile's name
  theParrots[0].TR = 500; // Time Repetition
  theParrots[0].NumSlices = 25;
  theParrots[0].NumVolumes = 10;
  theParrots[0].NumPrescans =3;
  theParrots[0].TickPerSlice = 1;
  theParrots[0].TickPerVolume = 1;
  theParrots[0].TickPerPrescan = 1;
  theParrots[0].keySyncSlice = 's'; // print on slice sync
  theParrots[0].keySyncVolume = 'S'; // print on volume sync
  theParrots[0].keySyncPrescan = 'S'; // print on volume sync
  theParrots[0].keysKBD[0] = 'A'; // LEFT
  theParrots[0].keysKBD[1] = 'B'; // RIGHT
  theParrots[0].keysKBD[2] = 'C'; // UP
  theParrots[0].keysKBD[3] = 'D'; // DOWN

  theParrots[1].DEBUG = 0;
  strcpy(theParrots[1].Name,"nnl25/90"); // profile's name
  theParrots[1].TR = 500; // Time Repetition
  theParrots[1].NumSlices = 25;
  theParrots[1].NumVolumes = 90;
  theParrots[1].NumPrescans =3;
  theParrots[1].TickPerSlice = 0;
  theParrots[1].TickPerVolume = 1;
  theParrots[1].TickPerPrescan = 0;
  theParrots[1].keySyncSlice = 's'; // print on slice sync
  theParrots[1].keySyncVolume = 'S'; // print on volume sync
  theParrots[1].keySyncPrescan = 'S'; // print on volume sync
  theParrots[1].keysKBD[0] = 'A'; // LEFT
  theParrots[1].keysKBD[1] = 'B'; // RIGHT
  theParrots[1].keysKBD[2] = 'C'; // UP
  theParrots[1].keysKBD[3] = 'D'; // DOWN

  theParrots[2].DEBUG = 0;
  strcpy(theParrots[2].Name,"nnl30/90"); // profile's name
  theParrots[2].TR = 500; // Time Repetition
  theParrots[2].NumSlices = 30;
  theParrots[2].NumVolumes = 90;
  theParrots[2].NumPrescans =3;
  theParrots[2].TickPerSlice = 0;
  theParrots[2].TickPerVolume = 1;
  theParrots[2].TickPerPrescan = 0;
  theParrots[2].keySyncSlice = 's'; // print on slice sync
  theParrots[2].keySyncVolume = 'S'; // print on volume sync
  theParrots[2].keySyncPrescan = 'S'; // print on volume sync
  theParrots[2].keysKBD[0] = 'A'; // LEFT
  theParrots[2].keysKBD[1] = 'B'; // RIGHT
  theParrots[2].keysKBD[2] = 'C'; // UP
  theParrots[2].keysKBD[3] = 'D'; // DOWN

  theParrots[3].DEBUG = 0;
  strcpy(theParrots[3].Name,"Nnl30/90"); // profile's name
  theParrots[3].TR = 500; // Time Repetition
  theParrots[3].NumSlices = 30;
  theParrots[3].NumVolumes = 90;
  theParrots[3].NumPrescans =3;
  theParrots[3].TickPerSlice = 0;
  theParrots[3].TickPerVolume = 1;
  theParrots[3].TickPerPrescan = 0;
  theParrots[3].keySyncSlice = 'S'; // print on slice sync
  theParrots[3].keySyncVolume = 's'; // print on volume sync
  theParrots[3].keySyncPrescan = 's'; // print on volume sync
  theParrots[3].keysKBD[0] = 'a'; // LEFT
  theParrots[3].keysKBD[1] = 'b'; // RIGHT
  theParrots[3].keysKBD[2] = 'c'; // UP
  theParrots[3].keysKBD[3] = 'd'; // DOWN

  theParrots[4].DEBUG = 0;
  strcpy(theParrots[4].Name,"Num30/90"); // profile's name
  theParrots[4].TR = 500; // Time Repetition
  theParrots[4].NumSlices = 30;
  theParrots[4].NumVolumes = 90;
  theParrots[4].NumPrescans =3;
  theParrots[4].TickPerSlice = 0;
  theParrots[4].TickPerVolume = 1;
  theParrots[4].TickPerPrescan = 0;
  theParrots[4].keySyncSlice = 'K'; // print on slice sync
  theParrots[4].keySyncVolume = 'k'; // print on volume sync
  theParrots[4].keySyncPrescan = 'k'; // print on volume sync
  theParrots[4].keysKBD[0] = '1'; // LEFT
  theParrots[4].keysKBD[1] = '2'; // RIGHT
  theParrots[4].keysKBD[2] = '3'; // UP
  theParrots[4].keysKBD[3] = '4'; // DOWN

  theParrots[5].DEBUG = 0;
  strcpy(theParrots[5].Name,"NNL25/10"); // profile's name
  theParrots[5].TR = 500; // Time Repetition
  theParrots[5].NumSlices = 25;
  theParrots[5].NumVolumes = 10;
  theParrots[5].NumPrescans =3;
  theParrots[5].TickPerSlice = 1;
  theParrots[5].TickPerVolume = 1;
  theParrots[5].TickPerPrescan = 0;
  theParrots[5].keySyncSlice = 's'; // print on slice sync
  theParrots[5].keySyncVolume = 'S'; // print on volume sync
  theParrots[5].keySyncPrescan = 'S'; // print on volume sync
  theParrots[5].keysKBD[0] = 'A'; // LEFT
  theParrots[5].keysKBD[1] = 'B'; // RIGHT
  theParrots[5].keysKBD[2] = 'C'; // UP
  theParrots[5].keysKBD[3] = 'D'; // DOWN


  
  cDevice.signature = 67; // the signature of the Thing
  cDevice.baudrate = 57600; // NNL SyncBox runs at 57600
  cDevice.cProfile = 0; // current prifile to start at
  cDevice.nProfiles = nProfiles; // number of profiles stored in EEPROM
  

  // write timings to EEPROM 
  EEPROM.put(eeAddress, cDevice);
  eeAddress += sizeof(cDevice);
    for ( int i=0;i<nProfiles;i++) {
      EEPROM.put(eeAddress, theParrots[i]);
      eeAddress += sizeof(cParrot);
    }
  
eeAddress = 0;  
#endif

  EEPROM.get(eeAddress, cDevice);
  eeAddress += sizeof(cDevice); // skip to the profile 0
  eeAddress += (sizeof(cParrot) * cDevice.cProfile); // skip to current profile
  EEPROM.get(eeAddress, cParrot);

//set up buttons
pinMode(K_TRIGGER, INPUT_PULLUP);
  debouncTrig.attach(K_TRIGGER);
  debouncTrig.interval(T_DEBOUNCE);
pinMode(K1, INPUT_PULLUP);
  debouncK1.attach(K1);
  debouncK1.interval(T_DEBOUNCE);
pinMode(K2, INPUT_PULLUP);
  debouncK2.attach(K2);
  debouncK2.interval(T_DEBOUNCE);
pinMode(K3, INPUT_PULLUP);
  debouncK3.attach(K3);
  debouncK3.interval(T_DEBOUNCE);
pinMode(K4, INPUT_PULLUP);
  debouncK4.attach(K4);
  debouncK4.interval(T_DEBOUNCE);

#ifdef HAVE_OLED
  //now, init i2c OLED display

  //u8g.begin();
  u8x8.begin();
  // flip screen, if required
  // u8g.setRot180();

  //u8g.setColorIndex(0);

//  short cWidth = u8g.getWidth();
//  short cHeight = u8g.getHeight();
//  u8g.drawBox(0, 0, cWidth, cHeight);


  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

//  // assign default color value
//  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
//    u8g.setColorIndex(255);     // white
//  }
//  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
//    u8g.setColorIndex(3);         // max intensity
//  }
//  else if ( u8g.getMode() == U8G_MODE_BW ) {
//    u8g.setColorIndex(1);         // pixel on
//  }
//  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
//    u8g.setHiColorByRGB(255, 255, 255);
//  }



//  u8g.setFont(u8g_font_unifont);
//  // end of OLED display init


//  u8g.firstPage();
//  do {
    oled_init();
//  }
//  while ( u8g.nextPage() );

#endif

#ifdef HAVE_OLED_JPRC
 // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, SH1106_I2C_ADDRESS);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  #endif



  // start serial port
  Serial.begin(cDevice.baudrate);
  delay(300);

#ifndef EEPROM_INIT
  // Setup callbacks for SerialCommand commands
  sCmd.addCommand("START",    CMD_paradigma_start);          // start paradigma
  sCmd.addCommand("STOP",   CMD_paradigma_stop);         // stop paradigma
  sCmd.addCommand("RESET",   CMD_paradigma_reset);         // reset paradigma
  sCmd.addCommand("STATE",   CMD_state);         // print state to serial port
  sCmd.addCommand("?", CMD_help);        // help un use
  sCmd.addCommand("S",     CMD_process);  // settings manipulation commands
  sCmd.addCommand("P",     CMD_profiles);  // profile manipulation commands
  sCmd.setDefaultHandler(CMD_any);      // Handler for command that isn't matched

  CMD_any();
 #endif
}





