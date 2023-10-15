#include <cmath>
#include <iostream>

struct point {
    double x, y;
};

struct triangle
{
    point pts[3];
    double square()
    {
        double sq = pts[0].x * (pts[1].y - pts[2].y) +
                    pts[1].x * (pts[2].y - pts[0].y) +
                    pts[2].x * (pts[0].y - pts[1].y);
        return std::abs(sq) / 2.0;
    }
};

int main()
{
    triangle t{};
    t.pts[0] = point{5.0, 7.0};
    t.pts[1] = point{3.0, 3.0};
    t.pts[2] = point{1.0, 2.0};
    double square = t.square();
    std::cout << square << std::endl;
}