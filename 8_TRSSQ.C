#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <process.h>
#include <math.h>

void square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
}

void traslate(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float tx, float ty)
{
    int x, y, a1, b1, a2, b2, a3, b3, a4, b4;

    a1 = x1 + (int)tx;
    b1 = y1 + (int)ty;
    a2 = x2 + (int)tx;
    b2 = y2 + (int)ty;
    a3 = x3 + (int)tx;
    b3 = y3 + (int)ty;
    a4 = x4 + (int)tx;
    b4 = y4 + (int)ty;

    printf("Before rotation- Yellow\nAfter rotation -White\n Tx = %0.2f \n Ty = %0.2f", tx, ty);
    square(a1, b1, a2, b2, a3, b3, a4, b4);
}

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    float tx, ty;

    clrscr();

    printf("Enter the coordinates of first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of second point: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of third point: ");
    scanf("%d %d", &x3, &y3);
    printf("Enter the coordinates of fourth point: ");
    scanf("%d %d", &x4, &y4);
    printf("Enter translation factor in x direction: ");
    scanf("%f", &tx);
    printf("Enter translation factor in y direction: ");
    scanf("%f", &ty);

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    square(x1, y1, x2, y2, x3, y3, x4, y4);

    getch();
    cleardevice();
    setcolor(9);
    traslate(x1, y1, x2, y2, x3, y3, x4, y4, tx, ty);

    setcolor(14); // YELLOW
    square(x1, y1, x2, y2, x3, y3, x4, y4);
    getch();
}