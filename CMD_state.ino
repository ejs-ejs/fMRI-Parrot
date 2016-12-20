/* CONTROLL COMMANDS
    state command
*/
void CMD_state() {
  Serial.println(F("\n\nThis is fMRI Parrot"));
  Serial.print(F("\t version "));
  Serial.println(__VERSION);
  Serial.println(F("=============================="));
  Serial.print(F("Profile: "));
  Serial.println(cParrot.Name);
  Serial.print(F("TR = "));
  Serial.print(cParrot.TR, DEC);
  Serial.println(F(" ms"));
  Serial.print(F("Number of volumes:\t"));
  Serial.println(cParrot.NumVolumes, DEC);
  Serial.print(F("Number of slices:\t"));
  Serial.println(cParrot.NumSlices, DEC);
  Serial.print(F("Prescan volumes:\t"));
  Serial.println(cParrot.NumPrescans, DEC);
  
  
  Serial.println(F("Sync on:"));

  Serial.print(F("\tprescan ["));
  cParrot.TickPerPrescan ? Serial.print(F("x")) : Serial.print(F(" "));
  Serial.println(F("]"));
  
  Serial.print(F("\t volume ["));
  cParrot.TickPerVolume ? Serial.print(F("x")) : Serial.print(F(" "));
  Serial.println(F("]"));
  
  Serial.print(F("\t  slice ["));
  cParrot.TickPerSlice ? Serial.print(F("x")) : Serial.print(F(" "));
  Serial.println(F("]\n"));
  
  
  Serial.print(F("Slice sync symbol:\t"));
  Serial.println(cParrot.keySyncSlice);
  Serial.print(F("Volume sync symbol:\t"));
  Serial.println(cParrot.keySyncVolume);
  Serial.print(F("Prescan sync symbol:\t"));
  Serial.println(cParrot.keySyncPrescan);

  
  Serial.print(F("Response keys:\t K1="));
  Serial.print(cParrot.keysKBD[0]);
  Serial.print(F("\t K2="));
  Serial.print(cParrot.keysKBD[1]);
  Serial.print(F("\t K3="));
  Serial.print(cParrot.keysKBD[2]);
  Serial.print(F("\t K4="));
  Serial.println(cParrot.keysKBD[3]);
  Serial.println();
  _Start ? Serial.println(F("Simulation running\n")) : Serial.println(F("Simulation stopped\n"));
}
