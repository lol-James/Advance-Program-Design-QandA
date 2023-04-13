#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main()
{
    map<int, queue<string>> players_map; // 利用queue FIFO的特性來存打擊資訊
    int a, b;
    string str;

    for (int i = 0; i < 9; i++)
    {
        cin >> a;
        queue<string> all_infos;
        for (int j = 0; j < a; j++)
        {
            cin >> str;
            all_infos.push(str); // 從queue後端push一筆資料
        }
        players_map[i] = all_infos;
    }
    cin >> b;

    int base[4] = {0}; // {本壘, 1壘, 2壘, 3壘}
    int player = -1, score = 0, out_count = 0;
    while (1)
    {
        int k = 0;

        player = (player + 1) % 9;
        string info = players_map[player].front(); // 從queue前方讀一個資訊
        players_map[player].pop();                 // 讀過的就把他pop掉

        if (info == "FO" || info == "GO" || info == "SO")
        {
            out_count++;
            if (out_count == b)
            {
                break;
            }
            else if (out_count % 3 == 0) // 三出局攻守交換
            {
                for (int i = 0; i < 4; i++)
                    base[i] = 0;
            }
        }
        else if (info == "1B")
        {
            k = 1;
        }
        else if (info == "2B")
        {
            k = 2;
        }
        else if (info == "3B")
        {
            k = 3;
        }
        else if (info == "HR")
        {
            k = 4;
        }

        for (int i = 0; i < k; i++)
        {
            base[0] = base[3];
            base[3] = base[2];
            base[2] = base[1];

            if (i == 0) // 只有第一次推進，打者要上一壘
                base[1] = 1;
            else
                base[1] = 0;

            if (base[0]) // 有人跑回本壘了，得分!!
                score++;
        }
    }

    cout << score << endl;

    return 0;
}
