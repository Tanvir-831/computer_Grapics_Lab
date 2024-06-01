#include <graphics.h>


void drawCircle(int xc, int yc, int x, int y) {

    putpixel(xc+x, yc+y, WHITE);

    putpixel(xc-x, yc+y, WHITE);

    putpixel(xc+x, yc-y, WHITE);

    putpixel(xc-x, yc-y, WHITE);

    putpixel(xc+y, yc+x, WHITE);

    putpixel(xc-y, yc+x, WHITE);

    putpixel(xc+y, yc-x, WHITE);

    putpixel(xc-y, yc-x, WHITE);

}


void drawNationalFlag() {

    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");


    setcolor(GREEN);

    rectangle(50, 50, 600, 400);

    floodfill(55, 55, GREEN);

    setcolor(RED);

    circle(325, 225, 75);

    floodfill(325, 225, RED);

    setcolor(RED);

    int xc = 325, yc = 225;

    int r = 30;

    int x = 0, y = r;

    int d = 3 - 2 * r;

    while (y >= x) {

        x++;

        if (d > 0) {

            y--;

            d = d + 4 * (x - y) + 10;

        } else

            d = d + 4 * x + 6;

        drawCircle(xc, yc, x, y);

    }

    delay(50000);

    closegraph();

}


int main() {

    drawNationalFlag();

    return 0;

}
