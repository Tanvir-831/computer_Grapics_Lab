#include <iostream>
#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int fishBodyX = 300;
    int fishBodyY = 300;
    int fishBodyRadiusX = 100;
    int fishBodyRadiusY = 40;
    ellipse(fishBodyX, fishBodyY, 0, 360, fishBodyRadiusX, fishBodyRadiusY);
    int fishTailX1 = fishBodyX - fishBodyRadiusX - 20;
    int fishTailY1 = fishBodyY;
    int fishTailX2 = fishTailX1 - 30;
    int fishTailY2 = fishBodyY - 20;
    int fishTailX3 = fishTailX1 - 30;
    int fishTailY3 = fishBodyY + 20;
    line(fishTailX1, fishTailY1, fishTailX2, fishTailY2);
    line(fishTailX2, fishTailY2, fishTailX3, fishTailY3);
    line(fishTailX3, fishTailY3, fishTailX1, fishTailY1);
    int fishEyeX = fishBodyX + fishBodyRadiusX / 2;
    int fishEyeY = fishBodyY - fishBodyRadiusY / 2;
    int fishEyeRadius = 10;
    circle(fishEyeX, fishEyeY, fishEyeRadius);
    int fishMouthX1 = fishBodyX + fishBodyRadiusX / 2;
    int fishMouthY1 = fishBodyY;
    int fishMouthX2 = fishBodyX + fishBodyRadiusX - 10;
    int fishMouthY2 = fishBodyY + 20;
    line(fishMouthX1, fishMouthY1, fishMouthX2, fishMouthY2);
    getch();
    closegraph();

    return 0;
}
