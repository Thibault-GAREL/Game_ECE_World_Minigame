#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <math.h>

#define PI 3.14159265


typedef struct _VECTOR2D_INT
{
    int x;
    int y;
}VECTOR2D_INT, *PVECTOR2D_INT;

typedef struct VECTOR2D
{
    float x;
    float y;
}Vector2D, *pVector2D;


Vector2D Vector2D_Set_Value(float _x, float _y);
Vector2D Vector2D_Get_Deviation(Vector2D _v1, Vector2D _v2);
Vector2D Vector2D_Get_Unitary(Vector2D _v);
float Vector2D_Get_Norm(Vector2D _v);
char Point_In_Rectangle(Vector2D point, Vector2D r1, Vector2D r2);

float Vector2D_Get_Angle(Vector2D _v);

#endif