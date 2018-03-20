//Constant definition
#define ESC 0x1B
#define BAR "\u2590"
#define UNICODE 	//Conditional compiling
#define RES 3
enum FGCOLORS{BLACK=30,RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
//Function prototype
void clearScreen(void);
void gotoxy(int, int);
void bar(int, double);
void setColor(int);
