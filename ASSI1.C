#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265

void drawCircle(int a, int b, int r, int col)
{
    int x, y, pk;
    x = 0;
    y = r;
    pk = 1 - r;
    while (y >= x)
    {
        putpixel(a + x, b + y, col);
        putpixel(a + y, b + x, col);
        putpixel(a - y, b + x, col);
        putpixel(a - x, b + y, col);
        putpixel(a - x, b - y, col);
        putpixel(a - y, b - x, col);
        putpixel(a + y, b - x, col);
        putpixel(a + x, b - y, col);
        if (pk < 0)
        {
            pk += (2 * x) + 1;
        }
        else
        {
            y -= 1;
            pk += (2 * x) - (2 * y) + 1;
        }
        x += 1;
    }
}

void rotatecircle(int a, int b, int r1, int r2, int col1, int col2)
{
    int revolve = 5;
    double angle, x, y;
    while (revolve--)
    {
        angle = 0;
        while (angle <= 2 * M_PI)
        {
            x = a + (r1 + r2) * cos(angle);
            y = b + (r1 + r2) * sin(angle);

            delay(20);
            cleardevice();
            drawCircle(a, b, r1, col1);
            drawCircle((int)x, (int)y, r2, col2);
            angle += 0.005;
        }
    }
}

void main()
{
    int gd = DETECT, gm;
    int x, y, r1, r2;

    printf("Enter the center point of the circle : ");
    scanf("%d %d", &x, &y);

    printf("Enter the radius of the main circle : ");
    scanf("%d", &r1);

    printf("Enter the radius of the out circle : ");
    scanf("%d", &r2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    rotatecircle(x, y, r1, r2, GREEN, CYAN);

    closegraph();
}