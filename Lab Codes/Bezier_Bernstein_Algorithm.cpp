#include <iostream>
#include <cmath>
#include <graphics.h>

// Define a structure to represent a 2D point
struct Point {
    int x, y;
};

// Function to calculate the Bézier curve point using polynomial approximation
Point calculateBezierPoint(Point p[], double t) {
    double u = 1.0 - t;
    double tt = t * t;
    double uu = u * u;
    double uuu = uu * u;
    double ttt = tt * t;

    Point pFinal;
    pFinal.x = static_cast<int>(p[0].x * uuu + 3 * p[1].x * t * uu + 3 * p[2].x * tt * u + p[3].x * ttt);
    pFinal.y = static_cast<int>(p[0].y * uuu + 3 * p[1].y * t * uu + 3 * p[2].y * tt * u + p[3].y * ttt);

    return pFinal;
}

// Main function
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Define Bézier control points
    Point controlPoints[4] = {{100, 100}, {150, 50}, {200, 200}, {250, 100}};

    // Draw the Bézier curve using polynomial approximation
    for (double t = 0.0; t <= 1.0; t += 0.01) {
        Point p = calculateBezierPoint(controlPoints, t);
        putpixel(p.x,p.y,RED);
    }

    delay(5000000); // Pause for a few seconds before closing the graphics window
    closegraph();
    return 0;
}


