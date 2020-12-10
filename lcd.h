#ifndef LCD
#define LCD
  void lcdCommand(char value);
  void lcdChar(char value);
  void lcdInit(void);
  void lcdString(char msg[]);
  void lcdNumber(int value);
  void lcdPosition(int line, int col);
#endif
