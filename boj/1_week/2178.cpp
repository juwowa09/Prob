#include <iostream>
#include <string>
#include <queue>
using namespace std;

pair<int, int> pos[4] = {
    make_pair(1, 0),
    make_pair(-1, 0),
    make_pair(0, 1),
    make_pair(0, -1),
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string input;
    queue<pair<int, int>> q;

    cin >> n >> m;
    int **arr = new int *[n];
    int **visit = new int *[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr[i] = new int[m];
        visit[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            visit[i][j] = 0;
            arr[i][j] = input[j] - '0';
        }
    }
    q.push({0, 0});
    visit[0][0] = 1;
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int row = q.front().first + pos[i].first;
            int col = q.front().second + pos[i].second;
            if (row >= 0 && row < n && col >= 0 && col < m &&
                !visit[row][col] && arr[row][col])
            {
                q.push({row, col});
                visit[row][col] = visit[q.front().first][q.front().second] + 1;
            }
        }
        q.pop();
    }
    cout << visit[n - 1][m - 1];
}