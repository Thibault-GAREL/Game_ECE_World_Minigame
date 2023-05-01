#include "Vector.h"


Vector2D Vector2D_Set_Value(float _x, float _y)
{
    Vector2D new = {_x, _y};
    return new;
}

Vector2D Vector2D_Get_Deviation(Vector2D _v1, Vector2D _v2)
{
    Vector2D deviation = {_v2.x - _v1.x, _v2.y - _v1.y};
    return deviation;
}

Vector2D Vector2D_Get_Unitary(Vector2D _v)
{
    float norm = Vector2D_Get_Norm(_v);
    Vector2D unitary = {_v.x / norm, _v.y / norm};
    return unitary;
}

float Vector2D_Get_Norm(Vector2D _v)
{
    return sqrtf(powf(_v.x, 2) + powf(_v.y, 2));
}

char Point_In_Rectangle(Vector2D point, Vector2D r1, Vector2D r2)
{
    return ((point.x < r1.x ) != (point.x < r2.x )) && ((point.y < r1.y ) != (point.y < r2.y ));
}

float Vector2D_Get_Angle(Vector2D _v)
{   
    return _v.x >= 0 ? atanf(_v.y / _v.x) : atanf(_v.y / _v.x) + PI;
}