#include <iostream>
using namespace std;

struct Point
{
    int x, y;
};
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool isRightTriangle(Point A, Point B, Point C)
{
    int AB2 = distSq(A, B);
    int BC2 = distSq(B, C);
    int CA2 = distSq(C, A);

    if (AB2 + BC2 == CA2 || AB2 + CA2 == BC2 || BC2 + CA2 == AB2)
    {
        return true;
    }
    return false;
}

int main()
{
    Point A, B, C;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    if (isRightTriangle(A, B, C))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
