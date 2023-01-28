#ifndef UI_H
#define UI_H
#define LINE_WIDTH 89 // Means: 89 of `*` covers a complete line
#define DEFAULT_PADDING_CHAR '-'

#include <stdbool.h>

typedef enum {
  CLEAR_FROM_CURSOR_TO_END,
  CLEAR_FROM_CURSOR_TO_BEGIN,
  CLEAR_ALL
} clear_codes;

typedef enum {
  RESET_COLOR,
  BLACK_TXT = 30,
  RED_TXT,
  GREEN_TXT,
  YELLOW_TXT,
  BLUE_TXT,
  MAGENTA_TXT,
  CYAN_TXT,
  WHITE_TXT,

  BLACK_BG = 40,
  RED_BG,
  GREEN_BG,
  YELLOW_BG,
  BLUE_BG,
  MAGENTA_BG,
  CYAN_BG,
  WHITE_BG,

  STYLE_BOLD = 1,
  STYLE_ITALIC = 3,
  STYLE_UNDERLINE = 4,
  STYLE_UNDERLINE_OFF = 24,
  STYLE_REVERSE_COLORS = 7,
  STYLE_NORMAL = 0,
} Colors;

#endif

void printLogo(Colors main_color, Colors container_color);
void printFramedTextList(char **text_list, char frame_char, int list_size);
                                  
void printFramedTextLeft(char *text, char frame_char, bool vertical_frame, Colors text_color, Colors frame_color);
                                   
void printFramedText(char *text, char frame_char, bool vertical_frame,  Colors text_color, Colors frame_color);
                            
void printErrorText(char *text);
void printWarningText(char *text);
void printInfoText(char *text);
void printTabs(int tabs_count, Colors color);
void printCharLine(char spacing_char, Colors color);
void printDashLine(Colors color);
void printStarLine(Colors color);
void printPaddedText(char *text, char padding_char, Colors color);
void printMenu(char *menu_title, char **labels, char *choices, int labels_num, char padding_char);
                      

void clearLine();
void clear_screen_to_bottom(void);
void clearScreenToTop(void);
void clearLine(void);
void clearLineToRight(void);
void clearLineToLeft(void);

void moveUp(int positions);
void moveDown(int positions);
void moveRight(int positions);
void moveLeft(int positions);
void moveTo(int row, int col);

void saveCursor();
void restoreCursor();

void resetColor();
void setColor(Colors color);