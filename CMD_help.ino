/* CONTROLL COMMANDS
    help command
*/

void CMD_help(void) {
  Serial.println(F("\n\nThis is fMRI Parrot"));
  Serial.print(F("\t version "));
  Serial.println(__VERSION);
  Serial.println(F("===== HELP COMMANDS =========="));
  Serial.println(F("\t START   - start simulation"));
  Serial.println(F("\t STOP    - stop simulation"));
  Serial.println(F("\t RESET   - reset simulation"));
  Serial.println(F("\t STATE   - show current state"));
  Serial.println(F("\t ?       - show this help"));
  Serial.println(F(" \t\t S-commands, used to controll settings:"));
  Serial.println(F("\t S TR time           - set TimeRepetition, in ms"));
  Serial.println(F("\t S VOLUMES nVolumes  - set number of volumes"));
  Serial.println(F("\t S SLICES nSlices    - set number of slices per volume"));
  Serial.println(F("\t S PRESCANS nSlices  - set number of slices per prescann"));
  Serial.println(F("\t S SYNC_VOLUME [0|1} - sync pulse on volume start"));
  Serial.println(F("\t S SYNC_SLICE [0|1}  - sync pulse on slice start"));
  Serial.println(F("\t S SYNC_PRESCAN [0|1}  - sync pulse on slice start"));
  Serial.println(F("\n\t S KV char  - character to print on the start of the volume"));
  Serial.println(F("\t S KS char  - character to print on the start of the slice"));
  Serial.println(F("\t S KP char  - character to print on the start of the prescan volume"));
  Serial.println(F("========================= Profiles ===================\n"));
  Serial.println(F("\t set current profile using UP and DOWN keys"));
  Serial.println(F("\t P LIST        - list profiles "));
  Serial.println(F("\t P COPY        - copy current profile to the new one"));
  //Serial.println(F("\t P DEL <number>         - delete the profile #number"));
  Serial.println(F("\t P NAME <name> - name the current profile as <name>"));


  
  Serial.println(F("==============================\n"));

}
