#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *
 *  NOTE: All the functions that take Colors as a parameter, calls resetColor()
 *  before returning when provided with a Colors that isn't 0.
 *
 *  This note is useful when you are calling setColor() and resetColor()
 *  directly in your views.
 *
 */

void printLogo(Colors main_color,  Colors container_color) {
  setColor(STYLE_BOLD);
  setColor(main_color);
  printStarLine(container_color);
  setColor(STYLE_BOLD);
  setColor(container_color);
  setColor(main_color);
  printFramedText("  ____                        _           ", '*', false,
    0, 0);
  printFramedText(" |  _ \\ ___ _ __   __ _ _   _(_)_ __  ___ ", '*', false,
    0, 0);
  printFramedText(" | |_) / _ \\ '_ \\ / _` | | | | | '_ \\/ __|", '*', false,
    0, 0);
  printFramedText(" |  __/  __/ | | | (_| | |_| | | | | \\__ \\", '*', false,
    0, 0);
  printFramedText(" |_|   \\___|_| |_|\\__, |\\__,_|_|_| |_|___/", '*', false,
    0, 0);
  printFramedText("                  |___/                   ", '*', false,
    0, 0);
  printStarLine(container_color);

  setColor(STYLE_BOLD);
  setColor(container_color);
  setColor(main_color);
  clearLine();
  resetColor();
}

void printFramedTextList(char** text_list, char frame_char, int list_size) {
  if (text_list == NULL) {
    printf("Error: print_framed_text_list() called with NULL text_list!\n");
    return;
  }
  printCharLine(frame_char, 0);
  for (int i = 0; i < list_size; i++) {
    printFramedText(text_list[i], frame_char, false, 0, 0);
  }
  printCharLine(frame_char, 0);
}

void printFramedTextLeft(char* text, char frame_char, bool vertical_frame,
  Colors text_color, Colors frame_color) {
  if (text == NULL) {
    printf("Error: printFramedText() called with NULL text!\n");
    return;
  }

  int text_len = strlen(text);
  int padding = LINE_WIDTH - text_len;

  if (vertical_frame) {
    if (frame_color) {
      resetColor();
      setColor(frame_color);
    }
    printCharLine(frame_char, 0);
  }

  if (frame_color) {
    resetColor();
    setColor(frame_color);
  }
  printf("%c", frame_char);

  if (text_color) {
    resetColor();
    setColor(text_color);
  }
  printf("%s", text);

  for (int i = 0; i < padding - 1; i++) {
    if (i == (padding - 2)) {
      if (text_color) {
        resetColor();
      }

      if (frame_color) {
        resetColor();
        setColor(frame_color);
      }
      printf(" %c", frame_char);
    } else {
      printf(" ");
    }
  }

  printf("\n\r");
  if (vertical_frame) {
    if (frame_color) {
      resetColor();
      setColor(frame_color);
    }
    printCharLine(frame_char, 0);
  }

  if (text_color || frame_color) {
    resetColor();
  }

}

void printFramedText(char* text, char frame_char, bool vertical_frame,
  Colors text_color, Colors frame_color) {
  if (text == NULL) {
    printf("Error: print_framed_text() called with NULL text!\n");
    return;
  }

  int text_len = strlen(text);
  int padding = LINE_WIDTH - text_len;
  int end_spacing = text_len % 2; // Remove one padding_char from the end if the
  // text is odd number of chars

  if (vertical_frame) {
    if (frame_color) {
      resetColor();
      setColor(frame_color);
    }
    printCharLine(frame_char, 0);
  }

  printf("\r");
  for (int i = 0; i < padding / 2; i++) {
    if (i == 0) {
      if (frame_color) {
        setColor(frame_color);
      }

      printf("%c", frame_char);

      if (text_color) {
        resetColor();
        setColor(text_color);
      }
    }
    printf(" ");
  }

  printf("%s", text);

  for (int i = 0; i < padding / 2 - end_spacing; i++) {
    if (i == (padding / 2 - end_spacing) - 1) {
      if (text_color) {
        resetColor();
      }

      if (frame_color) {
        setColor(frame_color);
      }

      printf(" %c", frame_char);

      if (text_color) {
        resetColor();
        setColor(text_color);
      }
    } else {
      printf(" ");
    }
  }
  printf("\n\r");

  if (vertical_frame) {
    if (frame_color) {
      resetColor();
      setColor(frame_color);
    }
    printCharLine(frame_char, 0);
  }

  if (text_color || frame_color) {
    resetColor();
  }

}

void printErrorText(char* text) {
  char* line = malloc(LINE_WIDTH);
  sprintf(line, " [Error] %s", text);
  printf("\n");
  printFramedTextLeft(line, '*', true, WHITE_TXT || WHITE_BG, RED_TXT);
  printf("\n");
  free(line);
}

