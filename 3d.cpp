#include <iostream>
#include <graphics.h>
#include <cmath>
#include <conio.h>

#define PI 3.1415

// Create a translation matrix T(tx, ty, tz)
void translation(float tx, float ty, float tz, float t[4][4]) {
    t[0][0] = 1;
    t[0][1] = 0;
    t[0][2] = 0;
    t[0][3] = tx;
    t[1][0] = 0;
    t[1][1] = 1;
    t[1][2] = 0;
    t[1][3] = ty;
    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = 1;
    t[2][3] = tz;
    t[3][0] = 0;
    t[3][1] = 0;
    t[3][2] = 0;
    t[3][3] = 1;
}

// Create a scaling matrix S(sx, sy, sz)
void scaling(float sx, float sy, float sz, float s[4][4]) {
    s[0][0] = sx;
    s[0][1] = 0;
    s[0][2] = 0;
    s[0][3] = 0;
    s[1][0] = 0;
    s[1][1] = sy;
    s[1][2] = 0;
    s[1][3] = 0;
    s[2][0] = 0;
    s[2][1] = 0;
    s[2][2] = sz;
    s[2][3] = 0;
    s[3][0] = 0;
    s[3][1] = 0;
    s[3][2] = 0;
    s[3][3] = 1;
}

// Create a rotation matrix R(theta) around X-axis
void rotationX(float angle, float r[4][4]) {
    float rad = angle * PI / 180.0;
    r[0][0] = 1;
    r[0][1] = 0;
    r[0][2] = 0;
    r[0][3] = 0;
    r[1][0] = 0;
    r[1][1] = cos(rad);
    r[1][2] = -sin(rad);
    r[1][3] = 0;
    r[2][0] = 0;
    r[2][1] = sin(rad);
    r[2][2] = cos(rad);
    r[2][3] = 0;
    r[3][0] = 0;
    r[3][1] = 0;
    r[3][2] = 0;
    r[3][3] = 1;
}

// Create a rotation matrix R(theta) around Y-axis
void rotationY(float angle, float r[4][4]) {
    float rad = angle * PI / 180.0;
    r[0][0] = cos(rad);
    r[0][1] = 0;
    r[0][2] = sin(rad);
    r[0][3] = 0;
    r[1][0] = 0;
    r[1][1] = 1;
    r[1][2] = 0;
    r[1][3] = 0;
    r[2][0] = -sin(rad);
    r[2][1] = 0;
    r[2][2] = cos(rad);
    r[2][3] = 0;
    r[3][0] = 0;
    r[3][1] = 0;
    r[3][2] = 0;
    r[3][3] = 1;
}

// Create a rotation matrix R(theta) around Z-axis
void rotationZ(float angle, float r[4][4]) {
    float rad = angle * PI / 180.0;
    r[0][0] = cos(rad);
    r[0][1] = -sin(rad);
    r[0][2] = 0;
    r[0][3] = 0;
    r[1][0] = sin(rad);
    r[1][1] = cos(rad);
    r[1][2] = 0;
    r[1][3] = 0;
    r[2][0] = 0;
    r[2][1] = 0;
    r[2][2] = 1;
    r[2][3] = 0;
    r[3][0] = 0;
    r[3][1] = 0;
    r[3][2] = 0;
    r[3][3] = 1;
}

// Create a shearing matrix SH(shx, shy, shz)
void shearing(float shx, float shy, float shz, float sh[4][4]) {
    sh[0][0] = 1;
    sh[0][1] = shx;
    sh[0][2] = shy;
    sh[0][3] = 0;
    sh[1][0] = shx;
    sh[1][1] = 1;
    sh[1][2] = shz;
    sh[1][3] = 0;
    sh[2][0] = shy;
    sh[2][1] = shz;
    sh[2][2] = 1;
    sh[2][3] = 0;
    sh[3][0] = 0;
    sh[3][1] = 0;
    sh[3][2] = 0;
    sh[3][3] = 1;
}

// Create a reflection matrix for the XY plane
void reflectionXY(float ref[4][4]) {
    ref[0][0] = 1;
    ref[0][1] = 0;
    ref[0][2] = 0;
    ref[0][3] = 0;
    ref[1][0] = 0;
    ref[1][1] = 1;
    ref[1][2] = 0;
    ref[1][3] = 0;
    ref[2][0] = 0;
    ref[2][1] = 0;
    ref[2][2] = -1;
    ref[2][3] = 0;
    ref[3][0] = 0;
    ref[3][1] = 0;
    ref[3][2] = 0;
    ref[3][3] = 1;
}

