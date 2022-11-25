#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void draw_line(int x0, int y0, int x1, int y1)
{
    int p0, pk;
    int x, y, dx, dy;

    dx = x1 - x0;
    dy = y1 - y0;
    p0 = (2 * dy - dx); // initialize

    pk = p0;
    x = x0;
    y = y0; // start

    while (x <= x1 && y <= y1)
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
            y = y + 1;
        }

	putpixel(x, y, 2); // GREEN
    }
}
int main()
{

    int gd = DETECT, gm;
    int x1, x2, y1, y2;
    clrscr();

    printf("Enter the coordinates of first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of second point: ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	draw_line(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}