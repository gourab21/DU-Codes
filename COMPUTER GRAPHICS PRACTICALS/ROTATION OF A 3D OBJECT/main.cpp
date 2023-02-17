#include <graphics.h>
#include <math.h>

#define PI 3.14159265

void applyRotation(float &x, float &y, float &z, float theta) {
    // convert theta to radians
    theta = theta * PI / 180.0;
    // apply rotation matrix about y-axis
    float x_new = x * cos(theta) + z * sin(theta);
    float y_new = y;
    float z_new = -x * sin(theta) + z * cos(theta);
    // update coordinates
    x = x_new;
    y = y_new;
    z = z_new;
}

int main() {
    // create a new graphics window
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");
    // set the origin to the center of the window
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    // define the 8 vertices of the parallelpiped
    float x[8] = { -50, 50, 50, -50, -50, 50, 50, -50 };
    float y[8] = { -50, -50, 50, 50, -50, -50, 50, 50 };
    float z[8] = { -50, -50, -50, -50, 50, 50, 50, 50 };
    // apply rotation about y-axis
    for (int i = 0; i < 8; i++) {
        applyRotation(x[i], y[i], z[i], 30.0);
    }
    // project onto z=0 plane
    for (int i = 0; i < 8; i++) {
        x[i] = x[i] * (z[i] + 100) / 100.0;
        y[i] = y[i] * (z[i] + 100) / 100.0;
    }
    // draw the projected parallelpiped
    for (int i = 0; i < 4; i++) {
        line(centerX + x[i], centerY - y[i], centerX + x[i + 4], centerY - y[i + 4]);
        line(centerX + x[i], centerY - y[i], centerX + x[(i + 1) % 4], centerY - y[(i + 1) % 4]);
        line(centerX + x[i + 4], centerY - y[i + 4], centerX + x[(i + 1) % 4 + 4], centerY - y[(i + 1) % 4 + 4]);
    }
    // wait for a key press and close the window
    getch();
    closegraph();
    return 0;
}
