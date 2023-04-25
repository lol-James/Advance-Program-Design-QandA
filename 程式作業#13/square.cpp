#include <bits/stdc++.h>

using namespace std;

double x_sum = 0, y_sum = 0;

inline void find_vertices(double a, double b, double d, double square[][2]);
inline void draw(double a, double b, double d, double x);

int main()
{
    double a, b, d, x;
    while (cin >> a >> b >> d >> x)
    {
        x_sum = y_sum = 0;

        if (a > 0 && b > 0)
        {
            x_sum += a;
            y_sum += b;
        }

        draw(a, b, d, x);

        cout << x_sum << " " << y_sum << endl;
    }

    system("pause");
    return 0;
}

inline void find_vertices(double a, double b, double d, double square[][2])
{
    square[0][0] = a + d / 2;
    square[0][1] = b + d / 2;
    square[1][0] = a - d / 2;
    square[1][1] = b + d / 2;
    square[2][0] = a - d / 2;
    square[2][1] = b - d / 2;
    square[3][0] = a + d / 2;
    square[3][1] = b - d / 2;
}

inline void draw(double a, double b, double d, double x)
{
    double square[4][2];

    find_vertices(a, b, d, square);

    for (int i = 0; i < 4; i++)
    {
        if (square[i][0] > 0 && square[i][1] > 0)
        {
            x_sum += square[i][0];
            y_sum += square[i][1];
        }
    }

    if (x)
    {
        if (a + d < 0 && b + d < 0)
            return;
        else
            draw(a + d / 2, b + d / 2, d / 2, x - 1);

        if (a < 0 && b + d < 0)
            return;
        else
            draw(a - d / 2, b + d / 2, d / 2, x - 1);

        if (a < 0 && b < 0)
            return;
        else
            draw(a - d / 2, b - d / 2, d / 2, x - 1);

        if (a + d < 0 && b < 0)
            return;
        else
            draw(a + d / 2, b - d / 2, d / 2, x - 1);
    }
}
