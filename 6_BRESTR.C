#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void draw_line_y(int x0, int y0, int x1, int y1) // |dy | > |dx| // increment of x is optional.
{
    int p0, pk;
    int x, y, dx, dy, xinc;

    dx = x1 - x0;
    dy = y1 - y0;

    xinc = 1;
    x0 < x1 ? xinc = 1 : xinc = -1; // incrementing factor

    dx < 0 ? (dx = -dx) : (dx = dx);

    p0 = (2 * dx - dy); //  x-deciding factor.

    pk = p0;
    x = x0;
    y = y0; // start

    while (y <= y1)
    {

        if (pk < 0)
        {
            pk = pk + 2 * dx;
            x = x;
            y = y + 1;
        }
        else
        {
            pk = pk + 2 * dx - 2 * dy;
            x = x + xinc;
            y = y + 1;
        }

        putpixel(x, y, 15); // WHITE
    }
}

void draw_line_x(int x0, int y0, int x1, int y1) // |dy | < |dx| // increment of y is optional
{
    int p0, pk; // x0 < x1 (always) // y0 < y1 (don't  know)
    int x, y, dx, dy, yinc;

    dx = x1 - x0;
    dy = y1 - y0;

    yinc = 1;
    y0 < y1 ? yinc = 1 : yinc = -1; // This is the hidden part vvi.

    dy < 0 ? (dy = -dy) : (dy = dy); // y will get reduced

    p0 = (2 * dy - dx); // initialize

    pk = p0;
    x = x0;
    y = y0; // start

    while (x <= x1)
    {

        if (pk < 0)
        {
            pk = pk + 2 * dy;
            x = x + 1;
            y = y;
        }
        else
        {
            pk = pk + 2 * dy - 2 * dx;
            x = x + 1;
            y = y + yinc;
        }

        putpixel(x, y, 15); // WHITE
    }
}

void draw_line(int x0, int y0, int x1, int y1)
{
    if (abs(y1 - y0) < abs(x1 - x0))
    {
        if (x0 < x1)
        {
            draw_line_x(x0, y0, x1, y1);
        }
        else
        {
            draw_line_x(x1, y1, x0, y0);
        }
    }
    else
    {
        if (y0 > y1)
        {
            draw_line_y(x1, y1, x0, y0);
        }
        else
        {
            draw_line_y(x0, y0, x1, y1);
        }
    }
}

int main()
{

    int gd = DETECT, gm;
    int x1, x2, y1, y2, x3, y3;
    clrscr();

    printf("Enter the coordinates of first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of second point: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of third point: ");
    scanf("%d %d", &x3, &y3);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    draw_line(x1, y1, x2, y2);
    draw_line(x2, y2, x3, y3);
    draw_line(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;
}

/**
 * Palette Number   	Three Colors
 * 0	LIGHTGREEN  	LIGHTRED	YELLOW
 * 1	LIGHTCYAN	LIGHTMAGENTA  	WHITE
 * 2	GREEN	RED	BROWN
 * 3	CYAN	MAGENTA	LIGHTGRAY
 *
 * Name	Value
 * BLACK	0
 * BLUE	1
 * GREEN	2
 * CYAN	3
 * RED	4
 * MAGENTA	5
 * BROWN	6
 * LIGHTGRAY	7
 * DARKGRAY	8
 * LIGHTBLUE	9
 * LIGHTGREEN	10
 * LIGHTCYAN	11
 * LIGHTRED	12
 * LIGHTMAGENTA	13
 * YELLOW	14
 * WHITE	15
 */
