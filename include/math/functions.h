#ifndef FOUNDATIONS_MATH_FUNCTIONS_H_
#define FOUNDATIONS_MATH_FUNCTIONS_H_


//Use f for returning float, d for returning double

float mathAreaRectFloat(float width, float height);
float mathAreaCircleRadiusFloat(float radius);
float mathAreaCircleDiameterFloat(float diameter);
float mathAreaTriangleFloat(float base, float height);

float mathWidthRectFloat(float area, float height);
float mathHeightRectFloat(float area, float width);
float mathRadiusCircleAreaFloat(float area);
float mathDiameterCircleAreaFloat(float area);
float mathBaseTriangleFloat(float area, float height);
float mathHeightTriangleFloat(float area, float base);


double mathAreaRectDouble(double width, double height);
double mathAreaCircleRadiusDouble(double radius);
double mathAreaCircleDiameterDouble(double diameter);
double mathAreaTriangleDouble(double base, double height);

double mathWidthRectDouble(double area, double height);
double mathHeightRectDouble(double area, double width);
double mathRadiusCircleAreaDouble(double area);
double mathDiameterCircleAreaDouble(double area);
double mathBaseTriangleDouble(double area, double height);
double mathHeightTriangleDouble(double area, double base);


#endif
