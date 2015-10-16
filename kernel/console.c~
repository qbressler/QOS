#include<console.h>


/* Some screen stuff. */
/* The number of columns. */
#define COLUMNS                 80
/* The number of lines. */
#define LINES                   24
/* The attribute of an character. */
#define ATTRIBUTE               7
/* The video memory address. */
#define VIDEO                   0xB8000

/* Variables. */
/* Save the X position. */
static int xpos;
/* Save the Y position. */
static int ypos;
/* Point to the video memory. */
static volatile unsigned char *video;

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

void putchar (int c)
{
	
	if (c == '\n' || c == '\r')
	{
		newline:
			ConsoleWriteString("..1");
           		xpos = 0;
           		ypos++;
           		if (ypos >= LINES)
	   		{
	     			ConsoleWriteString("..2");
             			ypos = 0;
           		}
           		return;
         }
     
	*(video + (ConsoleSize.X + ConsoleSize.Y * COLUMNS) * 2) = c & 0xFF;
	*(video + (ConsoleSize.X + ConsoleSize.Y * COLUMNS) * 2 + 1) = ATTRIBUTE;

	xpos++;
	if (xpos >= COLUMNS)
		goto newline;
}

void printf (const char *format, ...)
{
	char **arg = (char **) &format;
	int c;
	char buf[20];

	arg++;

	while ((c = *format++) != 0)
	{
		if (c != '%')
			putchar (c);
           	else
		{
	               char *p;
     
        	       c = *format++;
        	       switch (c)
        	       {
				case 'd':
				case 'u':
				 /*case 'x':
					   itoa (buf, c, *((int *) arg++));
					   p = buf;
					   goto string;
					   break;*/
			     
				 case 's':
				   p = *arg++;
				   if (! p)
				   	p = "(null)";
		     
				 string:
				   while (*p)
				     putchar (*p++);
				   break;
		     
				 default:
				   putchar (*((int *) arg++));
				   break;
			}
             	}
         }
}



/*unsigned int k_printf(char *message, unsigned int line) // the message and then the line #
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;

	i=(line*80*2);

	while(*message!=0)
	{
		if(*message=='\n') // check for a new line
		{
			line++;
			i=(line*80*2);
			*message++;
		} else {
			vidmem[i]=*message;
			*message++;
			i++;
			vidmem[i]=ConsoleDefaultColor;
			i++;
		};
	};

	return(1);
};*/

void ConsoleWriteStringColored (string s, uint8 color)
{
	while(*s != 0)
	{
		if(*s == '\n')
		{
			ConsoleCursor.Y++;
			//ConsoleCursor.X = 0;
		}
		ConsoleWriteCharColored (*s, color);
		s = s + 1;

	}
}
