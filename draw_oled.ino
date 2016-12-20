void draw_oled(unsigned int cVolume, unsigned int cSlice) {

#define R_NAME 10
#define R_INFO 28

#define R_TR 40
#define R_VOLUME 51
#define R_SLICE 63

#define C_TITLE 10
#define C_PROFILE 4
#define C_PRESCAN 60
#define C_INFO 8
#define C_NUMBERS 55
#define C_NUMBERS2 90


#ifdef HAVE_OLED_U8G
  // graphic commands to redraw the complete screen should be placed here
  u8g.setFont(u8g_font_tpssb);
  u8g.drawStr( C_TITLE, R_NAME, "fMRI Parrot v.");
  u8g.setPrintPos(C_NUMBERS2, 10);
  u8g.print(__VERSION);

  u8g.drawStr(C_PROFILE, R_INFO, cParrot.Name);
  u8g.setPrintPos(C_NUMBERS2, R_TR);
  u8g.print(cParrot.TR);
  u8g.setPrintPos(C_NUMBERS, R_VOLUME);
  u8g.print(cVolume);
  u8g.setPrintPos(C_NUMBERS2, R_VOLUME);
  u8g.print(cParrot.NumVolumes);
  u8g.setPrintPos(C_NUMBERS, R_SLICE);
  u8g.print(cSlice);
  u8g.setPrintPos(C_NUMBERS2, R_SLICE);
  u8g.print(cParrot.NumSlices);

  u8g.setFont(u8g_font_profont11);

  u8g.drawStr( C_NUMBERS + 4, R_TR, "TR =");
  u8g.drawStr( C_INFO, R_VOLUME, "Volume: ");
  u8g.drawStr( C_NUMBERS + 20, R_VOLUME, "of ");
  u8g.drawStr( C_INFO, R_SLICE, " Slice: ");
  u8g.drawStr( C_NUMBERS + 20, R_SLICE, "of ");

#endif

#ifdef HAVE_OLED_U8G8
  u8x8.setFont(u8x8_font_pcsenior_f);
  u8x8.drawString(C_TITLE, R_NAME, "fMRI Parrot v.");
  u8x8.setCursor(C_NUMBERS2, 10);
  u8x8.print(__VERSION);

  u8x8.setCursor(C_PROFILE, R_INFO);
  u8x8.print(cParrot.Name);
  u8x8.setCursor(C_NUMBERS2, R_TR);
  u8x8.print(cParrot.TR);
  u8x8.setCursor(C_NUMBERS, R_VOLUME);
  u8x8.print(cVolume);
  u8x8.setCursor(C_NUMBERS2, R_VOLUME);
  u8x8.print(cParrot.NumVolumes);
  u8x8.setCursor(C_NUMBERS, R_SLICE);
  u8x8.print(cSlice);
  u8x8.setCursor(C_NUMBERS2, R_SLICE);
  u8x8.print(cParrot.NumSlices);

  u8x8.setFont(u8x8_font_chroma48medium8_r);
  
  u8x8.drawString(C_NUMBERS + 4, R_TR, "TR =");
  u8x8.drawString(C_INFO, R_VOLUME, "Volume: ");
  u8x8.drawString(C_NUMBERS + 20, R_VOLUME, "of ");
  u8x8.drawString(C_INFO, R_SLICE, " Slice: ");
  u8x8.drawString(C_NUMBERS + 20, R_SLICE, "of ");

#endif

#ifdef HAVE_OLED_JPRC
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setCursor( C_TITLE, R_NAME);
  display.print("fMRI Parrot v.");
  display.setCursor(C_NUMBERS2, 10);
  display.print(__VERSION);

  display.setTextColor(WHITE);
  display.setCursor(C_PROFILE, R_INFO);
  display.print( cParrot.Name);
  display.setCursor(C_NUMBERS2, R_TR);
  display.print(cParrot.TR);
  display.setCursor(C_NUMBERS, R_VOLUME);
  display.print(cVolume);
  display.setCursor(C_NUMBERS2, R_VOLUME);
  display.print(cParrot.NumVolumes);
  display.setCursor(C_NUMBERS, R_SLICE);
  display.print(cSlice);
  display.setCursor(C_NUMBERS2, R_SLICE);
  display.print(cParrot.NumSlices);

  display.setTextSize(1);

  display.setCursor( C_NUMBERS + 4, R_TR);
  display.print( "TR =");
  display.setCursor( C_INFO, R_VOLUME);
  display.print( "Volume: ");
  display.setCursor( C_NUMBERS + 20, R_VOLUME);
  display.print( "of ");
  display.setCursor( C_INFO, R_SLICE);
  display.print( " Slice: ");
  display.setCursor( C_NUMBERS + 20, R_SLICE);
  display.print( "of ");
#endif

  if (_RunMode == 1) {
#ifdef HAVE_OLED_U8G
    u8g.drawStr( C_PRESCAN, R_INFO, "Prescanning");
#endif
#ifdef HAVE_OLED_U8G8
    u8x8.drawString(C_PRESCAN, R_INFO, "Prescanning");
#endif
#ifdef HAVE_OLED_JPRC
    display.setCursor( C_PRESCAN, R_INFO);
    display.print("Prescanning");
#endif

  }
}

