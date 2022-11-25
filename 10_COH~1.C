#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int x_min = 50;
int x_max = 150;
int y_min = 50;
int y_max = 150;

const int inside = 0; // 0000
const int top = 8;    // 1000
const int bottom = 4; // 0100
const int right = 2;  // 0010
const int left = 1;   // 0001

void draw_window_before(int x1, int y1, int x2, int y2)
{
    // line(x_min, y_min, x_max, y_min);
    // line(x_max, y_min, x_max, y_max);
    // line(x_max, y_max, x_min, y_max);
    // line(x_min, y_max, x_min, y_min);
    cleardevice();
    rectangle(x_min, y_min, x_max, y_max);
    line(x1, y1, x2, y2);
}
int get_tbrl_code(int x, int y)
{
    int code = inside;
    if (x < x_min)
        code |= left;
    if (x > x_max)
        code |= right;
    if (y < y_min)
        code |= bottom;
    if (y > y_max)
        code |= top;

    return code;
}

void cohen_sutherland(int x1, int y1, int x2, int y2)
{
    float x, y, slope;
    int accept = 0;
    int code1 = get_tbrl_code(x1, y1);
    int code2 = get_tbrl_code(x2, y2);
    int code_out;

    slope = (float)(y2 - y1) / (x2 - x1);
    while (1)
    {
        if ((code1 == 0) && (code2 == 0)) // both the endpoints are inside.
        {
            accept = 1;
            break;
        }
        else if (code1 & code2) // line is completely outside.//=>both have set_bit at atleast one position.
        {
            // accept = false;//useless line
            break;
        }

        else // and == 0000  //clipping
        {
            if (code1 != 0) // default process pt1 first
                code_out = code1;
            else
                code_out = code2;

            if (code_out & top)
            {
                y = y_max;
                // x = x1 + (float)(x2 - x1) * (y_max - y1) / (y2 - y1);
                x = x1 + (float)(y_max - y1) / slope;
            }
            else if (code_out & bottom)
            {
                y = y_min;
                // x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                x = x1 + (float)(y_min - y1) / slope;
            }
            else if (code_out & right)
            {
                x = x_max;
                // y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                y = y1 + (x_max - x1) * (float)slope;
            }
            else if (code_out * left)
            {
                x = x_min;
                y = y1 + (x_min - x1) * (float)slope;
            }

            if (code_out == code1)
            {
                x1 = (int)x;
                y1 = (int)y;
                code1 = get_tbrl_code(x1, y1); // updated code
            }
            else
            {
                x2 = (int)x;
                y2 = (int)y;
                code2 = get_tbrl_code(x2, y2);
            }
        }
    }

    clearviewport();
    delay(1000);
    rectangle(x_min, y_min, x_max, y_max);

    if (accept)
    {
        printf("line clipped from:(%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
        setcolor(2);
        line(x1, y1, x2, y2);
    }
}
int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    clrscr();

    printf("Enter the endpoints : ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // line(x1, y1, x2, y2);
    getch();
    cleardevice();

    draw_window_before(x1, y1, x2, y2);
    getch();
    cohen_sutherland(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
