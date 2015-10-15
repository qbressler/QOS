#include<console.h>

UPoint ConsoleCursor = {0, 0};
UPoint ConsoleSize = { ConsoleWidth, ConsoleHeight };

uint8* VideoRam = (uint8*)0xb8000;

void ConsoleClear()
{
	uint32 i;
	for(i = 0; i < ConsoleSize.X * ConsoleSize.Y * 2; i++)
		VideoRam[i] = 0;
}
void ConsoleWriteChar(char c)
{
	ConsoleWriteCharColored(c, ConsoleDefaultColor);
}
void ConsoleWriteCharColored(char c, uint8 color)
{
	uint32 location = ConsoleCursor.X + ConsoleCursor.Y * ConsoleSize.X;
	VideoRam[2*location] = c;
	VideoRam[2*location +1] = color;

	ConsoleCursor.X++;

	if(ConsoleCursor.X >= ConsoleSize.X)
	{
		ConsoleCursor.X = 0;
		ConsoleCursor.Y ++;
	}
}
void ConsoleWriteString (string s)
{
	ConsoleWriteStringColored (s, ConsoleDefaultColor);
}

void ConsoleWriteLineString (string s)
{
	ConsoleWriteStringColored(s, ConsoleDefaultColor);
}

void ConsoleWriteStringColored (string s, uint8 color)
{
	while(*s != 0)
	{
		ConsoleWriteCharColored (*s, color);
		s = s + 1;
	}
}
