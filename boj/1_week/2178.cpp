#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node
{
    int x;
    int y;
    int depth;
};

void enqueue(queue<Node> *q, int x, int y, int depth)
{
    Node nodes;
    nodes.x = x;
    nodes.y = y;
    nodes.depth = depth;
    q->push(nodes);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string input;
    queue<Node> q;

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
    Node node;
    node.x = 0;
    node.y = 0;
    node.depth = 1;
    visit[0][0] = 1;
    q.push(node);
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        if (x - 1 >= 0 && arr[x - 1][y] && !visit[x - 1][y])
        {
            visit[x - 1][y] = 1;
            enqueue(&q, x - 1, y, q.front().depth + 1);
        }
        if (x + 1 < n && arr[x + 1][y] && !visit[x + 1][y])
        {
            visit[x + 1][y] = 1;
            enqueue(&q, x + 1, y, q.front().depth + 1);
        }
        if (y - 1 >= 0 && arr[x][y - 1] && !visit[x][y - 1])
        {
            visit[x][y - 1] = 1;
            enqueue(&q, x, y - 1, q.front().depth + 1);
        }
        if (y + 1 < m && arr[x][y + 1] && !visit[x][y + 1])
        {
            visit[x][y + 1] = 1;
            enqueue(&q, x, y + 1, q.front().depth + 1);
        }
        if (x == n - 1 && y == m - 1 && visit[n - 1][m - 1])
            cout << q.front().depth;
        q.pop();
    }
}