#include "globals.h"
#include "terminal.h"
#include "utils.h"

extern struct editorConfig E;
extern struct programUtils PU;
extern textbuf TEXTBUF;

char editorReadKey(void);
void editorProcessKeyPress(void);
void editorRefreshScreen(void);
void editorInit(void);
int editorMoveCursor(char);

/*** FILE IO ***/
void editorOpen(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    char errorMessage[100];
    snprintf(errorMessage, 100, "Can not open File '%s'\r\nperrer message",
             filename);
    die(errorMessage);
  }

  textbufRead(&TEXTBUF, fp); // All lines of the file are read into TEXTBUF

  fclose(fp);
}

/*** Input ***/
/// Reads and returns the key once.
char editorReadKey(void) {
  int nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) < 1) {
    // read returns '\0' if no input is received after 0.1 s
    // read returns number of byte read. -1 when failure.
    if (nread == -1 && errno != EAGAIN)
      die("editorReadKey failed!");
  }

  if (c != '\x1b') // if no escape sequence is read.
    return c;

  // NOTE: INCOMPLETE CAPTURE FOR PAGE_UP
  char seq[3];
  for (int i = 0; i < 2; ++i)
    if (read(STDIN_FILENO, &seq[i], 1) < 1)
  //     return '\x1b';

  if (seq[0] != '[')
    return '\x1b';

  if (seq[1] == '5')
    return PAGE_UP;
  if (seq[1] == '6')
    return PAGE_DOWN;
  if (seq[1] == '3')
    return DEL_KEY;
  if (seq[1] == '1')
    return HOME_KEY;

 //  if (read(STDIN_FILENO, &seq[2], 1) < 1)
	// 	return '\x1b';
	// if (seq[2]!='~') 
	// 	return '\x1b';
  switch (seq[1]) {
  case 'A':
    return ARROW_UP; // TESTED
  case 'B':
    return ARROW_DOWN; // TESTED
  case 'C':
    return ARROW_RIGHT; // TESTED
  case 'D':
    return ARROW_LEFT; // TESTED
  case 'H':
    return HOME_KEY; // TESTED
  case 'F':
    return END_KEY;
  default:
    return '\x1b';
  }
  return '\x1b';
}

void editorProcessKeyPress(void) {
  char c = editorReadKey();
  PU.updated = 1;
  switch (c) {
  case (CTRL_KEY('q')):
    clearScreen();
    PU.running = 0;
    break;

  case (CTRL_KEY('z')):
		E.offsety = TEXTBUF.size - E.screenrows;
		E.cy = 0;
    break;
  case (CTRL_KEY('x')):
		E.offsety = 0;
		E.cy = E.screenrows-1;
    break;

  case ARROW_LEFT:
  case ARROW_RIGHT:
  case ARROW_DOWN:
  case ARROW_UP:
    editorMoveCursor(c);
    break;

  case PAGE_UP: // PAGE_UP, PAGE_DOWN tested
  case PAGE_DOWN: {
    int times = E.screenrows;
    while (times--)
      editorMoveCursor(c == PAGE_UP ? ARROW_UP : ARROW_DOWN);
    break;
  }

  case HOME_KEY:
  case END_KEY:
  case DEL_KEY:
    break;
  default:
		textbufInputChar(&TEXTBUF, c, E.cx, E.cy+E.offsety);
    break;
  }
}

static int appendWelcomeMessage(struct abuf *ptr) {
  struct abuf *abptr = ptr;
  char welcome[80];
  // KILO_VERSION defined in main.c
  // snprintf is form <stdio.h>
  int welcomelen =
      snprintf(welcome, sizeof(welcome), "Kilo Editor -- Version %d.%d.%d",
               KILO_VERSION_MAJOR, KILO_VERSION_MINOR, KILO_VERSION_PATCH);
  if (welcomelen > E.screencols)
    welcomelen = E.screencols;

  // Center the Message
  int padding = (E.screencols - welcomelen) / 2;
  if (padding) {
    abAppend(abptr, "~", 1);
    padding--;
  }
  while (padding--)
    abAppend(abptr, " ", 1);

  abAppend(abptr, welcome, welcomelen);

  return 1;
}

