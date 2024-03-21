#include "../../include/math/functions.h"

#include <math.h>

// Function to calculate the area of a rectangle using float precision
float mathAreaRectFloat(float width, float height) {
    return width * height;
}

// Function to calculate the area of a circle using the radius with float precision
float mathAreaCircleRadiusFloat(float radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a circle using the diameter with float precision
float mathAreaCircleDiameterFloat(float diameter) {
    float radius = diameter / 2.0f;
    return mathAreaCircleRadiusFloat(radius);
}

// Function to calculate the area of a triangle using float precision
float mathAreaTriangleFloat(float base, float height) {
    return 0.5f * base * height;
}

// Function to calculate the width of a rectangle given its area and height using float precision
float mathWidthRectFloat(float area, float height) {
    return area / height;
}

// Function to calculate the height of a rectangle given its area and width using float precision
float mathHeightRectFloat(float area, float width) {
    return area / width;
}

// Function to calculate the radius of a circle given its area using float precision
float mathRadiusCircleAreaFloat(float area) {
    return sqrtf(area / M_PI);
}

// Function to calculate the diameter of a circle given its area using float precision
float mathDiameterCircleAreaFloat(float area) {
    float radius = mathRadiusCircleAreaFloat(area);
    return radius * 2.0f;
}

// Function to calculate the base of a triangle given its area and height using float precision
float mathBaseTriangleFloat(float area, float height) {
    return 2.0f * area / height;
}

// Function to calculate the height of a triangle given its area and base using float precision
float mathHeightTriangleFloat(float area, float base) {
    return 2.0f * area / base;
}

// Function to calculate the area of a rectangle using double precision
double mathAreaRectDouble(double width, double height) {
    return width * height;
}

// Function to calculate the area of a circle using the radius with double precision
double mathAreaCircleRadiusDouble(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a circle using the diameter with double precision
double mathAreaCircleDiameterDouble(double diameter) {
    double radius = diameter / 2.0;
    return mathAreaCircleRadiusDouble(radius);
}

// Function to calculate the area of a triangle using double precision
double mathAreaTriangleDouble(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the width of a rectangle given its area and height using double precision
double mathWidthRectDouble(double area, double height) {
    return area / height;
}

// Function to calculate the height of a rectangle given its area and width using double precision
double mathHeightRectDouble(double area, double width) {
    return area / width;
}

// Function to calculate the radius of a circle given its area using double precision
double mathRadiusCircleAreaDouble(double area) {
    return sqrt(area / M_PI);
}

// Function to calculate the diameter of a circle given its area using double precision
double mathDiameterCircleAreaDouble(double area) {
    double radius = mathRadiusCircleAreaDouble(area);
    return radius * 2.0;
}

// Function to calculate the base of a triangle given its area and height using double precision
double mathBaseTriangleDouble(double area, double height) {
    return 2.0 * area / height;
}

// Function to calculate the height of a triangle given its area and base using double precision
double mathHeightTriangleDouble(double area, double base) {
    return 2.0 * area / base;
}
