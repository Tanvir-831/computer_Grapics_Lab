#include <iostream>
#include <graphics.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    int maxx, midy;
    initgraph(&gd, &gm, "X:\\TC\\BGI");

    maxx = getmaxx();
    midy = getmaxy() / 2;

    int laneWidth = 10;  // Width of the lanes (dashed lines)
    int laneLength = 30;  // Length of each dash in the lanes
    int laneGap = 20;  // Gap between the dashes
    int laneSpeed = 5;  // Movement speed of the lanes

    while (!kbhit()) {  // Run the animation until a key is pressed
        for (int i = 0; i < maxx; i += laneLength + laneGap) {
            // Clear screen
            cleardevice();

            // Set background color for road
            setfillstyle(SOLID_FILL, DARKGRAY);
            bar(0, midy - 40, maxx, midy + 40);

            // Draw the dashed lines for the lanes
            setcolor(WHITE);
            bar(i, midy - laneWidth / 2, i + laneLength, midy + laneWidth / 2);

            delay(100);

            i -= laneSpeed;  // Move the lane dashes to create the animation
        }
    }

    closegraph();
    return 0;
}
