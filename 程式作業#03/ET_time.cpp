#include <bits/stdc++.h>

using namespace std;

int main()
{
    char planet;
    int hh_0 = 0, mm_0 = 0, ss_0 = 0; // input time
    int hh_1 = 0, mm_1 = 0, ss_1 = 0; // output time
    int time_to_second = 0;
    int num;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        hh_0 = mm_0 = ss_0 = hh_1 = mm_1 = ss_1 = time_to_second = 0;
        cin >> planet;
        if (planet == 'Z')
        {
            cin >> hh_0 >> mm_0 >> ss_0;
            time_to_second = hh_0 * 1440 + mm_0 * 30 + ss_0;

            hh_1 = time_to_second / 3600;
            time_to_second %= 3600;

            mm_1 = time_to_second / 60;
            time_to_second %= 60;

            ss_1 = time_to_second;

            cout << "E"
                 << " " << hh_1 << " " << mm_1 << " " << ss_1 << endl;
        }
        else
        {
            cin >> hh_0 >> mm_0 >> ss_0;
            time_to_second = hh_0 * 3600 + mm_0 * 60 + ss_0;

            hh_1 = time_to_second / 1440;
            time_to_second %= 1440;

            mm_1 = time_to_second / 30;
            time_to_second %= 30;

            ss_1 = time_to_second;

            cout << "Z"
                 << " " << hh_1 << " " << mm_1 << " " << ss_1 << endl;
        }
    }

    return 0;
}