#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, num;
    string line;
    stringstream ss("");

    cin >> n;
    cin.ignore();
    while (n--)
    {
        vector<int> v;

        ss.clear();
        ss.str("");
        getline(cin, line);
        ss << line;
        while (ss >> num)
            v.push_back(num);

        if (v.size() == 0)
        {
            n++;
            continue;
        }

        int max = -1;
        for (int i = 0; i < v.size(); i++)
            if (v[i] >= max)
                max = v[i];

        if (max < 95)
        {
            int delta = 95 - max;
            if (delta > 0)
                for (int i = 0; i < v.size(); ++i)
                    v[i] += delta;
        }

        int count = 0;
        for (int i = 0; i < v.size(); ++i)
            if (55 <= v[i] && v[i] <= 59)
                count++;

        cout << count << endl;
    }

    return 0;
}
