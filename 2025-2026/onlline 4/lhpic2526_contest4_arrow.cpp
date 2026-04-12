#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 3;

int n;
string labyrinth[2];
bool visited[2][maxN];
int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};

bool inside(int x, int y)
{
    return (x >= 0 && y >= 0 && x < 2 && y < n);
}

bool recur(int x, int y)
{
    visited[x][y] = true;
    if (x == 1 && y == n - 1)
        return true;

    for (int i = 0; i < 4; i++)
    {
        int vx = x + dx[i],
            vy = y + dy[i];
        if (inside(vx, vy))
        {
            if (vx == 1 && vy == n - 1)
                return true;
            if (labyrinth[vx][vy] == '<')
                --vy;
            else
                ++vy;
            if (!visited[vx][vy] && recur(vx, vy))
                return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> labyrinth[0] >> labyrinth[1];

        // reset data
        memset(visited[0], 0, sizeof(visited[0][0]) * n);
        memset(visited[1], 0, sizeof(visited[1][0]) * n);

        if (recur(0, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
