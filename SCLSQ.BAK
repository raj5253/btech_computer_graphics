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

void scale(int x1, int y1, int x2, int y2, int x3,int y3, int x4, int y4, float sx, float sy)
{
    int  a1, b1, a2, b2, a3, b3, a4, b4;

    a1 = (int)(x1 * sx);
    b1 = (int)(y1 * sy);
    a2 = (int)(x2 * sx);
    b2 = (int)(y2 * sy);
    a3 = (int)(x3 * sx);
    b3 = (int)(y3 * sy);
    a4 = (int)(x4 * sx);
    b4 = (int)(y4 * sy);


    printf("Before scaling- WHITE\nAfter scaling -YELLOW\n Sx = %0.2f \n Sy = %0.2f", sx, sy);
    square(a1, b1, a2, b2, a3, b3, a4, b4);
}

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    float sx, sy;

    clrscr();

    printf("Enter the coordinates of first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of second point: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of third point: ");
    scanf("%d %d", &x3, &y3);
    printf("Enter the coordinates of fourth point: ");
    scanf("%d %d", &x4, &y4);
    printf("Enter scaling factor in x direction: ");
    scanf("%f", &sx);
    printf("Enter scaling factor in y direction: ");
    scanf("%f", &sy);

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");


    setcolor(15);
    square(x1, y1, x2, y2, x3, y3, x4, y4);

    getch();
    cleardevice();

    scale(x1, y1, x2, y2, x3, y3, x4, y4, sx, sy);

    setcolor(14);
    square(x1, y1, x2, y2, x3, y3, x4, y4);
    getch();
}