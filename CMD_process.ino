/* CONTROLL COMMANDS
    process command
*/

#ifndef EEPROM_INIT

void CMD_process() {
  int aNumber;
  char *arg;
  char *arg2;

  Serial.print(F("Processing command "));
  arg = sCmd.next();

  if (arg != NULL) {

    // Serial.print(F("First argument is: "));
    Serial.println(arg);
    arg2 = sCmd.next();
    if (arg2 != NULL) {
      aNumber = atol(arg2);
      Serial.print(F("Second argument is: "));
      Serial.println(arg2);
    } else {
      Serial.println("No second argument");
    }

    if (!strcmp(arg, "TR")) {
      if (arg2 != NULL) {
        cParrot.TR = aNumber > 6000 ? cParrot.TR : aNumber;
        Serial.print(F("\n Updated TR = "));
      } else {
        Serial.print(F("\n TR = "));
      }
      Serial.println(cParrot.TR, DEC);
    }

    if (!strcmp(arg, "VOLUMES")) {
      if (arg2 != NULL) {
        cParrot.NumVolumes = aNumber > 600 ? cParrot.NumVolumes : aNumber;
        Serial.print(F("\n Updated volumes: "));
      } else {
        Serial.print(F("\n Volumes: "));
      }
      Serial.println(cParrot.NumVolumes, DEC);
    }

    if (!strcmp(arg, "SLICES")) {
      if (arg2 != NULL) {
        cParrot.NumSlices = aNumber > 200 ? cParrot.NumSlices : aNumber;
        Serial.print(F("\n Updated slices: "));
      } else {
        Serial.print(F("\n Slices: "));
      }
      Serial.println(cParrot.NumSlices, DEC);

    }

     if (!strcmp(arg, "PRESCANS")) {
      if (arg2 != NULL) {
        cParrot.NumPrescans = aNumber > 20 ? cParrot.NumPrescans : aNumber;
        Serial.print(F("\n Updated prescans: "));
      } else {
        Serial.print(F("\n Prescans: "));
      }
      Serial.println(cParrot.NumPrescans, DEC);

    }

    if (!strcmp(arg, "SYNC_VOLUME")) {
      if (arg2 != NULL) {
        cParrot.TickPerVolume = aNumber ? 1 : 0;
        Serial.print(F("Updated sync on volume ["));
      } else {
        Serial.print(F("Sync on volume ["));
      }
      cParrot.TickPerVolume ? Serial.print(F("x")) : Serial.print(F(" "));
      Serial.println(F("]"));

    }

    if (!strcmp(arg, "SYNC_SLICE")) {
      if (arg2 != NULL) {
        cParrot.TickPerSlice = aNumber ? 1 : 0;
        Serial.print(F("Updated sync on slice ["));
      } else {
        Serial.print(F("Sync on slice ["));
      }
      cParrot.TickPerSlice ? Serial.print(F("x")) : Serial.print(F(" "));
      Serial.println(F("]"));
    }

    if (!strcmp(arg, "SYNC_PRESCAN")) {
      if (arg2 != NULL) {
        cParrot.TickPerPrescan = aNumber ? 1 : 0;
        Serial.print(F("Updated sync on prescan ["));
      } else {
        Serial.print(F("Sync on prescan ["));
      }
      cParrot.TickPerPrescan ? Serial.print(F("x")) : Serial.print(F(" "));
      Serial.println(F("]"));
    }

    if (!strcmp(arg, "KS")) {
      if (arg2 != NULL) {
        cParrot.keySyncSlice = *arg2;
        Serial.print(F("\t*** Updated sync symbol on SLICE to ["));
      } else {
        Serial.print(F("\t*** Sync symbol on SLICE ["));
      }
      Serial.print(cParrot.keySyncSlice);
      Serial.println(F("] ***"));
    }

    if (!strcmp(arg, "KV")) {
      if (arg2 != NULL) {
        cParrot.keySyncVolume = *arg2;
        Serial.print(F("\t*** Updated sync symbol on VOLUME to ["));
      } else {
        Serial.print(F("\t*** Sync symbol on VOLUME ["));
      }
      Serial.print(cParrot.keySyncVolume);
      Serial.println(F("] ***"));
    }

    if (!strcmp(arg, "KP")) {
      if (arg2 != NULL) {
        cParrot.keySyncPrescan = *arg2;
        Serial.print(F("\t*** Updated sync symbol on PRESCAN to ["));
      } else {
        Serial.print(F("\t*** Sync symbol on PRESCAN ["));
      }
      Serial.print(cParrot.keySyncPrescan);
      Serial.println(F("] ***"));
    }

    if (!strcmp(arg, "K1")) {
      if (arg2 != NULL) {
        cParrot.keysKBD[0] = *arg2;
        Serial.print(F("\t*** Updated response key K1 to ["));
      } else {
        Serial.print(F("\t*** Response key K1 is ["));
      }
      Serial.print(cParrot.keysKBD[0]);
      Serial.println(F("] ***"));
    }

    if (!strcmp(arg, "K2")) {
      if (arg2 != NULL) {
        cParrot.keysKBD[1] = *arg2;
        Serial.print(F("\t*** Updated response key K2 to ["));
      } else {
        Serial.print(F("\t*** Response key K2 is ["));
      }
      Serial.print(cParrot.keysKBD[1]);
      Serial.println(F("] ***"));
    }

    if (!strcmp(arg, "K3")) {
      if (arg2 != NULL) {
        cParrot.keysKBD[2] = *arg2;
        Serial.print(F("\t*** Updated response key K3 to ["));
      } else {
        Serial.print(F("\t*** Response key K3 is ["));
      }
      Serial.print(cParrot.keysKBD[3]);
      Serial.println(F("] ***"));
    }

    if (!strcmp(arg, "K4")) {
      if (arg2 != NULL) {
        cParrot.keysKBD[3] = *arg2;
        Serial.print(F("\t*** Updated response key K4 to ["));
      } else {
        Serial.print(F("\t*** Response key K4 is ["));
      }
      Serial.print(cParrot.keysKBD[3]);
      Serial.println(F("] ***"));
    }

    if (!strcmp(arg, "DEBUG")) {
      if (arg2 != NULL) {
        cParrot.DEBUG = aNumber ? 1 : 0;
      }
      Serial.print(F("Debug "));
      cParrot.DEBUG ? Serial.print(F("ON")) : Serial.print(F("OFF"));
    }

  }  else {
    Serial.println("No arguments");
  }

  int eeAddress = 0;
   eeAddress += sizeof(cDevice); // skip to the profile 0
  eeAddress += (sizeof(cParrot) * cDevice.cProfile); // skip to current profile
  EEPROM.put(eeAddress, cParrot);
}

#endif
