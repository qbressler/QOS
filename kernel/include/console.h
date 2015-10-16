#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include<types.h>

#define ConsoleWidth 80
#define ConsoleHeight 25
#define ConsoleDefaultColor 0x7

enum Colors {
	ColorBlack	= 0x0,
	ColorBlue	= 0x1,
	ColorGreen	= 0x2,
	ColorCyan	= 0x3,
	ColorRed	= 0x4,
	ColorMagenta	= 0x5,
	ColorBrown	= 0x6,
	ColorLightGray	= 0x7,
	ColorDarkGray	= 0x8,
	ColorLightBlue	= 0x9,
	ColorLightGreen	= 0xA,
	ColorLightCyan	= 0xB,
	ColorLightRed	= 0xC,
	ColorLightMagenta = 0xD,
	ColorYellow	= 0xE,
	ColorWhite	= 0xF,

};

extern void ConsoleClear();
extern void ConsoleWriteChar(char c);
extern void ConsoleWriteCharColored(char c, uint8 color);
extern void ConsoleWriteString (string s);
extern void ConsoleWriteLineString (string s);
extern void ConsoleWriteStringColored (string s, uint8 color);
//extern unsigned int k_printf(char *message, unsigned int line);

extern void printf (const char *format, ...);
extern void putchar (int c);

#endif

