#include <bits/stdc++.h>

using namespace std;

struct Rectangle
{
    int width;
    int height;
};

bool compare(Rectangle r1, Rectangle r2) // 以面積做排序
{
    return (r1.width * r1.height) < (r2.width * r2.height);
}

int main()
{
    int num;
    while (cin >> num)
    {
        while (num--)
        {
            int n;

            cin >> n;
            Rectangle rect[n];

            int a[n];
            for (int i = 0; i < n; i++)
                a[i] = 0;

            for (int i = 0; i < n; i++)
            {
                int w, h;

                cin >> w >> h;
                rect[i].width = w < h ? w : h;  // width 取短邊
                rect[i].height = w > h ? w : h; // height取長邊
            }
            sort(rect, rect + n, compare);

            int count = 0;

            for (int i = 0; i < n; i++)
            {
                a[i] = 1; // 以第i塊積木為基底，至少可堆一塊
                for (int j = 0; j < i; j++)
                {
                    if (rect[j].width <= rect[i].width && rect[j].height <= rect[i].height)
                        a[i] = a[i] > a[j] + 1 ? a[i] : a[j] + 1;
                    count = count > a[i] ? count : a[i];
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}
