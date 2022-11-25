#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int x_min = 50;
int y_min = 50;
int x_max = 150;
int y_max = 150;

void liang_bersky(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    float t, t1 = 0, t2 = 1;
    int i = 0;
    // int x1n = x1 , x2n=x1, y1n = y1, y2n = y1;
    int x1n, y1n, x2n, y2n;

    int p[4],
        q[4]; // initialize
    p[0] = -dx;
    q[0] = x1 - x_min;
    p[1] = dx;
    q[1] = x_max - x1;
    p[2] = -dy;
    q[2] = y1 - y_min;
    p[3] = dy;
    q[3] = y_max - y1;

    for (i = 0; i < 4; i++)
    {
        t = (float)q[i] / p[i];
        if (p[i] < 0)
        {
            if (t > t1) // slect the max
                t1 = t;
        }
        else
        {
            if (t < t2) // select the min
            {
                t2 = t;
            }
        }
    }
    printf("%f , %f\n", t1, t2);

    if (t1 < t2)
    {
        x1n = x1 + (int)(t1 * dx);
        y1n = y1 + (int)(t1 * dy);
        x2n = x1 + (int)(t2 * dx);
        y2n = y1 + (int)(t2 * dy);
    }
    printf("Line clipped from:(%d,%d) to (%d, %d)\n", x1n, y1n, x2n, y2n);
    rectangle(x_min, y_min, x_max, y_max);
    setcolor(4);
    line(x1n, y1n, x2n, y2n);
}
int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    clrscr();
    printf("Enter the end points: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(x_min, y_min, x_max, y_max);
    line(x1, y1, x2, y2);
    getch();

    cleardevice();
    liang_bersky(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}