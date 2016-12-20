void profile_set(int theProfile) {
  
//  Serial.print(F("Requested profile#"));
//  Serial.println(theProfile, DEC);
  
  if ( theProfile >= cDevice.nProfiles ) {
    theProfile = 0; // back to 0
  }
  if ( theProfile < 0) {
    theProfile = cDevice.nProfiles - 1; // back to max number
  } 
  cDevice.cProfile = theProfile;
  Serial.print(F("Switching to profile #"));
  Serial.println(cDevice.cProfile, DEC);
  int eeAddress = 0;
  EEPROM.put(eeAddress, cDevice); // save cuurent profile #
  eeAddress += sizeof(cDevice); // skip to the profile 0
  eeAddress += (sizeof(cParrot) * cDevice.cProfile); // skip to current profile
  EEPROM.get(eeAddress, cParrot);


}
