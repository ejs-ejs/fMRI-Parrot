void oled_init() {

#ifdef HAVE_OLED_U8G
  u8g.setFont(u8g_font_profont11);
  u8g.drawStr( 16, 20, "fMRI Parrot");
  u8g.setFont(u8g_font_tpssb);
  u8g.drawStr( 30, 58, "version");
  u8g.setPrintPos(80, 58);
  u8g.print(__VERSION);
#endif

#ifdef HAVE_OLED_U8G8
  u8x8.setFont(u8x8_font_pcsenior_f);
  u8x8.drawString(16, 20, "fMRI Parrot");
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(30, 58, "version");
  u8x8.setCursor(80, 58);
  u8x8.print(__VERSION);
#endif

#ifdef HAVE_OLED_JPRC
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(16, 20);
  display.println("fMRI Parrot");
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setCursor(30, 58);
  display.print("version");
  display.setCursor(80, 58);
  display.print(__VERSION);
  display.display();
  delay(2000);
#endif



}


