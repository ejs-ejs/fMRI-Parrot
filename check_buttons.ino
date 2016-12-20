void check_buttons(void) {
  if (debouncTrig.update()) {
    if ( !debouncTrig.read()) {
      _Start = !(_Start); // trigger start condition
    }
  }
  if (debouncK1.update()) {
    if ( !debouncK1.read()) {
      Serial.println(cParrot.keysKBD[0]); // print response
    }
  }
  if (debouncK2.update()) {
    if ( !debouncK2.read()) {
      if (_Start) {
      Serial.println(cParrot.keysKBD[1]); // print response
      } else {
        profile_set(cDevice.cProfile+1);
      }
    }
  }
  if (debouncK3.update()) {
    if ( !debouncK3.read()) {
      if (_Start) {
      Serial.println(cParrot.keysKBD[2]); // print response
      } else {
        profile_set(cDevice.cProfile-1);
      }
    }
  }
  if (debouncK4.update()) {
    if ( !debouncK4.read()) {
      if (_Start) {
      Serial.println(cParrot.keysKBD[3]); // print response
       } else {
        Serial.print(F("Number of profiles available: "));
        Serial.println(cDevice.nProfiles, DEC);
      }
    }
  }

}
