#include <bits/stdc++.h>

using namespace std;

/*
0 0 4 1
-20 -50 64 5
*/

double sum_x, sum_y;

void calcCoords(int x, double a, double b, double d)
{
    if (x == 0 || d == 0 || a + d < 0 || b + d < 0)
        return;

    if (a - d >= 0 && b - d >= 0)
    {
        sum_x += a * (pow(4, x + 1) - 1) / 3 - a;
        sum_y += b * (pow(4, x + 1) - 1) / 3 - b;
        return;
    }

    if (a + d < 0 || b + d < 0)
        return;

    double dist = d / 2.0;
    double x1 = a - dist, y1 = b - dist;
    double x2 = a + dist, y2 = b - dist;
    double x3 = a - dist, y3 = b + dist;
    double x4 = a + dist, y4 = b + dist;

    if (x1 > 0 && y1 > 0)
    {
        sum_x += x1;
        sum_y += y1;
    }
    if (x2 > 0 && y2 > 0)
    {
        sum_x += x2;
        sum_y += y2;
    }
    if (x3 > 0 && y3 > 0) 
    { 
        sum_x += x3; 
        sum_y += y3; 
    } 
    if (x4 > 0 && y4 > 0)
    {
        sum_x += x4;
        sum_y += y4;
    }

    if (x1 + dist > 0 || y1 + dist > 0)
        calcCoords(x - 1, x1, y1, dist);

    if (x2 + dist > 0 || y2 + dist > 0)
        calcCoords(x - 1, x2, y2, dist);

    if (x3 + dist > 0 || y3 + dist > 0)
        calcCoords(x - 1, x3, y3, dist);

    if (x4 + dist > 0 || y4 + dist > 0)
        calcCoords(x - 1, x4, y4, dist);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a, b, d;
    int x;

    while (cin >> a >> b >> d >> x)
    {
        x++;

        if (a > 0 && b > 0)
        {
            sum_x = a;
            sum_y = b;
        }
        else
            sum_x = sum_y = 0;

        calcCoords(x, a, b, d);

        cout << sum_x << " " << sum_y << "\n";
    }

    return 0;
}
