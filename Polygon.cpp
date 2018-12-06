#include "Polygon.h"
#include <cmath>
#include "Point.h"
#include <string>

std::string Polygon::getType()
{
    std::string myShape = "Polygon";
    return myShape;
}
double Polygon::getArea()
{
    int vertices = m_c;
    double area = 0;
    int j = (vertices - 1);
    for (int i = 0; i < vertices; i++)
    {
        area += (m_a[j].getX() + m_a[i].getX()) * (m_a[j].getY() - m_a[i].getY());
        j = i;
    }
    if (area == 0 || !isConvex())
        area = -1;
    else
        return area = abs(area / 2);
    return area;
}

double Polygon::getCircumference()
{
    double PolyCircum = 0;
    int vertices = m_c;
    int j = vertices - 1;
    for (int i = 0; i < vertices; i++)
    {
        PolyCircum += sqrt(pow(m_a[i].getX() - m_a[j].getX(), 2) + pow(m_a[i].getY() - m_a[j].getY(), 2));
        j = i;
    }
    return PolyCircum;
}

Point Polygon::getPosition() //I know this is off by a few, working on the correct one below
{
    double sumX = 0;
    double sumY = 0;
    int vertices = m_c;
    for (int i = 0; i < vertices; i++)
    {
        sumX += (m_a[i].getX()) / vertices;
        sumY += (m_a[i].getY()) / vertices;
    }
    Point centerPosition(sumX, sumY);
    return centerPosition;
}

bool Polygon::isConvex()
{
    int size = (m_c - 2);
    double *crossproduct = new double[size];
    double dix1, diy1, dix2, diy2;

    for (int i = 0; i < size; i++)
    {
        dix1 = m_a[i + 1].getX() - m_a[i].getX();
        diy1 = m_a[i + 1].getY() - m_a[i].getY();
        dix2 = m_a[i + 2].getX() - m_a[i + 1].getX();
        diy2 = m_a[i + 2].getY() - m_a[i + 1].getY();
        crossproduct[i] = (dix1 * diy2 - diy1 * dix2);
    }

    bool sumPos = false;
    bool sumNeg = false;

    for (int i = 0; i < size; i++)
    {
        if (crossproduct[i] > 0)
            sumPos = true;
        else
            sumNeg = true;
    }
    delete[] crossproduct;
    crossproduct = nullptr;

    if (sumPos && sumNeg)
        return false;
    else
        return true;
}

/*Polygon Polygon::operator+(const Polygon &rhs)
{
    Polygon ExtendedPolygon;
    m_a + rhs.getX() + rhs.getY();
    m_c + rhs.m_c+1;
    return ExtendedPolygon;
}*/