#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
    int x0, y0, x1, y1;
    float x, y, dx, dy, length;
    int i;

    int gd = DETECT, gm;


    clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
     printf("\nEnter x0: ");
     scanf("%d", &x0);
       printf("\nEnter y0: ");
     scanf("%d", &y0);
     printf("\nEnter x1: ");
      scanf("%d", &x1);
      printf("\nEnter y1: ");
     scanf("%d", &y1);

  //  x0 = 50; y0 = 40;
  //  x1 = 100; y1 = 120;

    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);

    if (dx >= dy)
    {
	length = dx ;
    }
    else
	length = dy;

    dx = dx / length;
    dy = dy / length;

    x = x0;
    y = y0;

   // setbkcolor(1);
    for (i = 0; i < length; i++)
    {

	putpixel(x, y, 2);
	x = x + dx;
        y = y + dy;
    }

    getch();
    closegraph();

    return 0;
}