// Create a reflection matrix for the YZ plane
void reflectionYZ(float ref[4][4]) {
    ref[0][0] = -1;
    ref[0][1] = 0;
    ref[0][2] = 0;
    ref[0][3] = 0;
    ref[1][0] = 0;
    ref[1][1] = 1;
    ref[1][2] = 0;
    ref[1][3] = 0;
    ref[2][0] = 0;
    ref[2][1] = 0;
    ref[2][2] = 1;
    ref[2][3] = 0;
    ref[3][0] = 0;
    ref[3][1] = 0;
    ref[3][2] = 0;
    ref[3][3] = 1;
}

// Create a reflection matrix for the XZ plane
void reflectionXZ(float ref[4][4]) {
    ref[0][0] = 1;
    ref[0][1] = 0;
    ref[0][2] = 0;
    ref[0][3] = 0;
    ref[1][0] = 0;
    ref[1][1] = -1;
    ref[1][2] = 0;
    ref[1][3] = 0;
    ref[2][0] = 0;
    ref[2][1] = 0;
    ref[2][2] = 1;
    ref[2][3] = 0;
    ref[3][0] = 0;
    ref[3][1] = 0;
    ref[3][2] = 0;
    ref[3][3] = 1;
}

// Matrix multiplication for 3D transformations
void transform(float p[4], float m[4][4], float result[4]) {
    for (int i = 0; i < 4; i++) {
        result[i] = 0;
        for (int j = 0; j < 4; j++) {
            result[i] += p[j] * m[i][j];
        }
    }
}

// Draw a 3D triangle
void drawTriangle(float p1[4], float p2[4], float p3[4], int color) {
    setcolor(color);
    line(p1[0], p1[1], p2[0], p2[1]);
    line(p2[0], p2[1], p3[0], p3[1]);
    line(p3[0], p3[1], p1[0], p1[1]);
}

int main() {
    int repeat = 1;
    int gd = DETECT, gm = DETECT;

    float x1, y1, z1, x2, y2, z2, x3, y3, z3;
    std::cout << "Enter coordinates of the triangle:\n";
    std::cout << "(x1 y1 z1): ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "(x2 y2 z2): ";
    std::cin >> x2 >> y2 >> z2;
    std::cout << "(x3 y3 z3): ";
    std::cin >> x3 >> y3 >> z3;

    while (repeat == 1) {
        initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

        float p1[4] = {x1, y1, z1, 1};
        float p2[4] = {x2, y2, z2, 1};
        float p3[4] = {x3, y3, z3, 1};

        // Original triangle (before transformation)
        drawTriangle(p1, p2, p3, WHITE);

        int choice;
        std::cout << "Choose the transformation:\n";
        std::cout << "1. Translation\n2. Scaling\n3. Rotation around X-axis\n4. Rotation around Y-axis\n5. Rotation around Z-axis\n6. Shearing\n7. Reflection on XY plane\n8. Reflection on YZ plane\n9. Reflection on XZ plane\n";
        std::cin >> choice;

        float matrix[4][4];
        if (choice == 1) {
            float tx, ty, tz;
            std::cout << "Enter translation factors (tx ty tz): ";
            std::cin >> tx >> ty >> tz;
            translation(tx, ty, tz, matrix);
        } else if (choice == 2) {
            float sx, sy, sz;
            std::cout << "Enter scaling factors (sx sy sz): ";
            std::cin >> sx >> sy >> sz;
            scaling(sx, sy, sz, matrix);
        } else if (choice == 3) {
            float angle;
            std::cout << "Enter rotation angle: ";
            std::cin >> angle;
            rotationX(angle, matrix);
        } else if (choice == 4) {
            float angle;
            std::cout << "Enter rotation angle: ";
            std::cin >> angle;
            rotationY(angle, matrix);
        } else if (choice == 5) {
            float angle;
            std::cout << "Enter rotation angle: ";
            std::cin >> angle;
            rotationZ(angle, matrix);
        } else if (choice == 6) {
            float shx, shy, shz;
            std::cout << "Enter shearing factors (shx shy shz): ";
            std::cin >> shx >> shy >> shz;
            shearing(shx, shy, shz, matrix);
        } else if (choice == 7) {
            reflectionXY(matrix);
        } else if (choice == 8) {
            reflectionYZ(matrix);
        } else if (choice == 9) {
            reflectionXZ(matrix);
        } else {
            std::cout << "Invalid choice!" << std::endl;
            continue;
        }

        float result1[4], result2[4], result3[4];
        transform(p1, matrix, result1);
        transform(p2, matrix, result2);
        transform(p3, matrix, result3);

        drawTriangle(result1, result2, result3, GREEN);

        std::cout << "Do you want to perform another transformation? (1 for Yes, 0 for No): ";
        std::cin >> repeat;

        closegraph();
    }

    return 0;
}
