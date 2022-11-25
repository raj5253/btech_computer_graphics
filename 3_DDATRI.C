#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int abs( int x){
 return ( x >= 0 ? x: ( x*(-1)) );
}

void draw_line(int x0, int y0, int x1, int y1, int color)
{
    int dx, dy, length, i;
    float xinc, yinc, x, y ;  //while draing we select the intger_form of x and y

    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);

    if (abs(dx) > abs(dy))
    {
	length = abs(dx);
    }
    else
       {	length = abs(dy); }

    xinc = dx /(float) length;
    yinc = dy /(float) length;

    x = x0;
    y = y0;

    for (i = 0; i <= length; i++)
    {
	putpixel((int)x,(int)y, color);
	x = x + xinc;
	y = y + yinc;
    }
}

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    draw_line(x1, y1, x2, y2, 2);
    draw_line(x2, y2, x3, y3, 14);
    draw_line(x1, y1,x3,y3 , 5);
}

int main()
{

    int x1, y1, x2, y2, x3, y3;
    float x, y, dx, dy, length;
    int i;

    int gd = DETECT, gm;

    clrscr();

    printf("\nEnter x1: ");
    scanf("%d", &x1);
    printf("\nEnter y1: ");
    scanf("%d", &y1);
    printf("\nEnter x2: ");
    scanf("%d", &x2);
    printf("\nEnter y2: ");
    scanf("%d", &y2);
    printf("\nEnter x3: ");
    scanf("%d", &x3);
    printf("\nEnter y3: ");
    scanf("%d", &y3);


    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    draw_triangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();

    return 0;
}