/*** Output ***/
void editorDrawRows(struct abuf *abptr) {
  for (int nrows = 0; nrows < E.screenrows; nrows++) {
    // Number of rows to be drawn
    const int n_rows_to_draw = nrows + E.offsety;
    if (n_rows_to_draw >= TEXTBUF.size || n_rows_to_draw < 0) {
      abAppend(abptr, "~", 3);
    } else {
      if (TEXTBUF.linebuf != NULL) {
        // temp points to the string of the row to be drawn.
        char *temp = *(TEXTBUF.linebuf + n_rows_to_draw);
        const int stringlen = strlen(temp);

        // For calculate the spaces for direction scrolling.
        const int xoffset = E.offsetx >= stringlen ? stringlen : E.offsetx;
        temp += xoffset;

        // Calculate the correct display length of the buffer
        int bufferlen = stringlen - xoffset; // same as strlen(temp)
        bufferlen = (bufferlen >= E.screencols) ? E.screencols - 1 : bufferlen;

        abAppend(abptr, " ", 1);  // The space before the Line.
        abAppend(abptr, temp, bufferlen);
      }
    }
    abAppend(abptr, "\r\n", 2);
  }
}

void editorRefreshScreen(void) {
  // init append buffer
  struct abuf ab = ABUF_INIT;

  abAppend(&ab, "\x1b[?25l", 6); // Hide cursor
  abAppend(&ab, "\x1b[H", 3);    // Move cursor to top left

  editorDrawRows(&ab);

  // Move mouse to correct position
  char buf[32];
  snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy + 1, E.cx + 1);
  abAppend(&ab, buf, strlen(buf)); // To corrected position
                                   // strlen is from <string.h>

  abAppend(&ab, "\x1b[?25h", 6); // Show cursor
  write(STDIN_FILENO, "\x1b[2J\x1b[H", 7);
  write(STDIN_FILENO, ab.b, ab.len);
  abFree(&ab);
}

int editorScrollDown(void) {
  if (E.offsety < TEXTBUF.size + E.screenrows / 4)
    E.offsety++;
  return 1;
}

int editorScrollUp(void) {
  if (E.offsety > -E.screenrows / 2)
    E.offsety--;
  return 1;
}

int editorScrollLeft(void) {
  if (E.offsetx >= 1)
    E.offsetx--;
  return 1;
}

int editorScrollRight(void) {
  E.offsetx++;
  return 1;
}

// TODO: Protection mechanism (stop from scrolling too far away from text 
// TODO: Needs to be reworked
int editorMoveCursor(char key) {
  PU.updated = 1;
  switch (key) {
  case ARROW_UP:
    if (E.cy > E.screenrows / 4 || E.offsety < 0){
			if (E.cy>0) E.cy--;
		}
    else
      editorScrollUp();
    return 0;
  case ARROW_DOWN:
    if (E.cy < 3 * E.screenrows / 4 - 1)
      E.cy++;
    else
      editorScrollDown();
    return 0;
  case ARROW_LEFT:
    if (E.cx > 0)
      E.cx--;
    if (E.cx < E.screencols / 4)
      editorScrollLeft();
    return 0;
  case ARROW_RIGHT:
    if (E.cx < E.screencols - 1)
      E.cx++;
    if (E.cx > 3 * E.screencols / 4)
      editorScrollRight();
    return 0;
  default:
    return -1;
  }
  return -1;
}

/*** init ***/
void editorInit(void) {
  E.cx = 0; // E is global variable
  E.cy = 0;
  E.offsety = 0;
  E.offsetx = 0;
  getWindowSize(&E.screenrows, &E.screencols); // from "terminal.h"

  PU.running = 1;
  PU.updated = 1;
	
	TEXTBUF.size = 0;
  TEXTBUF.linebuf = NULL;
  if (TEXTBUF.size != 0 || TEXTBUF.linebuf != NULL)
		die("Fail to Init TEXTBUF");
}

int main(int argc, char *argv[]) {
  enableRAWMode(); // from "terminal.h"; enable Terminal RAW mode
  editorInit();
  if (argc > 1) {
    editorOpen(argv[1]);
  }
  while (PU.running) { // PU is global struct, [P]rogram [U]tils
    if (PU.updated) {
      editorRefreshScreen();
      PU.updated = 0;
    }
    editorProcessKeyPress();
  }
  return 0;
}
