struct Device {
  unsigned short cProfile; // current prifile to start at
  unsigned short nProfiles; // number of profiles stored
  unsigned int baudrate; // RS-232 baudrate
  unsigned long signature;
};

struct Parrot {
  char Name[9]; // name of the profile
  unsigned int TR; // Time Repetition
  unsigned int NumSlices;
  unsigned int NumVolumes;
  unsigned int NumPrescans;
  byte TickPerSlice;
  byte TickPerVolume;
  byte TickPerPrescan;
  char keySyncSlice;
  char keySyncVolume;
  char keySyncPrescan;
  char keysKBD[8];
  byte DEBUG;
};


void check_buttons(void);
void slice_volume(void);
void draw_oled(unsigned int, unsigned int);
