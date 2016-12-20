/* PROFILE COMMANDS
    
*/

void CMD_profiles() {
  int aNumber;
  char *arg;
  char *arg2;

  Serial.print(F("Processing command "));
  arg = sCmd.next();

  if (arg != NULL) {
    arg2 = sCmd.next();
    if (arg2 != NULL) {
      aNumber = atol(arg2);
  }
  }

//    if (!strcmp(arg, "LIST")) {
//      // list profiles available asNumber, Name, TR, Volumes, Slices
//        Serial.println(F("\n To be implemented"));
//    }

    if (!strcmp(arg, "COPY")) {
        cDevice.cProfile = cDevice.nProfiles;
        cDevice.nProfiles += 1;
        memset( &cParrot.Name, 0, sizeof(cParrot.Name));
    }

//     if (!strcmp(arg, "DEL")) {
//      if (arg2 != NULL) {
//        Serial.print(F("NOT IMPLEMENTED YET:\n Deleteing profile #"));
//        Serial.println(aNumber, DEC);
//      }
//    }

    if (!strcmp(arg, "NAME")) {
      if (arg2 != NULL) {
         Serial.print(F("Renaming CURRENT profile to "));
         Serial.println(arg2);
         //cParrot.Name = arg2;
         strncpy( cParrot.Name, arg2, sizeof(cParrot.Name) );
      }
    }

  int eeAddress = 0;
   eeAddress += sizeof(cDevice); // skip to the profile 0
  eeAddress += (sizeof(cParrot) * cDevice.cProfile); // skip to current profile
  EEPROM.put(eeAddress, cParrot);
}

