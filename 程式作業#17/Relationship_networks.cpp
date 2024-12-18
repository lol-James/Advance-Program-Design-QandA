#include <iostream>
#include <vector>

using namespace std;

void dfs(int student, vector<vector<int>> &adj_matrix, vector<bool> &visited)
{
    visited[student] = true;
    for (auto &item : adj_matrix[student])
        if (!visited[item])
            dfs(item, adj_matrix, visited);
}

int find_class_num(int N, int M, vector<pair<int, int>> &school)
{
    vector<vector<int>> adj_matrix(N);
    vector<bool> visited(N, false);
    int class_num = 0;

    for (int i = 0; i < M; i++)
    {
        int X = school[i].first;
        int Y = school[i].second;
        adj_matrix[X].push_back(Y);
        adj_matrix[Y].push_back(X);
    }

    for (int student = 0; student < N; student++)
        if (!visited[student])
        {
            dfs(student, adj_matrix, visited);
            class_num++;
        }

    return class_num;
}

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<pair<int, int>> school(M);
        for (int i = 0; i < M; i++)
            cin >> school[i].first >> school[i].second;
        cout << find_class_num(N, M, school) << endl;
    }
    
    return 0;
}
