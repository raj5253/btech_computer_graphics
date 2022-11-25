#include <stdio.h>
#include <conio.h>
#include <graphics.h>     /* Author : SATYAM RAJ, CSE_2020105253 */

void draw_circle(int a, int b, int r, int col)
{
    int x = 0, y = r;
    int p0 = 1 - r; // for float

    while (y >= x) // from 90 to 45degree
    {
        putpixel(a + x, b - y, col);
        putpixel(a + x, b + y, col);
        putpixel(a - x, b - y, col);
        putpixel(a - x, b + y, col);

        putpixel(a + y, b + x, col);
        putpixel(a + y, b - x, col);
        putpixel(a - y, b + x, col);
        putpixel(a - y, b - x, col);

        if (p0 < 0) // mid point is inside,we select above point
        {
            x++;
            y = y;
            p0 += 2 * x + 3;
        }
        else
        {
            x++; // mid point is outside,we select below point
            y--;
            p0 += 2 * (x - y) + 5;
        }
    }
}
void main()
{
    int gd = DETECT, gm;
    int x, y, r;
    clrscr();
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the center for circle: ");
    scanf("%d %d", &x, &y);

    printf("Enter the radius for circle: ");
    scanf("%d", &r);

    draw_circle(x, y, r, 4); // 4 for RED
    getch();
    closegraph();
    // cleardevice();
}