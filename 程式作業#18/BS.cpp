#include <bits/stdc++.h>
using namespace std;

// 用來檢查length是否足夠包含所有服務點
bool isEnough(int length, vector<int> &P, int n, int k);   

int main()
{
    int k, n;   // k：基地台數量；n：服務點數量
    while (cin >> n >> k)
    {   
        vector<int> P;
        int num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            P.push_back(num);
        }
        sort(P.begin(), P.end());
        int lowerLen = 1, upperLen = 1000000000;
        while (lowerLen < upperLen)
        {
            if (upperLen - lowerLen == 1)
            {
                if (!isEnough(lowerLen, P, n, k))
                {
                    lowerLen = upperLen;
                }
                break;
            }
            else
            {
                int middle = (lowerLen + upperLen) / 2;
                if (isEnough(middle, P, n, k))
                    upperLen = middle;
                else
                    lowerLen = middle + 1;
            }
        }
        cout << lowerLen << endl;
    }

    system("pause");
    return 0;
}

bool isEnough(int length, vector<int> &P, int n, int k)
{
    int count = 1, rightPos = P[0] + length;
    for (int i = 1; i < n; i++)
    {
        if (P[i] > rightPos)
        {
            count++;
            rightPos = P[i] + length;
        }
    }

    return (count <= k);
}