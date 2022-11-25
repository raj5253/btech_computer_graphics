#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
    int i = 0;
    int gd = DETECT,gm;


    clrscr();
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    for (i = 1; i <= 11; i++)
    {
       //	setbkcolor(14);
	setcolor(i);
	outtextxy(100, 50 + 10*i, "Hell world of computer graphics");
    }

    getch();

    closegraph();

    return 0;
}

/*
gd = graphdriver;
gm = graphmode;
void initgraph (int *graphdriver, int *graphmode, char *pathtodriver) ;
Borland Graphics Interface (BGI) is a graphics library ,
that is bundled with several Borland compilers for the DOS operating systems since 1987.

closegraph deallocates the memory allocated by the graphics system ,
and then restores the screen to the mode it was in before calling initgraph.

void settextstyle(int font, int direction, int font_size);

*/