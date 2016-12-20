void slice_volume(void) {

  cTime = millis();

  timeDelta = cTime - timeTick;

  if (timeDelta >= tSlice) {
    timeTick = cTime;
    cSlice++;
    if (cParrot.TickPerSlice) {
      Serial.println(cParrot.keySyncSlice);
      if (cParrot.DEBUG) {
        Serial.print(F("DEBUG: cSlice="));
        Serial.print(cSlice, DEC);
        Serial.print(F("\t cVolume="));
        Serial.print(cVolume, DEC);
        Serial.print(F("\t tDelta="));
        Serial.println(timeDelta, DEC);
      }
    }
  }

}