void printWarningText(char* text) {
  char* line = malloc(LINE_WIDTH);
  sprintf(line, " [Warning] %s", text);
  printf("\n");
  printFramedTextLeft(line, '*', true, WHITE_TXT || WHITE_BG, YELLOW_TXT);
  printf("\n");
  free(line);
}

void printInfoText(char* text) {
  char* line = malloc(LINE_WIDTH);
  sprintf(line, " [Info] %s", text);
  printf("\n");
  printFramedTextLeft(line, '*', true, WHITE_TXT || WHITE_BG,
    WHITE_TXT || WHITE_BG);
  printf("\n");
  free(line);
}

void printTabs(int tabs_count, Colors color) {
  if (tabs_count == 0) {
    return;
  }
  printf("\r");
  if (color) {
    setColor(color);
  }
  for (int i = 0; i < tabs_count; i++) {
    printf("\t");
  }

  if (color) {
    resetColor();
  }

}

void printCharLine(char spacing_char, Colors color) {
  printf("\r");
  if (color) {
    setColor(color);
  }
  for (int i = 0; i < LINE_WIDTH + 1; i++) {
    printf("%c", spacing_char);
  }
  printf("\n");

  if (color) {
    resetColor();
  }


}

void printDashLine(Colors color) {
  printf("\r");
  if (color) {
    setColor(color);
  }
  for (int i = 0; i < LINE_WIDTH + 1; i++) {
    printf("-");
  }
  printf("\n");
  if (color) {
    resetColor();
  }

}

void printStarLine(Colors color) {
  printf("\r");
  if (color) {
    setColor(color);
  }
  for (int i = 0; i < LINE_WIDTH + 1; i++) {
    printf("*");
  }
  printf("\n");
  if (color) {
    resetColor();
  }


}

void printPaddedText(char* text, char padding_char, Colors color) {
  if (text == NULL) {
    printStarLine(color);
    return;
  }

  int text_len = strlen(text);
  int padding = LINE_WIDTH - text_len;
  int end_spacing = text_len % 2; // Remove one padding_char from the end if the
  // text is odd number of chars

  if (color) {
    setColor(color);
  }

  printf("\r");
  for (int i = 0; i < padding / 2; i++) {
    printf("%c", padding_char);
  }
  if (padding / 2 > 1) {
    printf(" ");
  }

  printf("%s", text);

  if (padding / 2 > 1) {
    printf(" ");
  }
  for (int i = 0; i < padding / 2 - end_spacing; i++) {
    printf("%c", padding_char);
  }
  printf("\n\r");

  if (color) {
    resetColor();
  }

}

void printMenu(char* menu_title, char** labels, char* choices, int labels_num,
  char padding_char) {
  if (labels == NULL || choices == NULL) {
    printCharLine('X', 0);
    printf("ERROR: Wrong args to printMenu()!\n");
    printCharLine('X', 0);
    return;
  }

  char _padding_char = '-';
  if (padding_char != -1) {
    _padding_char = padding_char;
  }

  if (menu_title != NULL) {
    printCharLine(_padding_char, 0);
    printPaddedText(menu_title, _padding_char, 0);
  }

  printCharLine(_padding_char, 0);
  for (int i = 0; i < labels_num; i++) {
    printf("\r[%c]-> <%s>\n", choices[i], labels[i]);
  }
  printCharLine(_padding_char, 0);
  printf("\n\r");
}

void clear_screen_to_bottom(void) {
  printf("\033[%dJ", CLEAR_FROM_CURSOR_TO_END);
}
void clearScreenToTop(void) {
  printf("\033[%dJ", CLEAR_FROM_CURSOR_TO_BEGIN);
}
void clearLine(void) { printf("\033[%dK", CLEAR_ALL); }
void clearLineToRight(void) { printf("\033[%dK", CLEAR_FROM_CURSOR_TO_END); }
void clearLineToLeft(void) {
  printf("\033[%dK", CLEAR_FROM_CURSOR_TO_BEGIN);
}

void moveUp(int positions) { printf("\033[%dA", positions); }

void moveDown(int positions) { printf("\033[%dB", positions); }

void moveRight(int positions) { printf("\033[%dC", positions); }

void moveLeft(int positions) { printf("\033[%dD", positions); }

void moveTo(int row, int col) { printf("\033[%d;%df", row, col); }

void saveCursor() { printf("\033%d", 7); }
void restoreCursor() { printf("\033%d", 8); }

void resetColor() { printf("\033[0m"); }

void setColor(Colors color) { printf("\x1b[%dm", color); }

